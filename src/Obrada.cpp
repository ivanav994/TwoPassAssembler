#include "Obrada.h"


TabelaSimbola* PrviProlaz::tabelaSimbola = new TabelaSimbola();
Mape* mape = new Mape();

string PrviProlaz::tekucaSekcija = "";
string PrviProlaz::prethodnaSekcija = "";
bool PrviProlaz::direktivaORG = false;
string PrviProlaz::vrednostORG = "";
bool PrviProlaz::drugiP = false;
int PrviProlaz::negativanBroj = 0;

PrviProlaz::PrviProlaz(){

}

string PrviProlaz::obrni(string s){
		string ret;
		while (s.length()){
			if (s.length() == 1) {
				return s;
			}
			else{
				return ret = obrni(s.substr(1, s.length())) + s.at(0);
			}
		}
		return "";
	}

int PrviProlaz::LC = 0;

string PrviProlaz::HexToBits(string s){
	char c;
	string t;
	for (unsigned i = 0; i < s.length(); i++){
		c = s.at(i);
		switch (c){
		case '0': t += "0000"; break;
		case '1': t += "0001"; break;
		case '2': t += "0010"; break;
		case '3': t += "0011"; break;
		case '4': t += "0100"; break;
		case '5': t += "0101"; break;
		case '6': t += "0110"; break;
		case '7': t += "0111"; break;
		case '8': t += "1000"; break;
		case '9': t += "1001"; break;
		case 'A': t += "1010"; break;
		case 'B': t += "1011"; break;
		case 'C': t += "1100"; break;
		case 'D': t += "1101"; break;
		case 'E': t += "1110"; break;
		case 'F': t += "1111"; break;
		}

	}
	return t;

}

int PrviProlaz::HexToDec(string hex){
	signed int result = 0; 
	if (hex == "0"){ result = 0; return result; }
	for (unsigned i = 0; i<hex.length(); i++) {
		if (hex[i] >= 48 && hex[i] <= 57)
		{
			result += (hex[i] - 48)*pow(16, hex.length() - i - 1);
		}
		else if (hex[i] >= 65 && hex[i] <= 70) {
			result += (hex[i] - 55)*pow(16, hex.length() - i - 1);
		}
		else if (hex[i] >= 97 && hex[i] <= 102) {
			result += (hex[i] - 87)*pow(16, hex.length() - i - 1);
		}
	}
	return result;
}

string PrviProlaz::DecUHex(string s){

	int br = stoi(s);
	int os;
	string ret;
	string t;
	if (br == 0){
		ret += '0'; return ret;
	}

	if (br<0){
			
		string b = DecUHex(to_string(abs(br)));
		string bb = HexToBits(b);
		negativanBroj = 1;
		
		string neg = "";
		for (unsigned i = 0; i < bb.size(); i++){
			if (bb.at(i) == '0') neg += '1';
			else neg += '0';
		}

		

		char trenutni = '1';
		string rez;
		for (unsigned i = neg.size()-1; i>=0; i--){
			if (neg.at(i) == '0' && trenutni == '1') {
				rez += '1';
				trenutni = '0';
			}
			else if (neg.at(i) == '0' && trenutni == '0'){
				rez += '0';
				trenutni ='0';
			}
			else if (neg.at(i) == '1' && trenutni == '0'){
				rez += '1';
				trenutni = '0';
			}
			else {
				rez += '0';
				trenutni = '1';
			}
			if (i == 0) break;
		}
		
		string vr = "";
		for (unsigned i = rez.size() - 1; i >= 0; i--){
			vr += rez.at(i);
			if (i == 0) break;
		}
		
		string ret = BitUHex(vr);
		return ret;

	}


	while (br > 0){

		os = br % 16;

		negativanBroj = 0;
		if (os > 9){
			switch (os){
			case 10:  t += "A"; break;
			case 11:  t += "B"; break;
			case 12:  t += "C"; break;
			case 13:  t += "D"; break;
			case 14:  t += "E"; break;
			case 15:  t += "F"; break;
			}
		}
		else{

			t += to_string(os);
		}
		br = br / 16;

	}
	ret = obrni(t);
	return ret;
}

string PrviProlaz::BitUHex(string s){
	string ss;
	string ret;
	string res;
	unsigned int i = 0;
	unsigned int j = 0;   

	

	unsigned duz = s.length();
	string duz1 = "";
	if ((duz % 4) != 0){
		
		int d = 4-(duz % 4);
		for (int i = 0; i < d; i++) duz1 += "0";
		s = duz1 + s;

	}




	while (i < s.length()){
		ss = s.substr(i, 4);

		if (ss == "0000"){
			ret += '0';
		}
		else if (ss == "0001"){
			ret += '1';
		}
		else if (ss == "0010"){
			ret += '2';
		}
		else if (ss == "0011"){
			ret += '3';
		}
		else if (ss == "0100"){
			ret += '4';
		}
		else if (ss == "0101"){
			ret += '5';
		}
		else if (ss == "0110"){
			ret += '6';
		}
		else if (ss == "0111"){
			ret += '7';
		}
		else if (ss == "1000"){
			ret += '8';
		}
		else if (ss == "1001"){
			ret += '9';
		}
		else if (ss == "1010"){
			ret += 'A';
		}
		else if (ss == "1011"){
			ret += 'B';
		}
		else if (ss == "1100"){
			ret += 'C';
		}
		else if (ss == "1101"){
			ret += 'D';

		}
		else if (ss == "1110"){
			ret += 'E';
		}
		else if (ss == "1111"){
			ret += 'F';
		}

		i += 4;

	}
	while (j < ret.length()){
		res += ret.at(j);
		j++;
		if (j % 2 == 0)res += ' ';
	}
	return res;
}

char PrviProlaz::staJeKonstanta(string s){

	
	if (s.find("0b") != string::npos) return 'b';
	else if (s.find("'") != string::npos) return 'c'; //kao char 
	else if (s.find("0x") != string::npos || s.find("0x") != string:: npos) return 'h';
	else {
		for (unsigned i = 0; i < s.size(); i++){
			if (s[i] == '-') negativanBroj = 1; 
			else if(isdigit(s[i])) continue;
			else return 0;
		}
		return 'd';
	}
	return 'e';  
}

bool PrviProlaz::daLiJeIzraz(string s){
	if (s.find('+') != string::npos || (s.find('-') != string::npos && s.at(0) != '-') || s.find('*') != string::npos || s.find('/') != string::npos
		|| s.find('(') != string::npos || s.find(')') != string::npos) return true;
	else return false; 
}

void PrviProlaz::podeliIzraz(string s){
	
	if (literali.empty() == false){  

		while (!literali.empty()){
			literali.pop_back();
		}
	}

	unsigned i = 0;
	string rec = "";
	string rec2 = "";
	while (i <= s.size()){
		if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '(' && s[i] != ')' && i < s.size())
			rec += s[i];
		else {
			if(rec!= "") literali.push_back(rec);   
			if (i < s.size()){
				rec2 += s[i];
				literali.push_back(rec2);
			}
			rec = rec2= "";
		}
		i++;
		
	}
}

