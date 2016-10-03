what is the input?
	Input子系统处理输入事务，任何输入设备的驱动程序都可以通过Input输入子系统提供的接口注册到内核，利用子系统提供的功能来与用户空间交互。输入设备一般包括键盘，鼠标，触摸屏等，在内核中都是以输入设备出现的。

	linux中input系统主设备号是13
	次设备号： 

		0-31      joystick（游戏杆）
		32-62  	  mouse(鼠标)
		63   	  mice（鼠标）
		64-95     事件（Event）设备

input子系统的结构
	1. Input子系统是分层结构的，总共分为三层： 硬件驱动层，子系统核心层，事件处理层。

	（1）其中硬件驱动层负责操作具体的硬件设备，这层的代码是针对具体的驱动程序的，需要驱动程序的作者来编写。
	（2）子系统核心层是链接其他两个层之间的纽带与桥梁，向下提供驱动层的接口，向上提供事件处理层的接口。
	（3）事件处理层负责与用户程序打交道，将硬件驱动层传来的事件报告给用户程序。

  	2.Input子系统的三个重要结构体：

	input_dev 是硬件驱动层，代表一个input设备

	input_handler 是事件处理层，代表一个事件处理器

	input_handle 个人认为属于核心层，代表一个配对的input设备与input事件处理器

struct input_handle {  
    void *private;   //每个配对的事件处理器都会分配一个对应的设备结构，如evdev事件处理器的evdev结构，注意这个结构与设备驱动层的input_dev不同，初始化handle时，保存到这里。   
    int open;        //打开标志，每个input_handle 打开后才能操作，这个一般通过事件处理器的open方法间接设置   
    const char *name;   
    struct input_dev *dev;  //关联的input_dev结构   
    struct input_handler *handler; //关联的input_handler结构   
    struct list_head    d_node;  //input_handle通过d_node连接到了input_dev上的h_list链表上   
    struct list_head    h_node;  //input_handle通过h_node连接到了input_handler的h_list链表上   
};

在内核中，input_dev 表示一个 input设备；input_handler 来表示input设备的 interface。 所有的input_dev 用双向链表 input_dev_list 连起来。
在调用 int input_register_device(struct input_dev *dev) 的时候，会将新的 input_dev 加入到这个链表中。所有的input_handler     用双向链表 input_handler_list 连起来。
在调用 int input_register_handler(struct input_handler *handler) 的时候，会将新的 input_handler 加入到这个链表中。每 个input_dev 和 input_handler 是要关联上才能工作的，在注册 input_dev 或者 input_handler的时候，就遍历上面的列表，找到相匹配的，然后调用 input_handler 的 connect函数来将它们联系到一起。
通常在input_handler 的 connect函数中，就会创建 input_handle， input_handle就是负责将 input_dev 和input_handler 联系在一起的.

输入事件

     各层之间通信的基本单位就是事件，任何一个输入设备的动作都可以抽象成一种事件，如键盘的按下，触摸屏的按下，鼠标的移动等。事件有三种属性：类型（type），编码(code)，值(value)，Input子系统支持的所有事件都定义在input.h中，包括所有支持的类型，所属类型支持的编码等。事件传送的方向是 硬件驱动层-->子系统核心-->事件处理层-->用户空间

设备有着自己特殊的按键键码，我需要将一些标准的按键，比如0－9，X－Z等模拟成标准按键，比如KEY_0,KEY-Z等，所以需要用到按键模拟，具体 方法就是操作/dev/input/event1文件，向它写入个input_event结构体就可以模拟按键的输入了。


linux/input.h中有定义，这个文件还定义了标准按键的编码等

struct input_event {

struct timeval time; //按键时间

__u16 type; //类型，在下面有定义

__u16 code; //要模拟成什么按键

__s32 value;//是按下还是释放

};

code：

事件的代码.如果事件的类型代码是EV_KEY,该代码code为设备键盘代码.代码植0~127为键盘上的按键代码,0x110~0x116 为鼠标上按键代码,其中0x110(BTN_ LEFT)为鼠标左键,0x111(BTN_RIGHT)为鼠标右键,0x112(BTN_ MIDDLE)为鼠标中键.其它代码含义请参看include/linux/input.h文件. 如果事件的类型代码是EV_REL,code值表示轨迹的类型.如指示鼠标的X轴方向REL_X(代码为0x00),指示鼠标的Y轴方向REL_Y(代码 为0x01),指示鼠标中轮子方向REL_WHEEL(代码为0x08).

