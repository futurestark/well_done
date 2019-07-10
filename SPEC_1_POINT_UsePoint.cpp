//SODERZHIT CLIENT CLASSA POINT (CLIENTSKIJ KOD)

#include <iostream> //sna4ala standart
#include "Point.h"  //potom svoi
//sna4ala includi potom usingi (a ne ya tak videl u drugih)
using namespace std; //4tob ne pisat std::(cout, endl etc)

int main()
{
	Point a; //object of type Point
	//we haven't accest to cout << a.x  as its private, we haven't ability
	//to set a.x = 55;(private field) so create(public) functions for this in Point.h
	
	//a.GetX(); moject vstroit tak kak header include i v nem inline metod, a esli bi @@@@@
	//telo bilo v Point.cpp on bi nevstroil mi poteryali b proizvoditelnost Point.cpp tolko dlya bolshih func
	//  !!! a esli ya hochu GetY sdelat vstraivaemoi s bolshim telom v Point.cpp to nado ee objavit vne classa
	//  v Point.h potomu chto ego soderzhimoe kompi videt v tochke vizova

	//pochemu po default takoe zna4enie u x i y pri4em odinakovoe?
	
	cout << a.GetX() << ", " << a.GetY() << endl;
	//potomu 4to eto kod kotorimi otlad4ik oblozhil nashu progu so vseh storon 4tob smotret
	// a ne vilizaem li mi iz pamyati a ne ispolzuem li neinit variables 4tob warning vidat etc
	int z = a.GetX(); // v debug add watch window tuda drag and drop z i pomenyai de na hex view z 
					  // -858993460 stalo 0xCCCCCCCC (C=1100) a v realease version bil bi realnui musor tak kak no info for debug !!

	a.SetX(10); 
	a.SetY(20); 
	cout << a.GetX() << ", " << a.GetY() << endl; //tozhe gromozdko sdelaem clientu print
	//4tob client smestil to4ku X na 5px naprimer kod bil bi gromozdkim
	//@@@ vigledil bi a.SetX(a.GetX()+5); @@@@ gromozdko povisim udobstvo clienta
	//a.SetX(a.GetX() + 5); napisivaya takie konstrucii legko oshibitsa class daet udobstvo i bezopastnost (sozdadim func Move)

	a.Move(5, 10);
	a.Print(); cout << endl;
	
	//ZADANIE NA DOM dopisat method Read(4tenie to4ki s klaviaturi)
	//                       method Dist(izmerenie rastoyaniya ot Point k Point)
	// ISPOLZUYA CLASS Point realizovat class Line(vmesto private x, y -> class Point a: Point b);
	// CLASS Treugolnik (3 Pointa :) za 11 min do konca video 3 nabor interestnih zada4 @@@!! sdelat potom as skill up and myToolCreate
}
