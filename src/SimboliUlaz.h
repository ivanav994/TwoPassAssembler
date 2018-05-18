#ifndef _SIMBOLI_ULAZ_
#define _SIMBOLI_ULAZ_



#include<string>
#include<iostream>
#include<iomanip>
using namespace std;



class SimboliUlaz{
private:
	string tip;
	int redniBroj;
	string naziv;
	int brojSekcije;
	string pocetnaAdresa;
	long velicinaSekcije;
	string flagLG;
	bool podORG;
	bool org;
	string vel;

public:
	static int rBr;
	
	friend class TabelaSimbola; 

	SimboliUlaz(string t, string n, int brojS, string pocetnaAdresa, long velicinaSekcije, string flagGL);
	SimboliUlaz(const SimboliUlaz& u);
	SimboliUlaz(SimboliUlaz&& u);
	SimboliUlaz();

	

	virtual ~SimboliUlaz();
	void setujOrg();
	bool daLiJePodOrg();
	void setujVel(string v);
	string getVel();
	string getTip();
	void setTip(string tip);
	int getRedniBroj();
	string getNaziv();
	void setNaziv(string naziv);
	int getBrojSekcije();
	void setBrojSekcije(int brSek);
	string getPocetnuAdresu();
	void setPocetnuAdresu(string pocAdr);
	long getVelicinuSekcije();
	void setVelicinuSekcije(long velSek);
	string getFlags();
	void setFlags(string f);
	void setOrg(); 
	bool getOrg();
	friend ostream& operator << (ostream& out, SimboliUlaz& ulaz);
	string ispisi();
	

};


#endif

