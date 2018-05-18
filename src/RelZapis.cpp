#include "RelZapis.h"

RelZapis::RelZapis(){

}

RelZapis::RelZapis(string a, string t, int r){
	adresa = a;
	tip = t;
	rbr = r;
}

RelZapis::~RelZapis(){

}

void RelZapis::setAdresu(string a){
	adresa = a;
}

void RelZapis::setTip(string t){
	tip = t;
}

void RelZapis::setRbr(int r){
	rbr = r;
}

string RelZapis::getAdresu(){
	return adresa;
}

string RelZapis::getTip(){
	return tip;
}

int RelZapis::getRbr(){
	return rbr;
}

string RelZapis::ispisi(){
	string ispis = "";
	ispis += "0x" + getAdresu() + " " + getTip() + " " + to_string(getRbr());
	return ispis;
}