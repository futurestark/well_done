all : buttontest
buttontest:	buttontest.c
	gcc -Wall buttontest.c -o buttontest `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
install:
	cp buttontest ~/bin
clean:
	rm -f buttontest *~ *.o   

