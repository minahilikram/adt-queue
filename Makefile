CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g

#Directories where the compiler can find things
INCLUDES    = -Iinclude

all : testing simulation


testing :
	gcc $(CFLAGS) src/linkedList.c src/queue.c src/testing.c -o bin/runTests -Iinclude


simulation: 
	gcc $(CFLAGS) src/linkedList.c src/queue.c src/simulation.c -o bin/simulation -Iinclude

clean:
	@ rm *.o
	@ rm bin/*

run:
	cd bin; ./simulation
	
runtests:
	cd bin; ./runTests