value：

事件的值.如果事件的类型代码是EV_KEY,当按键按下时值为1,松开时值为0;如果事件的类型代码是EV_ REL,value的正数值和负数值分别代表两个不同方向的值.


type: 

/*

 * Event types功能实现
 */

#define EV_SYN0x00 // 表示设备支持所有的事件
#define EV_KEY 0x01 // 键盘或者按键，表示一个键码
#define EV_REL 0x02 // 鼠标设备，表示一个相对的光标位置结果(相对坐标)
#define EV_ABS 0x03 // 手写板产生的值，其是一个绝对整数值
#define EV_MSC 0x04 // 其他类型
#define EV_SW  0x05 //
#define EV_LED 0x11 // LED灯设备
#define EV_SND 0x12 // 输入声音
#define EV_REP 0x14 // 允许重复按键类型
#define EV_FF  0x15 //
#define EV_PWR 0x16 // 电源管理事件
#define EV_FF_STATUS0x17
#define EV_MAX 0x1f

有哪些API

分配/释放一个输入设备：

       struct input_dev *input_allocate_device(void);

       void input_free_device(struct input_dev *dev);

注册/注销输入设备:


       int __must_check input_register_device(struct input_dev *);

       void input_unregister_device(struct input_dev *);

报告输入事件:    

       void input_event(struct input_dev *dev, unsigned int type, unsigned int code, int value);/* 报告指定type、code的输入事件 */

       void input_report_key(struct input_dev *dev, unsigned int code, int value);/* 报告键值 */

       void input_report_rel(struct input_dev *dev, unsigned int code, int value);/* 报告相对坐标 */

       void input_report_abs(struct input_dev *dev, unsigned int code, int value);/* 报告绝对坐标 */

       void input_sync(struct input_dev *dev);/* 报告同步事件 */


Input驱动编写步骤

1.分配一个输入设备；
2.注册一个输入设备；
3.驱动支持什么事件；
Set_bit告诉inout子系统它支持哪些事件
Set_bit(EV_KEY,button_dev.evbit)
Struct input_dev中有两个成员，一个是evbit;一个是keybit.分别用来表示设备所支持的事件类型和按键类型。
4.驱动事件报告；
5.释放和注销设备；

  7 /**
  8  * struct gpio_keys_button - configuration parameters
  9  * @code:               input event code (KEY_*, SW_*)
 10  * @gpio:               %-1 if this key does not support gpio
 11  * @active_low:         %true indicates that button is considered
 12  *                      depressed when gpio is low
 13  * @desc:               label that will be attached to button's gpio
 14  * @type:               input event type (%EV_KEY, %EV_SW, %EV_ABS)
 15  * @wakeup:             configure the button as a wake-up source
 16  * @debounce_interval:  debounce ticks interval in msecs
 17  * @can_disable:        %true indicates that userspace is allowed to
 18  *                      disable button via sysfs
 19  * @value:              axis value for %EV_ABS
 20  * @irq:                Irq number in case of interrupt keys
 21  * @gpiod:              GPIO descriptor
 22  */
 23 struct gpio_keys_button {
 24         unsigned int code;
 25         int gpio;
 26         int active_low;
 27         const char *desc;
 28         unsigned int type;
 29         int wakeup;
 30         int debounce_interval;
 31         bool can_disable;
 32         int value;
 33         unsigned int irq;
 34         struct gpio_desc *gpiod;
 35 };


struct gpio_keys_button {
        /* Configuration parameters */
        unsigned int code;      /* input event code (KEY_*, SW_*) */
        int gpio;               /* -1 if this key does not support gpio */
        int active_low;
        const char *desc;
        unsigned int type;      /* input event type (EV_KEY, EV_SW, EV_ABS) */
        int wakeup;             /* configure the button as a wake-up source */
        int debounce_interval;  /* debounce ticks interval in msecs */
        bool can_disable;
        int value;              /* axis value for EV_ABS */
        unsigned int irq;       /* Irq number in case of interrupt keys */
};



