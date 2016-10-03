CUR_TARGET=touchkeydemo  
  
INCLUDES   += -I./  
CUR_SRCS_THREAD:= touchkeydemo.c  
  
touchkeydemo:  
	$(CC) $(CUR_SRCS_THREAD) -o $(CUR_TARGET) -lpthread -ldl -lm  
  
clean:  
	rm -fv $(CUR_TARGET)
