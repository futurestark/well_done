all : helloworld
helloworld:	helloworld.c
	gcc -Wall helloworld.c -o helloworld `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
install:
	cp helloworld ~/bin
clean:
	rm -f helloworld *~ *.o   

