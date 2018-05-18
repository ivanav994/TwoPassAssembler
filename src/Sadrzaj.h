#ifndef _SADRZAJ_H_
#define _SADRZAJ_H_

#include<string>
#include<list>
#include "RelZapis.h"


typedef list<RelZapis*>::iterator Iter;


class Sadrzaj{

private:
	list<RelZapis*> zapisi;
	string kodovi;
	string sekcija;


public:
	friend class PrviProlaz;
	Sadrzaj(string sek);
	~Sadrzaj();
	void dodajZapis(RelZapis* rz);
	friend ostream& operator<<(ostream& out, Sadrzaj& zapisi);
	void dodajDeoIns(string i);
	void ispisiSadrzaj();
	Iter pocetak();
	Iter kraj();
	string getkodove();
	string getSekciju();



};

#endif