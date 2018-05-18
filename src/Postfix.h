#ifndef  _POSTFIX_H_
#define _POSTFIX_H_

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


class Postfix{
public:

	friend class Obrada;
	Postfix();
	~Postfix();
	int prioritetPrethodnog;
	static vector <string> post;
	static stack<signed int> racun;

	bool daLiJeOperator(string s);
	int proritetOperatora(string s);
	void uPostfix(vector <string> * v);
	int vrednostIzraza();

};

#endif 
