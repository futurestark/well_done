#include <iostream>
#include <fstream>
#include "String.h"
//using namespace std;   ploho pisat ibo gde use funciya moya s std mogut zabit using 

/*   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	NA LYBOI DRUGOI VERSII VISUAL STUDIO PRI OSHIBKAH 470+ SHTUK ZAITI V SVOISTVA PROEKTA I POMENYAT V GENERAL
	TEKUSHIYU VERSIYU PAKETA SDK -> VIBRAT IZ SPISKA TEKUSHEYU VERSIYU SDK PAKETA ON SAM NAPISHET NA KAKUYU MENYAT 
  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

int main() {
	//String a; //esi object pustovo classa daet v debuge error to nado otklu4it 4asti4nuyu
	          //cpmpilyaciyu Properties projecta -> Linker -> General -> Enable Incremental Linking set to No

	String a("Hello, world!"); //nado sozdat contructor kotorui prinimaet massiv charov
	//v classe contructor s odnim edinstvennim argumentom ili kotorui mozhet vizivatsa s odnim argumentom objecta
	//	ostalnue esli est to oni by default budet vistupat constructorom preobrazovaniya iz raznih tipov esli tolko
	//  etot odin edinstvennui argument ne object etogo zhe classa togda eto constructor kopirovaniya
	//  v ostalnih slu4ayah preobrazovaniya(iz drugih tipov sozdaet dannij) a kopirovaniya iz sebya zhe sozdaet kopiyu
	//otlado4naya pe4at 
	std::cout << "String a: \"";
	a.Print();
	std::cout << "\", Len=" << a.Len() <<std::endl;

	// a esli est zahva4ivaemie resursi to ono dubliruet ssilki i privodit k dvoinomu troinomu etc udaleniyu...
	String b = a;  //ili String b(a);
	std::cout << "String b: \"";
	b.Print();
	std::cout << "\", Len=" << b.Len() << std::endl;
	//================================================================

	//----------------------------POSLE PEREGRUZKI OPERATOROV-------------------------
	//^^ neploho bi bilo dobavim v sled less  vzat stroku a[0] = 'M'; 
	//dobratsa do 0 elementa i pomenyat ego, peregruzit dlya indeksirovaniya 
	b = a;  // nu i posle peregruzki operatora mi mozhem napisat tak: 
	b.operator=(a); //i eto tozhe budet rabotat - yavnui vizov etoi func po ee imeni hotya b=a; koro4e
	//============================= SAMOPRISVAIVANIE =======================
	//a 4to budet esli napishem b=b; ili b.operator=(b);
	b = b;  //rabotat budet? - da, a 4to za 4epuha vmesto texta polu4ilas????, otkuda musor?
	/*
		otkriv code peregruzki operatora = v String.cpp videm pervoi strokoi delete[] s;
		eto zna4it mi berem bolshoi 4ernui pistolet i strelyaem sebe v visok osvobodivshus ot
		toi stroki kotoroi mi vladeli, posle togo kak osvobodilis 4to tepr mi tuda kopiruem?:)
		na 4to nadeemsa? nu v dannui moment vot takoi musor pri4em ego bolshe 4em len 13 a len 13 pishet,
		a esli pereklu4imsya na release budet pustaya stroka a len vseravno 13 :))) i pri kazhdoi 
		recompile mozhet but raznoe...
			VIVOD NELZA STRELYAT SEBE V VISOK prezhde 4em 4toto udalyat, nado ubeditsa a ne sebya
			li mi udalyaem. Idem v String.cpp delaem zashitu
		ZACOMMENTIROVAT if{} i glyanut 4to on rabotaet i pomagaet v operatore= v String.cpp
	*/
	//======================================================================

	//&&&$$$$$$$$%%%%%%% OSTALSA ESHE ODIN DEFECT OB ETOM POTOM V SLED LESSONAH DOPISHEM %&#^%$##$@

	&a;  //po4emu bi ne vu4islit adress a unarnim operatorom :))) vse v poryadke
		 //no ne zabivaem ukazatel na const object i ne na const object eto raznie ukazateli #&^%^#

	//------------------------------------ KONKATENACIYA I EKVIVALENTNOST ------------------------
	// Bivaet dve concatenacii a = a + b i a += b zna4it i to i to nado realizovat
	//Mne bi hotelos sdelat konkatenaciyu strok a + b; no bivaet i takaya a+=b
	//v slu4ae a + b a ne menyaetsa, no v a+=b sozdaetsa ne4to novoe 4ego ranshe ne bilo
	//dlya vstroennih tipov naprimer x=x+1 ili x+=1 ili x++ ili ++x ekvivalentnie operacii 
	//i mi 4asto govorim a+b i a+=b ekvivalentnie a dlya classov nikto ni4ego podobnogo ne obeshal 
	//i esli mi sami ne realizuem to podobnue operacii budut ne ekvivalentnie s nashimi classami :)))
	//a poskolku mi hotim 4tob classi sebya veli podobno vstroennim tipam t nado realizovat obe operacii
	// a += b; i a = a + b,   = u nas est no dlya + u nas net peregruzki
	// okazivaetsa bolee udobnim realizovivat obi4nui operator + 4erez kombinirovanui += tem bolee 4to = u nas est uzhe
	//			v headere string realizovivaem operator += kak 4len classa ibo operator = tozhe 4len classa

	std::cout << "String b: \"";
	b.Print();
	std::cout << "\", Len=" << b.Len() << std::endl;

	// PEREGRUZILI operator += i smotrim 4to polu4ilos posle koncatinacii
	a += b;
	std::cout << "String a=+b: \"";
	a.Print();
	std::cout << "\", Len=" << a.Len() << std::endl;
	
	//A budet li teper compilirovatsa a += " Hi Hi!"; - da vse ok
	// Pisali += dlya String podstavili massiv char i ono rabotaet i dlya =   a = "Billy Bonce"; tozhe rabotaet Oo
	// a = "Billy Bonce";  compiliruetsa hot i pisali = dlya String potomu kak eto tozhe samoe 4to napisat
	// a.operator=("Billy Bonce"); operator= dolzhen prinimat String a emu dosunuli daleko ne string no compi obnaruzhievet
	//to esli u menya est   String(const char *str ="");  sposob kak ego preobrazovat v String to on neyavno vizivaet
	//constructor preobrazovaniya i vizivaet ego v operator=      fakti4eski on delaet vot 4to
	//        a.operator=(String("Billy Bonce")); vot takoi kod porozhdaet compi kogda mi pishem  a = "Billy Bonce"; 
	//     raz privodit neyavno types dva vizivaet operator = i a += " Hi Hi!"; rabotaet po toi zhe pri4ine
	a = "Billy Bonce"; 
	a += " Hi Hi!";
	std::cout << "String a=+ Hi Hi: \"";
	a.Print();
	std::cout << "\", Len=" << a.Len() << std::endl;

	//A kak realizovat a = a + b; 4em etot + otli4aetsa ot +=? zdes a i b dolzhni ostatsa kakimi bili no i dolzhna poroditsa
	//novaya stroka toest novui object dolzhen poyavitsa   delaem peregruzku operator+
	// a = a + "Billy Bonce";   vse ok 
	//no v a = "Billy Bonce" + b; vopros + ono realizovano kak 4len classa levogo operanda, kto zdes levui operand?
	// massiv charov eto class? - net nu i dosvidaniya peregruzka operatora + dlya takogo slu4aya work ne budet !!!!
	// a = a + "Billy Bonce"; vse ok tak kak zdes sleva class String
	a = a + b;
	a = a + "Billy Bonce";
	std::cout << "String a = a + Billy Bonce: \"";
	a.Print();
	std::cout << "\", Len=" << a.Len() << std::endl;
	//a = "Billy Bonce" + b;   ERROR 
	/*							---- FIXIM  ERROR a = "Billy Bonce" + b; -----
			no s drugoi storoni esli ya realizuyu  realizuyu ee vot takim obrazom gde X i gde Y budet opisano String 
					x@y ===>   ::operator+(X,Y)		===>   operator+(x,y)
		    no pri pereda4e odin budet String naprimer a drugoi massivom char to compilyator 4to oba privesti k type
			String(odin iz nih String drugoi massiv 4arov) budet neyavno vizivat constructor preobrazovaniya  4to dlya
			levogo 4to dlya pravogo operanda

		ITOG OBI4NO RESHENIE TAKOE -> ESLI MI PISHEM BINARNUI OPERATOR x@y DLYA SVOEGO CLASSA I ON MOZHET
		VZAIMODEISTVOVAT S OBJECTAMI DRUGIH TIPOV SMOTRIM MOZHEM LI MI BESPE4IT SIMETRI4NOST(COMMUTATIVNOST)?
		ESLI DA TO ODIN IZ PROSTIH PUTEY ETO SDELAT FUCNTION SVOBODNOI A NE 4LEN CLASSA(NE K X NE K Y NE OTNOSIT)
		A ESLI MOZHET TOLKO SAM S SOBOI(VSTROENNIE TYPESI DRUGIE CLASSI OFF) TOGDA NADO 4LENOM CLASSA DELAT
			UBERAEM PEREGUZKU OPERATORA + IZ CLASSA !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! I KIDAYU V HEADER NO POSLE CLASS{}
	*/
	a =  "Billy Bonce " + b;  // "Billy Bonce "  probel 4tob ne skleelos vplotnuyu s b, potom i prasit po probelu udobnee
	std::cout << "String a = Billy Bonce + b: \"";
	a.Print();
	std::cout << "\", Len=" << a.Len() << std::endl;
	/*KONCATINACIYA DELAETSA NE O4EN EFFECTIVNO S PERATOROM + =;  i global perem ne pomozhet ibo mozhem pisat
	------------------------------------------------------------
	 a = a + b + "Billy Bonce"; i s global perem budet neodnazna4nost ----> edinstvenno gde mozhem ekonomit eto ---->
	 zdes  a = "Billy Bonce";  i zdes a += " Hi Hi!"; i zdes a = a + "Billy Bonce"; i zdes a =  "Billy Bonce " + b;
			proishodit neyavnui vizov constructora i vudelyaetsa pamyat char *t = new char[n + str.n + 1]; 4tob v nee
			polu4it &str, i nado skazat esli u nas ne4asto proishodyat conkatenacii String i 4arov to i ladno
			ina4e mozhno dlya ekonomii sozdat v classe eshe odin operator kotorui budet String & operator=(const char *);
			i togda budet prinimatsa massiv charov ne preobrazuyas v String vudelyaya pod eto pamyat 4tob potom 
			ee osvobozhdat
		Polu4itsa dva peregruzhenih operatora = odin prinimaet String drugoi massiv 4arov ne vizivaya constr preobrazovaniya
			tak zhe += peregtuzit 4tob ne tolko stroki prinimalis no i massivi charov 
			i v + sdelat azh 3 peregruzki String String kak shas, v dobavok String massiv charov i massiv charov String.
			izbegaya vizova contr preobrazovaniya kotorui sna4ala vudelyaet pamyat a potom ee osvobozhdaet no zato stro4ek
			coda budet pobolshe :))) no zato effectivnee esli uzh sovsem 4asto i mnogo strok nado concatenirovat
	VOT OB ETOM I DOLZHEN ZABOTISA PROGRAMMIST KAKIE OBJECTI S KAKIMI I DAVAT SPEC PEREGRUZKI ESLI 4ASTO I MNOGO USE NADO
	 */
	//-------------------------------------------------------------------------------

	// A eshe bilo bi polezno peregruzit operator proverki na ravenstvo == 4tob sravnivat stroki no vot ee uzhe 
	// nado sdelat drugom poetomu peretaskivaem v public razdel classa i vse ostalnue smotri cpp tam rzhaka
	std::cout << (a == b) << std::endl;  //a pravda li
	std::cout << (a != b) << std::endl;  //a pravda li
	std::cout << (a > b) << std::endl;   //a pravda li
	//&&@$@*$@&$& i teper sravneniya strok mozhno podklu4at v razli4nie sortirovkki :)))))

	//OOOOOOOOOOOOOOOO davaite peregruzim nakonec operator indexirovaniya []  4tob mozhno bilo pisat a[i] = 'h';
	//				   peregruzim kak 4len classa ibo po drugom ego ne razreshaetsa 
	a[0] = 'h';  // %%%% zdes dostup dlya write %%%%%
	a[100] = '@'; //tozhe write, a gde write constantnui variant funcii vizivatsa ne mozhet
	std::cout << "a[0]= " << a[0] << std::endl; //eto 4tob uvidit pri ='h' %%%%%% zdes a[0] dostup dlya read %%%%%%
	std::cout << "a[100]= " << a[100] << std::endl; //eto 4tob uvidit a 4to polu4ilos pri @ kogda index out of range skazalo
	std::cout << "String a ";  a.Print(); //ai skleyu dve stro4ki koda nadoelo po 3 copy paste
	std::cout << "\", Len=" << a.Len() << std::endl;
	//const method ili ne const vizivat zavisit po otnosheniyu k objectu dlya kotorogo vizivaem method, pri cout << a[0] a u
	//nas obyavlena constantoi?? net nu tak tak i ne budet safety const method  vizivatsa, esli b ya pomestil
	// std::cout << "a[0]= " << a[0] << std::endl; v method kotorui ssilku na constantu vozvrashaet vot tam bi vizvalsa const
	// method operatora indeksirovaniya nu ili sozdal bi const object i pri ego cout tozhe bi const method vizivalsa
	/*		Nu pou4itelnogo v peregruzke operatora indeksirovaniya to 4to bivayut const i ne const varianti, indeksirovanie
		trebuet ot nas zaboti o bezopasnosti out of range indeksa, zaodno ponyali kakoi code pishet compilyator v teh yazikah
		gde sledit sam za vihodom za granici massiva(pri kazhdom a[i] takoi code  (0 <= index && index < n)    :)) 
	*/

									/*	PEREGRUZKA OPERATORA VSTAVKI V POTOK << */
	//================================ Postoyanno pishem a.Print i po4emu bi ne nau4it stringi ==============
	//									vivodit sebya v potok i 4itat iz potoka, go napishem !!!!!
	/*
				Peregruzhaem operator vvoda i vivoda v potok iz potoka kak 4leni classa tolko vot zhalgo usera
			vot sozdal on stroku  4toto s nei sdelal String str = "Xa-Xa"; i reshil eto nape4atat no vot tak
			cout << str; ego code compilirovatsa ne budet, potomu 4to esli operator << 4len classa String to 
			on dolzhe pisat tak str << cout; hmmmmmm krisha bi poehala i pisal bi vot tak str >> cin; hot eto bi i rabotalo
			POETOMU DELAEM STORONNEI FUNCIEI TAK KAK LEVUI OPERAND DOLZHEN BIT NE 4LEN CLASSA, cout dolzhen stoyat sleva,
			4tob ne narushat vse soglasheniya o peregruzke(4tob ne ehala krisha u usera), delo eshe v tom 4to operator
			vivoda v potok peregruzheni dlya tipov private: char *s; no dostupa k polyu net zna4it delaem friendom !!!!
	*/

	std::cout << "Test << :" << a << std::endl; //vse rabotaet bez a.Print()  :))
	//$$$%%% Peregruziv << operator mi nahalyavu polu4ili 4to esli dopishem v verh main.cpp eshe #include <fstream>
	//to srazu mozhem napisat sleduyushij kuso4ek gde ofstream class 4to ralizuet vihodnoi potok v file &&&%$%$%$
	std::ofstream myFile;  
	myFile.open("test.txt");  //dalshe argumenti by default v .open() i oni menya ustraivayut tak kak otkrivaetsa s za
							  //shitoi ot sovmestnogo dostupa k failu a vot esli on nuzhen smotri 4itai argumenti
	//&^$#&$^   Poskolku v ofstream est constructor to mozhno bilo napisat     std::ofstream myFile("test2.txt");  ^$#^$^#
	//			constructor bi sam i sozdal i otkril file i na 1 stroku coda menshe
	myFile << b << std::endl << a << std::endl;  //GOVORYU 4TO HO4U V FILE OTRPAVIT SNA4ala struku b potom a
	myFile.close(); //i zakrivayu file :))
	//&^$#&$^   Poskolku v ofstream est constructor to mozhno bilo napisat     std::ofstream myFile("test2.txt");  ^$#^$^#

	
	std::cout << "Enter your name: ";
	std::cin >> a;
	std::cout << "Hello, " << a << std::endl;   //a mog bi i v file pisat ili s nego s4itivat
	std::ofstream MySecondFile("test2.txt");// no kosyak v console norm a v file rus bukvi krivo budut pisatsa eto nado razberat
				//drugaya kodirovka rus bukv krakozyablaya, no po suti   >> a;  zdes vvelos po pravilam peregruzhennogo
				//operatora izvle4eniya iz potoka stroki 4itayutsa do pervogo probelnogo simvola(kak scanf %s), a esli
				//ya ho4u bolshe to v String.cpp nado ne tak 4itat is >> buf; a est takaya funciya getline i ona polu4aet
			    //pervim arg kuda pisat, vtorim skolko, i togda vmesto is >> buf; eto  is.getline(buf, sizeof buf);
				//ispravit delo v String.cpp
	MySecondFile << b << std::endl << a << std::endl; //no 4tob rus text pisal otdelno fixit nado eto kaknibud sam
	MySecondFile.close();							 //getline kontroliruet 4to bufer ne perepolnitsa no
							 //dynami4eskoe ego uveli4enie esli nado sam podumai kak sdelat ili posmotri v std libe string
	
							  //=================================================================================================
	//SOZDAM STROKU V DYNAM MEM(HEAPE)
	String *p = new String("Good Bye!"); //napisali new pishem i delete(a destructor s [] vse pravilno sdelaet)
	std::cout << "String in heap: \"";
	p->Print();							// tut vezde ne a.Print() a p->Print()
	std::cout << "\", Len=" << p->Len() << std::endl;  
	delete p; //napisali new pishem i delete(a destructor s [] vse pravilno sdelaet)


	system("Pause");
}

