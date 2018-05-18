#include "Postfix.h"
#include "Obrada.h"


Postfix::Postfix(){

}

Postfix::~Postfix(){

}

vector<string> Postfix::post;
stack<int> Postfix::racun;

bool Postfix::daLiJeOperator(string s){
	if (!s.compare("+") || !s.compare("-") || !s.compare("*") || !s.compare("/") || !s.compare("(") || !s.compare(")"))
		return true;
	else return false;
}


int Postfix::proritetOperatora(string s){
	if (!s.compare("+")) return 1;
	else if (!s.compare("-")) return 1;
	else if (!s.compare("*")) return 2;
	else if (!s.compare("/")) return 2;
	else if (!s.compare("(")) return 0;
	else return 3;
}


void Postfix::uPostfix(vector<string> *v){
	prioritetPrethodnog = 0;
	
	//ovde koristim samo ovaj vektor post da stavim postfiksni oblik
	stack<string> operatori;
	string j;
	for (unsigned i = 0; i < (*v).size(); i++){
		
		j = (*v)[i];
		if (daLiJeOperator(j)){
			if (((proritetOperatora(j) > prioritetPrethodnog) || (proritetOperatora(j) == 0)) && proritetOperatora(j) != 3) {
				operatori.push(j);
				if (!operatori.empty())
				prioritetPrethodnog = proritetOperatora(operatori.top());  
			}
			else if (proritetOperatora(j) == 3){
				while (operatori.top() != "("){
					string t = operatori.top();
					post.push_back(t);
					operatori.pop();
					
				}
				operatori.pop();
				if (!operatori.empty())
				prioritetPrethodnog = proritetOperatora(operatori.top());
				else prioritetPrethodnog = 0;
			}
			else if (proritetOperatora(j) == prioritetPrethodnog && !operatori.empty()){
				string t = operatori.top();
				post.push_back(t);
				operatori.pop();
				operatori.push(j);
				prioritetPrethodnog = proritetOperatora(operatori.top());
			}
			
			else{
				
				if (!operatori.empty()){
					string t = operatori.top();
					post.push_back(t);
					operatori.pop();
					operatori.push(j);
					prioritetPrethodnog = proritetOperatora(operatori.top());
				}
			}
		
			

		}
		else{
		
			post.push_back(j);
		}
		
		}
	//izbaci jos sve operatore sa steka
	while (!operatori.empty()){
		string t = operatori.top();
		post.push_back(t);
		operatori.pop();
	}


}

int Postfix::vrednostIzraza(){
	signed int rezultat;
	signed int op1, op2;

	for (unsigned i = 0; i < post.size(); i++){
		string p = post[i];
		if (!daLiJeOperator(p)) racun.push(stoi(p));
		else{
			op2 = racun.top();
			racun.pop();
			op1 = racun.top();
			racun.pop();

			if (!p.compare("+")) rezultat = op1 + op2;
			else if (!p.compare("-"))
				rezultat = op1 - op2; 
				
			

			else if (!p.compare("*")) rezultat = op1 * op2;
			else if (!p.compare("/")) rezultat = op1 / op2;
			else rezultat = 0;
			racun.push(rezultat);
		}
	}

	return rezultat;


}
