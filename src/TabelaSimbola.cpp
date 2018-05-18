#include "TabelaSimbola.h"


TabelaSimbola::TabelaSimbola(){

	SimboliUlaz* ulaz = new SimboliUlaz("SEG", "UND", 0, "0", 0, "L");
	tabela.push_back(ulaz);

}

TabelaSimbola::TabelaSimbola(const TabelaSimbola& tabela){

}

TabelaSimbola::~TabelaSimbola(){

}

Iterator TabelaSimbola::pocetakTabele(){
	return tabela.begin();
}

Iterator TabelaSimbola::krajTabele(){
	return tabela.end();
}

bool TabelaSimbola::postojiSimbol(string ime){
	for (Iterator iter = pocetakTabele(); iter != krajTabele(); iter++){
		if ((*iter)->getNaziv() == ime) return true;
	}
	return false;
}

void TabelaSimbola::dodajSimbol(SimboliUlaz* simbol){
	tabela.push_back(simbol);
}

int TabelaSimbola::rbr(string ime){
	for (Iterator iter = pocetakTabele(); iter != krajTabele(); iter++){
		if ((*iter)->getNaziv() == ime) return ((*iter)->getRedniBroj());
	}
	return 0;
}

SimboliUlaz* TabelaSimbola::dohvatiSimbol(string ime){
	for (Iterator iter = pocetakTabele(); iter != krajTabele(); iter++){
		if ((*iter)->getNaziv() == ime) return (*iter);
	}
	return 0;
}

SimboliUlaz* TabelaSimbola::dohvatiPoR(int rbr){
	for (Iterator iter = pocetakTabele(); iter != krajTabele(); iter++){
		if ((*iter)->getRedniBroj() == rbr) return (*iter);
	}
	return 0;
}


ostream& operator<<(ostream& out, TabelaSimbola& tabela){
	out << "#TabelaSimbola\n";
	for (Iterator iter = tabela.pocetakTabele(); iter != tabela.krajTabele(); iter++){
		out << (*iter)->ispisi();
		out << "\n";
	}
	return out;
}