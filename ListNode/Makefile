OBJECTS = ListNode.o Main.o
CC = g++
TAGARTS = TESTNODE
$(TAGARTS) :$(OBJECTS)
	$(CC) -g $(OBJECTS) -o TESTNODE  
ListNode.o : ListNode.cpp ListNode.h
	$(CC) -g -c ListNode.cpp
Main.o : Main.cpp ListNode.h
	$(CC) -g -c Main.cpp
clean:
	rm $(OBJECTS) $(TAGARTS)
