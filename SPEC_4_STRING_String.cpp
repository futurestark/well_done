#define _CRT_SECURE_NO_WARNINGS  //strcpy unsafe function zatknem ee...
#include <iostream>
#include <cstring> //unasledovanui ot c dlya raboti so strokami 4tob use strlen
				   //hotya mozhno bilo napisat kopiruem simvoli poka ne naletim na 0 no
				   //vnutri strlen tozhe samoe + optimizirovano pod platformi raznie
#include "String.h"

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