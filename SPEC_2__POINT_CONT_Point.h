#pragma once
//SODERZHIT OPREDELENIE CLASSA POINT

class Point
{
private:
	int x, y; //lutshe esli ho4etsa x_ y_ posle 4em pered 4tob ne sovpadalo s std libami

public:
	
	//traditionally fucn nazv Get Set a dalshe imya togo field skotorim oni rabotayut
	// drugaya tradiciya nazivaetsa takje kak field budto peregruzhaem no s bolshoi bukvi: 
	//  int X();    esli skobki pustie to eto Get method        (iz nee 4itaem)
	//  void X(int); esli return zna4enie void to mu Set method (v nee peredaem)
	/*  a esli private:
	int x_, y_;
	int x();      to koro4e togda s malenkih bukv
	void x(int);
	*/
	//------------- tak delat nelza ibo nelza sdelat zishitu ot duraka -------
	// ili voobshe vkleivaut vse v odnu func
	// int &X();  to cout<<X(); get   X()=90;set    client mozhet nakosya4it
	//------- a zna4it eto tolko dlya public polei a oni DIRKA V PROEKTE -----
	int GetX()const { return x; } //tut kompi videt 4to x ne menyaetsa(const)	

	int GetY()const;   //int Y(); //alternative zapis , a tut y ne videt 4to const
					   //poetomu const ukazivaem i v prototipe int GetY()const; i v realizacii nizhe inline int Point::GetY()const { return y; } 

	void SetX(int);
	void SetY(int);  //void Y(int); //alternative zapis
	
	void Move(int delta_x, int delta_y); 
	void Print()const;  //eto zhe kasaetsa i Print v Point.cpp

	//sdelaem func takuyu kak fDist no tolko 4lenom classa tolko ei ne nado 2 objecta peredavat(const Point &, const Point &);
	//odin u nee uzhe taino est(this) ona zhe 4len classa, a do kovo izmerit i peredaem (ot sebya do togo parnya)
	double Dist(const Point &)const; //@@@@const posle args eto mi zazhishaem tovo dlya kovo ee vizivat budem, u friendDist zhe 2 consta

	// friend func mozhet bit gde ugodno i v private i v public i vse budet ok no logi4nee vsego v samui konec public potomu 4to
	//specifikatori prav dostupa private i public vozdeistvuyut tolko na 4leni klassa, func friend 4lenom klassa ne yavlyaetsa
	friend double friendDist(const Point &, const Point &); //imena ne vazhni i tak ponyatno
	//@@druzhba inkapsulyaciyu ne narushaet !!! ibo drugom metod obyavlyaet class, snaruzhi druzhbu ne navyazhesh classu!!! 
	//drugom mozhet bit eshe funciya 4len kakovoto classa ili ves class friend Class Point; i togda kazhdaya func classa druga 
	//stanovitsa drugom etogo classa no tak bivaet redko no bivaet :)
	//druzhba voznikaet kogda mi hoteli bi metod sdelat 4lenom klassa public no ne mozhem a prava dostupa dat nado

};

inline int Point::GetY()const { return y; } 
