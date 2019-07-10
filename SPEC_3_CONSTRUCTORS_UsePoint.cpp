#include <iostream>
#include "Point.h"
//=================== SPECIALNIE METODI CLASSA =====================
//constr osobaya func ni4e ne return, imya sam ne vuberish, vizivaetda tolko compilyatorom a ne programistom
using namespace std;
//vazhneishee nazna4enie constructora eto mehanizm inicializacii sozdavaemih objectov !!!
//otsuda v C++ i razresheno pisat v peremeshku operatori opisaniya peremennih i ih ispolzovaniya 4tob
//sozdavat peremennie srazi ih inicializiruya pravelnim zna4eniem TYT CONSTRUCTOR I V POMOSH. objects ne dolzhni boltatsa v proizvolnom sostoyanii

Point test(Point q)
{
	return q;
}

Point &test1(Point &q)
{
	return q;
}

const Point &test2(const Point &q)
{
	return q;
}


int main()
{
	//@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@### 
	//KSTATE posle constr copy so spiskom inicializacii mehanizma ponyatno 4to budet korectnaya zapis i takaya
	int aa(111); //vmesto int aa = 111; VSE ROVNO COMPILITSA vstroennie tipi use tot zhe mehanizm(contr classa raspostranyaetsa i na vstroennie tipi)
	int bb(aa); // vmesto int bb = aa; I TOZHE COMPILE VSE OK
	int *qq = new int(100); //imenno tak pisat poshlo iz mehanizma classa ved on primenim kovsemu vstroennomu
	//Point *p1 = new Point(111); pravda odin i tot zhe mehanizm i forma zapisi na litso :)))))
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	Point y,z; //sozdal object pustogo classa(file realizacii Point.cpp poka pustoi) a v Point.h class Point {};			        
	cout << sizeof y << endl; //object pustogo classa zanimaet rovno 1byte potomu kak eto minimalnui objem kotorui mozhno adresovat
	     //tem bolee esli bi 0 byte bilo to Point y,z; v steke legli na odnom adresse, a esli bi object pustogo classa bil 4astyu  drugogo
	     //classa to zanimat 1byte emu ne obyazatelno

	Point a,b[5]; //programmist ne mozhet vizvat constructor ego vizivaet compilator!!!!
	//v OOP kazhdui raz kogda sozdaetsa object lubim sposobom na steke, stati4eski, v dynam mem, kak 4ast ddrugogo classa bazovui ili komponentnui
	//compilator obyazan dlya nego vizvat constructor, etot vizov nevozmozhno objehat, compi napishet hot pustoi constructor;
	
	//----- proverim vizov constructora copirovaniya
	Point c = a; //sozdali c i kopiruem tuda vse s objecta a; //posle kopirovaniya budet vizvan destructor
	
	test(a); //2 raza potomu 4to pervui kopiruem iz a v test a vtoroi return vozvrashaet object i togo 2 vizova constructora copy
	//esli mi rukami constr copy ne napisali compilyator eto vse ravno delaet
	//compilyator pishet constr copy ibo classi razvitie structur a struct mozhna odinakovie prisvaivat drug drugu ili peredavat po zna4eniyu struct perem v funciyu togda ona copy
	//pod kovrom, constr by def pishet compi ibo struct peremenuyu mozhna sozdat i srazu inicializirovat v {} zna4eniyami.
	//@@@@ + esli perem polya classa yavlyaetsa type ne int a object drugovo classa  to pri kopirovanii objecta v object budet vizvan konstructor copy i pervogo objecta i nashego itogovogo
	// a pobitovoe copirovanie ne porozhdaet vizov constructora + mogut bit raznie viravnivaniya vlevo a na drugoi platforme vpravo.	
	// destructor osvobozhdaet resurs udaliv object naprimer socket, soedinenie s bazoi dannih etc.
	//-----------------------------------------------

	// Peregruzhenui by def constructor
	Point d(100, 200); // sposob pervui
	Point d1 = Point(101, 201); // sposob vtoroi
	//kstate destructori vizivautsa dlya auto objectov v obratnom poryadke vizovu constructorov ved dostavat iz steka nado naoborot 4em lozhit :))

	Point e(10); // govorim 4to hotim s odnim argumentov (tipa sdelat iz odnogo int Point kstate o4en tvor4eski mozhno kombinirovat convertaciyu tipov)
	Point e1 = Point(11); //ekvivalentnaya forma 
	Point e2 = 12; // no tut est i tretiya forma zapisi kogda argument 1 

	//v kakom poryadke new pishu v takom i sozdautsa objecti constructorom
	Point *p = new Point; //sozdadim obj v dynam mem tut budet vizivatsa constructor by default
	Point *p1 = new Point(111); //tak delaetsa dlya vizova constructora s odnim param
	Point *p2 = new Point(111, 222); // tak dlya dvuh 4tob polnui constructor vizivalsa

	//@@@@!!! nu i kone4no zhe ne zabivaem
	delete p2; //@@@!! v kakom poryadke delete pishu v takom destructori i vizivautsa dlya objectov
	delete p1; 
	delete p;  //esli net osoboi strategii poryadka udaleniya objectov to postavim ih v takom zhe poryadke kak iz steka udalyautsa

	//================= 4TO LU4SHE 3 CONSTRUCTORA ILI 1 3 V ODNOM FLACONE? ======
	/*
	    GIBKOST CONTROLYA
		LU4SHE 3 OTDELNIH TAK KAK NAPRIMER ZAKINUV KOSTRUCTOR BY DEFAULT V PRIVATE POLE Point.h
		YA ZAPRESHU SOZDAVAT OBJECTI PO UMOL4ANIYU(TOEST BEZ ARGUMENTOV NELZA SOZDAVAT OBJ)
		ILI NELZA POLZOVATELYU SOZDAVAT S ODNIM TOLKO ESLI ZAKINU V PRIVATE CONSTR PREOBRAZOVANIYA
	
	    !!!! ESLI SOZDAEM V DYNAM MEM MASSIV OBJECTOV TO KAZHDUI IZ ETIH ELEMENTOV 
	    INICIALIZIRUETSA CONSTRUCTOROM BY DEFAULT I TOLKO IM !!!!!
		a zna4it esli zakinut ego v private client ne smozhet sozdavat massivi obj v dynam mem, otdelnuie obj da, arrays net :)))
	    NO V STEKE MASSIVI OBJECTOV SOZDAVAT MOZHNA NO INIT IH 4ASTI4NO NELZA ILI VSEH ILI NIKOGO Point arr[4] = { 1, 2, 3, 4 }; MOZHNA  
		Point arr[4] = { 1, 2,} NELZA, A NE BIL BI V PRIVATE ZAPOLNIL BI TRETIJ I 4ETVERTUI ELEMENT NULYAMI
	*/

	//Point arr[4]; //tut vizovetsa constr by def i zapolnit lulyami hot on i private ibo eto stek detka
	Point arr[4] = { 1, 2, 3 }; //a tut vizovetsa uzhe constr preobrazovaniya i nabor 4isel preobrazuet v nabot objectov tipa Point
	                            //@@@@@ iz 4etureh pervih tri init zna4eniem ostalnue komu nedostalos nulyami(eto 4etvertui element)@@@@@@@@
	                                    // eto kapec kak logi4no 
	
	// POPROBUEM PROINITIT ARR OBJECT POINTS dvumya parametrami a ne odnim a vtoroi 0 
	Point arr1[4] = { Point(1,2), Point(3), 4 }; //budet 1,2; 3,0; 4,0; 0,0; zapisano

	test(c); //sozdastsa 2 objecta putem kopirovaniya ibo pereda4a po zna4eniu 1 obj sozdalsa constriktorom copirovaniya + return vtoroi object vtoroi constr copy  
	          // eto esli c uzhe bilo sozdano a tak bi bilo 3 :)
	//--------- TAK PRAVILNEE I LUTSHE ----
	test1(c); //teper netu nikakovo kopirovaniya tak kak pereda4a po silke !!!!! lishnih 2 deistviya ubrali
			  //otsuda vidno 4to objecti osovenno bolshie ne vigodno peredavat po zna4eniyu a tolko po silke nado
	//@@@@ imenno poetomu kogda proger pishet v func argument silka to odno iz dvuh 1)libo on ho4et 4tob func polu4ila dostup k vneshnemu objectu
	//@@@@ i mogla ego menyat 2)libo on zabotitsa ob efectivnosti bolee bistroi pereda4i a menyat ne ho4et no silka nado, kak otli4it test2 pokazhet
	
	test2(c); //vot eto yavno pokazivaet 4to mi silku sdelali dlya efectivnoi pereda4i a ne varian 1)
	
	//----------------------------- proverka na soobrazitelnost ---------------------
	/* @@@@ kstate u classa Point private polya tipa int vot i constr preobrazovaniya na int delali rashitannim(int v Point)
	test1(777); kompilirovatsa ne budet no esli dobavit v etu fucn const kak v test2 to compile budet
				  sozdastsa object Point(777,0) i posle otrabotki funcii udalitsa
	 a vot test(777); compilirovatsa budet Point(777,0) po zna4eniyu takaya je analogiya kak s const silkami no tolko + 2 cosntructora copirovniya
	 ETOT KOD(777) VIPOLNYALSA I COMPILILSYA POTOMU 4TO EST KONSTRUCTOR PREOBRAZOVANIYA KOTORUI POZVOLYAET IZ INT SDELAT POINT!!!
	 ETI PREOBRAZOVANIYA V CONSTRUCTORE(PREOBRAZOVANIYA) I U4ASTVUYUT V NEYAVNIH PRIVEDENIYAH TIPOV COMPILYATOROM I COMPI VIZIVAET
	 ETOT COSTRUCTOR NEYAVNO 4TOBI SOZDAT OBJECT(777,0) PRI4EM V SLU4AE PEREDA4I PO ZNA4eNIYU test(777) COMPI VIZOVET TOLKO ODIN 
	 CONSTRUCTOR COPIROVANIYA KOTORUI NA MESTE RETURN, A KOPIROVAT V FUNC ON NE BUDET ON UMNUI OPTIMIZIRUET I SOZDAST OBJECT 777,0 
	 SRAZU V TOM MESTE V STEKE FUNCII KUDA DOLZHEN BIL SKOPIROVAT VIZVAV PERVUI CONSTRUCTOR KOPIROVANIYA !!!!!@@@
	
	test(77.7); scompilitsa no vidast preduprezhdenie 4to iz double v int mozhet privesti k potere dannih rezultat sozdast object(77,0)
	            tut dva neyavnih preobrazovaniya sna4ala iz double v int a potom iz int v Point (compi dumal v obratnom poryadke kak polu4it Point?
				- mozhno polu4it iz int, 77.7 eto ne int eto double no est arifmetic preobrazovanoe double v int pravda s poterei to4nosti nu i dal warning
	@@@@@IZ CONSTRUCTOROV PREOBRAZOVANIYA(esli ih mnogo tam v int, v double etc) ESLI VOZNIKAET TSEPO4KA PREOBRAZOVANIJ ISPOLZUETSA TOLKO ODIN, IH NELZA VIZIVAT TSEPO4KOI !!!!!!!!!!!!!!

	test('7'); COMPILIRUETSA RESULTAT (55,0) VED 55 ETO KOD CIFRI 7
	test("7"); ERROR COMPILYACII IBO NET CONSRUCTORA COTORUI POLU4AET MASSIV A VUDAET POINT(NAPISHEM BUDET :))
	
	                //------- EXPLICIT 
	@@@ eto zhe ploho 4to v Point mogut prevrashatsa chari dobule i tak dalee test('#') krasivij Point? :)) no ved compilitsa i rabotaet
	    eto mozhno ispravit, constructor preobrazovaniya compi vizivaet kak kandidata v neyavnih preobrazovaniyah 4tob udovletvorit funciyu
		!!!! v Point.h pered contructorom preobrazovaniya pishem explicit(yavnui) explicit Point(int); i teper etot constructor razreshaetsa
		tolko yavno vizivat i teper test(777), test(77.7), test('7') stali ERRORS !!!!!! a esli hotim vse zhe preobrazovat pishem yavno
		vot tak test(Point(777)); a (77.7) i ('7') kak ti yavno preobrazuesh?- nikak i code stal BOLEE NADEZHNUI ETO LOGI4NO 4TOB takih pointov nebilo
	@@@
	stanovitsa ponyatno 4to v C++ v dopolnenie k obi4nomu operatoru privideniya tipov yazika C sushestvuet i funcionalnaya forma privedeniya tipov
	test(Point(777)); test(int(777); imya tipa i v()4to prevesti eto funcionalnaya forma privedeniya StrouStup tak pridumal 4tob v classe mozhno bilo
	privodit k vstroennim tipam; test((Point)777); mozhno i tak eto C style privedeniya tipa i vse ok compilit.
			((Point)777); C forma kogda tip v skobkah potom zna4enie (double)56; vudet 56.0
			(Point(777)); FUNCIONALNAYA FORMA VITEKAET S CLASSOV C++
		    HOTYA PO POLNIM PRAVILAM MOZHNO test(static_cast<Point>(777)); no pe4atat dolgo i ne silno 4itaemo
	*/
	//-------------------------------------------------------------------------------
	//===================== TEPER POSLE DOBAVLENIYA EXPLICIT v Point.h ERRORS ======
	// Point e(10); vse ok ono yavnoe  Point e1 = Point(11); eto tozhe
	// vot tut Point e2 = 12; i tut Point arr[4] = { 1, 2, 3 };  ERRORS CONSTR COPY VIZIVAETSA NEYAVNO A NAYAVNO MI ZAPRETILI
	// Point arr1[4] = { Point(1,2), Point(3), 4 }; i 4 tozhe ERROR ono neyavno v Point convert
	//========================= UBEREM POKA EXPLICIT s headera(zakomentim) =========
	
	//@@@###=========== I NAKONEC  4 SLU4AYA KOGDA KONSTRUCTOR MOZHNA INICIALIZIROVAT TOLKO SPISKOM(A NE POLYAMI other) ================
	/*			----- VARIANTI KOGDA SPISKOM MOZHNA A BEZ SPISKA INICIALIZACII NET ------
		1) NAPRIMER ESLI DLYA POLZOVATELSKOGO TIPA NET CONSTRUCTORA BY DEFAUL(kto zhe togda sozdast objecti v constr copy :) )
		
		2) primer na vstroennom tipe esli  (const int a =10; inicializaciya) eto korrektno a vot (const int a; a = 10; prisvaivanie) uzhe ERROR ibo init mozhno kolko
		   v srazu v moment sozdaniya a potom uzhe sled instrukciei nikak
		   TOEST ESLI 4LEN CLASSA OPISAN KAK CONST TO EDINSTVENNIJ SPOSOB PRISVOIT EMU ZNA4eNIE ETO V MOMENT SOZDANIYA
		   I TOLKO INICIALIZACIYA A NE PRISVAIVANIE... (: x(other.x), y(other.y) - inicializaciya)  (x = other.x; - prisvaivanie)
		Inicializaciya sozdaet object s nuzhnim zna4eniem, Prisvaivanie zamenyaet tekushee zna4enie na drugoe dazje esli sozdali s musorom...
		
		3) int b; int &a = b; CORRECT,   int &a; a = b; ERROR tak kak silka dolzhna bit srazu inicializirovana
		   POETOMU ESLI V CLASSE SILKA ETO POLE NA TO EE MOZHNA INICIALIZIROVAT TOLKO V CONSTRUCTORE I TOLKO V SPISKE INICIALIZACII
		
		4) ETO UZHE NAPERED u classa est bazovie classi to inicializirovat bazovij class v moment sozdaniya mozhna tolko spiskom inicializacii
		   vizvat constructor bazovih classov mozhno tolko ispolzovav spisok inicializacii
	*/
	//@@@###========================================================================================================

	//%%%%%%%%%%%%%%%% VAZHNO KONEC ITOG -> compilyator deistvitelno generiruet constructor by default %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	//%%%%%%%%%%%%%%%% esli programmist sam ne sozdal v classe nikakogo constructora, no object to sozdavat nado
	//%%%%%%%%%%%%%%%% vot togda compilyator napishet code, no esli programmist sobralsa sam rulit' sozdaniem objectov,
	//%%%%%%%%%%%%%%%% i skazal ya ih budu sozdavat s odnim argumentom s dvumya argumentami - vse compilyator umivaet ruki 
	//%%%%%%%%%%%%%%%% i govorit ah ti sam rulish nu togda sam reshai nuzhen tebe constructor by default ili net, no ya tebe ego 
    //%%%%%%%%%%%%%%%% delat bolshe ne budu i ne sozdast :))) %%% esli hot 1 constructor suschestvuet to compilyator imivaet ruki %%%%
	//@@@@@ ESLI OBJECTI SOZDAYUTSA KAK 4AST DRUGOGO CLASSA TO IH CONSTRUCTORI VSERAVNO VIZIVAUTSA @@@@@

	//&&&&&&&&&&&& OBJECT PUSTOGO CLASSA VSEGDA ZANIMAET 1BYTE 4TOB Point a,b; NE LEGLI NA ODNOM ADDRESE V STEKE KAK ESLI BI BILI PO 0 BYTE !!!!
	//             ,a esli v objecte est pole int x, sozdastsa object 4 byte,  int x,y; 8Byte etc i object uzhe ne pustoi pust i v x,y musor;

	//!!!!!!!!! a ot destructorov polza bivaet ubedimsya v sleduyushem CLASSE STRING !!!!!!!!!!!!!
	
	//DOM ZADANIE V PROSHLOM CLASSE POIN DOBAVIT VSE NUZHNIE CONSTRUCTORI
	//		SOEDINIT UROK 2 i etot 3 v ponocenniy safety class Point
	//      I ESLI SOZDADIM CLASS LINE IZ DVUH OBJECTOV POINT TO HOT ONI I 4ASTI
	//      DRUGOVO CLASSA NO PRI SOZDANII OBJECTA LINE CONSTRUCTORI DVUH POINTOV VIZIVATSA BUDUT !!!!!!!!!!

	system("Pause");
}
