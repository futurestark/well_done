all: cursedcolors cursedinput cursedmouse cursedpassword
cursedcolors:
	gcc cursedcolors.c -o cursedcolors
cursedinput:
	gcc cursedinput.c -o cursedinput
cursedmouse:
	gcc cursedmouse.c -o cursedmouse
cursedpassword:
	gcc cursedpassword.c -o cursedpassword
install:
	cp cursedcolors ~/bin
	cp cursedinput ~/bin
	cp cursedmouse ~/bin
	cp cursedpassword ~/bin
clean:
	 rm -f *.o   
	 rm -f cursedcolors cursedinput cursedmouse cursedpassword
	 rm -f *~
