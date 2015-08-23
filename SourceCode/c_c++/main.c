#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>
#include<errno.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/time.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define IPSTR "196.168.2.40"/*IP地址*/
#define PORT 80/*端口号*/
#define BUFSIZE 4096/*缓冲区大小*/

#define VALUE    "{...}"/*改成你自己的VALUE,此处针对yeelink.net泛型传感器，详见网站API文档*/
#define APIKEY   "29933f69a514a91a010f42d5078b3c16"/*改成你自己的APIKEY*/
#define DEVICE   "16477"/*改成你自己的硬件地址*/
#define SENSOR   "28843"/*改成你自己的传感器地址，28840往手机发，28841往设备发控制开关*/

void get_time_string(char*time_str);

int main(int argc,char**argv)
{
    int sockfd,ret;
    struct sockaddr_in servaddr;/*用来存放转化后的32位二进制格式IP地址的结构体*/
    char *str,*tempstr,*time_str;
    socklen_t len;
    /*创建套接字，用socket()函数*/
    if((sockfd = socket(AF_INET,SOCK_STREAM,0))<0)/*地址族，TCP流类套接口，指定协议常用0*/
    {
        printf("socket error!\n");
        exit(0);
    }
    /*描述端口信息*/
    bzero(&servaddr,sizeof(servaddr));/*将servaddr清零，sizeof()包括'\0',推荐用memset替代bzero */
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(PORT);/*htons是将整型变量从主机字节顺序转变成网络字节顺序，就是整数在地址空间存储方式变为：高位字节存放在内存的低地址处（大尾顺序）*/

    /*点分十进制（ddd.ddd.ddd.ddd）转变为32位二进制整数*/
    if(inet_pton(AF_INET,IPSTR,&servaddr.sin_addr)<=0)/*地址族，来源地址，转化后数据*/
    {
        printf("inet_pton error!\n");
        exit(0);
    }
    
    /*建立通讯连接，TCP必须先接通再read,write;UDP不用接通即可sendto。区别：TCP像打电话，只有通了才能对话，UDP就像发短信。*/
    if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))<0)
    {
        printf("connect error!\n");
        exit(0);
    }

    /*申请动态内存，并清零。动态内存存放在堆栈中*/
    tempstr=(char*)malloc(128);
    memset(tempstr,0,128);
    time_str=(char*)malloc(32);
    memset(time_str,0,32);

    get_time_string(time_str);/*显示当前具体时间*/

    strcat(tempstr,"{\"timestamp\":\"");/*tempstr={timestamp: */
    strcat(tempstr,time_str);
    strcat(tempstr,"\",\"value\":");
    strcat(tempstr,VALUE);
    strcat(tempstr,"}");
    len=strlen(tempstr);

    free(time_str);

    str=(char*)malloc(4096);
    memset(str,0,4096);

    strcat(str,"POST /v1.0/device/");
    strcat(str,DEVICE);
    strcat(str,"/sensor");
    strcat(str,SENSOR);
    strcat(str,"/datapoints HTTP/1.1 \r\n");/*有时候仅仅\n不能换行，需要先\r回车再\n换行才行*/
    strcat(str,"User-Agent:curl/7.35.0\r\n");
    /*URL:http://api.yeelink.net/v1.0/device/16477/sensor28840/datapoints*/   
    strcat(str,"Host:api.yeelink.net\r\n");
    strcat(str,"Accept:*/*\r\n");
    strcat(str,"U-ApiKey:");
    strcat(str,APIKEY);
    strcat(str,"\r\n");
    strcat(str,"Content-Type:application/x-www-form-urlencoded\r\n");
    strcat(str,"Content-Length:%d\r\n\r\n");
    strcat(str,tempstr);
    strcat(str,"\r\n\r\n\n\n");

    free(tempstr);
    sprintf(str,str,len);/*将格式化数据写入某个字符串缓冲区*/
    
    printf("%s",str);

    ret=write(sockfd,str,strlen(str));/*将str写入sockfd中*/
    if(ret<0)
    {
        printf("send error! errno %d,error messege'%s'\n",errno,strerror(errno));
        exit(0);
    }
    else
    {
        printf("send succeser total send %d bytes! \n\n",ret);
    }

    free(str);
    
    close(sockfd);
    return 0;
}

void get_time_string(char*time_str)
{
    time_t timep;
    struct tm *p;

    time(&timep);
    p=localtime(&timep);/*此函数获得tm结构体的时间，是已经进行过时区转化为本地时间*/
 
    sprintf(time_str,"%d-%d-%dT%d:%d:%d",1900+p->tm_year,1+p->tm_mon,p->tm_mday,p->tm_hour,p->tm_min,p->tm_sec);
}
