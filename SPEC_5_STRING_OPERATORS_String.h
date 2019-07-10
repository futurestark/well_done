#pragma once

class String   //s malenkoi string bibliote4nui class 4tob ne konfliktovalo
{
	//--------------- a sozdavatsa stroka budet construktorom ----------------
public: 

	
//operator vivoda v potok i 4teniya peregruzheni dlya tipov private: char *s; no dostupa k polyu net zna4it delaem friendom !!!!
//mozhno bilo bi oboitis bez druzhbi esli vizivat Print()const etogo classa no nam interestno zdelat kak polozheno
//est v std ostream class vihodnih potokov i object cout prenadlezhit kakraz etomu classu i recomenduetsa esli mi
//v headere ssilaemsa na 4to libo iz standartnogo prostranstva imen tam v .cpp faile classa napishem using namespace std;
//pered include <String.h> vse skompilitsa posle uzhe net tak kak String.h sobiraetsa v sostave String.cpp v edinui object
//poetomu 4tob ne pisat using i ne narivatsa na oshibki vsegda pishem standartnie prostranstva polnostyu  std::ostream &,
// a ne  ostream &, v slu4ae eslib using namespace std; shel v String.cpp posle #include <iostream> no pered 
// #include <String.h 4to samo po sebe ne privi4no i sdelat oshibku raz dva !!!!!!!!!!!!!!!!!!!!!!!!
// a return dolzhen etot operator snova svoi perui argument 4tob oni mogli stseplyatsa v tsepo4ki kak cout << a << b << endl;
	friend std::ostream & operator<<(std::ostream &, const String &);
	
	//vtoroi drugom ne obyazan yavlyatsa >>


	//peregruznaem dlya sravneniya strok operator == , a po4emu ne 4len classa == a 4tob iz neyavnih privedenij mozhno
	//bilo bi delat sravneniya String i massivov charov kak sleva tak i sprava(tozhe obespe4enie simetrii)!!! no vot ee uzhe 
	// nado sdelat drugom poetomu peretaskivaem v public razdel classa
	friend bool operator==(const String &, const String &);

	//SMOTRI CPP tam rzhaka kak eto vse prosto 2 frienda ostalnue prosto ih vizivaut v sebe :))))
	friend bool operator>(const String &lh, const String &rh);


	//=================== peregruzim indexirovanie kak 4len classa ibo po drugomu nelza
	//char operator[](int);   // nu a hrena tak on i dolzhen vugledit, a vot net tak on budet brat kopiyu govorit nam 
							//hotite portite hotite net a original ostanetsa kak bil, vot i vozvrashaem ssilku
	char & operator[](int); //eto ponyatno?))) no na etom primere eshe vidno 4to esli u nas pomeshaetsa vnutr funcii 
							//constantnaya ssilka const String &(dlya effectivnosti) a vnutri ya ho4u pervuyu bukovku 
							//dostat dlya nee etot operator vipolnitsa ili net? - net ibo eto mozhet narushit constantnost
							//zna4it prijdetsa zdelat tve realizacii odna obi4naya vtoraya const(ved mozhet i ne budem menyat)
							// pervaya char & operator[](int);   vtoraya char & operator[](int)const; no teper pervaya ne 
							//budet compile ved' mi govorim s odnoi storoni vot vam const s drugoi vot vam return ssilka 4erez
							//kotoruyu mozhna menyat i esli obe realizacii est to code compile ne budet
							// A VOT TAK BUDET !!!!!!!!!!!!!!!
	const char & operator[](int)const; /*&#$&#$^#&^#&$^&^$&#^&$&#$#^  VNIMANIE %%%%%%%%%%%%%%%%%%%%
									    VOT DVE FUNCII			char & operator[](int);
															    const char & operator[](int)const;
								       u nih imena odinakovie? -da zna4it oni peregruzhennie, u nih argumenta odinakovie? - da 
									   a peregruzka tut postroenna na(vozvrashaemoe zna4enie ne mozhet u4astvovat v peregruzke
									   tak kak v virazhenii nelza ukazat kakoe zna4enie mi polu4aem) OKAZIVAETSA CONST ILI
									   NE CONST FUNCII CLASSA CONST ETO TOZHE 4AST FUNCII CLASSA PRI PEREGRUZKE i poetomu
									   v classe mogut bit metodi s odnoi storoni constantnie s drugoi ne constantnie i togda
									   oni u4astvuyut v peregruzke drug druga i vesti sebya poraznomu
									   */


