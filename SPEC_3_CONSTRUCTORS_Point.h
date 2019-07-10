#pragma once

class Point //v pustom classe Point {}; 6 metodov kotorie pri neobhodimosti napishet compilyator
{
	int x, y;
    void Print()const;
public:
	Point(const Point &); //eto constructor kotorui sozdaet odin object Point iz drugogo objecta Point
						  //@@@ constructor kopirovaniya zanesem ego telo v Point.cpp
	Point(); //davai v constructore prisvoim objectu korrectnie na4alnie zna4eniya (@@@ constr po umol4aniyu)

	// @@@@ CONSTRUCTOR MOZHNA PEREGRUZHAT 4TOB NAPRIMER SOZDAT OBJ TO4KU NA PLOSKOSTI SRAZU V NUZHNOI KOORDINATE!!!!!
	Point(int, int); //PEREGRUZKA ili zhe parametri4eskij constructor ili polnoi inicializacii (@@ POLNUI "ARGUMENTOV" CONSTRUCTOR)
	
	//explicit Point(int);
    Point(int); // eshe peregruzim teper s odnim arg @@ CONSTRUCTOR PREOBRAZOVANIYA - preobrazuet zna4enie tipa int v tip Point
	            // sozdaet iz int Point tolko emu nado opisat kak eto sdelat


	//------------------- zakomentiruyu meshaet tem trem on zhe ih zamenitel --------------------------
	//@@ vmesto Point(); Point(int); Point(int, int);  etih teh constructorov ya mog bi sozdat odin vot takoi
	//Point(int = 0, int = 0); //nebudet arg compi postavit 0-0, budet 1 vtoroi budet 0; @@@@@ 
	                         // 3 V ODNOM FLACONE (constr by def + constr preobrazovaniya + constr polnui)
	//-------------------------------------------------------------------------------------------------
	~Point(); //destructor ~otricanie pobitovoe - razrushenie vse v 0)
};

/*
    //explicit 
	Point(int);   udobno tak dobavili zakomentili ubralos raskomentili snova na KRUTOE FORMANIROVANIE !!!
*/