char PrviProlaz::kojiJeOperator(string s){
	if (!s.compare("+")) return '+';
	else if (!s.compare("-")) return '-';
	else if (!s.compare("*")) return '*';
	else if (!s.compare("/")) return '/';
	else if (!s.compare("(")) return '(';
	else if (!s.compare(")")) return ')';
	else return 'e';

}

int PrviProlaz::vrednostIzraza(){
	
	Postfix* pos = new Postfix();
	pos->uPostfix(&vrednosti);
	

	int vrati = pos->vrednostIzraza();
	for (unsigned i = 0; i < pos->post.size(); i++)
		pos->post.pop_back();
	pos->~Postfix();
	return vrati;
	
}

int PrviProlaz::velicinaPodatka(string s){
	int sabirati = 0;
	if (!s.compare("DD")) sabirati += 4;
	else if (!s.compare("DW")) sabirati += 2;
	else if (!s.compare("DB")) sabirati += 1;
	else sabirati = 0;
	return sabirati;
}

int PrviProlaz::izrazPreDup(string s){
	podeliIzraz(s);
	string hex, dec;
	int decimalni = 0;
	for (unsigned i = 0; i < literali.size(); i++){
		char p = staJeKonstanta(literali[i]);
		if (p != 'e'){  
			
			if (p == 'b') hex = BitUHex(literali[i]);
			else if (p == 'c'){ //za znakove
				char znak = literali[i].at(1);
				int dec = (int)znak;
				hex = DecUHex(to_string(dec));
			}
			else if (p == 'h') hex = literali[i];
			else dec = literali[i];
		}
	}
	return 0;
}

bool PrviProlaz::obradiSekciju(string s){

	
	string naziv;
	string pocetnaAdresa;
	
	bool prva = false;
	bool druga = false;

	if (!s.compare(".text") || !s.compare(".data") || !s.compare(".rodata") || !s.compare(".bss")) prva = true;
		
	else if (!s.compare(0, 6, ".text.") || !s.compare(0, 6, ".data.") || !s.compare(0, 8, ".rodata.") || !s.compare(0, 4, ".bss.")) druga = true;
	else return false;
	

	if (prva || druga){
		if (drugiP) return true;
		naziv = s.substr(1);
		if (tekucaSekcija != ""){
			int velicinaPrethodneSekcije = LC - HexToDec((tabelaSimbola->dohvatiSimbol(tekucaSekcija)->getPocetnuAdresu()));
			string dec = DecUHex(to_string(velicinaPrethodneSekcije));
			tabelaSimbola->dohvatiSimbol(tekucaSekcija)->setVelicinuSekcije(velicinaPrethodneSekcije);
			tabelaSimbola->dohvatiSimbol(tekucaSekcija)->setujVel(dec);

		}
		tekucaSekcija = naziv;
		
		if (direktivaORG == true){
			pocetnaAdresa = vrednostORG;
			
			LC = HexToDec(vrednostORG);
			direktivaORG = false;
			
		}
		else {
			pocetnaAdresa = "0";
			LC = 0;
			vrednostORG = "n"; 
		}

		string flags = "";
		if (s.find(".text") != string::npos) flags = "LRX";
		else if (s.find(".rodata") != string::npos) flags = "LR";
		else if (s.find(".bss") != string::npos) flags = "LRW";
		else flags = "LRW";

		SimboliUlaz* noviUlaz = new SimboliUlaz("SEG", naziv, 0, pocetnaAdresa, 0, "");
		noviUlaz->setFlags(flags);
		tabelaSimbola->dodajSimbol(noviUlaz);
		return true;

	} 
	else return false;


}

void PrviProlaz::obradiORG(string s){
	string adresa="";
	char c;
	
	if (!daLiJeIzraz(s)){
		c = staJeKonstanta(s);
		if (c == 'b') adresa = BitUHex(s.substr(2)); 
		else if (c == 'd') adresa = DecUHex(s);
		else if (c == 'h') adresa = s.substr(2);
		else adresa = "";
	}
	else { 
		//moram da stavim dup ili def 
		def = 1;
		int rez = dupdef(s);
		if (rez == -1 || rez == -2) {
			return;
		}
		def = 0;
		adresa = DecUHex(to_string(rez));
	}


	vrednostORG = adresa;
}

bool PrviProlaz::EPG(string s){
	if (!s.compare(".extern") || !s.compare(".global") || !s.compare(".public"))
		return true;
	else return false;

}

bool PrviProlaz::jesteLabela(string s){    
	string ss = s;
	if (ss[ss.size() - 1] == ':') return true;
	else return false;
}

bool PrviProlaz::jesteInstrukcija(string s){
	if (!s.compare("ADD") || !s.compare("SUB") || !s.compare("MUL") || !s.compare("DIV") || !s.compare("MOD") || !s.compare("AND")
		|| !s.compare("OR") || !s.compare("XOR") || !s.compare("NOT") || !s.compare("ASL") || !s.compare("ASR") || !s.compare("PUSH")
		|| !s.compare("POP") || !s.compare("INT") || !s.compare("JZ") || !s.compare("JNZ") || !s.compare("JGZ") || !s.compare("JGEZ") ||
		!s.compare("JLZ") || !s.compare("JLEZ") || !s.compare("JMP") || !s.compare("CALL") || !s.compare(0, 4, "LOAD")
		|| !s.compare(0, 5, "STORE") || !s.compare("RET")) return true;
	else return false;
}

bool PrviProlaz::jestePodatak(string s){
	string rec = s;
	if (!rec.compare("DB") || !rec.compare("DW") || !rec.compare("DD"))
		return true;
	else return false;
}

