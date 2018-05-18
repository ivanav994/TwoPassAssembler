#ifndef _PRVIPROLAZ_H_
#define _PRVIPROLAZ_H


#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<bitset>
#include<sstream>
#include<math.h>
#include"TabelaSimbola.h"
#include "Postfix.h"
#include "Sadrzaj.h"
#include "Mape.h"


class PrviProlaz{

private:
	

public:
	PrviProlaz();
	~PrviProlaz();
	static TabelaSimbola* tabelaSimbola;
	string linija;
	vector<string> reci;
	vector<string>pomocneReci;
	vector<string>in;
	void brisiLiniju();
	void smestiSimbol();
	static int LC;
	bool flagInsLab;
	static bool drugiP;
	char staJeKonstanta(string s);
	int brojacReci, labela, dup, def, org, ins, podatak, sekcija;
		static int  negativanBroj; 
	static string DecUHex(string s);
	static int HexToDec(string hex);
	static string BitUHex(string s);
	static string HexToBits(string s);
	static string obrni(string s);
	bool daLiJeIzraz(string s);
	int izrazPreDup(string s);
	void podeliIzraz(string s);
	vector<string> literali;
	vector<string> vrednosti;
	char kojiJeOperator(string s);
	int vrednostIzraza();
	static string tekucaSekcija;
	static string prethodnaSekcija;
	static bool direktivaORG;
	static string vrednostORG;

	static bool obradiSekciju(string s);
	void obradiORG(string s);
	static bool EPG(string s);
	std::size_t j;
	bool jesteInstrukcija(string s);
	void obrada(ifstream& ulaz, ofstream& izlaz);
	bool jesteLabela(string s);
	bool jestePodatak(string s);
	int velicinaPodatka(string s);
	int sabirac;
	int dupdef(string s);
	string error;
	string pisi;
	int velicinaInstrukcije();
	int brojLabela(string s);
	void srediRelok(string s);
	int vrednostIns;
	string simbolRelok;
	string labFlag;
	string srediKod(int vrednost, int velicina);
	int aritmeticke, ret;
	string adresiranje;
	string srediIns(string b, int vel);
	void drugiProlaz(ifstream& ul, ofstream& iz);
	bool proveraRegistra(string r);
	int skokovi, ls;
	string sek;




};




#endif