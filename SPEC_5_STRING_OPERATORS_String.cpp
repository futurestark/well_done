#define _CRT_SECURE_NO_WARNINGS  //strcpy unsafe function zatknem ee...
#include <iostream>
#include <cstring> //unasledovanui ot c dlya raboti so strokami 4tob use strlen
				   //hotya mozhno bilo napisat kopiruem simvoli poka ne naletim na 0 no
				   //vnutri strlen tozhe samoe + optimizirovano pod platformi raznie
#include "String.h"

std::istream & operator>>(std::istream &is, String &str)
{
	//soglasites mi ne mozhem s klaviaturi vvodit(iz potoka 4itat i pisat) v tot buffer kotorim se4as obladaet stroka str
	//ibo razmer buffera ograni4en a esli budet v potoke bolshe? nado razshirat razmer, vot mi tut dokonca etogo
	//delat ne budem a iz standartnoi biblioteke C++ String eto delaet(dynami4eski uveli4ivaet blockami razmer esli nado)
	//a shas v nashem zdelaem tupo
	char buf[2048];   //sozdadim bufer na 2kb vryatli user s klaviaturi v console stolko nape4ataet :)))
					  //2048 symbolov eto uzhe ves ekran perekrivaet tselekom
	//is >> buf; //iz objecta is ya mogu pro4itat buffer   fixim dlya korrektnoi zapisi v file, v maine comments
	is.getline(buf, sizeof buf); //kuda i koli4estvo simvolov
	str = buf; //a kak teper soderzhimoe bufera kuda user nape4atal peredat v &str nash??? a u nas operator = est zhe :)))
	return is;		   																//	i on pozvolyaet  prinimat massivi charov :))
}

//friend tolko v headere tut uzhe pered funciei ne pishem
std::ostream & operator<<(std::ostream &os, const String &str)  //os kak abreviatura output stream
{	//voobsheto ya v konce ne dolzhen vivodit nikakovo perehoda na novuyu stroku, a to vdrug v tsepo4ke
	os << str.s;   //ktoto zaho4et eshe 4toto dope4atat skleikoi v etu stroku a ego postoyanno perebrasivat budet
	return os; //2 stro4ki coda eti sovmestit mozhno odnoi strokoi      return os << str.s; 
}


/* CONST ILINE CONST FUNCII CLASSA,    CONST ETO TOZHE 4AST FUNCII CLASSA PRI PEREGRUZKE no tolko funcii 4lena classa 
i poetomu v classe mogut bit metodi s odnoi storoni constantnie s drugoi ne constantnie i togda
oni u4astvuyut v peregruzke drug druga i vesti sebya poraznomu //String:: ukazanie prinadlezhnosti funcii classu//*/
const char & String::operator[](int index)const  //sna4ala realizuem etu kak bolee prostuyu
{
	//dlya bezopasnogo coda vsegda vipolnyaem proverku vihoda indexa za predeli massiva !!!!!!!!!!!!!
	if(0<=index && index < n) return s[index]; 
	//ina4e nado 4et vernut tipa oshibki naprimer konec stroki return s[n]; tipa ssilka na nulevoi byte ne popal v stroku
	//				vot tebe 0, i snaruzhi udobno proveryat ne vernula li func 0, zna4it norm otrabotala
	//				sdrugoi storoni kakto eto ne o4en, nu davai virugaemsa v ecception no esli delat magkuyu obrabotku
	std::cerr << "Index out of range" << std::endl; //cerrr object kotorui v iostream predstavlyaet soobshenie ob oshibke
	return s[n];  //a mogli bi sdelat exit -1 ili abort(avarijnoe zavershenie progi)
	
	/********************************* NEBOLSHOE REZUME *************************
		Mi govorili 4to v yazike C ne kontroliruuetsa vihod za predeli massiva eto potomu 4to pri kazhdom
		a[index] compilyator dolzhen  vot takoe code pisat 
							if(0<=index && index < n) return s[index];
							std::cerr << "Index out of range" << std::endl;
							return s[n];
		nu i kak vam eto nravitsa? poetmu v C i C++ ne kotroliruetsa a esli nam samim o4 nado budem pisat vru4nuyu
	*/
} 

char & String::operator[](int index)  //teper etu kak bolee slozhnuyu  ved etot mozhet eshe i pisat(menyat stroku)
{
	if (0 <= index && index < n) return s[index];
	std::cerr << "Index out of range" << std::endl;
	//no tut uzhe nado vernut 4toto hitroe ibo lyuboe 4islo ubet nam pamyat vne massiva etim zhe 4islom,  dlya 
	// bezopastnosti mi vernem pustishku 
	static char dummy;
	dummy = '\0';
	
	return dummy;   //nelza vernut ssilku na localnuyu peremennuyu no eta static i ona  sushestvuet vsegda
}				    //esli on ee isportit bog s nei, no esli on ne pishet a 4itaet ya emu kazhdui raz
					//esli b ya tak napisal static char dummy='\0'; to on pisal bi v 100ui raz 'h' i dumal 4to vse norm
					//a tak kak tut sdelano ona garantirovano kazhdui raz nulevaya i dlya 4teniya i dlya zapisi!!!


