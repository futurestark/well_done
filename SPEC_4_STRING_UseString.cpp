#include <iostream>
#include "String.h"
//using namespace std;   ploho pisat ibo gde use funciya moya s std mogut zabit using 


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

	//=================== sozdadim eshe odnu stroku(strategy glubokoe copirovanie) ==================
	//proga compile, i dazhe zapuskaetsa no v runtime 4to za polu4i fashist granatu????
	//eto zna4it 4to v otlado4nom variante bil podklu4en code kotorui nas poimal a v release proshlo bi mol4a
	//no problema ostanetsa to i roblema 4to on ne vizivaet nash constructor tak kak dolzhen bit ukazatel na char,
	//a emu podsunuli String i zna4it on budet vizivat construktor copirovaniya, tut u nas i a i b type String(odin sozdaetsa iz drugovo zna4it constr copy)
	//no mi to ne napisali contr copy a compile ibo etot constr pishet compilyator no eta ego usluga medvezhya
	
	//a smisl v tom(PICTURE STRING COPY) 4to b=a vse polya objecta a skopirovalis v polya objecta b, kotorui tozhe na steke no b, v rezultate
	//teper object b i a sovmestno ukazivaut na odin block pamyati v ku4e i kogda dohodit do delete to ploho tem 4to kogda dohodim do konca main{} to v poryadke obratnom
	//sozdaniya vizivautsa destructori, destructor b rabotaet pervim i osvobozhdaet Hello World v heap i potom so steka sletaet posle etogo
	//delo dohodit do objecta a i on na4inaet povtorno osvobozhdat uzhe osvobozhdennuyu pamyat, otlad4ik i slovil nas a tak bi ne upalo i upalo kogdato potom v release
	//medvezhya usluga ne goditsa pishem svoi constr copy i on dolzhen sozdavat novuyu stroku vsego navsego :) dlya etogo sozdat v pamyati kopiyu i ukazatel svoi nastroit tuda
	//i teper kazhdui otve4aet za svoi block mem(STRING_COPY_3) i eto strategy glubokovo copirovaniya, a to 4to napisal compilator pole v pole eto poverhnosnoe copirovanie
	//nas ustraivaet poverhnosnoe copirovanie tolko esli u nas v classe net ukazatelei ili ssilok na vneshnie resursi !!!!!!!!!!!!!!!!!!!
	// a esli est zahva4ivaemie resursi to ono dubliruet ssilki i privodit k dvoinomu troinomu etc udaleniyu...
	String b = a;  //ili String b(a);
	std::cout << "String b: \"";
	b.Print();
	std::cout << "\", Len=" << b.Len() << std::endl;
	//================================================================

	/*   a posle sozdanoi copii 4erez constr copirovaniya pri prisvoenii snova polu4i fashist granatu!
		 tut eto operator prisvaivaniya i nado ego peregruzit v sled LESSONE 
	A probema prisvaivaniya v nashem primere PICTURE_STRING_PRISVAIVANIE v tom 4to kogda mu prisvaivaem 
	iz a vse zna4eniya v b, to ukazatel teper pokazivaet na Hello World a, tak kak ukazatel skopirovalsya 
	a construcktorom kopirovaniya sozdalas novaya kopiya i ukazatel na nee navsegda teper poteryan !!!!
	malo togo 4to u nas dvoinaya ssilka iz a i b na din i tot zhe Hello World pri operatore prisvaivniya no i
	navsegda poteryan address ukazatelya na novuyu stroku kopii b i o4istit ee navsegda nekomu --- UTE4KA
	sled lesson peregruzka operatorov v4asnosti prisvaivaniya 4tob korrektno osvobodit block kotorim mi vladeem, 
	sdelat korrektno kopiyu zna4eniy i na nee soslatsa krome togo peregruzit operator sravnenie strok, konkatenaciya, etc...
		^^ neploho bi bilo dobavim v sled less  vzat stroku a[0] = 'M'; dobratsa do 0 elementa i pomenyat ego, peregruzit dlya indeksirovaniya 
	b = a;                           
	std::cout << "String b: \"";
	b.Print();
	std::cout << "\", Len=" << b.Len() << std::endl;
	*/

	//SOZDAM STROKU V DYNAM MEM(HEAPE)
	String *p = new String("Good Bye!"); //napisali new pishem i delete(a destructor s [] vse pravilno sdelaet)
	std::cout << "String in heap: \"";
	p->Print();							// tut vezde ne a.Print() a p->Print()
	std::cout << "\", Len=" << p->Len() << std::endl;  
	delete p; //napisali new pishem i delete(a destructor s [] vse pravilno sdelaet)

	/*  ------------- String in mem picture --------------------------
			u ya4eek char *s; int n; esli sozdali v stacke est name a.
			a esli v heape to imeni netu i dostup 4erez ->,

		Est raznie sposobi 4tob zamenit poverhnosnoe copirovanie na 4toto bolee menee prili4noe
		1)Strategy - sdelat copiyu togo 4em vladeet original i podarit ego copii(copii podarit copiyu stroki)
					 puskai zavladeet svoim i osvobozhdaet sebya(glubokoe kopirovanie)
		
		2)Strategy s pos4etom ssilok, kogda proizvoditsa copirovanie to delautsa copii ukazatelei a stroka 
					stroka ostaetsa odna(v odnom ekzemplyare), 4asto copii delaut 4tob 4toto raspe4atat, kudato otpravit
					sohranit voobshem ne modificirovat, i togda puskai na odnu stro4ku pokazivaut tolko osvobozhdenie
					pamyati tut modificiruetsa, kazhdoe copirovanie s4et4ik ssilok na etu peremennuyu uveli4ivaetsa
					a kazhdoe udalenie s4et4ik ssilok umenshaet, i delete vizivaetsa tolko togda kogda s4et4ik stal 0.
					no togda nado v object vstroit pos4et ssilok, v JAVA C# .NET etu problemu pods4eta ssilok 
					reshaet sborshik musora(specialnui potok kotorui hodit i smotrit a 4to tam v dynam mem proishodit est
					li tam objecti kotorue uzhe ne use counter_ssilok == 0?, udlalyaet posle etoko ku4a dirok v pamyati
					a zna4it nado opyat memory styanut - sdelat defragmentaciyu sobrat vmeste podryad zanyatie blocki pamyati
					no eto ved kakie tormoza :))))) zato potom on mozhet vudelit bolshue blocks memory esli nam nado budet
		KSTATE U NAS ESLI bi peretaskivali b=a to malo sdvinut v pamyati nado eshe peredat vse ssilki na b i na a, ne tolko 
		koli4estvo ssilok no i ih samih a zna4it pri kopirovanii blocka nado poiti i vse ssilki kotorie na nego ssilalis tozhe 
		otkorektirovat poetomu i govorat 4etko kogda est sborshik musora no vsegda li eto dopustimo...
				EST C++ KNIGI GDE OPISANO KAK SOZDAT SAMOMU SBORSHIK MUSORA NO SAM ON V YAZIK NE VSTROEN !!!!!

		3)Strategy s pereda4ei prava vladeniya naprimer esli Hello World vladeet object a, to esli on copiruetsa v b,
					pravo vladeniya perehodit v b, i v a ssilka obnulyaetsa on poteryal pravo vladeniya, i polu4aetsa poslenij
					kto polu4il tot za block pamyati i otve4aet on pro nee znaet a ostalnie vse zabuli i on etu memory i osvobozhdaet

		4)Strategy eshe odna hitraya - delaetsa pods4et ssilok i vse pokazivaut v odnu pamyat, no esli ya izmenu Hello World 4erez odnu
					iz ssilok to drue to tozhe polu4at izmenennui Hello World, i delaut tak block mem Hello World s4itaetsa const i kogda
					odna iz ssilok ho4et izmenit ei tut zhe na letu sozdaetsa personalnaya copiya blocka mem s Hello World i puskai
					on delaet s nei vse 4to ho4et, i osvobozhdaet ee.

	    O4en slozhno organizovat glubokoe copirovanie esli v dynam mem lezhat ne prosto Hello World a objecti kotorie dalshe ukazivaut gde
		lezhit Hello World a tam eshe ukazateli resurs Hello World, a inogda bivaut cycli4eskie ssilki drug na druga i kak togda kopirovat vse
		i osvobozhdat?? 
	*/
	system("Pause");
}