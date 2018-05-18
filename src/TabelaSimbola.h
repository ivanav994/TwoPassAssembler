#ifndef _TABELASIMBOLA_H_
#define _TABELASIMBOLA_H_

#include<list>
#include "SimboliUlaz.h"

typedef list<SimboliUlaz*>::iterator Iterator; 

class TabelaSimbola{

private:
	

	list<SimboliUlaz*> tabela;

public:
	friend class PrviProlaz;
	TabelaSimbola();
	~TabelaSimbola();
	TabelaSimbola(const TabelaSimbola& tabela);


	bool postojiSimbol(string ime);
	void dodajSimbol(SimboliUlaz* simbol);
	SimboliUlaz* dohvatiSimbol(string ime);
	SimboliUlaz* dohvatiPoR(int rbr);
	friend ostream& operator<<(ostream& out, TabelaSimbola& tabela);
	Iterator pocetakTabele();
	Iterator krajTabele();
	int rbr(string ime);

};





#endif