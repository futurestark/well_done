#pragma once
/*
//================================ IN PREVIOUS LESSEON ==================================
	obi4no s4et4ik ssilok v samom objecte ne hranyat a delayut obvertku k etomu inogda
	dazhe delayut specialnui class kotorui obleg4aet pods4et ssilok
	-------------- KNIGA SCOTT MAYERS effectivnoe programmirovanie C++ -------------
	-------------- on zhe 55 sovetov kak ulutshit effectivnost vashei programmi ----
	-- KNIGI SCOTTA MAYERSA srazu 4itt posle kursa C++!!!!!!!!!
	--- BJERN STRAUSTRUP posle scotta mayersa eto 3ui lvl osvoeniya C++

	##Poskolku nash class String vladeet sistemnimi resursami pri4em mi sistemie resursi 
		addresuem pri pomoshi ukazatelya standartnui constructor kotorui pishet compilyator ne
		podhodit(poverhnosnogo kopirovaniya), i voznikaut problemi mnogokratnogo udaleniya
		odnogo objecta, poetomu mi napisali sobstvennui constructor glubokogo copirovaniya,
		kotorui sozdaet kopiyu stroki kotorui vladeet object i togda u kazhdogo svoya kopiya i
		kazhdui za svoei sledit modificiruet i udlyaet. No Strategei mnogo i glubokoe ne vsegda
		horosho. 
			Naprimer ono mozhet bit tehni4eski slozhnim(ne prosto massiv kak u nas a eshe
		objekti u kotorih ssilki dalshe vplot do cycli4eskih), vovtorih nash object ne stol 
		velik a esli b vladeli bolshim objectom kopirovanie kotorih bi zanimalo mnogo vremeni
		to kazhdui raz kopirovat vozmozhno i ne stoilo bi ved o4en 4asto kopii delayut 4tob 
		ih izmenyat, a esli pe4atat sohranyat otsilat to kzhdui raz kopirovat ne effectivno.
		Dlya podobnih slu4aev lutshe strategiya s pods4etom ssilok. I dalshe modificaciya poka
		objecti ne hotyat izmenit kopiyu oni vse vladeyut odnoi a esli ho4et to emu nemedlenno
		sozdaetsa ego personalnaya kopiya nad kotoroi on budet izdevatsa.

 ^^^ A dalshe mi viyasnili 4to b=a;  prisvaivanie malo togo 4to sozdaet 2 ssilki na odin resurs
	 tak eshe i propadaet/teryaetsa navsegda resurs togo objecta kotorui sleva ot prisvaivaniya
	 i poetomu obshee pravilo takoe ---- Esli vam prihoditsa pisat sobstvennui variant constr
	 copirovaniya to obi4no prihoditsa pisat i sobstvennui variant operatora prisvaivaniya
	 i naoborot poskolku oni delayut shozhuyu rabotu.]
//==========================================================================================

		4tob napisat sobstvennuyu versiyu operatora prisvaivaniya mi dolzhni ego pereopredelit/
		peregruzit.
	&&& PEREGRUZKA OPERATOROV SOVSEM NE YAVLYAETSA OBYAZATELNIM SVOISTVOM OOP yazikov, 
		podavlyaushie bolshinstvo yazikov ne imeyut takoi vozmozhnosti, a vot STROUSTRUP
		podaril nam takuyu vozmozhnost povedeniya operatorov dlya teh tipov dannih kotorie mi
		sozdaem(v drugih yazikah gde est garbagge collector takoi problemi net, tam progeri 
		pamyatyu ne upravlyaut) i eto pozvolyaet nam koro4e pisat code i o4en 4asto ponyatnee&&

		Predstavim sebe 4to u nas est class compelxnih 4isel
		class my_complex
		{
				....
		public:
			Add(...);
			Sub(...);
			Mul(...);
			Div(...);
			Assign(...);   prisvaivanie 
		};		 
		i ya ho4u sozdav neskolko objectov complexnih 4isel vu4islit formulu
		my_complex a,b,c,d,e;     
		
		e = (a+b) * (c-d);   i takie vu4isleniya dlya etogo classa imeyut bolshoi smisl on 
		
		dlya etogo i pishetsa no operatori eti ne peregruzheni zato imeutsa imenovanie funcii.
		I pri pomoshi etih funcii napisat etu formulu polnui zashkvar no v drugih yazikah pishut
		    
			e.Assign((a.Add(b)).Mul(c.Sub(d)));  dobavim eshe div i uzhe napisat slozhnovato
		
		No esli est peregruzka a v C++ est to etu formulu pishem kak est pri4em ee proshe 
			ponyat i menshe oshibok. Stroustrup pozvolil nam estestvennim obrazom vstroit v
			yazik novie type kotorie mi razrabativaem i sdelat operacii raboti s nimi 
			neotli4imimi ot podobnih operaciy nad vstroennimi types !!!!!!!!!!!!!!!
		Eto ne sredstvo OOP a sredstvo vstraivaniya svoih novih tipov v yazik dlya mega prostogo
			ih vzaimodeistviya kak vzaimodeistvoyut vstroennie data types. Tak kak eto novui
			data type to bez peregruzok polzovatsa im o4en slozhno i prihoditsa pisat takie 
			virazheniya kak e.Assign((a.Add(b)).Mul(c.Sub(d))); A s peregruzkoi e = (a+b) * (c-d);
//===========================================================================================

	NELZA PEREGRUZHAT OPERATOR DLYA VSTROENNIH TIPOV !!!!!!!!!!!!!!!!!!!!!!!!!!!!!
%%%	In C 47 operatorov v CPP oni unasledovani plus new, delete, etc  itogo gdeto 60
		%%%%%% PEREGRUZHAT NE RAZRESHAETSA SLED OPERATORI %%%%%%%%%%%%%%%%%%%%%%%%
	1)	.(dostup k 4lenu classa a ina4e kak vizivat metodi esli . budet ozna4at 4toto drugoe)
	2)	.*(razimenovanie ukazatelei na 4leni classa, sna4ala zaberemsa v object classa a
			potom ego razimenuem)
	3)	:: (ne v unarnom ne v binarnom formate a ina4e kak skazat 4to funciya 4len classa)
	4)	?: (uslovnui esli to, ibo on ternarnui a peregruzhat mozhno unarnie i binarnie)
	5)	sizeof (vopervih object ne smozhet znat o svoem razmere, a na samom dele eto
			edinstvennui operator kotorui na etape compilyacii vu4islyaetsa i vo vremya
			raboti programmi ego uzhe ne pomenyaesh)
	6)	ZAPRESHAETSA PEREGRUZHAT LUBOI IZ NOVIH OPERATOROV PRIVEDENIYA TIPOV
		..._cast<>()   (static_cast, dynamic_cast, reiteprint_cast, const_cast) 
	7)  typeid()	

	~~~~~~~ I EST OPREDELENNIE OGRANI4ENIYA PRI PEREGRUZKE OPERATOROV ~~~~~~~~ 
	1) Mi ne mozhem izmnit ih povedenie dlya vstroennih tipov, esli + to on dolzhen
		rabotat kak + no s moimi data types.
	2) Nelza izmenit arnost operatorov esli unarnui to i dlya moih dolzhen rabotat
		kak unarnui binarnui ostaetsa binarnim
	3) Nelza izmenit prioritet i associativnost peregruzhaemih operatorov.
		umnozhit pribavit takoi zhe poryadok vu4isleniya kak i dlya intov naprimer
		i vse prisvaivaniya, incrementi etc. smotri tablicu C.
	4) Nelza pridumat novuyu leksemu dlya obozna4eniya operatora kotoroi nebilo v yazike.
		Stradalci s basica o4en perezhivayut 4to net operatora vozvedeniya v stepen i pervoe
		4to prihodit im v golovu ya sdelayu etot operator.
		No esli int a i b, to nelza dlya vstroennih tipov peregruzit operator, a ya govorit 
		sozdam class Int a, b, c; i peregruzhu ved dlya classa mozhno, 
		c = a b; vopros 4em obozna4it vozvedenie v stepen? nu govorit kak v fortran a ** b
		no v C CPP takoi leksemi net, zna4it nelza, nu ok govorit togda kak c basic
		c = a ^ b; takaya leksema v yazike est ispolzovat mozhno? da kak skazat
		esli ya zapishu c = a ^ b + 1; to 4to ya hotel vu4islit? naverno a v stepeni b i 
		pribavit 1, no v C CPP u + prioritet vishe 4em u ^ zna4it na samom dele eto
		obozna4aet 4to a vozvoditsa v stepen b+1 vryatli stradalec eto hotel togda
		govorit skobki budu stavit c = (a ^ b)+1; no togda uzhe leg4e napisat CPP
		c = pow(a,b)+1; i ne mu4atsa :)))))))))
	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	
	c = (a ^ b)+1;  c = pow(a,b)+1;  eto ilustraciya 4to nelza izmenit povedenie operatora
		dlya vstroennih tipov(a tolko dlya svoih classov), nelza izmenit prioriteti i
		nelza pridumat teh leksem kotorih v yazike netu
    Nu a tak kak ostaetsa eshe okolo 50 to mnogo 4ego mozhno peredelat

//============================== SAMA PEREGRUZKA =================================
		======================== PEREGRUZKA UNARNIH OPERTOROV ====================
		Predpolozhim est class X i nekotorui ego object x;  i mi hotim posmotret kak dlya
	etogo classa peregruzhautsa unarnie operatori.
	
	Kak obozna4it dlya naglyadnosti te 50 operatorov abstraktnik zna4kom nu davaite @ ego
	v yazike net 4isto dlya vizualnogo primera(on budet == + - / etc)
	ponyatno 4to @ use nelza, togda unarnui operator eto virashenie 
		@x i kogda compi vstre4aet v proge takoe virazhenie on pitaetsa otiskat v classe X
			funciyu X::operator@    (@ znak operacii) vot esli nahodit to vmesto @x compi
			vpisivaet sleduyushiy text x.operator@()  vmesto @x  (vizov etoi funcii)

		@x ===> X::operator@()  ===> x.operator@()  A Esli compi nahodit vneshniyu svobodnuyu
			funciyu vne classa s odnim edinstvennim argumentom prenadlezhashim classu X
		===> ::operator@(X) togda on zamenyaet @x na vizov etoi funcii ===> operator@(x)

		@x ===> X::operator@()	    ===> x.operator@()
		   ===>  ::operator@(X)		===>   operator@(x)
		Ili pervoe ili vtoroe esli nahoditsa i pervoe i vtoroe to eto privedet k 
			neodnozna4nosti vizova -> error due compilation
			ITOG unarnie operatori mozhem peregruzhat ili kak 4len classa ili kak free function
		
		SPISOK UNARNIH OPERATOROV KOTORIE MOZHEM PEREGRUZHAT:
		! ++ -- ~ i mnogo drugih
						A ESLI COMPI VSTRETIT 
   ++x   ili 
   x++   to kak emu postupit? zna4it compi is4et ++x

	++x ===> X::operator++()	    ===> x.operator++()    ili
	   ===>   ::operator++(X)		===>   operator++(x)   i eto PREFIXNAYA FORMA !!!!!!!!
	
	S drugoi storoni esli compi vstre4aet x++ to is4et funciyu ++ no s dopolnitelnim 
		fectivnim argumentom int esli nahodit vizivaet nu a vmesto int peredaet 0 :)))
	x++   ===> X::operator++(int)	    ===> x.operator++(0)    libo esli 
			eto svobodnaya func to s dvumya argumentami dlya postfix x++
		  ===>   ::operator++(X, int)		===>   operator++(x, 0)

	X::operator++() i X::operator++(int) imeyut raznuyu signaturu zna4it oni peregruzheni
		STRAUSTRUPOM specialno dlya razli4iya prefix i postfix incrementa/decrementa
	//==============================================================================

	//======================= BINARNAYA PEREGRUZKA =================================
		Puskai u nas est dva objecta odin prednadlezhit classu X x; drugoi class Y y;
	ne obyazatelno X i Y raznie classi mogut bit i odinakovie ...
	Kogda compi vstre4aet binarnui operator operandami kotorogo est objecti x i y to
	compi pitaetsa naiti v classe prenadlezhashemu LEVOMU OPERANDU(X) funciyu s argumentom
	k kotoromu otnositsa PRAVUI OPERAND(Y), esli nahodit vizivaet ee, ili zhe
	is4et v globalnom prostranstve vne vseh classov funciyu s dvumya argumentami 
	pri4em pervui argument dolzhen imet type LEVOGO(X) operanda a vtoroi PRAVOGO(Y)
	esli nahodit to vizivaet etu funciyu peredavaya v nee objecti x i y.
			
			(Operandi te nad kem/s kem vipolnyautsa operatori)

	x@y ===> X::operator++(Y)	    ===> x.operator++(y)   
	===>   ::operator++(X,Y)		===>   operator++(x,y)   
		I snova esli nahodit i to i to to voznikaet neodnozna4nost -> error compilation
	zna4it peregruzhaem libo pervim sposobom v classe libo vtorim v globale no ne i tak i tak
		UMnui compi kak vstre4aet x@y on prosto is4et podhodyashiyu funciyu i vizivaet ee :))
	//=================================================================================

			A v yazike C bila peregruzka operatorov??????
	esli a-b oba int? (a esli a ukazatel i b int??? to eto zdvig ukazatelya i eto sovsem
	ne vu4itanie), a esli a i b oba ukazateli??? - to beretsa raznica addressov i delitsa na
	sizeof ih obshego tipa. Dlya raznih tipov a-b vipolnyaetsa v C po raznomu no mi ne znali
	ob etom a STRAUSTRUP otkril etu tainu pokazal nam i dal polzovatsa mehanizm...
	   &&&&&&&&&&&&& No est eshe para ograni4eniy kotorue mi vunuzhdeni soblyudat &&&&&&&&
	 1) Nu kak govorilos peregruzku nado delat odnim iz dvuh sposobov(4len classa ili global)
	 ESLI FUNCIYA 4LEN CLASSA TO ONA DOLZHNA PRENADLEZHAT BIT OPISANA V CLASSE LEVOGO OPERANDA

  $%$%$$^ KAKOI IZ DVUH VIBRAT KAK 4LEN CLASSA ILI KAK GLOBAL FUNC??? vo mnogih slu4ayah proger
		rehsaet sam no est slu4ai kogda reshat ne prihoditsa i nelza, delo v tom 4to est
		1) ograni4eniya operator prisvaivaniya = mozhno peregruzhat tolko kak 4len classa !!!
			Tolko kak 4len classa razreshaetsa peregruzhat operator [] (indexirovanie),
			tolko kak 4len classa () vizov funcii mozhno peregruzhat, operator -> ,
			i (type) privedenie k tipu v stile C. 
	%%%%%%^^@@$@$^@^%&%^&%^&%@ s ostalnimi operatorami proger sam reshaet 4to lutshe hotya
		v ryade slu4aev i hotelos bi kak 4len classa da ne stoit i luthe kak svobodnui func

	I NA POSLEDOK RAZRESHAETSA NO NE RECOMENDUETSA PEREGRUZHAT SLED OPERATORI !!!!!!!!!
		&& || ,  eto mozhno no not recomended, u etih operatorov vsegda strogiy poryadok
		vu4isleniya operandov pervui vsegda levui tselikom i polnostyu, potom mozhet 
		mozhet vu4islyatsa a mozhet ne vu4islyatsa pravui a u , vsegda pravui vu4islyaetsa
	no vsegda posle levogo(i vsegda tselikom odin a potom tselikom drugoi ne mozhet po kuso4kam)
	tak eto rabotaet dlya vstroennih tipov i tak programmisti privikli i mi ne smozhem 
	putem peregruzki obespe4it takoe povedenie etih operatorov i programmistov pereu4it.
     !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 Vot vozmu i peregruzhu &&(konyunkciyu) operator&&(x,y) ya mogu nadeyatsa na poryadok
	 vu4isleniya argumentov u funcii?? ponyatno 4to net on neopredelen, i nikto ne garantiruet
	 4to sna4ala budet vu4islyata tselikom i polnostyu x a potom y bolee togo sovershenno
	 nevozmozhno sdelat tut 4tob pri vu4islenii x y ne vu4islyalsa. Poetomu ne stoit 
	 vvodit programmistov C i CPP v zabluzhdenie hotya peregruzit to mozhem...

	 ITOGO RECOMMENDED 4TOB NASHI PEREGRUZHENNIE OPERATORI VELI SEBYA PODOBNIM OBRAZOM
	 KAK DLYA VSTROENNIH TIPOV INA4E NE PEREGRUZHAI, 4TOB + DELAL KAK - ILI && VOOBSHE
	 NEPREDSKAZUEMO I U OSTALNUH PROGRAMMISTOV SMOTREVSHIH CODE TEKLI MOZGI, DA I SAM ZABUDESH.
*/