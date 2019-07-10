#pragma once

class String   //s malenkoi string bibliote4nui class 4tob ne konfliktovalo
{
	//nash string eto massiv charov kotorui zakan4ivaetsa nulevim bytom
	//  u nas budut stroki peremennoi dlinni ane 255 naprimer i budut zanimat v pamyati 
	//  stolko skolko im nado(toest dinami4eski)

	//--------------- a sozdavatsa stroka budet construktorom ----------------
public: 
	String(const char * ="");  //const potomu 4to mi ne izmenyaem stroku kogda kopiruem v sebya
			//i mozhem dazhe dat umol4anie pustaya stroka "" no tolko esli upuskaem imya
			//formalnogo argumenta to tolzhen bit hot odin probel * =""  ina4e *= vosprinimaetsa kak umnozhit i prisvoit
			//ili (const char *str=""); togda ne voznikaet voprosov nu napishem imya vmesto (const char * ="");
			// a esli napishem (const char *str=0); to eto sovsem drugoe eto nulevoi ukazatel i eto ne est pustaya stroka !!!!
			//Mi napisali zna4enie po umol4aniyu pustaya stroka i teper constructor mozhet vizivatsa bez argumentov i togda on budet by default
			//A mozhet vizivatsa s argumentom i togda mi proinicializiruem dva polya char*s i int n. tem samim parametri4eski 
	        //A s tretei storoni u nego odin edinstvennui arg ego type const char* ne otnositsa k type nashego classa String a sozdaet
			//nash class i v etom smisle on eshe i constructor preobrazovaniya vihodit etot constructor 3 in 1 kak shampun ego telo v String.cpp
	
	//constructor copirovaniya i zdes principialno 4to argument peredaetsa po ssilke &, i esli ssilku ubrat to on dolzhen
	//		peredavatsa kak copiya no 4tob sozdat sam sebya kak copiyu vizivaet copiyu i GLUBO4aISHAYA RECURSIYA POLU4ITSA 4TO BRED
	//ssilka na constantnui String
	String(const String &);

	~String();  //A ZNA4IT ESLI MI V CLASSE SAMI ZAHVATIVALI RESURSI TO MI OBYAZANI PEREOPREDELIT DESTRUCTOR 4TOB NE UTEKALA PAMYAT PRI UDALENII OBJECTA
				// CONSTRUCTORI V CLASSE MOZHNO PEREGRUZHAT A DESTRUCTORI NE RAZRESHAETSA !!!
				//rozhdatsa objecti mogut na domu v roddome v samolete(constructorov mnogo mozhet bit) a umiraut vse odinakovo kontrolnui v golovu(destructor odin)
	
	//dobavim paru poleznih funcij
	int  Len()const { return n; }    //vot sdelali etu krohu inline :)
	void Print()const;   //oni const(horoshui tone) tak kak ne izmenyaut object i Len i Print

private:
	char *s;  //a zna4it v classe nado ukazatel na dynam memory 
	//mozhno kazhdui raz izmeryat dlinnu stroki(strlen()) no lutshe hranit v stroke ee dlinnu(pozhertvovat neskolko byte)
	int n; //no lutshe bilo bi type size_t i include <cstdlib>
	
};
/* ----------------- ITOG v classe kotorui vladeet ukazatelem na resurs char *s;  ---------
			dolzhen bit sobstvennui destructor kotorui osvobozhdaet etot resurs i 
			i sobstvennui constructor copirovaniya 4to bi izbezhat neskolkih ssilok
			na etot odin resurs i mnogokratnogo ego osvobozhdeniya...
*/