		//po analogii tozhe 4len classa i mi smozhem delat a = a + b; i a = a + "Billy Bonce";
		//                           a mozhet mi eshe i tak bi hoteli a = "Billy Bonce" + b;
	//String & operator+(const String &);   A VOT NET 4TOB OBESPE4IT SIMETRIYU UBERAEM S CLASSA I DELAEM SVOBODNOI
		// I DELAEM DVA ARGUMENTA TIPA STRING String & operator+(const String &, const String &); LEVUI I PRAVUI OPERAND
	    //String & operator+ eto ssilka na 4to?? NA LEVUI OPERAND ? - NET, NA PRAVUI? - NET eto ssilka na localnui object
		//kotorui umret kogda funciya zavershitsa a zna4it peredaem po zna4eniyu putem copyrovaniya a ne po ssilke !!!!!!!
												//String operator+(const String &, const String &);

		//recomendation =+ sleduet realizovitavat podobno = operatoru a on 4len classa
	String & operator+=(const String &);

	String & operator=(const String &);// = ne mozhet bit svobodnoi func,ee argument - drugoi object 
	//etogo zhe classa, za4em po ssilke - dlya effectivnosti, no v otli4ii ot constructora
 //operator prisvaivaniya eto funciya kotoraya vozvrashaet zna4enie dlya dalneishih vu4islenij
   //kakoi type? - String, kak vozvrashaet? - po ssilke &. Vot obi4naya signatura operatora =
   //mozhno bilo bi ubrat const i & no v lubom slu4ae eta func govorit ya prinimayu object type String!!
   //no tut u nas ssilka lya effectivnosti a const 4tob ne isportili object

	String(const char *str ="");  //const potomu 4to mi ne izmenyaem stroku kogda kopiruem v sebya
	                              // v prototipe String(const char *str =""); i String(const char * =""); odno i tozhe 
								  // prosto bez imeni argumenta ili s imenem a vot v .cpp pisat 100% nado tak go pisat vezde
	
	//constructor copirovaniya i zdes principialno 4to argument peredaetsa po ssilke &, i esli ssilku ubrat to on dolzhen
	//		peredavatsa kak copiya no 4tob sozdat sam sebya kak copiyu vizivaet copiyu i GLUBO4aISHAYA RECURSIYA POLU4ITSA 4TO BRED
	//ssilka na constantnui String
	String(const String &);

	~String();  //A ZNA4IT ESLI MI V CLASSE SAMI ZAHVATIVALI RESURSI TO MI OBYAZANI PEREOPREDELIT DESTRUCTOR 4TOB NE UTEKALA PAMYAT PRI UDALENII OBJECTA
				// CONSTRUCTORI V CLASSE MOZHNO PEREGRUZHAT A DESTRUCTORI NE RAZRESHAETSA !!!
				//rozhdatsa objecti mogut na domu v roddome v samolete(constructorov mnogo mozhet bit) a umiraut vse odinakovo kontrolnui v golovu(destructor odin)
	
	//dobavim paru poleznih funcij
	//Kstate Len polnui analog Get() a Set() v etom classe net tolko 1 accesor i tak bivaet
	int  Len()const { return n; }    //vot sdelali etu krohu inline :)
	void Print()const;   //oni const(horoshui tone) tak kak ne izmenyaut object i Len i Print

private:
	char *s;  //a zna4it v classe nado ukazatel na dynam memory 
	//mozhno kazhdui raz izmeryat dlinnu stroki(strlen()) no lutshe hranit v stroke ee dlinnu(pozhertvovat neskolko byte)
	int n; //no lutshe bilo bi type size_t i include <cstdlib>
	
};

String operator+(const String &, const String &);
bool operator!=(const String &lh, const String &rh);
bool operator<=(const String &lh, const String &rh);
bool operator>=(const String &lh, const String &rh);
bool operator<(const String &lh, const String &rh);
//vot teper so strokami mozhem delat vse 4to zahotim :)))

//NU I VVOD V POTOK NE BUDET DRUGOM IBO ETO NE OBYAZATELNO
 std::istream & operator>>(std::istream &, String &);//nu i poskolku pishem v stroku vtoroi argument bez const, prosto String   

/*   --------------- ITOG DLYA NASHEGO CLASSA MI VINUZHDENI BILI REALIZOVAT TE 4 FUNCII ----------
				    KOTORIE OBI4NO 4ASTO PISHET COMPILYATOR SAM (SPECIALNIE METODI CLASSA)

		String & operator=(const String &);		operator prisvaivaniya =
		String(const char * ="");				constructor copyrovaniya
		String(const String &);					constructor umolchaniya (default)
		~String();								destructor 

	         i ne odna iz nih kotorue napisal bi nam compilyator nas ne ustraivala		
		
		nikogda vmesto operatora prisvaivniya constructor copii ne vizivaetsa eto raznie mehanizmi !!!!!
		v b=a; new netu vnutri(kotoroe iz a delaet copiyu i nazivaet ee b) a tut prosto perepis pole v pole

		i v pustom classe vseravno est eti 4 specialnih methoda classa kotorie napishet potom compi

*/