void PrviProlaz::smestiSimbol(){

	
	unsigned i = 0;
	brojacReci = dup = def= podatak= labela = ins=0;
	string rec = "";
	j = linija.find(';');

		if (linija.find(":") != string::npos) {
			labela = 1; 
			while (linija[i] != ':'){
				rec += linija[i++];
			}
			rec += linija[i++];
			reci.push_back(rec);
			rec = "";
			if (linija[i] == ' ') i++;
			brojacReci++;
			if (i >= linija.size()) return;
		}



		while (linija[i] != ' ' && i < linija.size()) 
			rec += linija[i++];
		reci.push_back(rec);
		rec = "";
		brojacReci++;
		if (i >= linija.size()) {
			if (!reci[brojacReci - 1].compare("RET")) ins = 1;
			return;
		}
		//ORG direktiva

		if (!reci[brojacReci - 1].compare("ORG")){
			while (i < linija.size() && linija[i] != ';'){
				if (linija[i] != ' ')
					rec += linija[i];
				i++;
			}
			reci.push_back(rec);
			brojacReci++;
			org = 1;
			return;
		}
		
			if (jestePodatak(reci[(brojacReci-1)]) || linija.find("DEF") != string::npos) {

			if (linija.find("DUP") != string::npos) dup = 1;
			else if(linija.find("DEF") != string::npos) def = 1;
			if(dup || def)
			{

			if (dup){
			podatak = 1;
			sabirac = velicinaPodatka(reci[brojacReci - 1]);
			while (linija[i] != 'D'){
			if (linija[i] != ' ')
			rec += linija[i++];
			else i++;
			}
			reci.push_back(rec);
			brojacReci++;
			rec = "";
			}
			if (def){
			while (linija[i] != 'D')
			i++;
			}


			if(dup)
			reci.push_back("DUP");
			else if (def) reci.push_back("DEF");
			rec = "";
			brojacReci++;
			i = i + 3;
			//smestam reci iza DUP ili DEF
			while (i < linija.size() && linija[i-1] != ';'){
				
				while (linija[i] != ',' && i < linija.size() && linija[i] != ';'){
				
			if (linija[i] != ' ')
			rec += linija[i];
			i++;
			
			}
			reci.push_back(rec);
			rec = "";
			brojacReci++;
			
			i++;

			}

			}
			else {
				podatak = 1;
				sabirac = velicinaPodatka(reci[brojacReci - 1]);
				while (i < linija.size() && linija[i-1] != ';'){
					while (linija[i] != ',' && i < linija.size() && linija[i] != ';'){  
			if (linija[i] != ' ')
			rec += linija[i];
			i++;
			}  
			reci.push_back(rec);
			brojacReci++;
			rec = "";
			
			i++;
			

			}
			}
			}


			

		if (jesteInstrukcija(reci[brojacReci - 1])){
			ins = 1;
			if (linija.find("R") != string::npos || linija.find("SP") != string::npos){
				
				//smestim prvo Ri ili SP u vektor reci do prvog zareza
				while (linija[i] != ',' && i < linija.size()){
					if (linija[i] != ' ')
						rec += linija[i];
					i++;
				}
				reci.push_back(rec);
				brojacReci++;
				rec = "";
				if (linija[i] == ']') return;
				if (i >= linija.size()) return;
				i++;
				while (linija[i] == ' ') i++;
				//sta sve moze dalje da bude
				if (linija[i] == '[' && linija[i] == '$'){
					while (linija[i] != ';' && i < linija.size()){
						if (linija[i] != ' ')
							rec += linija[i];
						i++;
					}
					reci.push_back(rec);
					brojacReci++;
					rec = "";
					return;
				}

			}

				//smestam izraze ili jos registara
				while (i < linija.size() && linija[i-1] != ';'){
					while (linija[i] != ',' && i < linija.size() && linija[i] != ';'){
						
						if (linija[i] != ' ')
							rec += linija[i];
						i++;
					}
					reci.push_back(rec);
					rec = "";
					brojacReci++;
					i++;


				}
			}

		if (EPG(reci[brojacReci-1])){
			string rec = "";
			while (i < linija.size() && linija[i] != ';'){
				while (linija[i] != ',' && i< linija.size()){
					if(linija[i]!= ' ') rec += linija[i];
					i++;
				}

				reci.push_back(rec);
				rec = "";
				brojacReci++;
				i++;
			}
		}


	}

int PrviProlaz::brojLabela(string s){
	
	podeliIzraz(s); 
	int broj = 0;
	for (unsigned i = 0; i < literali.size(); i++){
		if (tabelaSimbola->dohvatiSimbol(literali[i])){
			if (tabelaSimbola->dohvatiSimbol(literali[i])->getBrojSekcije() != -1)
			broj++;
		}
	}
	return broj;
}

string PrviProlaz::srediIns(string b, int vel){
	string vrati = "";
	string hex = BitUHex(b);
	return hex;

}

void PrviProlaz::srediRelok(string s){
	if (!daLiJeIzraz(s)){
		if (staJeKonstanta(s) == 0){
			//nije obican broj, pa proveri dal je labela ili kontanta sa def
			if (brojLabela(s) == 1){
				//obradjujem relokaciju za labelu
				if ((tabelaSimbola->dohvatiSimbol(s)->getOrg() == false) || (tabelaSimbola->dohvatiSimbol(s)->getOrg() == true && linija.find("$")!=string::npos)){
					simbolRelok = s;
					if (tabelaSimbola->dohvatiSimbol(s)->getFlags() == "G"){
						vrednostIns = 0;
						labFlag = "G";
						return;
					}
					else{
						labFlag = "L";
						if (!linija.find("$") != string::npos && tabelaSimbola->dohvatiSimbol(s)->getOrg() == true){
							
							if (tabelaSimbola->dohvatiSimbol(s)->getBrojSekcije() != tabelaSimbola->dohvatiSimbol(sek)->getBrojSekcije()){
								int rbr = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
								SimboliUlaz* get = tabelaSimbola->dohvatiPoR(rbr);
								int razlika = HexToDec(tabelaSimbola->dohvatiSimbol(simbolRelok)->getPocetnuAdresu()) - HexToDec(get->getPocetnuAdresu());
								s = to_string(razlika);
							}
						}


					}
				}
			}  
			dup = 1;
			vrednostIns = dupdef(s);
		}
		else{
			dup = 1;
			//NEG
			if (negativanBroj) {
				vrednostIns = dupdef(s.substr(1)); //NEG
				vrednostIns = 0 - vrednostIns;
			}
			else vrednostIns = dupdef(s);
			simbolRelok = ""; 
		}
		dup = 0;
	
	}
	else {
		
		int obradjenih = 0;
		obradjenih = brojLabela(s);
		int oduzeto, flagBio;
		flagBio = 0;
		podeliIzraz(s);
		int k = 0;

		while (obradjenih > 0){
	
			for (unsigned i = 0; i < literali.size(); i++){
				oduzeto = 0;
				if (tabelaSimbola->dohvatiSimbol(literali[i])){
					if (tabelaSimbola->dohvatiSimbol(literali[i])->getBrojSekcije() != -1){
					
						for (unsigned j = i + 1; j < literali.size(); j++){
							k = j;
							if (tabelaSimbola->dohvatiSimbol(literali[j])){
								if (tabelaSimbola->dohvatiSimbol(literali[j])->getBrojSekcije() != -1 && tabelaSimbola->dohvatiSimbol(literali[i])->
									getBrojSekcije() == tabelaSimbola->dohvatiSimbol(literali[j])->getBrojSekcije()){
									if ((((i == 0) || literali[i-1].compare("(")==0) && literali[j - 1].compare("-") == 0) || (i>0 && ((kojiJeOperator(literali[i - 1]) == '+' && kojiJeOperator(literali[j - 1]) == '-') || kojiJeOperator(literali[i - 1]) == '-' && kojiJeOperator(literali[j - 1]) == '+'))){
									

										int racun = 0;
										if ((i == 0) || literali[i - 1].compare("(")==0) {
											if (HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu()) < HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu())) continue; //trazi sledecu labelu
											racun = HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu()) - HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu());
											if(i==0)literali[0] = to_string(racun);
											else literali[i] = to_string(racun);
											literali.erase(literali.begin() + (j-1));
											literali.erase(literali.begin() + (j-1));
											
											obradjenih = obradjenih - 2;
											oduzeto = 1;
											i = i - 1; 
											break;
											
										}
										else{
											if (literali[i - 1] == "+"){
												if (HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu()) < HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu())) continue;
												racun = HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu()) - HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu());
												literali.erase(literali.begin() + (i - 1));
												literali.erase(literali.begin() + (i-1));
												literali.erase(literali.begin() + (j - 3));
												literali.erase(literali.begin() + (j-3));
												literali.push_back("+");
												literali.push_back(to_string(racun));
												obradjenih= obradjenih -2;
												oduzeto = 1;
												i = i - 1;
												break;
											}
											else {
												if (HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu()) < HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu())) continue;
												racun = HexToDec(tabelaSimbola->dohvatiSimbol(literali[j])->getPocetnuAdresu()) - HexToDec(tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu());
												literali.erase(literali.begin() + (i - 1));
												literali.erase(literali.begin() + (i-1));
												literali.erase(literali.begin() + (j-3));
												literali.erase(literali.begin() + (j-3));
												literali.push_back("+");
												literali.push_back(to_string(racun));
												obradjenih= obradjenih -2;
												oduzeto = 1;
												i = i - 1;
												break;
											}
										}




									}
									else {
										error = "Nedozvoljena upotreba labela";
										
										break;
									}
									continue; //trebalo bi da izlazi iz j petlje
								}
							}
						}

						//ako postoji samo jedan simbol
						//ako nemamo sa cim da je uparimo!!!!!
						if ((oduzeto==0) && (k = literali.size())){
							
							if (flagBio == 1) {
								error = "Nedozvoljeno koriscenje labela!!!";
								return;
							}
							if ((tabelaSimbola->dohvatiSimbol(literali[i]) != 0 && tabelaSimbola->dohvatiSimbol(literali[i])->getOrg() == false) || (tabelaSimbola->dohvatiSimbol(literali[i]) != 0 && tabelaSimbola->dohvatiSimbol(literali[i])->getOrg() == true && ins && (linija.find("$") != string::npos))){ //vise literali[i] nisu isto
								simbolRelok = literali[i];
								obradjenih--;
								flagBio = 1;
								if (tabelaSimbola->dohvatiSimbol(literali[i])->getFlags() == "G"){
									
									labFlag = "G";
									if (i == 0){
										//da stavimo 0 umesto njega u izrazu
										//literali.erase(literali.begin() + i);
										//literali.erase(literali.begin() + i); 
										//i = i - 1; 
										literali[0] = "0";
									}
									else{
										//literali.erase(literali.begin() + (i - 1));
										//literali.erase(literali.begin() + (i - 1));
										//i = i - 2;
										literali[i] = "0";
									}
									
									//return;
								}
								else {
									labFlag = "L";
									if (linija.find("$") != string::npos && tabelaSimbola->dohvatiSimbol(literali[i])->getOrg() == true){
										
										int razlika = HexToDec(tabelaSimbola->dohvatiSimbol(simbolRelok)->getPocetnuAdresu()) - HexToDec(tabelaSimbola->dohvatiSimbol(sek)->getPocetnuAdresu());
										literali[i] = to_string(razlika);
									}


								}
							}
							else{
								if (tabelaSimbola->dohvatiSimbol(literali[i]) != 0 && tabelaSimbola->dohvatiSimbol(literali[i])->getOrg() == true)
								if (obradjenih == 1) {
									obradjenih--;
									break;
								}
							}

							
						}
				
					}
				}
			}

		}

		
		string rez;
		for (unsigned i = 0; i < literali.size(); i++){
			rez += literali[i];
		}
		dup = 1;
		vrednostIns = dupdef(rez);
		//NEG
		
		dup = 0;
	}
}

