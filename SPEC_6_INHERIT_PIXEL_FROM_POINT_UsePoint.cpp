//SODERZHIT CLIENT CLASSA POINT (CLIENTSKIJ KOD)

#include <iostream> //sna4ala standart
#include <cmath>
#include "Point.h"  //potom svoi

using namespace std; 
//-------------- i takoe mogna -------------------------
	Point g;   // tut class pamayti EXTERN
	static Point sg;  // a tut STATIC
//------------------------------------------------------
// v func gDist parametri peredautsa po zna4eniyu(zna4it kopiruetsa)esli to4ek ne mnogo to mozhno kopirovat
double globalDist(Point a, Point b)
{
	return sqrt(pow(static_cast<double>(a.GetX() - b.GetX()), 2)
		      + pow(static_cast<double>(a.GetY() - b.GetY()), 2) //kovo v double v  kruglih skobkah poetomu 2 para skobok
			   );  //@@@@@@@@@@ esli v header GetX() GetY() zakinut v private to eta func perestanet compile(tak kak private 4leni classa a eta func global)
}

double silkaDist(const Point &a, const Point &b) //kogda mi peredaem silku na kakoito object mi predostavlyaem ei pryamoi dostup k originalu
{
	return sqrt(pow(static_cast<double>(a.GetX() - b.GetX()), 2)
		+ pow(static_cast<double>(a.GetY() - b.GetY()), 2) //kovo v double v  kruglih skobkah poetomu 2 para skobok
	);
}


int main()
{
	
	static Point sl;  //eshe odin STATIC
	Point a,b; // SOZDANIE OBJECTA (AUTOMATICHESKOI MEM TOEST V STACKE) i zna4it 4to pamyat automati4eski osvobo-
			 // ditsa compilatorom kogda zakon4itsa block (v dannom slu4ae block main :)) STACK vutolknen object posle konca blocka
	
	cout << a.GetX() << ", " << a.GetY() << endl; //===== kogda object v neopredelennom sostoyanii
	int z = a.GetX();

	a.SetX(10); 
	a.SetY(20);  
		
	//===========================================================================================
	cout << a.GetX() << ", " << a.GetY() << endl;


	a.Move(5, 10);
	a.Print(); cout << endl;

	Point *p = new Point;  
	
	p->SetX(65);   // stavim p-> i smotrim 4to dostupno 4erez ukazatel
	p->SetY(70);   // a delot to mogno vse 4to mogna dleat s objectom classa
	p->Print(); cout << endl; 	

	//-------- delaem method izmerenie rasstoyaniya mezhdu to4kami gDist------
	p->Move(-20, 0); //dlya funcii gDist 4tob krugloe 4islo bilo vizvali
	cout << "Distance from";  a.Print();
	cout << "and "; p->Print();
	cout << " = " << globalDist(a, *p)<<endl;
	cout << " = " << silkaDist(a, *p) << endl; // teper eta funciya vizivaetsa bistrie a izmenenij nikahih tolko silka

	//------- dlya testa friend func fDist hotya lusthe nazvat bi frDist a to ktoto float pro4itaet
	cout << "Distance from";  a.Print();
	cout << "and "; p->Print();
	cout << " = " << friendDist(a, *p) << endl;

	// dlya 4lena klassa Dist
	cout << "Distance from";  a.Print();
	cout << "and "; p->Print();
	cout << " = " << a.Dist(*p) << endl; //sposob vizova 1
	cout << " = " << p->Dist(a) << endl; //sposob vizova 2
	cout << " = " << a.Dist(a) << endl; //sposob vizova 3 ved rastoyanie ot a do b ravno ot b do a !

	delete p;  //NELZA ZABIVAT ON SAM SEBYA NE UDALIT KAK V AUTO MEM,  UTECHKA PAMYATI ! ! ! !
}