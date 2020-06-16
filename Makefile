HEADERS	= dense.h
SOURCES	= test.c dense.c
OBJECTS	= test.o dense.o
LINK	= gcc -o
COMPILE	= gcc -c -Wall -std=c99 -w

test : $(OBJECTS)
	$(LINK) test $(OBJECTS) -lm

test.o : $(SOURCES) $(HEADERS)
	$(COMPILE) test.c

dense.o : dense.c dense.h
	$(COMPILE) dense.c

memcheck : test
	valgrind --tool=memcheck test

clean :
	rm -f test $(OBJECTS)
