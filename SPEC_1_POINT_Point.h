#pragma once
//SODERZHIT OPREDELENIE CLASSA POINT

class Point
{
private:
	int x, y;

public:
	//int GetX() { return x; } x(private) no mu imeem delos s (returned int) GetX a ono public
	int GetX() { return x; } //inline po umolchaniyu pisat ne nado ibo vnutri classa(esli vne to nado!!))
		// !!!inline delaet tozhe 4to i define v GetX budet prosto podstavleno x a ne vizov funcii potom return 
		// x i tak dalee a prosto srazu dadut x na polzuisya) polnui analog #define s argumentami prosto opisanie 
		// ne o4evidno ne znaya 4to pod kapotom @@ (a esli bi bilo return x + y ili return 2x to v UsePoint.h a.GetX
		// poevilos bi srazu 2x ili x+y samo virazhenie :))) no ne vse func mozhno vstraivat osobenno bolshie
	int GetY();   //ee bolshoe telo vstroeno v header nizhe no v classe skaza 4to takaya func est nado
	void SetX(int); // tela v Point.cpp
	void SetY(int); // void SetY(int _y); _y informativnosti ne dobavit
	//SET GET(motedi dostupa/Accesori) obrazuyut min nabor classa
	//a pro4ie metodi povishaut udobstvo clienta (print, move etc no ih ne dolzhno bit 100 shtuk 4itat zamu4aesya)
					//esli 100 metodov nado razdeli ih na classi po logike promeneniya @@@!!!!!
	
	void Move(int delta_x, int delta_y);  //move absolutnui(v to4ku kuda nado) i otnositelnui(na skolko px ot tekushego mesta)
		       // PEREGRUZIM IH ili dadim imena AbsMove RelMove a lutshe nazovem ponyatno args funcii (raz delta_x zna4it priroshenie(RelMove))
	void Print();  
	//@@@@@@@@@@@@!!! void Move(int delta_x, int delta_y); imena args v headere i v cpp realizacii mogut ne sovpadat i voobshe otsutstvovat
	// SLEDUET V .H pisat podrobnie imena argumentov 4tob clien 4itaushij headrer vse ponyal a v .CPP sokrashat v tele funcii programmista 
};

//int GetY() { return y; }  eto kakayato func GetY a mne nado chlen classa
inline int Point::GetY() { return y; } 
//CLASSIKI GOVORYAT: ne pishite inline nekogda za isklu4eniem malenkih funcii a ih mogno i v classe vstroit bez
	//slova inline a vot kogda proga gotova berete profilirovshik i stavite inline funcciyam kotoruie siedaut
	//bolshe vsego vremeni i smotrite s inline lutshe ili huzhe stalo, a esli tut snyat inline a tut postavit etc only experimentalno