/*	============================== ITOG =======================================
	NIKOGDA CONSTRUCTOR COPIROVANIA DLYA OPERATORA PRISVAIVANIYA NE VIZIVAETSA!!!
	kak otli4it inicializaciyu String b = a; s constructorom copirovaniya
	ot operatora prisvaivaniya b = a; ?????????????? pohozhie no raznie mehanizmi

	    String b = a;  tut object b vpervie sozdaetsa ego eshe nebilo on tut sozdaetsa
					   constructorom i inicializiruetsa pri pomoshi kopii sushestvuyushego
					   objecta.
		b = a;	a tut object b uzhe sushestvuet on ne sozdaetsa zanovo constructorom,
				u nego zamenyautsa zna4eniya ego polei. Poetomu drugaya operaciya prisvaivanie
		Raznica v odnom sushestvuet uzhe object k etomu momentu ili eshe net *************


	Pri razrabotke classa i ego interfaceov vsegda pervue voprosi:  (nu i mozhet vzyatie addresa objecta operator & dlya const
																	 i ne cosnt objectov tozhe peregruzit esli nad budet)
			1)Kak objecti classa sozdayutsa
			2)kak objecti classa uni4tozhautsa
			3)kak objecti classa copiruyutsa  ===> i prisvaivayutsa  eto svyazka
	Potom reshaetsa 4to eshe s etimi objectami mozhno delat(4em oni buli bi polezni):
			

*/

