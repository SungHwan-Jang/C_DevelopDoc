CFLAGS=-Wall -g

OBJECTS = ex22.o ex22_main.c

ex22.o: ex22.c
	gcc -c ex22.c -o ex22.o

install: $(OBJECTS)
	gcc $(OBJECTS) -o ex22_main

clean:
	rm -rf $(OBJECTS)