bool PrviProlaz::proveraRegistra(string r){
	if (r.at(0) == 'R'){
		string br = r.substr(1);
		int b = stoi(br);
		if (b >= 0 && b <= 15) return true;
		else return false;
	}
	else if (r.find("SP") != string::npos) return true;
	else return false;
}

int PrviProlaz::dupdef(string s){
		if (vrednosti.empty() == false){ 

			while (!vrednosti.empty()){
				vrednosti.pop_back();
			}
		}
		if (!daLiJeIzraz(s)){
			
			SimboliUlaz * sim = tabelaSimbola->dohvatiSimbol(s);
			if (sim == 0){
				char cc = ' ';
				cc = staJeKonstanta(s);
				string dec;
				if (cc == 'b') dec = BitUHex(s.substr(2));  
				else if (cc == 'c'){
					int d = (int)s.at(1); 
					return d;
				}
				else if (cc == 'd') return stoi(s);
				else if (cc == 'h') dec = s.substr(2);
				else dec = "";
				return HexToDec(dec);
			}
			else {
				if ((sim->getBrojSekcije() == -1 && sim->getPocetnuAdresu() != "-") || sim->getBrojSekcije() != -1) return HexToDec(sim->getPocetnuAdresu()); //MENJANO ZA DRUGI PROLAZ
				
			}
		}
		else {
			
			podeliIzraz(s); 
			for (unsigned i = 0; i < literali.size(); i++){
				string j = literali[i];
				if (kojiJeOperator(literali[i]) == 'e'){
					if (staJeKonstanta(literali[i]) != 0) {
						char cc = 0;
						cc= staJeKonstanta(literali[i]);
						string dec;
						
						if (cc == 'b') dec = BitUHex(literali[i].substr(2)); 
						else if (cc == 'd') dec = DecUHex(literali[i]);
						else if (cc == 'c'){
							dec = DecUHex(to_string((int)literali[i].at(1))); 
						}
						else if (cc == 'h') dec = literali[i].substr(2);
						else dec = "";
						vrednosti.push_back(to_string(HexToDec(dec)));
						continue;
					}
					if (dup){
						
						if (tabelaSimbola->dohvatiSimbol(literali[i])){
							string vrednost = tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu();
							if (vrednost != "-")
								vrednosti.push_back(to_string(HexToDec(vrednost)));
							else return -1; //ISPISI PORUKU DA DATI SIMBOL NIJE DEFINISAN ILI NE POSTOJI U TABELI SIMBOLA
						}
						else return -1;
					}
					else if (def){
						if (tabelaSimbola->dohvatiSimbol(literali[i])){
							string vrednost = tabelaSimbola->dohvatiSimbol(literali[i])->getPocetnuAdresu();
							if (vrednost != "-")
								vrednosti.push_back(to_string(HexToDec(vrednost)));
							else return -2; //ne moze se jos uvek izracunati vrednost datog simbolaa!!!    "-" za vrednost u t.s.
						}
						else return -2;
					}
				}
				else if (kojiJeOperator(literali[i]) != 'e') vrednosti.push_back(literali[i]);//
				else return -3; //nesto nije u redu sa izrazom!!!
			}
			
			
		}
		int rez = 0;
		rez = vrednostIzraza();
		//ako je rezultat negativan 
		char konst = staJeKonstanta(to_string(rez));
		if ((konst == 'd') && (negativanBroj == 1)){
		
		}
		return rez;
	}

string PrviProlaz::srediKod(int vrednost, int velicina){
	//NEG
	

	string vrati = "";
	int vel = velicina;
	string hex = DecUHex(to_string(vrednost)); 
	unsigned j = hex.size() - 1;
	for (int i = hex.size() - 1; i >= 0; i--){
		if (i > 0){ 
			if (hex[i] == ' '){
				vrati += hex[i - 2];
				vrati += hex[i-1];
				i--;
			}
			else{
				vrati += hex[i - 1];
				vrati += hex[i];
			}
			vrati += " ";
			i--;
			vel--;
		}
		
		else {
			if (i == j || i==0){
				if (!negativanBroj)
				vrati += "0";
				else vrati += "F";
				vrati += hex[i];
				vrati += " ";
				vel--;
			}
			else break;
		}
	}

	while (vel > 0){
		if (!negativanBroj)
		vrati += "00";
		else vrati += "FF";
		vrati += " ";
		vel--;
	}

	return vrati;


}
				
