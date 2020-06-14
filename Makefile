HEADERS	= test.h
SOURCES	= est.c
OBJECTS	= test.o
LINK	= gcc -o
COMPILE	= gcc -c -Wall -std=c99 -w

test : $(OBJECTS)
	$(LINK) test $(OBJECTS) -lm

test.o : test.c
	$(COMPILE) test.c

memcheck : test
	valgrind --tool=memcheck test

clean :
	rm -f test $(OBJECTS)
