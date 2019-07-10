all : calculator-1 calculator-2
calculator-1:	calculator-1.c
	gcc -Wall calculator-1.c -o calculator-1 `pkg-config --cflags --libs libglade-2.0`
calculator-2:	calculator-2.c
	gcc -Wall calculator-2.c -o calculator-2 `pkg-config --cflags --libs libglade-2.0`
install:
	cp calculator-1 ~/bin
	cp calculator-1 ~/bin
clean:
	rm -f calculator-1 calculator-2 *~ *.o   

