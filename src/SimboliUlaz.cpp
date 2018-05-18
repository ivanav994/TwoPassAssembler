#include "SimboliUlaz.h"


int SimboliUlaz::rBr = 0;

SimboliUlaz::SimboliUlaz(string t, string n, int brojS, string pocetnaAdr, long velicinaS, string flags){

	tip = t;
	redniBroj = rBr++;
	naziv = n;
	if (t == "SEG") brojSekcije = redniBroj;
	else brojSekcije = brojS;
	pocetnaAdresa = pocetnaAdr;
	velicinaSekcije = velicinaS;
	flagLG = flags;
	org = false;
	vel = "0"; //zbog UND
}

SimboliUlaz::SimboliUlaz(const SimboliUlaz& u){
}

void SimboliUlaz::setujVel(string v){
	vel = v;
}

string SimboliUlaz::getVel(){
	return vel;
}

void SimboliUlaz::setujOrg(){
	podORG = true;
}

bool SimboliUlaz::daLiJePodOrg(){
	if (podORG) return true;
	else return false;
}

SimboliUlaz::SimboliUlaz(SimboliUlaz&& u){

}

SimboliUlaz::SimboliUlaz(){
	redniBroj = rBr++;
}

SimboliUlaz::~SimboliUlaz(){

}

string SimboliUlaz::getTip(){
	return tip;
}

void SimboliUlaz::setTip(string tip){
	this->tip = tip;
}

int SimboliUlaz::getRedniBroj(){
	return redniBroj;
}

string SimboliUlaz::getNaziv(){
	return naziv;
}

void SimboliUlaz::setNaziv(string naziv){
	this->naziv = naziv;
}

int SimboliUlaz::getBrojSekcije(){
	return brojSekcije;
}


void SimboliUlaz::setBrojSekcije(int brSek){

	brojSekcije = brSek;
}
string SimboliUlaz::getPocetnuAdresu(){
	return pocetnaAdresa;
}

void SimboliUlaz::setPocetnuAdresu(string pocAdr){
	pocetnaAdresa = pocAdr;
}

long SimboliUlaz::getVelicinuSekcije(){
	return velicinaSekcije;

}

void SimboliUlaz::setVelicinuSekcije(long velSek){
	velicinaSekcije = velSek;
}

string SimboliUlaz::getFlags(){
	return flagLG;
}

void SimboliUlaz::setFlags(string f){
	flagLG = f;
}

void SimboliUlaz::setOrg(){
	org = true;
}

bool SimboliUlaz::getOrg(){
	return org;
}

ostream& operator << (ostream& out, SimboliUlaz& ulaz){

	out << std::setw(5) << left << ulaz.getTip();
	out << std::setw(5) << left << to_string(ulaz.getRedniBroj());
	out << std::setw(5) << left << ulaz.getNaziv();
	out << std::setw(5) << left << to_string(ulaz.getBrojSekcije());
	out << std::setw(5) << left << ulaz.getPocetnuAdresu();
	if (ulaz.getTip().compare("SEG") == 0) out << std::setw(20) << left << to_string(ulaz.getVelicinuSekcije());
	out << std::setw(5) << left << ulaz.getFlags();
	out << "\n";

	return out;
}

string SimboliUlaz::ispisi(){
	string s;
	if (tip == "SEG"){ 
		
		s += getTip() + " " + to_string(getRedniBroj()) + " " +
			getNaziv() + " " + to_string(getBrojSekcije()) + " "
			+ "0x" + getPocetnuAdresu() + " " + "0x" + getVel() +
			" " + getFlags();
	}
	else{
		s += getTip() + " " + to_string(getRedniBroj()) + " " +
			getNaziv() + " " + to_string(getBrojSekcije()) + " "
			+ "0x" + getPocetnuAdresu() + 
			" " + getFlags();
	}

	return s;

		
}