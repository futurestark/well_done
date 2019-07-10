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
    //est dve oshibki ibo 7 peregruzok int int double double int double etc
	//poetomu mi i delaem yavnoe privedenie pervogo argumenta k tipu double
	return sqrt(pow(static_cast<double>(a.GetX() - b.GetX()), 2)
		      + pow(static_cast<double>(a.GetY() - b.GetY()), 2) //kovo v double v  kruglih skobkah poetomu 2 para skobok
			   );  //@@@@@@@@@@ esli v header GetX() GetY() zakinut v private to eta func perestanet compile(tak kak private 4leni classa a eta func global)
}

//----- bolee effectivnaya pered4a argumentov po silke malo li vdrug profil krila peredavat budem 4tob ne kopirovat
//tak nado peredavat bolshie i slozhnie objekti funcii(v C eto bil ukazatel a v C++ silka)

double silkaDist(const Point &a, const Point &b) //kogda mi peredaem silku na kakoito object mi predostavlyaem ei pryamoi dostup k originalu
{//, a vdrug ee zaglu4it zna4it i isportit original kak i ukazatel, zna4it dobavlyaem "const" dlya bezopasnosti 
// kak dobavili const 4 oshibki, compilator vizivaet GetX GetY Print a vdrug ona menyaet a i b on ne znaet nado etu funciyu tozhe zdelat const v headere!!!!
// eto potomu 4to Pint.h include a v nem on videt tela tolko inline metodov i ne veidet tela kotoroe v Point.cpp a zna4it const ne mozhet garantirovat(delaem ih const v headere)
// @@ poetomu vse metodi klasa delyatsa na 2 vida - modificiruyushie object i (ne modificiruyushie(inspektori) object oni const) 
// po sravneniyu s gDist eta funciya bolee bistraya i bolee bezopasnaya !!!!!! pereda4a po constantnoi silke zabota dlya unmodificated objects

	// a i b eto psevdonimi dlya(a i *p kotorie mi peredadim pri vizove) cout<<"="<<silkaDist(a, *p)<<endl;
	//toest dlya a i *p objecta
	return sqrt(pow(static_cast<double>(a.GetX() - b.GetX()), 2)
		+ pow(static_cast<double>(a.GetY() - b.GetY()), 2) //kovo v double v  kruglih skobkah poetomu 2 para skobok
	);
	//@@@ dlya togo 4tob polu4at dannie etogo klasa eta funciya dolzhna obrashatsa k aksesoram(GetX, GetY)no esli ya GetX() i GetY() v headere zakinu v private ane public kak shas, eta funciya srazu
	//perestanet kompilorovatsa takim obrazom razrabot4ik klassa mozhet predostavlyat raznie vozmozhnosti raboti s objectami ubral metodi s4itivaniya 
	//konkretnih koordinat, client code mozhet ih uznat no tolko raspe4atav naprimer se4as pryamovo dostupa net no ya mog bi napisat druguyu func kotoruyu bi client mog use a mog bi i ne delat
	//togda client izmenat object mog bi no uznavat ego sostoyanie ne mog bi(tolkat 4enij yashik v temnote a gde on hz)ne nabludaemui object) a esli zakinut metodi SetX SetY v private togda
	//client mozhet nabludat no ne mozhet menyat(read only object) takim obrazom raspologaya v public ili private metodi mozhno upravlyat povedeniem usera
	
	//------------------------- FRIEND KAK I DLYA 4EGO -------------------------
	//@@@@ esli GetX() GetY() bili bi v private ili ih voobshe ne sozdal bi nikto rozrabot4ik klassa mog bi predostavit osobie prava dostupa k zakritim komponentam klassa @@@@@
	//klass mozhet objavit druguyu func svobodnuyu naprimer kak gDist ili func 4len klassa drugovo ili celui klass drugom(friend) a druzhba b C++ eto samaya silnaya stepen svyazi
	//drug ne budu4i 4lenom klassa imeet dostup ko vsem private i public komponentam na pravah druzhbi kak na 4ukotki drug priehal sani?- ponravilis beri sani ruzhe?- drugu - vse :)
	//func drug ne mozhet bit v headere tam ne mozhet bit realizacii + mnogoratno mozhet dublirovatsa esli eto tolko ne inline, ee nado realize v Point.cpp file realizacii
	//delayu fDist s silkaDist
}


