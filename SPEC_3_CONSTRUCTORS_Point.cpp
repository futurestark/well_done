#include <iostream>
#include "Point.h"

using namespace std;

//davai v constructore prisvoim objectu korrectnie na4alnie zna4eniya
Point::Point()
//V CONSTRUCTORE BY DEF x = y = 0; TOZHE KRUTO BILO BI NASPISAT SPISKOM INICIALIZACII
//vot tak     : x(0), y(0)

{//I TEPER POKA MI NE SDELALI SET S MOMENTA SOZDNAIYA, OBJ GARANTIROVANO BUDET KOREKTNIM
	x = y = 0;  //VOT I ZAKRITA DIRA no ne vsegda podhodit 0 ina4e compilyator bi nuli vsem pisal by def
	//pri sozdanii obj v dynam mem operator new vizivaet v etom meste constructor
	//for debug
	cout << "Point(): ";
	Print();
}

//!!!!!!!!!!!!!!! etot zhe telo dlya constr 3 V ODNOM FLACONE vse budet korectno a te mozhno comment
Point::Point(int _x, int _y) //skopiruyu s constr by def a ne ego ispravlyat budu tem bolee eto peregruzka
{ //+ postavit zashitu ot zapisi naprimer 4isel menshe 0, use Set() metod 4tob sozdavalsa korektno s proverkoi
	x = _x;  //zdes nado ispolzovat Set() metodi
	y = _y;  //zdes nado ispolzovat Set() metodi
	cout << "Point(int, int): ";
	Print();  //VOT GDE SEt() bilo bi kruto ee peripisat 4tob ona vizivalas v  : x(0), y(0) kontekste
}

Point::Point(int _x) // 4em x initialize est a 4em y? nu mozhem tem zhe 4to x ili x*2 ili 0 etc...
{  
	x = _x;  //zdes nado ispolzovat Set() metodi
	y = 0;   
	cout << "Point(int): ";
	Print();
}

Point::Point(const Point &other) //dali imya other tipa drugoi Point tot kotorui kopirovat budem
: x(other.x), y(other.y)   //spisok inicializacii - tut srazu v x() copiruetsa Point &other(x) ibo odnogo tipa kak int a = b; bez vsyakih const by default vizovov
//:x(Set(other.x)), y(Set(other.y) mozhno bilo bi na letu proverku delat eslib funciya Set() vozvrashala zna4eniya @@!!!!!!
// po etoi pri4ine 4tob ne delat Set s return 4tob ne putalos s Get ---> mi delaem otdelnuyu fuc VALIDATOR(Check naprimer) i vizivaem ee i nikakih problem ###@@@
{                  
	x = other.x; //kopiruet pole v pole po standartu, polya kopiruyutsa a ne blocki bitov
	y = other.y; //@@@###### zdes ne nado ispolzovat Set() metodi ibo object uzhe sozdalsa korectno i proveryat ne nado(provekroi v Set())###@@
	
	cout << "copyConstrPoint(): "; Print();
	/*
	KROME TAKOI ZAPISI EST ESHE VTOROI SPOSOB SPISOK INICIALIZACII ILI INICIALIZACIYA SPISOK
	etot spisok raspolagaetsa mezhdu zagolovkom i telom funcii i otdelyaetsa ot zagolovka dvoeto4iem
		Point::Point(const Point &other): ____i potom tut sledom spisok____ ili pishut
		{
		}
		Point::Point(const Point &other):
		i __tut spisok____
		{
		}      ili
	    Point::Point(const Point &other)
		: __ i tut spisok____
		{
		}
    I SOSTOIT SPISOK IZ POLEI V DLYA KOTORIH V SKOBKAH PISHETSA INICIALIZIRUYUSHEE ZNA4ENIE RAZDELYAYA ','
	Point::Point(const Point &other)
	: x(other.x), y(other.y)               polyu x prisvaevetsa zna4enie other.x
	{
	}
	*****************************************************************
	KAK LUTSHE SPISKOM INIT ILI KAK BILO polyami v tele x = other.x; ????????????????
	OTVET - pri pro4ih ravnih spisok inicializacii 4ashe daet bolee effectivnui code, a v nekotorih situaciyah tolko 
		    spiskom vozmozhna inicializaciya, a v tele constructora nevozmozhna
			Vsegda polzuisya spiskom inicializacii - effectivnost v primer nizhe
	
	NAPRIER SDELALI DOMASHNEE ZADANIE I SOZDALI CLASS LINIYA
	Class Line
	{
		Point x,y;  
		....      kak bi dlya etogo classa vugledil bi constructor copirovaniya?
	};
	Line::Line(const Line &other)  constuctor sozdaet object kotorogo nebilo
	//: x(other.x), y(other.y)  
	{
		x = other.x;  do vhoda v costructor x,y object kotorogo nebilo a tut uzhe est zna4it do vhoda v telo x,y sozdautsa constructorom 
		y = other.y;  po umol4aniyu(by default) a v etom mesto davai mi zna4enie po umol4aniyu sotrem i zamenim novimi zna4eniyami
	                  toest sdelalsa init a potom prisvaivanie eto tozhe samoe 4to
		int a = 0; dva deistviya  
		a = b;     dva deistviya 
			a mozhno bilo 
		int a = b;   vot eto i est analog inicializacii spiskom effectivnost nalitso v odnu operaciyu
	}
	*********************************************************************
	*/
}

Point::~Point() //~ eto osobaya bukva v imeni destructora eto ego imya
{ //vizivaetsa kazhdij raz pri uni4tozhenii objecta, vutalknulsa li on iz steka vuhodya iz oblasti vidomosti avtomamati4eski 
  //ili uni4tozhaetsa budu4i stati4eskim ili globalnim kogda programma otrabotala, v dynam mem operator delete vizivaet constr 
	cout << "~Point(): "; Print(); 
}

void Point::Print() const {  
	cout << '(' << x << ',' << y << ')' << endl;
	//@@@@@@@@@@ obratitsa k addressu mogna 4erez ->this
	//na samom dele v kod luboi funccii  compilyator podstavlyaet ->this pered vsemi 4lenami classa
	//cout << '(' << this->x << ',' << this->y << ')' << endl;
};