/*         Esli b ya sozdal class Point p; bili bi polezni operatori indeksirovaniya p[0], p[1]	??
		nu p[0] naprimer ozna4alo bi pole x, p[1] y vmesto vizova SetX() SetY(), i kstate nikto ne govoril 4to
		argumentom u operatora indeksirovaniya obyazatelno dolzhen bit tselui tip alya int, double, prikinte ya bi
		peregruzil tak p['x'], p['y'] da i vrode normalno tak s pointom rabotat, 4itabelno :)), eto kak v exele macrosi
		pishut obrashatsa mozhna po imeni ili indeksu i vot po takoi realizacii pod kovrom p['x'] tolko v 'x' dolzhna bit
		peregruzka s ukazatelem na char.  
*/

//========================================== DOMASHNEE ZADANIE &#$%#%^$#^$%#^%$#%$#%^$^%^$#%^$%#%^$%^#$%^#$%
/*
	POSMOTRET THEORY PRO STATI4ESKIE I CONSTANTNIE 4LENI CLASSA nu pro const funcii govorili 4to kogda ne menyayut
		object vsegda const pisat nado osobenno kogda read object state ili print, i 4to constantnie peremennie
		dolzhni initializirovatsa v spiske constructora...
	A VOT PRO STATI4ESKIE 4LENI CLASSA PO4ITAT HOTYA YA VRODE I TAK ZNAYU *****
*/
//============================== $&@&$&@^&#%^@$^@%^$%^@^$%^@$%@%^$@*%**&@%*&@%*&@*&%@%*&@*&%&*@*&%@%*&@*&%*@%