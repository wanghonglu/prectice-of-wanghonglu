#makefile
##OBJECTS=boy_student.o student.o  ##此处一定要先写最里面的那个 最后写主函数
OBJECTS=student.o boy_student.o  ##此处一定要先写最里面的那个 最后写主函数
CC=g++ 
#生成可执行程序Apple
Apple: $(OBJECTS)
	$(CC)$(OBJECTS) -o Apple
##student.o: student.h
##boy_student.o: boy_student.h
#清除源文件以外的操作命令
clean:
	rm -f Apple core $(OBJECTS)
