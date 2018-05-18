#ifndef _RELZAPIS_H_
#define _RELZAPIS_H_

#include <string>
#include<iostream>
using namespace std;


class  RelZapis{

private:
	string adresa;
	string tip;
	int rbr;

public:
	RelZapis();
	RelZapis(string a, string t, int r);
	~RelZapis();

	friend class PrviProlaz;
	
	void setAdresu(string a);
	string getAdresu();
	void setTip(string t);
	string getTip();
	void setRbr(int r);
	int getRbr();
	string ispisi();




};


#endif