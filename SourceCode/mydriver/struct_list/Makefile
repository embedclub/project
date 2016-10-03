TARGET=list_test  
SRC=list_test.c list.c  
#SRC=$(wildcard *.c)  
OBJ=$(SRC:.c=.o)  
CFLAGS=-g -Wall -o  
  
$(TARGET):$(SRC)  
	gcc $(SRC) $(CFLAGS) $(TARGET)  
clean:  
	rm $(OBJ) $(TARGET)  