int PrviProlaz::velicinaInstrukcije(){
	if (pomocneReci.empty() == false){  

		while (!pomocneReci.empty()){
			pomocneReci.pop_back();
		}
	}

	if (labela) {
		for (unsigned int i = 1; i < reci.size(); i++)
			pomocneReci.push_back(reci[i]);
	}
	else{
		for (unsigned int i = 0; i < reci.size(); i++)
			pomocneReci.push_back(reci[i]);
	}

	int vrati = 0;

	string ime = pomocneReci[0];
	if (!ime.compare("ADD") || !ime.compare("SUB") || !ime.compare("MUL") || !ime.compare("DIV") || !ime.compare("MOD") || !ime.compare("AND")
		|| !ime.compare("OR") || !ime.compare("XOR") || !ime.compare("NOT") || !ime.compare("ASL") || !ime.compare("ASR") || !ime.compare("PUSH")
		|| !ime.compare("POP") || !ime.compare("INT")) {
		vrati = 4;
		if (!ime.compare("PUSH") || !ime.compare("POP") || !ime.compare("INT")) aritmeticke = 0;
		else aritmeticke = 1;
	}
	if (!ime.compare("RET")) {
		vrati = 4;
		ret = 1;
	}
	if (!ime.compare("JZ") || !ime.compare("JNZ") || !ime.compare("JGZ") || !ime.compare("JGEZ") ||
		!ime.compare("JLZ") || !ime.compare("JLEZ")){
		skokovi = 1;
		
		
		if (((pomocneReci[1].at(0) == 'R' && isdigit(pomocneReci[1].at(1))) || (pomocneReci[1].find("SP")!= string::npos)) && pomocneReci[2].at(0) == 'R') {
			adresiranje = "regdir";
			vrati = 4;
		}
		else if (((pomocneReci[1].at(0) == 'R' && isdigit(pomocneReci[1].at(1))) || (pomocneReci[1].find("SP") != string::npos)) && pomocneReci[2].at(0) == '[' && (pomocneReci[2].at(3) == ']' || pomocneReci[2].at(4) == ']')){
			vrati = 4;
			adresiranje = "regindir";
		}
		else if (((pomocneReci[1].at(0) == 'R' && isdigit(pomocneReci[1].at(1))) || (pomocneReci[1].find("SP") != string::npos)) && (pomocneReci[2].at(0) == '[' && (pomocneReci[2].find("+") != string::npos || pomocneReci[2].find("-") != string::npos)
			|| pomocneReci[2].at(0) == '$')) {
			vrati = 8;
			adresiranje = "pomeraj"; 
		}
		else {
			vrati = 8;
			adresiranje = "memdir";
		}
	}

	if (!ime.compare("JMP") || !ime.compare("CALL")){ 
		if (((pomocneReci[1].at(0) == 'R') && isdigit(pomocneReci[1].at(1))) || pomocneReci[1].find("SP") != string::npos){ // && (pomocneReci[1].size() == 4 || pomocneReci[1].size() == 5)){
			vrati = 4;  
			adresiranje = "regdir";
		}
		else if (pomocneReci[1].at(0) == '[' && (pomocneReci[1].at(3) == ']' || pomocneReci[1].at(4) == ']')){
			vrati = 4;
			adresiranje = "regindir";
		}
		else if ((pomocneReci[1].at(0) == '[' && daLiJeIzraz(pomocneReci[1])) 
			|| pomocneReci[1].at(0) == '$') {
			vrati = 8;
			adresiranje = "pomeraj";
			
		}
		else {
			vrati = 8;
			adresiranje = "memdir";
		}
	}

	if (!ime.compare(0, 4, "LOAD") || !ime.compare(0, 5, "STORE")){

		ls = 1;

		if ((pomocneReci[2].at(0) == 'R' && isdigit(pomocneReci[2].at(1))) || (pomocneReci[2].find("SP")!=string::npos)|| (pomocneReci[2].at(0) == '[' && (pomocneReci[2].at(3) == ']' || pomocneReci[2].at(4) == ']'))) {
			vrati = 4;
			if (pomocneReci[2].find("[") != string::npos) adresiranje = "regindir";
			else adresiranje = "regdir";
		}
		else if ((pomocneReci[2].at(0) == '[' && (pomocneReci[2].find("+") != string::npos || pomocneReci[2].find("-") != string::npos)) //dodato za minus
			|| pomocneReci[2].at(0) == '$') {
			vrati = 8;
			adresiranje = "pomeraj";
		}
		else if (pomocneReci[2].find("#") != string::npos){
			vrati = 8;
			adresiranje = "neposr"; 
		}
		else if ((pomocneReci[2].find("R") == string::npos) && (pomocneReci[2].find("#") == string::npos) && (pomocneReci[2].find("SP") == string::npos)) {
			vrati = 8;
			adresiranje = "memdir";
		}
		
		else vrati = 0;
	}


	return vrati;
}

