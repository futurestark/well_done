//SODERZHIT REALIZACIYU CLASSA POINT

#include <iostream> //Point::Print metod classa use cout
#include <cmath>
#include "Point.h";
using namespace std; //Point::Print metod classa use cout

//======= SKRITIJ ARG ETO ADRESS OBJECTA DLYA KOTOROGO FUNCIYA VIZVANA =====
// FUNKCIYAM PEREDAETSA TAINO ADDRESS OBJECTA(DLYA KOVO ONA VIZIVAETSA) 
// A NE U OBJECTA KU4A SSILOK NA  VSE FUNCII CLASSA
// K ETOMU ADDRESSU V KAJDOI FUNCII CLASSA MOGNA OBRATITSA PO IMENI ->THIS
void Point::SetX(int _x) { // +1 Skritij ARG ( itogo 2)
	
	x = _x >= 0 ? _x : 0; 
						 
};
//=========== FUNCIYA VISHE 4EREZ THIS-> HULIGANSKOE ISPOLZOVANIE ->THIS ================
/*
void Point::SetX(int x) { 
	//tut x bez _ i 4tob ih razli4at stavyat this->	k 4lenu classa			
	this->x = x >= 0 ? x : 0; //tot kto this-> tot x i 4len classa 
							  // a kto bez tot x localnui argument
};		// no 4e mnogie tak kod i pishut osobenno 4asto return this->x+y;
        // eshe ispolzuut pri peregruzke operatorov prisvaivaniya etc 
*/
//==========================================================================

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
	//@@@@ da esli etu func zakinut v header v otdel private to ona vsravno bud compile tak kak ona ne 4len classa a friend
	//to na nee ne deistvuet private public etc no logi4nee kidat ee v public tak kak ona dostupna lubomu vneshnemu kodu
	//&&&&&&&&& DRUZHBA INCAPSULYACIYU NE NARUSHAET TAK friendom funciyu delaet class v headere kotorogo obyavlena i vne
	//classa druzhbu ne navyazhesh, i drugom mozhet byt funciya ili vse funcii drugovo classa !!!!!!!!!!
	//naprimer v headere point.h takoe   friend Pixel::Move(int, int); i tak kazhduyu
	//v CONSTRUCTORAH(sled uroke) budet primer kogda mu i hotim sdelat func 4lenom classa no ne mozhem a prava dostupa dat nado vot togda friend reshaet
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