//no vot 4tb posimvolno sravnivat nado ee zelat friend i napryamuyu brat dlya strcmp nashi chari 
bool operator==(const String &lh, const String &rh)
{	
	//no vot esli ravni nado vozvrashat true ina4e false 
	//return strcmp(lh.s, rh.s)==0; //naprimer tak ili return strcmp(lh.s, rh.s)!0; ili s ?: combinaciei

	//no vdrug dlinni strok kotoruie uzhe tam hranyatsa ne ravni 4e sravnivat posimvolno i tratit vremya?, :))) i togda 
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ POMNI PRO TO KAK RABOTAET && @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//a teper o prioritetah, prioriter operatora == vishe 4em u && operatora zna4it mozhno bez dvoinih skobok (())
	return lh.n == rh.n && strcmp(lh.s, rh.s) == 0;  //VOT ESLI SPRAVA && FALSE TOESR NE RAVNI ZNA4IT LEVOE I NE S4ITAEM 
}

//========================== LOL A OPERATOR != vugledil bi ispolzuya ==   elementarno i emu druzhba ne nuzhna :)))
bool operator!=(const String &lh, const String &rh)
{
	return !(lh == rh);   
}

//========================= LOOL TEPER posle != delaem > < =================================
bool operator>(const String &lh, const String &rh)
{
	//stroki mogut bit raznoi dlinni no stravnenie idet po pervomu nesovpadeliyu bukv a eto nam ne podhodit
	//togda tupo vot tak no ei nado dostup k .s znait tozhe friend  :)))))))))
	return strcmp(lh.s, rh.s) > 0;
}

//vot tak realizuetsa <= esli estperegruzka > 
bool operator<=(const String &lh, const String &rh)
{
	//menzhe ravno eto ved ne bolshe ei dostup k private *s ne nado ona ne friend ona usaet frienda:))))))))))))))))
	return !(lh > rh);
}


bool operator<(const String &lh, const String &rh)
{
	//levui menshe pravogo togda kogda pravui bolshe levogo :))))))))))))))))
	return rh > lh;
}

bool operator>=(const String &lh, const String &rh)
{
	//a bolshe ili ravno eto ne menshe :))))))))))))))))
	return !(lh < rh);
}

String operator+(const String &lh, const String &rh) 
{
	// TOT ZHE SAMUI SCOTT MAYERS pridumal i vvel v tradiciyu i mnogie shas tak delayut - kogda peregruzhaut 
	//bnarnui operator to levui operand obozna4at kak lhs(left hand side), prabui rhs(right hand side) ili lh rh
	   // SOZDAEM NOVUIOBJECT STRING -> nado li tak rezervirovat pamyat? char *t = new char[n + str.n + 1]; - da
	   //potom skopirovat ot lh, potom dokopirovat ot rh, no dlya togo 4tb pisat str.n str.s tak kak funciya ne 4len
	   //classa a dostup k private polyam nuzhen delaem ee FRIENDOM ibo net Get metoda 4tb dobratsa do s !!!!!!!!!
	   // NO MOZHNO OBOITIS I BEZ DRUZHBI ESLI SDELAT SLEDUYUSHIM OBRAZOM
	String t = lh;           //String t vremennaya stroka kotoraya potom umret i code budet compile ibo eto constructor
							 // copirovaniya dlya strok a on realizovan
	//t += rh;    // tozhe budet compile tak kak operator += tozhe uzhe realizovan 
	//v rezultate polu4ilsa otvet kotorui mi return  =))))))))))))))))) i bez DRUZHBI OBOSHLIS
	return t += rh;
}

String & String::operator+=(const String &str)
{
	//a kak mi dolzhni vipolnit concationation dvuh strok?
	//poskolku stroka kotoraya dolzhna polu4itsa budet ne koro4e toi 4to sleva += to na mesto a ona ne pomestitsa
	//zna4it nado vudelit novoe mesto pod novuyu stroku a+=b
	char *t = new char[n + str.n + 1];
		//zdes dolzhna bit obrabotka ecception esli pamyat ne vudelitsa(zakon4itsa u proccesa)
	strcpy(t, s);//dalshe kopiruem tuda
	strcat(t, str.s); //teper skleivaem
	//dalshe v s sohranyaem novuyu stroku udaliv staruyu
	delete[] s;
	s = t; n += str.n;  //s = t; eto nvoe zna4enie novoi stroki teper s ee addresuet i staraya osvobodilas (delete[] s;)
						// t eto vremennaya peremennaya kotoraya lezhit zdes na steke ona udalitsa i address t uzhe
						// produblirovan v s i vladeet novoi strokoi
	
	//i na posledok vozvrashaem rezultat
	return *this;
}