void PrviProlaz::obrada(ifstream& ul, ofstream& iz){

	labela = brojacReci = dup = def = org = podatak = sekcija =ins = 0;
	error = "";

	while (getline(ul, linija)){
		if (literali.empty() == false){  

			while (!literali.empty()){
				literali.pop_back();
			}
		}
		if (reci.empty() == false){  

			while (!reci.empty()){
				reci.pop_back();
			}
		}

		smestiSimbol();

		if (!reci[0].compare(".end")) {
			if (tekucaSekcija != ""){
				int velicinaPrethodneSekcije = LC - HexToDec((tabelaSimbola->dohvatiSimbol(tekucaSekcija)->getPocetnuAdresu()));
				string dec = DecUHex(to_string(velicinaPrethodneSekcije));
				tabelaSimbola->dohvatiSimbol(tekucaSekcija)->setVelicinuSekcije(velicinaPrethodneSekcije);
				tabelaSimbola->dohvatiSimbol(tekucaSekcija)->setujVel(dec);
			}
			break;
			
		}

	
		if (org) {
			obradiORG(reci[1]);
			if (error != "") break; 
			direktivaORG = true;
			org = 0;
			continue;

		}

		if (EPG(reci[0])) {    

			for (unsigned int i = 1; i < reci.size(); i++){
				SimboliUlaz* simbol = 0;
				if (tabelaSimbola->dohvatiSimbol(reci[i])) {
					simbol = tabelaSimbola->dohvatiSimbol(reci[i]);
					simbol->setFlags("G");
				}
				else{
					simbol = new SimboliUlaz("SYM", reci[i], 0, "0", 0, "G");
					tabelaSimbola->dodajSimbol(simbol);
				}
			}
		}
		if (obradiSekciju(reci[0]) == true)
			continue;

		if (labela) {

			string imeLabele = "";
			int i = 0;
			while (reci[0].at(i) != ':') {
				imeLabele += reci[0].at(i);
				i++;
			}

			SimboliUlaz* dohvacenaSekcija = tabelaSimbola->dohvatiSimbol(tekucaSekcija);
			SimboliUlaz * noviSimbol = 0;
			int rbrSek = dohvacenaSekcija->getRedniBroj();
			string adresa = DecUHex(to_string(LC));
			if (!tabelaSimbola->dohvatiSimbol(imeLabele)){
				noviSimbol = new SimboliUlaz("SYM", imeLabele, rbrSek, adresa, 0, "L");
				tabelaSimbola->dodajSimbol(noviSimbol);
				if(vrednostORG != "n") tabelaSimbola->dohvatiSimbol(imeLabele)->setOrg();
			}
			else {
				noviSimbol = tabelaSimbola->dohvatiSimbol(imeLabele);
				noviSimbol->setBrojSekcije(rbrSek);
				noviSimbol->setPocetnuAdresu(adresa);
				if (vrednostORG != "n") noviSimbol->setOrg();
			}

			

		}
		
		if (labela && reci.size() == 1) continue; 

		if ((labela && podatak) || podatak){

			unsigned int brojPocetnihVrednosti;
			brojPocetnihVrednosti = 1;
			if (!dup){
				if (labela) brojPocetnihVrednosti = reci.size() - 2;
				else brojPocetnihVrednosti = reci.size() - 1;
				LC = LC+ sabirac*brojPocetnihVrednosti;
			}

			else{
				
				if (labela)
					brojPocetnihVrednosti = dupdef(reci[2]);
				else brojPocetnihVrednosti = dupdef(reci[1]);

				if (brojPocetnihVrednosti != -1)
					LC = LC+ sabirac * brojPocetnihVrednosti;
				else  {
					error = "Simbol se ne nalazi u tabeli simbola ili je nedefinisan jos uvek!";
					break;
				}
			}


		}
		if ((labela&&def) || def){
			
			SimboliUlaz* noviSimbol = 0;
			string sim = "";
			string vrednost = ""; 
			if (labela) {
				sim = reci[1];
				int vr = dupdef(reci[3]);
				if (vr != -2)
					vrednost = DecUHex(to_string(vr));
				else vrednost = "-";
			}
			else {
				sim = reci[0];
				int vr = dupdef(reci[2]);
				if (vr != -2)
					vrednost = DecUHex(to_string(vr));
				else vrednost = "-";
			}

			if (!tabelaSimbola->dohvatiSimbol(sim)){
				noviSimbol = new SimboliUlaz("SYM", reci[0], -1, vrednost, 0, "L");
				tabelaSimbola->dodajSimbol(noviSimbol);
			}
			else {
				noviSimbol = tabelaSimbola->dohvatiSimbol(sim);
				noviSimbol->setBrojSekcije(-1);
				noviSimbol->setPocetnuAdresu(vrednost);
			}

		}


		if (ins){
			LC += velicinaInstrukcije();
		}



	}
	if (error != "") iz << error;
	else 
	iz << *tabelaSimbola;
	iz << "\n";
	iz << "\n";

	ul.clear();

	ul.seekg(0, ios_base::beg);
}

