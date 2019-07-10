all : buttontest fixedbuttons fontview watchwindow
buttontest:	buttontest.c
	gcc -Wall buttontest.c -o buttontest `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
fixedbuttons:	fixedbuttons.c
	gcc -Wall fixedbuttons.c -o fixedbuttons `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
fontview:	buttontest.c
	gcc -Wall fontview.c -o fontview `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
watchwindow:	fixedbuttons.c
	gcc -Wall watchwindow.c -o watchwindow `pkg-config --cflags gtk+-2.0` `pkg-config --libs gtk+-2.0`
install:
	cp buttontest ~/bin
	cp fixedbuttons ~/bin
	cp fontview ~/bin
	cp watchwindow ~/bin
clean:
	rm -f buttontest fixedbuttons fontview watchwindow *~ *.o   