// a vot tut ukazivaem 4to eto ne svobodnaya func a 4len classa i daem argumentu name
String & String::operator=(const String &str)  
{						//algorithm b = a;
	//2)itak on dolzhen osvobodit tu pamyat kotoroi vladel object sleva(b)
	//3)sdelat novui ekzemplyar toi pamyati kotoroi vladeet object sprava(a)
	//4)i podarit ee vo vladeniya objectu sleva(b)
    //1)!!!!! I 4TOB NEBILO UTE4KI NADO OSVOBODIT TO 4EM VLADEL OBJECT KOGDA DLYA NEGO VIZVALI PRISVAIVANIE

	//----------- 0) Delaem zashitu ot samoprisvaivaniya potom zakomentit 4tob porzhat i ubeditsa---
	/*				if(*this == str) 
	sleva u nas *this sprava str mozhem li mi ih sravnit == ?? otvet net
	ved class string v dushe ne grebet kak sravnivat svoi objecti -> delaem peregruzku == operatora
	ved sleva i sprava u nas String vot compi i is4et funciyu operator== a ee netu i error
		no mi mozhem sravnit dva objecta po adressam a ne zna4eniyam
		vmesto if(*this == str) napisat if(this == &str) ved esli 2 objecta lezhat po odnomu addressu
		i imeyut odinakovui type to navernoe mi imeem delo samim s soboi.
	Kstate proverka na zna4enie Stringov if(*this == str) ne obyazatelno pokazhet 4to eto tot zhe samui
	eto mozhet zaprosto bit copiya po drugomu addressu !!!!!!!!!!!! MISL PONYATNA?? b=b; i b=a; davalo bi
	istinnu esli bi sravnivali po zna4eniyu i peregruzili operator== ...
	*/
	if (this == &str)
	{
		return *this; //esli sovpali ni4ego delat ne nado nado vernut to4to bilo
	} 
	//a ina4e delaem vse kak bilo
	//----------------------------------------------------------------------------------------------
	delete[] s;
	n = str.n;   //eto podobno tomu kak v constructre copirovaniya
	s = new char[n + 1]; //eto podobno tomu kak v constructre copirovaniya
	strcpy(s, str.s);  //i potom mu tuda kopiruem tu stroku kotoroi vladeet object sprava ot = (a)
	//no est eshe odno otli4ie ot constructora copy, pervoe eto delete[] s; a vtoroe eto vozvrat 
	//rezultata prisvaivaniya toest stroki (vozvrashaem samogo sebya)
	return *this; //mi dolzhni vernut object a this eto ukazatel razimenovanui/razaddresovanui
	//VOT GLAVNIM OBRAZOM STROUSTRUP nam dal this v ruki 4tob eto mogli pisat
}

String::String(const char *str) //zdes v tele uzhe ne ukazivaetsa zna4enie po umol4aniyu(ono tolko v headere prototipa)
{
	n = strlen(str);  //izmeril stroku teper znayu skolko nado byte videlit dynami4eski
	
	//rezerviruyu pri pomoshi new dlya tipa char pos4itanui n + 1 nulevoi byte kotorui ne vhodit po umol4aniyu
	s = new char[n + 1]; 

	//zdes v realnih zada4ah dolzhna bit obrabotka oshibok (ecception handler)
	//tak kak v nashem prostom slu4ae dlya nebolshih stro pamyat vsegda naidetsa no v realnoi zada4e
	//stroki mogut bit o4en bolshie i pamyati mozhet ne okazatsa svobodnoi ot imeni os dlya nashego processa
	//OSOBENNO V NOVOM STANDARTE SE4AS new vizivaet isklu4enie obrabotku kotorogo nado napisat a rasnhe prosto nulevoi ukazatel return

	//esli pamyat vudelilas to mi mozhem skopirovat v videlennui block dynam mem te bukovki kotorie mi polu4ili snaruzhi kak argument !!!!!!!
	strcpy(s, str);
	//vot i ves construktor 3 in 1 :))  a raz new zna4it v destructore nado delete[] a destructor by default kotorui napishet
	//   compilyator ni4ego podobnogo ne sdelaet i budet ve4naya ute4ka pamyati pri udlalenii objectov String !!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
}

//------------------------- CONTRUCTOR GLUBOKOVO COPIROVANIYA -----------------
String::String(const String &str)
{
	n = str.n;  //n = strlen(str); izmeryat uzhe ne nado mi mozhem prosto vzat i vitashit
	s = new char[n + 1];  //goditsa

	// copirovanie strcpy(s, str); ne goditsa potomu kak nash String eto str.s
	strcpy(s, str.s);  //hot s private no mi to svoi :)) !!!! tak zhe kak i n vishe i vse okkkk
}

//A ZNA4IT ESLI MI V CLASSE SAMI ZAHVATIVALI RESURSI TO MI OBYAZANI PEREOPREDELIT DESTRUCTOR 4TOB NE UTEKALA PAMYAT PRI UDALENII OBJECTA
String::~String() 
{
	delete[] s; //[] potomu 4to new tozhe imel [] !!!!!!!
}

void String::Print()const
{
	std::cout << s;
}