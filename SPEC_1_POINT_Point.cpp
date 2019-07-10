//SODERZHIT REALIZACIYU CLASSA POINT

#include <iostream> //Point::Print metod classa use cout
#include "Point.h";
using namespace std; //Point::Print metod classa use cout

void Point::SetX(int _x) {
	// x viden s private field 4erez #include "Point.h"; v nego i pishem set nami _x
	x = _x >= 0 ? _x : 0; //proverka duraka delaet set esli name _x>=0 ina4e set 0
						  //poetomu nemozhem isportit x i zagnat Point za predeli ekrana
};

void Point::SetY(int _y) {

	y = _y >= 0 ? _y : 0;
};

//dx ne sovpadaet s delta_x v headere imenem no i ne obyazano sovpadat
void Point::Move(int dx, int dy) {
	//set eto kontrol tam proverka i ee ne nado delat i perepisivat v drugih funciyah
	SetX(x + dx);  //@@@!!! METODI CLASSA MOGUT VIZIVAT METODI SVOEGO CLASSA
	SetY(y + dy);
};

void Point::Print() {
	//cout << '(' << a.GetX() << ", " << a.GetY() << endl;
	//-------- a.GetX ne nado ibo func Print 4len classa poetomu prosto x ------
	cout << '(' << x << ','<<y<< ')' << endl; 
};