int main()
{
	//INTERFACE CLASSA DOLGEN BUT MINIMALNUI NO DOSTATOCHNIM
	//(ne 100 nethodov no 4tob s hih vse mogno bilo slepit vse neobhodimoe)
		
	//INCAPSULATION eto dopisivanie/peredelivanie Point.cpp/.h 
	//i v eto vremya v UsePoint.cpp client mojet pisat svoi kod hot i metod uge peredelan na bolee bistrij
	
	//instanciirovanie ekzemplyara classa (sushnost korotko zovut object)
	//======================================== MEZHDU sozdaniem objecta =========================
	static Point sl;  //eshe odin STATIC
	Point a,b; // SOZDANIE OBJECTA (AUTOMATICHESKOI MEM TOEST V STACKE) i zna4it 4to pamyat automati4eski osvobo-
			 // ditsa compilatorom kogda zakon4itsa block (v dannom slu4ae block main :)) STACK vutolknen object posle konca blocka
	
	cout << a.GetX() << ", " << a.GetY() << endl; //===== kogda object v neopredelennom sostoyanii
	int z = a.GetX();

	a.SetX(10);  //===================== I ego inicializaciei est DIRA, a esli ya ne sdelav Set 
	a.SetY(20);  //vizovu Move(), ili SetX sdelal a SetY ne sdelal pol objecta pravilnaya vtoraya musor i dlashe Move
		//------- DLYA LIKVIDACII ETOI DIRI I BULI PRIDUMANI CONSTRUCTORS(SPECIALNIE METODI CLASSA), NO ETO SLED LESSON @@@@ !! ! ! !
	//===========================================================================================
	cout << a.GetX() << ", " << a.GetY() << endl;


	a.Move(5, 10);
	a.Print(); cout << endl;

	Point *p = new Point; //NELZA ZABIVAT ON SAM SEBYA NE UDALIT KAK V AUTO MEM,  UTECHKA PAMYATI ! ! ! !
						  // SOZDANIE OBJECTA V DYNAMIC MEM/KUCHE/HEAPE (NO! v predostavlenii DYNAM MEM buvaut i otkazi)
						  //togda new vozbuzhdaet isklu4enie ili mogno ego poprosit vernut null ptr
    //@@@ !!!zdes dolgna bit obrabotka oshibok pri videlenii pamyuati	 
	
	p->SetX(65);   // stavim p-> i smotrim 4to dostupno 4erez ukazatel
	p->SetY(70);   // a delot to mogno vse 4to mogna dleat s objectom classa
	p->Print(); cout << endl; // 4tob ne prikleevalos
	// ITOGO SOZDANO 5 OBJECTOV POINT ( u kagdogo svoi fields x,y)
	//@@ !!! A KAK PONYAT p->Print(); kakovo iZ 5ti objectov x y raspe4ataet???@ @
	// NA SAMOM DELE U VSEH METODOV CLASSA +1 ARG (u Print 0 zna4it 1 skritij argument)
	// Tak kak *p sodanniy OBJECT v dynam mem to v p->Print() tayno peredaet address p
		// a.Print();  address a etc 
	

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

//======================== ITOG ================================
/*
	CLASS eto mehanizm(predostavlyaet) incapsulacii.
	4ASHE VSEGO ESLI V PUBLIC FUNCIYAH KOD DUBLIRUETSA EGO POMESHAYUT V PRIVATE FUNC
		I VIZIVAUT ETU PRIVATE FUNC VNUTRI PUBLIC FUNCS NARIMER CORRECTNUI LI VVOD COORDINAT BIL
		,SOKRASHENIE DROBEI SDELAT PRIVATE FUNC dlya unutrennego upotrebleniya etc.
	
	inline 4to pod kapotom - return sqrt(pow(static_cast<double>(a.GetX() - b.GetX()), 2) 
		GetX() inline metod i kompilyator a ne(preprocessor) prosto vstavit a.x - b.x vmesto vizova etih funcij v etom meste v moment compilyacii
		esli inline func private zna4it ee svoi mogut vizivat a 4uzhie net

	Esli sozdat 1 milion objectov classa to polei dannih budet milion a nabor funcij tolko odin(4erez this rabotaet zhe) vse v kodovom segmente

	OBJECT eto oblast pamyati kotoraya sootvetstvuyushim obrazom inicializirovana v C# gibrid u nego silo4naya model pamyati i
		na steke taino lezhat ssilki, sna4ala mi opisivaem a potom pri pomozhi new sozdaem object, a opisali to zha4em a eto ta tainaya ssilka
		kotoraya na steke lezhit. V C# gibrit v nem vse v heap(ku4e lezhit) no dlya uskoreniya nekotorie prostie tipi mozhem raspologat v steke
		, a v JAVA vse v ku4e i tolko v nei ili primitivi tozhe na steke -> viu4im JAVA))))

	^^^^^^^ ITAK esli sozdali mnogo objektov to budet mnogo oblastei pamyati x y, a funciya odna i blagodarya skritomu this a v python yavnomuy .self
			dlya kontkretnogo obekta peredadutsa pravinie x y v etu edinuyu dlya vseh funciyu

	INCAPSULYACIYA nam nuzhna dlya togo 4tob nalozhit lapu na popolznaveniya clienta i strogo kontolirovat
			(pri neobhodimosti ina4e v private ne pihat) te manipulyacii kotorie on ho4et delat s nashimi objectami
			v itoge on mozhet delat tolko to shto predusmotreno v interfeace(headere publica) classa ili compiniruya
			public methodi classa hitrim obrazom, a nasha zada4a vnutri etih metodov realizovat kontrol 4tob client ne 
			mog privesti object v nekorektnoe(invalidnoe) sostoyanie, ponyatno 4to eto kosaetsa metodov modificatorov 
			kotorie menyaut sostoyanie objecta. !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! y = _y >= 0 ? _y : 0;   radi etogo i sdelana incapsulyaciya
			i kontroliruem peremennie eshe t4atelnee ukazateli, i delaem metodi tak 4tob ne pozvolit vuiti za predeli amin brat :))  
			i togda objecti na protyazhenii vsei svoei zhizni budut pravelnimi(ne ispor4enimi).
	  A 4TOB ESHE I ROZHDALIS OBJECTI V CORRECTNOM SOSTOYANII SLED LESSON CONSTRUCTORI - SPECIALNIE METODI CLASSA (esli ya SetX sdelal a SetY zabil)	
*/
