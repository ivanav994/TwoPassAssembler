#include "Sadrzaj.h"


Sadrzaj::Sadrzaj(string sek){
	kodovi = "";
	sekcija = sek;
}

Sadrzaj::~Sadrzaj(){

}

void Sadrzaj::dodajZapis(RelZapis* rz){
	zapisi.push_back(rz);
}

void Sadrzaj::dodajDeoIns(string s){
	kodovi += s;
}
string Sadrzaj::getkodove(){
	string kod = "";
	int brojac = 0;
	for (unsigned i = 0; i < kodovi.length(); i++){
		if (kodovi.at(i) != ' '){
			brojac = brojac + 1;
			kod += kodovi[i];
		}
		else {
			kod += kodovi[i];
			if ((i+1) < kodovi.length()){
				
				if (kodovi.at(i + 1) == ' ') i++;
					 
			}
		}
		if (brojac == 32){
			
			kod += '\n';
			i++;
			if ((i + 1) < kodovi.length() &&  kodovi.at(i + 1) == ' ')i++;
			
			brojac = 0;
		}
		
	}

	return kod;
}

Iter Sadrzaj::pocetak(){
	return zapisi.begin();
}

Iter Sadrzaj::kraj(){
	return zapisi.end();
}

string Sadrzaj::getSekciju(){
	return sekcija;
}

ostream& operator<<(ostream& out, Sadrzaj& zapisi){
	out << "\n";
	out << "#rel." + zapisi.getSekciju(); 
	out << "\n";
	for (Iter iter = zapisi.pocetak(); iter != zapisi.kraj(); iter++){
		out << (*iter)->ispisi(); 
		out << "\n";
	}
	out << zapisi.getSekciju();
	out << "\n";
	out << zapisi.getkodove();
	out << "\n";
	return out;
}

