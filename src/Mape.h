#ifndef _MAPE_H
#define _MAPE_H_

#include <map>
#include <string>
using namespace std;

class Mape{
public:
	typedef map<string, string> mapInst;
	static mapInst mapIns;
	typedef map<string, string> mapAdres;
	static mapAdres mapAdr;
	typedef map<string, string> mapTipovi;
	static mapAdres mapTip;
	typedef map<string, string> mapRegis;
	static mapAdres mapReg;
};

#endif