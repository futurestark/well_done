//------ headers without .h are standart  with .h user created
#include <iostream>  
#include <cstdlib> // (c)headers from standart lib C language with .h user created for example from my c project <cgimbal.h>
				   // bez .h takie kak <cstdlib> eto unasledovanie standartnie iz C no podognanie pod C++ standart
#include <clocale> // for rus cout
#include <Windows.h> 

//include vklu4aet prototips, structs, enums no ne bibliote4nui kod ego delaet linker ili zagruz4ik
//theme  Servise -> Parameters -> general blue...

using namespace std;  //vmesto inf23_write_buf(); naimenovanij funcij
// ili esli 4asto use funcii vna4ale faila ih prostranstvo uto4nili i ispolzuem dalshe bez std::
using std::cout; 
using std::endl;

double a = 123.3; //dlya proverki novogo operatora :: unarnogo vida primeneniya kak dostup k global space variable
 
int main() {
	setlocale(LC_CTYPE, "rus"); //"Russian" work to
	cout << "Привет";
	// >> operator izvle4enie iz potoka, << vstavka v potok
	int a = 5.5;
	int b = 2.5;
	cout << "a==b is"  //vstavka v cout srazu vurageniya - pravda li 4to a == b (pe4ataet 0 ili 1) skobki iza prioriteta
		 << (a == b) << endl;
	
	cout << "Half of b:" << b / 2 << endl; // udobno proveryat vivodya v kakuyu storonu okruglyaet !!!
	cout << "Half of a:" << a / 2 << endl << "Casting:" << (double)a/2 << '\t'; //prividenie tipa kak v C
											          //<<double(a)/2 <<endl  funcionalnui vid v CPP iz C

	const int n = 10; //vmesto #define v C kotorui tipi ne proveryaet napishem #define n 1.5 i 4e za razmer massiva?
	int arr[n]; // sushestvuet do konza bloka tut do konca funcii main() !!

	// v CPP peremennue mogna sozdavat v pryamo v tom meste gde oni ponadobilis dage vnutri while( int a != c) etc
	for (int i = 0; i < n; ++i) {
		arr[i] = rand() % 100;  // i vidno i sushestvuet v zagolovke for i ego tele !! 
								// esli nado do koca funkcii main to sozdat i pered for() strokoi vishe
	}	
		
	bool t = false; // novij tip dannih - logi4eskij so zna4eniem true/false
					// int f(int,int);
				    //bool f(int,int); //delaut odno i toge no s bool ponyatnee nazna4enie funcii i dlya peregruzki udobno
					//bool f(int,bool); vnutri func bool kak arg govorit 4to on 4to-to vklu4aet ili vuklu4aet
		//no po prejnemu za true stoit 1 za false 0 i mogno 5 + true i budet 6 i vse korrectno !!!!!!!!!!!!!

		//------------- novoe v neyavnih preobrazovaniyah ukazatelei
		const int* cp = &n; //ukazatel(ReadOnly) na kostantnui object adresuet konstantu (n u nas const vishe po tekstu)
				   cp = &a; //teper na nekonstantnui object no eto bezopastno  (cp govorit var a 4itat budu a pisat ne budu)
		// ++*cp; //error ibo ukazatel const a zna4it read only 4to var a 4to var n
		int * p = &a;
		++*p; // uveli4it na +1 zna4enie var a
		cp = p; // object na kotoui pokazivaet p mogno i pisat i 4itat, cp tolko 4itat poetomu on p ne isportit tak mogno !!
		//p = cp; // error tut naoborot poetomu isportit a ++*p privedet k nepredskazuemum posledstviyam(popitka izmenit konstantu)
		p = (int*)cp; //yavno privesti p=cp vukrutit kompilyatoru ruki no tolko esli uveren 4to object cp 4erez p ne poportitsa

		void * vp = p; //ukazatel na void eto ukazatel na luboi tip dannih(amnezia adress pomnit a tip po addressu net) !))
		//bezopastno ukazatelu void pristaivat ukazatel lubovo tipa ved vp ne smoget ego razimenovat i poportit zna4enie, 
		// sdelat ukazatelu vp ++ ili -- ved eto shagnut na skolko-to byte a na skolko ne ponyatno ved void
		//on moget tolkto hranit 4eito address no on ne znaet 4ei(type) (samui bezobidnui ukazatel)
	//p = vp; // v C etot kod kompile a v CPP net i eto logi4no 4to v CPP nelza  
		p = (int*)vp; //esli mu uvereni 4to vp hranit adress int a vishe po kodu posmotreli da, to yavno privodim type
				      //nasilno vykrutiv kompilyatoru ruki a neyavoe prividenie kak v C kompi ne sdelaet vp k p
		// in C functions malloc calloc realloc returns pointer void* poetomu v C mogno p = skolko-to bytes a v CPP nelza !

		vp = 0; // v CPP dlya ukazatelei = 0 toje samoe 4to = NULL prosto ono neyavno podstavitsa(nulevoi ukazatel)
				// potomu 4to NULL na raznih platformah raznij 4erez #define a use #define v cpp ploho poetomu
				// = 0 vsegda v CPP preobrazuetsa v pravelnui NULL dlya toi platformu na kotoroi shas compile !!!

		//======================= NEW TYPE SSILKA (psevdonim dlya objecta) =======================================
		int & r = a; // sozdavaya var ssilo4nogo tipa ee kak const srazu nado initialize pri4em tovoge type 4to i object(a)
					 //compi teper s4itaet 4to ya4ejka pamyati a polu4ila psevdonim r (vse operacii 4to mogna 
					 // delat s a mogno delat i s r (operacii nad r zavisyat ot type a)
		cout << "a=" << a << ", r=" << r << endl;
		cout << "&a=" << &a << ",&r=" << &r << endl; // vu4islyatu address a i address r ponyatno oni odinakovie
		r = b;     //eto ne v r zapisalos b, eto ekvivalentno a = b; !!
		cout << "a=" << a << ",r=" << r << endl; //ssilka obi4no realizuetsa kompilyatorami pri pomoshi 
			// samo razadresuemogo ukazatelya predstavlyaem 4to kompi sam stavit * pered r poetomu nam stavit ne nado
			// no lutshe predstavlyat 4to r eto prosto votroe imya a menshe logic errors budet (1.30min shema pod kapotom)
		const int & cr = a; //cr eto a read only (tak v lob ssilki kak i ukazateli nikto ne use)kak use dalshe

  // const int * const r   pervui const nelza menyat soderjimoe obj a vtoroi nelza nastroit na drugoi addr kak u ssilok
		//osnovnoe primenenie ssilok eto kak argumentu u funccij( dve situacii)
	 // 1) 4tob func 4erez args svoi mogla vozdeistvovat na vizivaushij ee kod 
	 // 2) pereda4a po ssilke bolshih objects 4tob ne kopirovat ego v func a prosto taino peredat ego address(ssilku)
   
		/*
		void swap1(int a, int b) //pereda4a args po zna4eniyu C variant vse args copy, kopii perestavlyaet mestami
		{				// no originali kak bili ne pomenyani tak i ostalis a po ssilke kak v slu4ae ukazatelya in C
			int t = a; a = b; b = t; 
		}
		swap1(a,c)  //vizov @@@@@@@

		void swap2(int*x, int*y)
		{
			int t = *x; *x = *y; *y = t;  // variat 4isto C swap 4erez ukazatel
		}
		swap2(&a, &c) //vizov ne sovsem udobnij kak i mnogo * vnutri tela @@@@@@@@

		void swap3(int & a, int & b) 
		{
			int t = a; a = b; b = t;  // zapis kak swap1 tolko kakbudto swap2 nastavili ku4u * vezde (pe4atat kuda proshe)								
		}							  // a smisl ne na gram ne pomenyalsa
		swap3(a,c) //vizov takoi je kak swap1 tolko uge ne kopii a realno a i c pomenyautsa mestami @@@@@@@@

		//vo vremya vizova swap3 sozdalos 2 args link tipa i srazu nastroilis na address a i c 
		//teper kogda pishem a = b on sam * dobavlyaet i pravit original a eshe compi sozdav ssilki s tipami int
		//mu nikak uge ne mogem pereputat tipi i on proverit a s ukazatelyami nakosya4it mogo s types za neh delat @@@@@@
		*/
		 
		//ssilka moget bit i vozvrashaushim zna4eniem funcii  int & max(int&, int&);
		// cout << "max=" << max(a,c) << endl;  vernet ssulku na bolshee iz a i c 
		// po kli4kam opredelit kto bolshee iz jivih originalov kogda func zakon4itsa vernet kli4ku na tot jivoi kotorui bolshe
		//@@@@@@@@@@@ poetomu nelza return ssilki na localnue args @@@@@@@@@@@@@@@@

		//ssilka moget bit i Lvalue ot prisvaivaniya, vot v C++ takoi code vozmozhen esli vozvrashaemoe zna4enie ssilka @@@@
		// max(a,c) = 0; // naidi maximalnogo obj iz a i c i ubey ego nulyom(toest ssilka na max obj iz a i c zamenyaetsa nulyem) 
		// ++max(a,c);  //naidi max iz a i c i sdelai ego zna4eniyu ++

		//Lvalue sleva = eto addresuushie virazhenie kotoroe v itoge(posle vizova funcii) ili srazu(peremennaya) 
		//daet nam address kuda mi hotim zanesti zna4enie i ssilka kak Lvalue 4etvertui ego vid v C mi znali 3 vida
		//ukazatel, ptosto peremennaya i pohodu massiv ili structura da i function mozhet bit kotoraya potom po 
		//ukazatelyu vnutri sebya zapishet v pamyat
		/*
		int & max(int & a, int & b)  // telo func max :D
		{
			return a > b ? a : b; //esli a > b vernem a ina4e b, tak kak a i b ssilki to vozvrashaemoe zna4enie tozhe ssilka
		}
		*/
		//@@@@ SSILKA BILA PRIDUMANA V C++ DLYA CLASSOV NO OKAZALOS 4TO KLEVA EE USE NE TOLKO S NIMI A I PROSTO KAK TUT
		//	   A GLAVNOE POVISHAT BEZOPASNOST CODA 
		//@@@@@@@@@@ nelza sozdat ssilku na ssilku ili ukazatel na ssilku a ssilku na ukazatel mogna
		//@@@@@@@@@@ nelza sozdat massiv ssilok i nulevuyu ssilku(ssilku vnikuda ved dolzhen bit ee init)
		//@@@@@@@@@@ Esli ssilka const to ona mozhet inicializirovatsa addresom vremennogo objecta esli tipi ne sovpadayut
		//           eto kogda mi 4erez ssilku 4itaem mi zhe mozhem double pro4itat kak int, vnutri sozdat vremennui
		//			 int i vernut kak ssilku na int 4tob pro4itat
		//@@@@@@@@@@ A esli ssilka ne na constantu to types dolzhni sovpadat togo 4ei address v nee kladesh(eto kogda mi 4erez ssilku pishem)
		//@@@ CLASSIKI SAY VEZDE I VO VSEH VNESHNIH INTERFACEx megdu modulyami nado use ssilki a ukazateli tolko gdeto gluboko vnutri private metodov
		//@@@@@@@@@@@@@ vnutri 4tob oni ni4e ne isportili i 4erez nih nikto ne smog isportit zabiv gdeto * postavit@@@@@@ !!
	 //---------------------------------------------- SSILKA THE END -------------------------------------------------

	//---------------------------------------- NEW OPERATORS -----------------------------------------------------
    //---------- obrashenie k global namespace iz local
	//	::  unanij/binarnui - dostup k globalnomu kontekstu, a bivaet on zhe eshe i binarnui kak v slu4ae std::cout 
	//               sleva imya prostranstva, sprava imya iz etogo prostranstva i eshe o4en 4asto binarnui vid use
	//               v kontekste s classami no eto dalshe(sleva imya classa sprava func vnutri klassa(4len classa), etc)
	//ITOG BINARNUI::ETO DOSTUP K KONTEKSTU CLASSA EGO PROSTRANSTVU IMEN A UNARNUI ETO DOSTUP K GLOBALNOMU PROSTRANSTVU IMEN
	
	/*
	double a = 12.345;  // GLOBAL var 4to opisana pered main() sverhu - osobenno 4asto v C use takoi podhod opisaniya
	int main() 
	{
		....
		int a;  // LOCAL esli napishem a = to eto LOCAL skroet GLOBAL vnu4ri main() a esli zahotim k GLOBAL to
		....
		cout << "GLOBAL a=" << ::a << endl; //@@@@ vot on novui operator i slu4ai kogda use kak obrashenie s global space
		cout << "LOCAL a=" << a << endl; 
	}	
	*/
	cout << "GLOBAL SPACE OUT OF MAIN a=" << ::a << endl; //@@@@ vot on novui operator i slu4ai kogda use kak obrashenie s global space
	cout << "LOCAL SPACE IN MAIN a=" << a << endl;

	//=========================== RABOTA S DYNAMIC MEMORY (heap) ===================================
	// v C bili func calloc() malloc() realloc() free() etc, v C++ dynamic memory use gorazdo 4ashe i pod 
	//		 objecti raznogo razmera !! imenno dlya bolshei effectivnosti i bezopasnosti v yazik C++ vstroili
	//        operatori dlya raboti s dynam mem(eto sredstvo yazika a ne vneshnei biblioteki kak v C)
	p = new int(100); /* prosit vudelit pamyat na 1 object int v heap(ku4e) i prisvoit emu zna4enie 100, rezultat - address
		etogo blocka memory vernet ukazately na int (p vishe sozdali)v otli4ii ot malloc v skobkah mojna
		napisat luboe virajenie kotoroe v etoi to4ke mozhna vu4islit i ego zna4eniem budet init vudelennaya memory.
		Vot primer po4emu v C++  sozdaem peremennie i objecti tolko v tot moment i togda v code kogda mozhem ih pravilno
		inicializirovat, 4tob neodnogo momenta vremeni objecti ne sushestvovali v necorrectnom sostoyanii,
	a ne kak v C sozdali pered main() mnogo globalov zainitili a potom is4em 4e zna4enie ne to gde kto portit, kakya func... 
	*/

	int *ptrnum = new int;
	*ptrnum = 7;
	cout << *ptrnum << endl;
	delete ptrnum;
	
	if (!p) {  //do standarta operator new kak i funcii malloc esli ne vudelilas pamyat vozvrashal nulevoi ukazatel(NULL)
			   //poetomu i nugna bila proverka, a teper soglasno standartu dolgno vozbujdatsa isklu4enie
			   //ono dolgno otlavlivatsa i obrabativatsa, o exception pozje v konce vsego @@@@@@@@@@@@@@@@@@@@@@@@@@@@
	}  // block obrabotki dlya error pri vudelenii pamyati        
	else {
		cout << p << '\t' << *p << endl;  //pe4ataetsa address i 4to po nemu lezhit
		a = *p;  //izvlekli zna4enie v a (a nahoditsa ne v heap a v nashem stack i zna4enie perepisalos v stack iz heap)
		cout << "a = " << a << endl; // pe4ataetsa a 

		*p = 2*a; //zatem zapisivaem udvoennoe a v etu ya4eiku pamyati (v heap p from stack a)
		cout << p << '\t' << *p << endl; //i snova pe4ataetsa address i 4to po nemu lejit

		delete p; //perestala but nado pamyat ya ee osvobojdayu spec operatorom (p hranit address blocka kotorui vudelili i hotim del)
		//@@@@@@@ posle delete p samim p polzovatsa uge nelza ved sozdali 4erez new i udalili i osvobodili a ne obnulili
		//@@ v malloc in C mu rukami vu4islyali razmer pisali sizeof(int) a new umnee on sam znaet skolko int zanimaet vah molodec :D
		//@@ vovtorih malloc return ukazatel na void i ya dolgen nasilno preobrazovat v int 4tob prisvoit p, 
		//@@ new sam vozvrashaet privedennui k pravelnomu tipu ukazatel int(ili tot kokogo tipa sozdaval je?)   :DD
	}
		//v CPP calloc() malloc() i realloc() free ostalis no kategori4eski nelza ih smeshivat s new i delete 
	    //v odnoi func eto 2 raznie podsistemi videleniya dynam mem	(naprimer sozdat callolc osvobodit free ili sozdat
	    //4erez new a udalit 4erez free(), ruhnut obe podsistemi pamyati a eshe huzhe porabotaet 10 min i upadet proga i idi znai 4ego...
	
	//@@ esli new[] to i delete[]
	p = new int[10]; //sozdanie massiva elementov int v dynam mem, vmesto 10 mojet but luboe expr kotoroe tut mogna calc
					 //naprimer otkrivayu file s4itivayu k-vo 4isel kotoroe tam hranitsa i peredayu suda
	//@@@ eslib vudelyali massiv 4erez malloc to rukami nado umnogat k-vo elem-ov na razmer kajdogo(10 ili n * sizeof(int))
	//a new umnui :D, no esli u new buli [] to i u delete dolzhni bit [] kak napominanie 4to udalaetsa massiv a ne odin elem
	if (!p) {
		 //block error handler during mem vudeleniya
	}
	else
	{
		for (int j = 0; j < 10; ++j) p[j] = j*j;
		//for (j = 0; j < 10; ++j) cout << p[j] << (j < 9 ? "," : "\n");
		delete[] p;   // esli u new buli[] to i u delete dolzhni bit[] !!!!!!!!!!!!!!!!!!!!!
	}

	float *ptrarr = new float[10]; //sozdanie dynam massiva 4erez ukazatel
	
	for (int i = 0; i < 10; i++)
		ptrarr[i] = rand() % 80 + 1;
	for (int i = 0; i < 10; i++)
		cout << ptrarr[i] << " ";
	delete[] ptrarr;	//esli u new buli [] to i u delete dolzhni bit [] !!!!!!!!!!!!!!!!!!!!!
	//======================================== END DYNAM MEM ======================================

	//@@@@@@@@@@@  initialization of different types memory by zeros or gurrbage @@@@@@@@@@@@@@@@@
	//stack i heap 4asto menyautsa objects udalautsa drugie sozdautsa func v stack zamenyautsa ih vars poetomu init musorom
	//stack i heap init mussorom ved ih 4istit o4 dorogo a vot GLOBAL space vars i static nahodyatsa v segmente dannyh(ROM) 
	//poetomu garantirovano zapolnyautsa by zeros kstate v stack i heap objetcs of class toge srazu inityatsa constructorom
	//by default a on zero pishet, no standart types musorom @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

	//9.3 ============== NOVUI TYPE UKAZATELEI NA 4LENI CLASSA I OPERATOR IH RAZIMENOVANIYA ===============
	// poyavilis iz potrebnosti classov, primenyautsa ne 4asto i na 4leni classa, ved v ssilkah menshe oshibok dopuskayut
	struct point //imya(TEG), struct ne yavlaetsa polnocennim imenem novogo tipa(on ne obyazatelen kak v C) pishem gde ugodno
				 // struct point p; // C language style obyazatelno a esli bilo len pisali typedef @~!
	{			 // point p; C++ style slovo struct ne obazatelno pri sozdanii objecta
		int x, y; //tozhe samoe kasaetsa union i enum @@!!!!
	};
	point pt = { 15,51 }; // ugodno tut i bez klu4evogo slova struct i tak ponyatno compilyatoru g++ :)))
	point *sp = &pt; //sozdayu obichnui ukazatel na struct peremennuyu tipa point
	int point::*mp = &point::x; //NOVOE!!- ukazatel na 4len structuri/classa, :: - binarnui dostup k kontekstu struct/classa
			//*mp ukazatel prednazna4en ukazivat na objects vnutri tipa point, a type point eto structura, 
			//zna4it eto ukazatel na int x,y, etc - polya structuri ili 4leni classa
			//smotri kakoi init slozhnui vishel,zdes ukazatel mp nastraivaetsa na address polya x, x int vot i ukazatel int
	
	//A esli b ya sdelal mnogo objects pt1 pt2 pt3 to vopros na x iz kakoi peremennoi nastroilsya ukazatel?
	//	otvet da ne znayu na kakuyu imenno no na imya x eto to4no, togda 4tob polu4it dostup k konkretnogo objecta x
	//  nado ukazat tot object(u nas tut on structurnogo tipa) vnutr kotorogo x mi hotim zalezt etim ukazatelem!!!!!
	//					.*  - razadresaciya ukazatelya na 4len(pole) objecta structuri/classa 
	cout << endl << "konkretnogo objecta pt.x = "<< pt.*mp << endl; //##@# VOT ON .* dostup k polyu konkretnogo obj 4erez ukazatel

	//%%%%% mp = &point::y;   binarnui operator :: kak dostup k kontekstu structuri/classa (bez sozdannogo objecta)
										//toest teper tot zhe ukazatel nastroili na lyuboe imya y. 
	mp = &point::y; //a na kakuyu konkretno?- nu ukazite a u nas est addres v ranee sozdanui point *sp = &pt; i teper
	cout << "dostup 4erez ukazatel na obj i ukazatel na ego field pt.y= " << sp->*mp << endl;
	//%%%%% gde  ->*  razadresaciya ukazatelya na 4len structuri/classa po addresu konkretnogo objecta kotorui on hranit
	//	    4tob zalezt i pro4itat/zapisat pole na kotoroe abstraktno nastroili ukazatel na pole

	//&&&&&&&^^^^^^^^^^^^^^ NO GLAVNIM OBRAZOM sp ->* mp BILO PRIDUMANO DLYA CLASSOV I 4TOB SOZDAVAT UKAZATELI NE NA
	//					 DANNIE(POLYA) A NA METODI(FUNCII 4LENI CLASSA) !!!! 
	//4tob kak v C funciya 4erez arg ukazatel na funciyu prinimala druguyu func i ee vnutri ispolzovala(KAK CALLBACK FUNC)
	//vot 4tob class mog soobshit metodu drugovo classa 4to vot obrashaisa ko mne vot 4erez etu funciyu vot na nee 
	//tebe ukazatel i ya tebe otve4u (CALLBACK MEHANIZM). vot dlya takogo vosnovnom i use
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^&&&&&&&&&&&&

	//============================== NOVIE OPERATORI YAVNOGO PRIVEDENIYA TIPA =============================
	/*			 C++ unasledoval iz C operatori privedeniya tipa, no ne recomnduet ih ispolzovat oni unsafe
		A VOT NAM 4 SPECIALIZIROVANIH(SAFETY) OPERATORA YAVNOGO!!!! PRIVEDENIYA TIPA 
	*/
	//1) static_cast<>() i uzhasnui sintaksis dlya privedeniya mezhdu arifmeti4ekimi tipami, ukazatelyami, ili ssilkami !
	a = static_cast<int>(::a); //vot tak peremennuyu global a ona tipa double smotri pered main() privesti k tipu int
							   //v <> k kakomu tipu nado privesti i v () kogo
	                           // v C postarinke bi pisali a = double(::a);
	
	vp = sp; //ili vot bil u nas ukazatel na void(void pointer(vp)) mozhno zhe prisvoit ukazatelyu na void lyuboi address
			 //naprimer vot toi to4ki tipa structura point  sp uzhe nastroen na address objecta structuri v ukazatel
	         //s amneziei prisvoit mozhno eto bezopastno(kto zhuvet ne pomnyu no address ne zabil i hranyu)
	         //a 4tob ispolzovat address nado zdelat obratnoe privedenie tak vot soglasno C++ pravilno nado pisat tak:
	sp = static_cast<point*>(vp);  //vot eto v stile C++ i max safety a safety vot v 4em: double v int double v char etc,
								   //mezhdu ukazatel na void v ukazatel na int, ukazatel na void v ukazatel na struct etc,
								   //ili analogi4no s ssilkami tak vot 4to polu4aetsa - esli eto privedenie nelza sdelat
								   //to static_cast ne compiliruetsa naprimer nelza ukazatel na funciyu privesti v 
								   //ukazatel na int, ili ukazatel na struct v ukazatel na int vot i budet error, a
								   //formalno po C mozhno tam budet bred no compilyator promol4it,
							//OSOBENNO VAZHNO ETO SAFETY PRI ISPOLZOVANII OBJECTS CLASSOV
	/* STROUSTRUP PISAL YA SPECIALNO SDELAL TAKOE URODLIVUI SINTAKSIS 4TOB BILO PROTIVNO PE4ATAT, ZA4EM?
		1) V C++ bezopastnie privedeniya tipov vsegda vipolnyautsa mol4a neyavno a podozritelnie trebuyut yavnogo
			 privedeniya, ina4e C++ ne compiliruet.
		2) Esli v programme ispolzuetsa tolko bezopasnie preobrazovaniya/privedeniya to static_cast pisat ne nado, ono
			 pishetsa kogda v programme delaetsa 4toto opasnoe/podozritelnoe 4to mozhet i bez oshibok bit no 
			 programmist pod4erkivaet a 4itayushemu v glaza brosaetsa vot sdes delaet 4eto takoe vot a za4em? eto
			 zaostryaet vnimanie :)) Esli v tekste stoit sp = (point*)vp na etom glaz ne ostanovitsa...
		3) Esli v programme 4asto prihoditsa pisat static_cast zna4it vi ploho sproektirovali programmu i nado perepisat
		     4tob isklu4it maximum problemnih privedeniy
		4) Programma vudaet bred i rabotaet neustoi4ivo, to padaet to bred to zna4eniya blizkie k ozhidaemim, i o4en 4asto
			 takoe povedenie vizivaet nekorektnoe privedenie osobenno ukazatelei, i pervoe 4to nado sdelat eto naiti vse
			 yavnie privedeniya ukazatelei i proverit na lyapi, a iz faila.cpp v 10k strok koda po poisku static_cast 
			 o4en bisto vudast spisok strok gde maximalno bistro mozhno proverit i pofixit i po vsem failam!!!!!!!!!!!!!!
	*/

	//const_cast<>()  - dlya otmeni kvalifikatora constantnosti ili volatile  
    //                  static_cast ne umeet otmenyat constantnost !!! V C 4asto bil ukazatel const mi ego preobrazovali
	//                   i slovo const poteryali on obeshal ne pisat a teper mozhet(a esli ruzhye vesit na scene ono)...
	// Esli bilo const point*vp; to mi i v sp = static_cast<const point*>(vp); pisat dolzhni ina4e on vidast error !!!!!
	//				     static_cast tolko odin tip v drugoi perevodit i constantnost i volatile ne snimaet
	// A const_cast delaet tolko eto i ne mozhet ukazatel na int v ukazatel na chat preobrazovat i naoborot !!!!!

	// Esli nam nado i to i drugoe to delaem dva posledovatelnih preobrazovaniya i dumaem pri etom a nelza li bilo ina4e??
	// %%%%% HOROSHUI LIFE HACK DLYA FIND PISAT _cast  i vupadut vse casti kotorie est v programme :)))

	// cp bil ukazatel na constantnui int a p bul na obu4nui i pravilnoe privedenie vot takoe
	p = const_cast<int*>(cp);
	//####### A VOOBSHE V C++ OTMENYAT CONSTANTNOST ETO O4EN PLOHO !!!!! no inogda nuzhno obi4no eto bivaet kogda code 
	//kotorui mi pishem mi dolzhni stikovat s ranee napisanim codom(s unasledovanim) v kotorom nebilo const postavleno
	//a esli naoborot tam bilo i v C++ voobshe takaya filosofoya metodov to otmenyat i delat bez const breeed !! ####
	// tipa vot liba mi tam pomenyat ne mozhem a ispolzovat ee nado vot i pogonyaem svoi code pod nee i takie mesta
    // nado zritelno vudelit pri pomoshi const_cast ##############################

	//^^^^^^^^^^^^^^^^^^^^^^^^^^ DYNAMIC CAST BUDET POZHE V OTDELNOM MODULE ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	//  dynamic_cast<>()   - dlya privedeniya polymorphnih ukazatelei i ssilok (ot predkov k potomkam dlya dafety)
	//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^ REINTERPRENT CAST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	 reinterpret_cast  - dlya sistemno zavisimih privedeniy samo nazvanie govorit 4to menyaetsa 
						 interpritaciya bitov
			Naprimer pri pomoshi etogo privedeniya mozhno i nuzhno preobrazovivat type int v ukazatel !!!!!
		bivaet nado nastroit ukazatel na konkretnui address pamyati, tak prosto v nego constantu ne zapishesh
		dazhe C vidaval preduprezhdenie, nado delat yavnoe privedenie tak vot soglasno C++ eto privedenie
		dolzhno bit reinterpret_cast, nikakoi nahren ne static_cast i ne const_cast !!!!!!!!!!
		Ili naprimer znakovui type v bezznakovui static_cast etogo ne budet delat a etot budet !!!!
	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
	// Smisl etih novih castov 4to oni v sovokunosti (static_cast, const_cast, reinterprent_cast) pokrivayut
	// vse unasledovanie vozmozhnosti C yazika no yavlyautsa bolee bezopastnimi tak kak kazhdui otve4aet tolko
	// za svoyu 4ast roboti, a v C delaya 4toto odno legko isportit 4toto drugoe(poteryali const i privet)a code compile:))

	//========================== KOROTKO O RTTI TAK KAK BUDET OTDELNUI LESSON =============================
	/*   
		Vo vremya raboti programmi inogda voznikaet vopros a kakogo tipa etot object address kotorogo mi imeem?
			ili ssilku na kotorui mi imeem, delo v tom 4to v C++ za adressami objectov odnogo tipa mogut
			pryatatsa objecti drugih tipov(proizvodnih), i 4tob opredelit kto tam, dlya etogo est operator typeid()
	*/
	#include <typeinfo>
	//typeid() vozvrashaet ssilku na class v kotorom est funciya name kotoraya pozvoyaet uznat imya tipa k kotoromu
	//prenadlezhit object kotorui peredaem kak argument operatora typeid i est operatori sravneniya na ravno ne ravno
	cout << typeid(pt).name() << endl; //raspe4ataet imya tipa k kotoromu prenadlezhit eta peremennaya ili object 
									   //otvet struct point
	cout << (typeid(*sp) == typeid(point)) << endl;  //a eto sravnit pravda li 4to ukazatel kotorui pokazivaet
															 //na object otositsa k tipy point  - 1(true) da
	
	//%%%%%%%%% ETOT OPERATOR TYPEID MOZHET PRIMENYATSA BEZ CLASSOV NO GLAVNOE EGO PRIMENENIE ETO NE PROSTO
	//%%%%%%%%% S CLASSAMI A S POLYMORPHNIMI CLASTERAMI IZ CLASSOV!!!!!!!!!!!! UF UF UF 
	//=====================================================================================================

	//=============================== BOLSHIE NOVOSTI - FUNCII ============================================
	/*
			V C standarte recomenduetsa opredelyat functions do ih vizova (pered main prototype v main ego vizov)
			C dopuskaet vizivat funcii bez prototipov, C++ zapreshaet vizivat functions esli prezhde v tekste
			compi ne nashel prototip funcii ili tselekov ee opredelenie(telo),  
				V C naprimer mozhem vizvat printf ili scanf bez include stdio, budut warnings no code otkompilitsa 
				i budet rabotat, v C++ srazu errors, v C 4asto compi pishet predpologayu 4to vse vozvrat zna4eniya int
				extern int, printf i scanf k s4astyu tozhe int vozvrashaet poetomu vse norm budet, no esli mi v C
				sqrt() vizovem bez include math.h to compi predpolozhit 4to return int, a mi peredali argumenti double
				i vozvrashaet sqrt double no compi otkusit double do int i polu4itsa bred. Poetomu v C++ eto srazu errors.
				Imenno poetomu nado compilyatoru prototip 4tob proverit types i skolko argumentov, a code prototipa iz
				include biblioteki emu prineset i vstavit linker na preveryai i dogda on ne budet dumat 4to int by default.

		V C mi pisali int f(void);  v C++ pustie () eto uzhe void poetomu int f(); C++ style
				v C int f(void) - eto prototip int f() - a eto obyavlenie v starom stile, v C mezhdu nimi est raznica 
				v C++ netu !!!!!!!!!!  int f(); v C eto obyavlenie v starom stile i compi ponimaet tak: func vozvrashaet int 
				a pro argumenti ni4ego ne izvestno i takuyu func v C programist mozhet vizivat bez args, s odnim s dvumya etc,
				skolko napishem args stolko compi i peredast on zhe ne znaet skolko ih tam dolzhno bit i kakie types tozhe,
				razve 4to vse 4to koro4e int iz args udlennit do int a float do double...
				
		A esli ya v C ho4u skazat 4to peremennoe koli4estvo argumentov u func togda standart govorit pishi tak:
				int printf(const char*, ...);  pervui arg to4no const char* a kakie i skolko dalshe nenznayu
				mozhno i bez , pisat (const char* ...);

		Tak kak v C++ int f() i int f(void) ekvivalentno to esli pisat v C++ s void to govoryat iz takogo koda ehse
			    tor4at oslinie ushi yazika C

									ARGUMENTI PO UMOL4ANIYU
		Zato v C++ tak kak protitype obyazatelen to mi v nem mozhem ukazat argumenti po umol4aniyu !!!!!!!!!!%%#$#%#%#%#
				void print(const int *array, int size, const char *delimeter=", ");  toest arg po umol4aniyu eto
				simvol razdeleniya pri pe4ate zapyataya probel kotorui compi podstavit esli ya ne peredam drugoi v etot arg.
				toest mogu vizvat etu funciyu v dvuh variantah :
				print(arr, n);   s dvumya tut po default vstavit ", "
				print(arr, n, ":");   a tut uzhe to 4to ya peredal
				Argumentov by default mozhet bit mnogo naprimer mog napisat size=10 v prototipe, i togda print(arr)
				ostalnie arg po default vstavyatsa 4to pe4atat 10 elementov i razdelitel zapyataya probel &&&&^^&^&^^%^%
			$$$$ I PRAVILO - ESLI HOT ODIN ARGUMENT BY DEFAULT MI OPUSKAEM PRI VIZOVE FUNCII A IH TAM NESKOLKO TO
				 OSTANIE TOZHE OPUSTYATSA, NELZA V FUNC GDE NAPRIMET 2 ARGS BY DEFAULT ODIN PEREDAT ZNA4ENIEM A VTOROI NET
				 ILI VSE PEREDAEM TO PEREDAEM ILI VSE OPUSKAEM I TOGDA VSTAVYATSA DEFAULTS, A 50 NA 50 NELZA $$$$$$$$$$$$$
				 I POETOMU ARGS BY DEFAULT PISHUTSA SPRAVA NALEVO KAK V PRIMERE VISHE 4TOB UDOBNEE BILO PEREDAVAT ILI OPUSKAT  
				 A MOG BI VSE TRI BY DEFAULT ZADAT GDE PERVUI BIL BI const int *array=my_buff, i togda vizivalsa bi 
				 print(); kotorui bi pe4atal my_buff  10 elementov s razdelitelem ", " !!!!!!!&&&&&&&&&&&&&

	%%%%%% A VOT TELO ETOI FUNCII I SMOTRI 4TO V TELE MI UZHE ZNA4ENIE BY DEFAULT NE PISHEM ONO TOLKO V PROTOTIPE OSTAETSA
		void print(const int *arr, int sz, const char *delim)
		{
			while(sz--) cout << *arr++ << (!sz? "\n" : delim);
		}  napomnyu 4to imena args v prototipe i v tele mogut nesovpodat i v tele 4ashe sokrashayut a v prototipe tselekom
			ili voobshe ne pishut mol smotri telo... Nu i tut kopii peredayutsa ne sovsem nice func nado bi 4erez ssilku
	
	//PRIVET STRADALTSAM S PASKALYA vot primer eshe odnoi func s arg by default 
		double sqr(double, int = 2);  //pust sqr vozvodit v kvadrat no esli zaho4u to v lyubuyu druguyu stepen
		cout << "sqr(2)=" << sqr(2) << endl;  
		cout << "sqr(2,10)=" << sqr(2,10) << endl; //tut 2 v 10 stepen vozvedet da no i telo samomu napisat nado &^$&#^$&^#
				a ladno vot ee telo
		double sqr(double x, int n)
		{
			return pow(x, static_cast<double>(n));   //tut eshe raz static_cast demonstriruetsa 4to type int nado 													 
		}									         //privesti k type double potomu 4to pow dva doubla prinimaet :)))
	
	*/
	//=====================================================================================================

	//=============================  SVYAZIVANIE C CODA V C++ PROJECTE =================================
	/*
		extern "C" {
			double sin(double);
			double cos(double);
			double pow(double, double);
		}
		Zabegaya vpered kogda funciya otkompilirovanaya C compilyatorom i mi budem ee linkovat s funciyami na C++
			oni ne budut druzhit i linkovatsa, dlya etogo nado specialno obyavit 4to a vot eti funcii bili polu4eni
			pri pomoshi C compilyatora i togda C++ compilyator dlya etih vizovit C compilyator i vse budet ok,
			nu v standartnih libah unasledovanih iz C naprimer <cstdlib> zaidi tam vsyudu extern "C" stoit 4tob
			C++ compilyator dlya etogo coda esli ya ego use vizival C compilyator i vstavlyal vse v itogovui object file.

	*/
	//=====================================================================================================

	//============================ NU I KUDA BEZ PEREGRUZOK FUNCIY ========================================
	/*   4tob kak v C ne mu4itsa ne stavit prefix funciyam tipa abs, labs, fabs, 4to mol beret po modulyu
			no pervaya dlya int, vtoraya long, tretyaya float, eshe i v golove derzhi vse varianti nazvaniy
	
		int & max(int &, int &);  // C++ 4tob golova ne puhla daet ability nam peregruzhat funcii
		int max(int,int,int);	  // esli oni otli4ayutsa signaturoi(tipom, koli4estvom i poryadkom sledovaniya argumentov)
		int max(const int*, int);
			No v to4ke vizova compi videl vse 3 obyavleniya imenno poetomu bez nelza kak v C, vuberet tu po tipam kotoroi
			sovpadut peredavaemie nami args, esli ne s odnoi ne sovpadut error !!!4itai brat prototipi 4tob pravilno vizvat

		cout << "Max from " << a << "," << c << "is" << max(a,c) << endl;  //zdes pervaya vizovetsa (2 inta)
		cout << "Max from " << arr[0] << "," << arr[1] << "," << arr[2] 
							<< "is" << max(arr[0], arr[1], arr[2]) << endl;   //zdes vtoraya 3 argumenta int
		cout << "Max from\n"
		print(arr, n);						//a tut tretiya, imya massiva eto ukazatel, a n razmer
		cout << "is" << max(arr, n) << endl;  
												IH TELA
		inline int & max (int & a, int & b)
		{
			return a ? b : b; 
		}

		int max(int a, int b, int c)
		{								   // DLYA DVUH TO UZHE EST
			return max(max(a,b), c);       // ETO GENEALNO &$#&$&#$&#&$&#$&$ TAK MOZHNO I VKLADIVAT I VKLADIVAT DLYA ARGS++
		}		#$^#%^$#^% O4en 4asto v C++ funcii o4en korotkie a procedura vizova o4en dlinnaya osobenno kak tut
				zagruzi argumenti, zagruzi address vozvrata, peredai upravlenie potom pustya4ok sdelai i obratno razmativai
				vozvrashai upravlenie, udalyai argumenti, i rashodi dlya korotkih funciy mogut bit bolshimi

	C++ razreshaet obyavit funciyu inline -	inline int & max (int & a, int & b)	i togda dlya int max(int a, int b, int c)
		compi mozhet popitatsa vmesto vizova funcii po standartnoi vzat prosto ee telo i vstroit v to4ku vizova!!!!!!
		podobno tomu kak v C delaetsa define s argumentami to virazhenie prosto vstavlyaetsa v kod vmesto ulovnogo 
		MAKROSOVSKIMI BOLSHIMI bukvami slova...

		int max(const int*ar, int sz)   
		{
			int *p const_cast<int*>(ar);    //zdes otmenyaem const ved arg const a v tselom nashi varianti peregruzok
			int m = *p++;				    //funcii max constantnosti ne obeshayut
			while(--sz) m = max(m, *p++);
			return m;
		}
							PRO MASSIVI UKAZATELI I SSILKI I IH OTLI4IYAH
		Kogda massiv peredaetsa v funkciyu on razlagaetsa v ukazatel(toest peredaetsa address na4ala massiva)
		no sam po sebe tip massiv eto ne ukazatel i eto dve bolshie raznici. Imya massiva v virazhenii razsmatrivaetsa
		4asto kak constantnui ukazatel(ved na4alo massiva 0 element address u nego postoyannui), no type massiv i 
		type ukazatel eto raznie types, razreshaetsa sozdat ssilku na ukazatel no kak napisat ssilku na massiv???
		da eto i bezsmislenno po toi zhe pri4ine 4to nelza sozdat ukazatel na ssilku(potomu kak ukazatel dolzhen
		init adreesom ssilki a ego vy4islit nelza i ukazatel na ssilku ne nastroish), 
			Dalshe 4to takoe massiv?? iz-za tesnoi svyazi ukazatelei i massivov rabota s massivom trebuet operaciy
		s addresnoi arithmetikoi kogda mishem a[i] eto na samom dele *(a + i)(razadresovanoei a); no dazhe esli b
		udalos nastroit ssilku na na4alo massiva(svayazat s addressom pervogo elementa massiva) to mi 4erez nee
		ko vtoromu ne doberemsya ved nado primenit addressnuyu arithmetiku a ona dlya ssilok ne goditsa, toest
		v lutshem slu4aye mozhna sozdat ssilku na odin element massiva no hodit g drugim 4erez nee ne smozhem,
		potomu 4to indexirovanie eto addressnaya arithmetika(prodvizhenie ukazatelya na sizeof tipa a eti operatori
		dlya ssilki ne opredeleni)
	*/
	//======================================================================================================
	
	//=================================== TEMPLATES ========================================================

	/*		Otdelnui module pro nih dalshe a zdes shabloni funcii mogut ispolzovatsa bez classov $%%#@#@#@#, 
		a v etom module rassmatrivaem situaciyu C++ bez classov.

								PO4EMU V C++ #define not recomended for using
		%$%$%% otstupim 4ut i vspomnim 4to C++ ne privetstvuet #define v 4astnosti ne privetstvuet macro podstanovok
			   s argumentami, naprimer v C pisali #define MAX(a,b) i stroka podstanovki a ? b : b(esli a bolshe b a ina4e b
			   i vzali vse v skobki smotri C uroki) takaya podstanovka horosha tem 4to ona vstraivaetsa v code(zameniv 
			   formalnue argumenti na facti4eskie i vstaviv ih tupo v virazhenie gde use eto), C++ s4itaet takuyu 
			   podstanovku opasnoi ved net nikakovo kontrolya za tipami podstavlyaemih argumentov esli ya v macrose
			   podstavly v funciyu max odin int ili double a drugoi ukazatel naprimer, preproccessor vozmet i podstavit
			   a 4to polu4itsa pri kompilyacii? no tut eshe macros prostoi i srazu vidno budet 4to ne tak, a esli pod
			   windows est macrosi gde mi napisal dnu stro4ku(vrode DECLARE_HANDLES) i 40+ strok v programmu dobavilos
			   i esli tam pri compilyacii vozniknet oshibka to v moem texte budet ukazano na stro4ku DECLARE_HANDLES i 
			   i soobshatsa budut oshibki v imenah macrosa kotorih shas u menaya v programme to net oni vstavyatsa na etape
			   compilyacii, s drugoi storoni vstraivanie macrosov ne vli4et nakladnih rashodov pri vizove funcii,
			   mozhna zamenit macros max na funciyu max no vizov funcii 4egoto stoit a macros ni4ego ne stoit,  
			   no s tretei storoni u nas est inline i esli ego napisali to ono prosit preprocessor vmesto vizova funcii
			   vstavit ee telo v to4ku vizova i nakladnih rashodov tozhe net, no ogromnui plus inline funcii pered #define
			   macrosom v tom 4to tak kak eto funciya to u nee est argumenti opredelennih types i pri vizove etoi vstavke
			   compilyator proverit 4to types args soovtvetstvuyut a esli net zdelaet neyavnoe privedenie k ozhidaemim
			   tipam a esli ego zdelat nelza to polu4im error !!!!!! Po bistrodeistvyu code odinakovui no inline daet
			   dopolnitelnui level nadezhnosti(s vproverkoi tipov) 4to v C++ i normalnom code must have !!!!!!!!!!

		No 4to plohovato 4to macros goditsa dlya lubih tipov a nasha inline max funciya tolko dlya intov, a esli nado 
			dlya double to delaem peregruzku inline s args double i return double i code stro4ek budet bolshe a esli mne
			nado eshe dlya char, long, short, to rukami stolko pisat peregruzok zashkvar vot i pridumali inline
			TEMPLATES funcii i eto pezopasno i v lutshih tradiciyah C++
		%#$#%$%#$%#%$#%$#%$#%$%%%%%%%%%%%%%%%%%#$#$#$#%$%#$%#$%@%#%@%#%@%$%#$%#%$%#%$%#%$%#@%$%@%#%%#$%#%$%#%$#%$%#%$%#

											SHABLON FUNCII
			template<typename T>   klu4evoe slovo template a <> skobki ukazivayut 4to to 4to v nih stoit eto
								   parameters etogo shablona sredi nih klu4evoe slovo typename i na ego meste
			mozhet eshe stoyat klu4evoe slovo class, i kogda STRAUSTRUP pridumival templates on v parametrah ispolzoval
			imenno slovo class no komitet po standartu predlozhil ispolzovat typename kak bolee to4nui termin!!!!!!
			no na samom dele se4as podderzhivaetsa i class i typename a STRAUSTRUP govorit ya ploho pe4atayu poetomu mne
			class koro4e i bustree nabirat, no slovo class namikaet 4to parameter T dolzhen vrede kak bit classom a na 
			samom to dele eto lyboi vstroennui i ne vstroennui data type, a zna4it typename vse zhe bolee ponyatnee 
			otrazhaet suut voprosa i lutshe pisat ego hotya mozhna i class.
				
					SHABLON eto konstrukciya u kotoroi parametrom yavlyaetsa data type, vstroennui ili user defined bez
			raznici, shablon eto algorithm kotorui parametrizuetsa tipom dannih.
				^&^&&^%^    Esli govorit bolee razshirenno to dostato4no 4asto sushestvuyut algorithmi kotorue ne menyayut
			svoei logiki no primenyautsa k raznim tipam dannih, nu naprimer algorithm sortirovki massiva, ponyatno 4to
			s fizi4eskoi to4ki zreniya massiv intov i doublov realizuetsa 4ut po raznomu tam blocks po 4 bytes 
			perestavlyautsa a tam po 8 bytes, no s logi4eskoi to4ki zreniya algorithm odin i tot zhe, tak vot 
			templates pozovlyaut zapisat etu obshiyu logiku dlya raznih tipov, i skazat 4to eta logika goditsa dlya
			tipov kotorie budut parametrami etogo template.

	template<typename, T>
	void tswap(T & a, T & b)    tswap s namekom na template swap function
	{
		T t = a; a = b; b = t;
	}                     eta func polu4aet dva argumenta po ssilke(ssilka pozvolyaet rabotat s objectom vo vneshnem mire
						  ssilka eto psevdonim a rabta budet idti s originalom ne sozdavaya copii v funcii shablone)
			template<typename, T> govorit nam 4to imya T eto parametr shablona kak obozna4enie nekotorogo tipa kotorui
			potom budet uto4nen pri vizove etoi funccii i mi v tele func mozhem ispolzovat ego vezde gde on nam nuzhen,
			i v ka4estve return zna4eniya tozhe esli nam ego nado return !!!!!!!!!! *#&$*&#&$#*^&#^&#^@^&^&#@$^&#@
			I telo proshe ne bivaet sohrani pervui element potom na ego mesto zapishi vtoroi i sravni sohranennui s pervim.

	Kogda compilyator vstre4aet text shablona on ego ne compiliruet i nikakovo koda ne porozhdaet vmesto etogo on 
		zapominaet 4to est shablonnaya funciya s imenem tswap i esli gdeto dalshe po textu vstre4aetsa vizov takoi 
		funcii vot code primera 

	tswap(a,c);  //a i c v etom lessone imeyut type int 
	cout << "a = " << a << "c = " << c << endl;   // a = 0, c = 12 posle swapa

		I vot compilyator smotrit tswap() - vizov funcii, smotrit est li po textu vishe obyavlenii tswap(), otvet net
			NO!!!, vishe po textu est obyavlenie funcii s takim imenem v vide shablona, i compi mozhet proverit tak kak
			v pri vizove dva argumenta tipa int a u shablona tozhe dva argumenta i esli vmesto T podstavit int, to 
			opredelenit(telo) funcii budet to4no sootvetstvovat vizovu, i togda compi bered code tela template funcii
			4estno zamenyaet v nem T na int(sam sebe pishet takoi kuso4ek programmi), sam ego compiliruet, code vstavlyaet
			kuda polozheno v object file, a zdes pishet tswap(a,c); i polu4aetsa 4to on sam napisal sebe code kotorui sam
			otkompiliroval i potom zdes vizval pri tswap(a,c);   
						a teper s drugimi args type poprobuem
	double x = 1.5, y = 2.5; 
	tswap(x,y);    
	cout << "x = " << x << "y = " << y << endl;   // x = 2.5, y = 1.5 posle swapa
		compilyator tut probuet ponyat 4to takoe tswap i kogo tut nado vizvat smotrit tswap() eto funciya s argumentami
		tipa double a tolko 4to vishe compi porodil funciyu tswap s argumentami tipa int, mozhno vizvat etu porozhdennuyu
		funciyu esli u double obrubit hvosti i eto dopustimo, i compi navernyaka tak bi i sdelal esli bi ne obnaruzhil
		4to est eshe opisanie shablonnoi funcii(dlya compi template eto ve4naya amneziya esli mnogo raz 1 shablon use
		i on kazhdui raz proveryaet kak v pervui raz) v kotorui esli T zamenit na double to sootvetstvie tipov budet
		gorazdo lutshe sootvetstvovat vizovu 4em double obrezanui do int, i togda on snova sam napishet neskolko strok
		koda na4inaya s void i zamenit T na double, etot code otkompiliruet, polu4itsa variant peregruzhennoi funcii i
		ee telo sohranitsa tozhe v object module, a zdes vizovetsa variant peregruzki s argumentami double.

	Eshe odin vizov no s args tipa char :))))

		char c1 = 'A', c2 = 'Z';
		tswap(c1,c2);
		cout << "c1 = " << c1 << "c2 = " << c2 << endl;   

	Tut compi uzhe znaet 4to est variant tswap dlya double, char v double preobrazuetsa? nu v principi da eto zakonno,  
		no est eshe i tswap s int, char v int tozhe zakonno preobrazuetsa i dazhe lutshe 4em v double, tak mozhet char
		v int vizvat?? no eshe vishe po textu est opyat zhe shablonnaya func tswap i esli T zamenit na char to budet
		voobshe idealnoe sootvetstvie, i togda compi opyat pishet neskolko stro4ek coda, compiliruet v object file,  
		i sozdaet tretij variant peregruzki funcii tswap a v tswap(c1,c2); ee vizivaet :)))))))))))))))))))
	Zamette 4to copy i paste s izmeneniem tipa delaet compilyator, no mega kruto zhe !!!!!:)))

			-------------------- PRAVILA VIBORA PEREGRUZHENNOI FUNCII COMPILYATOROM :)) ---------------
		VOOBSHE dovolnoe slozhnoe, vopervih rassmarivautsa sootvetstviya po kazhdomu argumentu, i sostavlyaetsa spisok
			nailutshih kandidatov po kazhdomu argumentu, potom beretsa ih perese4enie(etih spiskov), a esli v spiske
			okazivaetsa odna edinstvennaya funciya - ona vizivaetsa, esli nekogo - zna4it vizvat nekogo, esli dve
			ili bolee - vizov ne odnozna4en. A sredi kandidatov na nailutshee sootvetstvie na4inaetsa sravnivatsa
			privedenie tipov i tam tselue ierarhii, tipi svyazannie s udlennenie tipa predpo4titelnee 4em 
			preobrazovaniya svyazannie s poterei to4nosti(drobnoi 4asti etc).
			--------------------------------------------------------------------------------------------	
		Obratim vnimanie vot emu vseravno po tablice v char v double ili v int ne fact 4to v int lutshe mozhet bit i
		neodnozna4nost no raz sushestvuet shablon kotorui mozhet privesti pri vizove idealno to neodnazna4nosti netu!!

		I esli nizhe po textu snova vstrititsa tswap ot int to nikakovo novogo varianta peregruzki compi sozdavat ne 
		budet a vozmet tot kotorui uzhe ranshe sozdal i tut ee povtorno vizovet uah uah MOLODEC :))))))!!!!!!!!!
			Nu i nakonec 4tob v to4ke gde vizivaetsa tswap(a,c); ot int compi mog vizvat sgenerirovannuyu
			funciyu a prezhde ee sgenerirovat on tolzhen videt telo shablona a zna4it shablon dolzhen raspologatsa do
			to4ki vizova, a voobshe esli shablon ispolzuetsa v neskolkih failah ili dlya classa to obi4no shabloni 
			raspologayut v header failah, i includom ego podklu4aem v kazhduiy file projecta gde on nuzhen #$#%#%%#%#%#%%
	Tak kak code shablona samogo ego tela ne porozhdaet coda to mnoga raz ne dubliruetsa vo vse faili, compilyator
	sam sgeneriruet peregruzki esli nado i po odnomu razu i vstavit vo vse to4ki vizova gde nado glavnoe 4tob include bil !!

		@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	I SAMUI SOK TEMPLATES @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
				
				vot code kotorui videt compi

				template<typename, T>
				void tswap(T & a, T & b)    
				{
				T t = a; a = b; b = t;
				}   

				a ya reshil zdelat vot takoi vizov 

				char pc[10] = "ABCDE", pd[10] = "XYZ";
				tswap(pc, pd);
				cout << "pc-> " << pc << "pd-> " << pd << endl;   i 4to zhe proizoidet??? v ka4stve args dva massiva dayu

			Kstate a #define eto bi zdelal?:) - da kakoito bred bi podstavil a 4to u nas proizoidet? - da nikto ne znaet
		kak budet rabotat sgenerirovannui code, a primer etot vot dlya 4ego - shabloni funciy pozvolyayut nam zapisivat 
		rodovie(obobshennie) algorithmi ved funciya eto realizaciya algorithma, vot i etot instrument nam daet vozmozhnost
		pisat algorithmi kotorie primenyautsa k tselomu simeistvu tipov(poetomu i rodovie), a v rodu(simye) ne bez uroda,
		to bivaet tak 4to algorithm dlya mnogih tipov goditsa no est odin dva tri tipa(classa) dlya kotorih ego primenyat 
		nelza i eto imenno etot slu4ai, tak vot kogda rodovoi ne goditsa i nuzhno 4toto bolee konkretnoe naprimer esli ya 
		v max argumenti peredam simvolnie stroki - ona zhe na4net sravnivat addressa strok, a zdes voobshe ne ponyatno 4to
		i kak perestavlyat budet tswap, @@@@@@@ vot dlya takih osobih slu4aeev mi mozhem peregruzit shabonnuyu funciyu
		no uzhe obi4noi s takim zhe imenem i uzhe bez template<typename, T> a prosto void tswap(char *a, char *b) so
		specialnim telom obrabotki takogo osobovo slu4aya @@@@@@@
						
					#$%$%%$%$	naprimer vot tak peregruzit mozhem shablonnuyu obi4noi $%$%$%$%
		
		void tswap(char *a, char *b)
		{
			tswap(*a, *b);
		}						pishem s tem zhe imenem no uzhe s nuzhnimi mne tipami argumentov dlya kotorih telo 
			shablona ne podhodit, i togda compi v to4ke vizova tswap(pc, pd); vidya godovuyu funciyu 
			void tswap(char *a, char *b) i funciyu dlya kotoroi lish zadan sposob porozhdeniya(shablon) 
			void tswap(T & a, T & b) ostanovitsa na uzhe gotovoi funcii i ne budet use shablon toest u nee prioritet
			vishe !!!!  Nu telo svoei pregruzki ya pridumal tak esli mne user podsunit massivi ya perestavlyu u nih
			tolko pervie bukvi, massivi to menyat nelza oni raznui razmer v pamyati zanimayut, hotya esli zamoro4itsa to
			mozhna napisat shikarnoe telo obmena strok luboi dlinni, nu eto uzhe ot fantazii i skila zavisit...

		ITAK templates eto instrument(sposob) zapisi obobshennih(rodovih) algoritmnov, parametrom u kotrih yavlyaetsa tip,
		dlya primeneniya dlya konkretnih raznih tipov porozhdautsa peregruzhennie varianti sootvetstvuyushih funciy,
			Bolee podrobno v module gde templates, funcii i kone4no zhe classi rasmotrim.

			#$$#$#$$#$#$#$#	IBO KAK OSNOVNAYA POTREBNOST ETO PISAT SHABLONNIE CLASSI, A POSKOLKU CLASSI SODERZHAT  #$#$#$#$
							FUNCII, TO V SHABLONE CLASSE FUNCIYA TOZHE SHABLON, A RAZ FUNCIYA SHABLON TO EE MOZHNO
							ISPOLZOVAT I BEZ CLASSA 4TO TUT I RAZSMOTRELI (BEZ CLASSA ETO VUTISNIT POTREBNOST
							#DEFINE S ARGUMENTAMI I USILIM BEZOPASNOST CODA) a napishite vot takoi shablon i napishite
							prered nim inline ->    inline void tswap(T & a, T & b) eto privedet k tomu 4to esli shablon
							korotkiy to podobno macropodstanovke v to4ku vizova funcii budet podstavlyatsa telo shablonnoi
							funcii(a ne standartnui ee vizov), to 4to eto shablon pozvolit podstavlyat v raznih mestah
							zna4eniya raznih tipov, a to 4to eto vse taki funcii to pered podstanovkoi tela to 
							obyazatelno proveryatsa tipi i sootvetstviya argumento, a eto safety, a pod raznie types po
							shablonu budut generirovatsa raznie peregruzhennie varianti funciy + moi 4astnie peregruzki !!!!
							i za4em nam #define :))))))
		  $#$#$#$#$#$#$#$#$$#$#$#$#$#$#$#$#$#$#$^$#$#$#$#$#$#$#$#$#$#$#$#$$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$#$
	*/

	//===== VOOBSHEM THATS ALL DALSHE STRUCTURA DAY TIME + FUNCII DLYA RABOTI S NIMI ALYA NA4ALO CLASSOV ===
	/*	
			struct time						struct date
			{								{
			};								};

			set();							set();
			print();						print();
			read();							read();
	 
	 Funcii nazivayutsa odinakovo no v to4ke vizova zdelav peregruzku oni budut prinimat raznie struct types i vse ok!

		time t;					date d;
		print(t);				print(d);

	*/

	return 0;
}
