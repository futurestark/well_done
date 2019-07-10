//SODERZHIT REALIZACIYU CLASSA POINT

#include <iostream> //Point::Print metod classa use cout
#include <cmath>
#include "Point.h";
using namespace std; //Point::Print metod classa use cout

void Point::SetX(int _x) { // +1 Skritij ARG ( itogo 2)
	
	x = _x >= 0 ? _x : 0; 
						 
};


void Point::SetY(int _y) { // +1 Skritij ARG ( itogo 2)

	y = _y >= 0 ? _y : 0;
};

void Point::Move(int dx, int dy) { // +1 Skritij ARG ( itogo 3)
	//this->SetX(this->x + dx);  //COMPI SAM PODSTAVLYAET PERED VSEMI 4LENAMI CLASSA 
	//this->SetY(this->y + dy); //a pered SetY nujen ved ei on tozhe peredalsa skritij 3ij argument
	SetX(x + dx);
	SetY(y + dy);
};


//-------- FRIEND FUNC ----------
double friendDist(const Point &a, const Point &b) //zagolovok v header s pometkoi friend
{
	//tak kak drug to prosto srazu k polyam klassa a.x - b.x a ne 4erez aksesori a.GetX() - b.GetX()) kak bilo
	//4tob zna4 4to takoe pow i sqrt nado include <cmath>
	return sqrt(pow(static_cast<double>(a.x - b.x), 2)
		+ pow(static_cast<double>(a.y - b.y), 2) //kovo v double v  kruglih skobkah poetomu 2 para skobok
	    );
	
}
//--------- DIST KAK 4LEN CLASSA
double Point::Dist(const Point &b)const //vtoroi arg ne nado meryaet ot sebya i do togo parnya
{	//poetomu vtoroi const posle args() zashitit togo dlya kovo vizivat budem 4tob ne pomenyat slu4aino ego original
	
	//func dist vizvana dlya objecta na kotorui pokazivaet this imeet li ona pravo zalezt k koordinate drugovo objecta b(b.x)esli ona 4len classa?
	//modificatori prav dostupa pivate i public opisivaut prava dostupa ne k konkretnim objectam classa a ko vsem objectam.
	//(priv pub deistvuut na urovne classa a ne objecta)
	return sqrt(pow(static_cast<double>(x - b.x), 2)
		+ pow(static_cast<double>(y - b.y), 2) 
	    );
}

//============= vot esli sdelaem ukazatel na object Point ==========
// i takih objectov mnogo kak ponyat 4erez ukazatel kod kakova objecta vizovetsa??
void Point::Print() const{ // +1 SKRITIJ ARG ( itogo 1)
	//dobavili const i teper esli x ili y budet menyatsa f etoi funcii budet error compilatora
	//cout << '(' << x++ << ',' << y++ << ')' << endl;  x++ y++ vizivaut teper oshibki funciya to const
	//v etom i smisl pisat const ne tolko v headere no i tut 4tob compilator mog proverit contract v clientskom kode

	cout << '(' << x << ','<<y<< ')' << endl;
	//@@@@@@@@@@ obratitsa k addressu mogna 4erez ->this
	//na samom dele v kod luboi funccii  compilyator podstavlyaet ->this pered vsemi 4lenami classa
	//cout << '(' << this->x << ',' << this->y << ')' << endl;
};