void PrviProlaz::drugiProlaz(ifstream& ul, ofstream& iz){

	LC = 0;
	drugiP = true;
	direktivaORG = false; 
	labela = brojacReci = dup = def = org = podatak = sekcija = ins = 0;
	error = "";
	Sadrzaj* noviZapis = 0;
	sek = "";

	while (getline(ul, linija)){

		if (literali.empty() == false){

			while (!literali.empty()){
				literali.pop_back();
			}
		}
		if (reci.empty() == false){

			while (!reci.empty()){
				reci.pop_back();
			}
		}

		if (pomocneReci.empty() == false){

			while (!pomocneReci.empty()){
				pomocneReci.pop_back();
			}
		}

		if (in.empty() == false){

			while (!in.empty()){
				in.pop_back();
			}
		}
		

		smestiSimbol();

		if (EPG(reci[0])) continue;

		if (!reci[0].compare(".end")) break;

		if (obradiSekciju(reci[0])) {
			
			if (noviZapis){
				iz << (*noviZapis);
				noviZapis->~Sadrzaj();
				noviZapis = 0;
				
			}
			LC = HexToDec(tabelaSimbola->dohvatiSimbol(reci[0].substr(1))->getPocetnuAdresu());
			sek = reci[0].substr(1);
		    noviZapis = new Sadrzaj(reci[0].substr(1)); 
			continue;
		}

		if (org){
			direktivaORG = true;
			org = 0;
			continue;
		}

		if (def) continue;

		if ((labela && podatak) || podatak){

			//obrada relokacija za podatke!!!
			labFlag == "";
			unsigned int brojPocetnihVrednosti;
			brojPocetnihVrednosti = 1;
			if (labela) {
				for (unsigned int i = 1; i < reci.size(); i++)
					pomocneReci.push_back(reci[i]);
			}
			else{
				for (unsigned int i = 0; i < reci.size(); i++)
					pomocneReci.push_back(reci[i]);
			}

			int dupp = dup;
			if (!dupp)
				brojPocetnihVrednosti = pomocneReci.size() - 1;
			else brojPocetnihVrednosti = dupdef(pomocneReci[1]);
				
				for (unsigned i = 1; i <= brojPocetnihVrednosti; i++){

					negativanBroj = 0; //NEG
					int vrednostLC = 0;
					int rbrSim = 0;
					labFlag = "";
					
					if (!noviZapis->getSekciju().compare(0, 3, "bss")){
						if ((pomocneReci[i]).find("?") == string::npos)
							error = "U bss sekciji se mogu naci samo neinicijalizovani podaci!!!";
						break;
					}


					
						if (!dupp){
							if ((pomocneReci[i]).find("?") != string::npos)vrednostIns = 0;
							else srediRelok(pomocneReci[i]); 

						}
						else {
							if ((pomocneReci[3]).find("?") != string::npos)vrednostIns = 0;
							else srediRelok(pomocneReci[3]);
					}
					
					if (labFlag == "G"){
						vrednostLC = LC;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, sabirac); //vrednostIns koja moze da bude negativna
						noviZapis->dodajDeoIns(s);

					}
					else if(labFlag=="L"){
						vrednostLC = LC;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, sabirac);
						noviZapis->dodajDeoIns(s);

					}
					else{
		
						string s = srediKod(vrednostIns, sabirac);
						noviZapis->dodajDeoIns(s);
					}
			
					LC += sabirac;
					
				}
		}

		if ((labela && ins) || ins){

			if (labela) {
				for (unsigned int i = 1; i < reci.size(); i++)
					in.push_back(reci[i]);
			}
			else{
				for (unsigned int i = 0; i < reci.size(); i++)
					in.push_back(reci[i]);
			}

			int vrednostLC = 0;
			//int ins = 0;
			int rbrSim = 0;
			labFlag = "";
			string op = "";
			skokovi = ls = 0;
			aritmeticke = ret = 0;
			adresiranje = "";
			

			int lcIns = velicinaInstrukcije();
			string bit = "";
			map<string, string>::iterator it;

			if (ret){
				
				it = mape->mapIns.find(in[0]);
				bit += it->second;
				bit += "000000000000000000000000";
				string s = srediIns(bit, 4);
				noviZapis->dodajDeoIns(s);
				 
			}

			else if (aritmeticke){
				it = mape->mapIns.find(in[0]);
				bit += it->second; //dodam kod za instrukciju
				it = mape->mapAdr.find("regdir");
				bit += it->second;

				if (!proveraRegistra(in[1]) || !proveraRegistra(in[2])) {
					error = "Nelegalan registar!";
					break;
				}
				if (in[0].compare("NOT") && !proveraRegistra(in[3])) {
					error = "Nelegalan registar!";
					break;
				}

				for (unsigned i = 1; i < in.size(); i++){
					it = mape->mapReg.find(in[i]);
					bit += it->second;
				}
				if (!in[0].compare("NOT")) bit += "00000000000";
				else bit += "000000"; 
				string s = srediIns(bit, 4);
				noviZapis->dodajDeoIns(s);
			}

			else if (!in[0].compare("PUSH") || !in[0].compare("POP") || !in[0].compare("INT")){

				it = mape->mapIns.find(in[0]);
				bit += it->second;
				it = mape->mapAdr.find("regdir");
				bit += it->second;


				if (!proveraRegistra(in[1])) {
					error = "Nelegalan registar!";
					break;
				}

				it = mape->mapReg.find(in[1]);
				bit += it->second;
				bit += "0000000000000000";
				string s = srediIns(bit, 4);
				noviZapis->dodajDeoIns(s);
			}

			else if (!in[0].compare("CALL") || !in[0].compare("JMP") || skokovi){

				it = mape->mapIns.find(in[0]);
				bit += it->second;


				it = mape->mapAdr.find(adresiranje);
				bit += it->second;

				if (!in[0].compare("CALL") || !in[0].compare("JMP")) skokovi = 0;

				if (skokovi) {
					
					if (!proveraRegistra(in[1])) {
						error = "Nelegalan registar!";
						break;
					}

					it = mape->mapReg.find(in[1]);
					bit += it->second;

				}

				if (skokovi) op = in[2];
				else op = in[1];

				
				if (!adresiranje.compare("regdir") || !adresiranje.compare("regindir")){

					if (!adresiranje.compare("regindir")){
						op = op.substr(1, op.size() - 2);
					}
					

					if (!proveraRegistra(op)) {
						error = "Nelegalan registar!";
						break;
					}

					it = mape->mapReg.find(op);
					bit += it->second;

					if (!skokovi)
					bit += "0000000000000000";
					else bit += "00000000000"; 
					string s = srediIns(bit, 4);
					noviZapis->dodajDeoIns(s);

				}
				else if (!adresiranje.compare("memdir")){

					srediRelok(op);
					if (skokovi)
					bit += "0000000000000000";
					else bit += "000000000000000000000";

					if (labFlag == "G"){
						vrednostLC = LC+4;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);


					}
					else if (labFlag == "L"){
						vrednostLC = LC+4;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);

					}
					else{
						//ako je vratio samo broj, odnosno vrednostIns koju treba da upisem u instrukciju i ne treba da pravim zapis o relokaciji!
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);
					}



				}
				else if (!adresiranje.compare("pomeraj")){

					string op1 = "";

					if (op.find("$") != string::npos){
						//registarsko indirektno sa PC+ pomeraj  
						//LABELE IZ ISTE SEKCIJE NE IDU U RELOKACIJU, POMERAJ SE RACUNA

						string tek = noviZapis->getSekciju();

						if (op.find("$(") != string::npos){

							op1 = op.substr(2, op.size() - 3);
						}
						else op1 = op.substr(1);
							srediRelok(op1);

							if (skokovi){
								
								it = mape->mapReg.find("PC");
								bit += it->second;
								bit += "00000000000";
							}
							else{
								it = mape->mapReg.find("PC");
								bit += it->second;
								bit += "0000000000000000";
							}
							 
							
							int rez = 0;
							//ovo je kad mu ja sama namestam pomeraj,kad jesu iz iste sekcije
							if (labFlag != ""){
								if (tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije() == tabelaSimbola->dohvatiSimbol(tek)->getBrojSekcije()){
									//NECE BITI RELOKACIJE
									string izraz = "";
									int rez1 = 0;
									if (labFlag == "G"){ //DODAJ ZA ORG 
										if (vrednostIns<0)
										izraz = simbolRelok + to_string(vrednostIns);
										else izraz = simbolRelok + "+" + to_string(vrednostIns);
										dup = 1;
										rez1 = dupdef(izraz);
										dup = 0;
									}
									else rez1 = vrednostIns;
									int iz = LC + 8;
									izraz = to_string(rez1) + "-" + to_string(iz);
									rez = dupdef(izraz);
									labFlag = "";
									vrednostIns = rez;
								}
								else{
									
								}
							
							}
							else{
								int iz = LC + 8;
								string izraz = to_string(vrednostIns) + "-" + to_string(iz);
								rez = dupdef(izraz);
								vrednostIns = rez;
							}
						
							if (labFlag == "G"){
								vrednostLC = LC + 4; //ovde se desava relokacija,prepravljanje adresa * 
								//vrednostIns = 0;
								rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
								RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "R", rbrSim);
								noviZapis->dodajZapis(novi);
								vrednostIns = vrednostIns - 4;
								string s = srediKod(vrednostIns, 4);
								string ss = srediIns(bit, 4);
								string sss = ss + " " + s;
								noviZapis->dodajDeoIns(sss);


							}
							else if (labFlag == "L"){
								vrednostLC = LC + 4;
								//vrednostIns = 0;
								rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
								RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "R", rbrSim);
								//OVDE SE MENJA ZA LOKALNE ORGOVANE JER JE PROBLEM
								noviZapis->dodajZapis(novi);
								vrednostIns = vrednostIns - 4;
								string s = srediKod(vrednostIns, 4);
								//string s = srediKod(vrednostIns, 4);
								string ss = srediIns(bit, 4);
								string sss = ss + " " + s;
								noviZapis->dodajDeoIns(sss);

							}
							else{
							
								string s = srediKod(vrednostIns, 4);
								string ss = srediIns(bit, 4);
								string sss = ss + " " + s;
								noviZapis->dodajDeoIns(sss);
							}


						

					}
					else{
						//proveravam ovaj izraz posle R+ ...

						string r= "";
						string op1 = "";
						r += op.at(1);
						r += op.at(2);
						if (op.at(3) != ' ' && ((op.at(3) != '+') && (op.at(3) != '-'))) r += op.at(3);
						int j = 0;
						int flagMin=0;

						for (unsigned i = 0; i < op.size() - 2; i++){
							if (op.at(i) == '+' || op.at(i) == '-') { //dodato
								if (op.at(i) == '-')flagMin = 1;
								j = i;
								break;
							}
						
						}

							op1 = op.substr(j + 1);
							op1 = op1.substr(0, op1.size() - 1);
						if (!proveraRegistra(r)) {
							error = "Nelegalan registar!";
							break;
						}

						it = mape->mapReg.find(r);
						bit += it->second;

						if (skokovi) bit += "00000000000";
						else bit += "0000000000000000";

						
						srediRelok(op1); //ovo nam vraca vrednost ins
						if (flagMin) {
							vrednostIns = 0 - vrednostIns;
							flagMin = 0;
						}
						
						if (labFlag == "G"){
							vrednostLC = LC + 4;
							//vrednostIns = 0;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
							noviZapis->dodajZapis(novi);
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);


						}
						else if (labFlag == "L"){
							vrednostLC = LC + 4;
							//vrednostIns = 0;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
							noviZapis->dodajZapis(novi);
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);

						}
						else{
							
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);
						}



					}


				}

				else{
					error = "Nelegalno adresiranje!!!";
					break;
				}
			}
			else if (ls){

				
				string tip = "";

				if (in[0].size() > 4 && !in[0].compare(0, 4, "LOAD")) tip = in[0].substr(4);
				else if (in[0].size() > 5 && !in[0].compare(0, 5, "STORE")) tip = in[0].substr(5);
				else tip = "DD";


				//u mapama nemam load i store sa prefiksima!!!
				if (!in[0].find("LOAD")) in[0] = in[0].substr(0, 4);
				else  in[0] = in[0].substr(0, 5);
				it = mape->mapIns.find(in[0]);
				bit += it->second; //dodam kod za instrukciju


				it = mape->mapAdr.find(adresiranje);
				bit += it->second;

				op = in[2];
				string reg1 = in[1];



				if (!adresiranje.compare("regdir") || !adresiranje.compare("regindir")){


					if (!adresiranje.compare("regindir")){
						op = op.substr(1, op.size() - 2);
					}

					if (!proveraRegistra(reg1)) {
						error = "Nelegalan registar!";
						break;
					}

					it = mape->mapReg.find(reg1);
					bit += it->second;

					if (!proveraRegistra(op)) {
						error = "Nelegalan registar!";
						break;
					}

					it = mape->mapReg.find(op);
					bit += it->second;


					bit += "00000";
					it = mape->mapTip.find(tip);
					bit += it->second;
					bit += "000";

					string s = srediIns(bit, 4);
					noviZapis->dodajDeoIns(s);

				}
				else if (!adresiranje.compare("memdir")){


					bit += "00000"; 

					if (!proveraRegistra(reg1)) {
						error = "Nelegalan registar!";
						break;
					}

					it = mape->mapReg.find(reg1);
					bit += it->second;

					bit += "00000";
					it = mape->mapTip.find(tip);
					bit += it->second;
					bit += "000";

					srediRelok(op);
					if (labFlag == "G"){
						vrednostLC = LC + 4;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);


					}
					else if (labFlag == "L"){
						vrednostLC = LC + 4;
						//vrednostIns = 0;
						rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
						RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
						noviZapis->dodajZapis(novi);
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);

					}
					else{
						
						string s = srediKod(vrednostIns, 4);
						string ss = srediIns(bit, 4);
						string sss = ss + " " + s;
						noviZapis->dodajDeoIns(sss);
					}



				}

				else if (!adresiranje.compare("pomeraj")){

					string op1 = "";

					if (op.find("$") != string::npos){
						//registarsko indirektno sa PC+ pomeraj

						string tek = noviZapis->getSekciju();

						if (op.find("$(") != string::npos) op1 = op.substr(2, op.size() - 3);
						else op1 = op.substr(1);

						srediRelok(op1);

						it = mape->mapReg.find("PC");
						bit += it->second;
						it = mape->mapReg.find(reg1);
						bit += it->second;
						bit += "00000";
						it = mape->mapTip.find(tip);
						bit += it->second;
						bit += "000";


						int rez = 0;
				
						if (labFlag != ""){
							if (tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije() == tabelaSimbola->dohvatiSimbol(tek)->getBrojSekcije()){
							
								string izraz = "";
								int rez1 = 0;
								if (labFlag == "G"){
									if (vrednostIns<0)
										izraz = simbolRelok + to_string(vrednostIns);
									else izraz = simbolRelok + "+" + to_string(vrednostIns);
									dup = 1;
									rez1 = dupdef(izraz);
									dup = 0;
								}
								else rez1 = vrednostIns;
								int iz = LC + 8;
								izraz = to_string(rez1) + "-" + to_string(iz);
								rez = dupdef(izraz);
								labFlag = "";
							}

						}
						else{
							int iz = LC + 8;
							string izraz = to_string(vrednostIns) + "-" + to_string(iz);
							rez = dupdef(izraz);
							vrednostIns = rez;
						}

						if (labFlag == "G"){
							vrednostLC = LC + 4;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "R", rbrSim);
							noviZapis->dodajZapis(novi);
							vrednostIns = vrednostIns - 4;
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);


						}
						else if (labFlag == "L"){
							vrednostLC = LC + 4;
							//vrednostIns = 0;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "R", rbrSim);
							noviZapis->dodajZapis(novi);
							vrednostIns = vrednostIns - 4;
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);

						}
						else{
				
							string s = srediKod(rez, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);
						}


					}


					else{
						//proveravam ovaj izraz posle R+ ...

						string r = "";
						string op1 = "";
						r += op.at(1);
						r += op.at(2);
						if (op.at(3) != ' ' && ((op.at(3) != '+') && (op.at(3) != '-'))) r += op.at(3);

						int j = 0;
						int flagMin = 0;

						for (unsigned i = 0; i < op.size() - 2; i++){
							if (op.at(i) == '+' || op.at(i) == '-') {
								if (op.at(i) == '-') flagMin = 1;
								j = i;
								break;
							}

						}

						op1 = op.substr(j + 1);
						op1 = op1.substr(0, op1.size() - 1);
						if (!proveraRegistra(r)) {
							error = "Nelegalan registar!";
							break;
						}

						it = mape->mapReg.find(r);
						bit += it->second;

						it = mape->mapReg.find(reg1);
						bit += it->second;

						bit += "00000";
						it = mape->mapTip.find(tip);
						bit += it->second;
						bit += "000";

						
						srediRelok(op1);
						if (flagMin){
							vrednostIns = 0 - vrednostIns;
							flagMin = 0;
						} 

						if (labFlag == "G"){
							vrednostLC = LC + 4;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getRedniBroj();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
							noviZapis->dodajZapis(novi);
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);


						}
						else if (labFlag == "L"){
							vrednostLC = LC + 4;
							rbrSim = tabelaSimbola->dohvatiSimbol(simbolRelok)->getBrojSekcije();
							RelZapis* novi = new RelZapis(DecUHex(to_string(vrednostLC)), "A", rbrSim);
							noviZapis->dodajZapis(novi);
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);

						}
						else{
							
							string s = srediKod(vrednostIns, 4);
							string ss = srediIns(bit, 4);
							string sss = ss + " " + s;
							noviZapis->dodajDeoIns(sss);
						}



					}


				}

				else if (!adresiranje.compare("neposr")){

					if (!in[0].compare("STORE")){
						error = "Neposredno adresiranje nije dozvoljeno kod load instrukcije!";
						break;
					}

					
					bit += "00000";
					it = mape->mapReg.find(reg1);
					bit += it->second;
					bit += "00000";

					it = mape->mapTip.find(tip);
					bit += it->second;
					bit += "000";
					

					srediRelok(op.substr(1));
					if (labFlag != ""){
						error = "Izraz mora biti konstantan!!!";
						break;
					}


					string s = srediKod(vrednostIns, 4);
					string ss = srediIns(bit, 4);
					string sss = ss + " " + s;
					noviZapis->dodajDeoIns(sss);

				}

			}
			LC += lcIns;

			//kraj
		}

	
		

		 

	}
	if (error != "") iz << error;
	else 
	iz << (*noviZapis); //da se ispise i poslednji zapis
	iz << "\n";
	iz << "#end";


}
