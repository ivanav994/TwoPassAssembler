#include "Obrada.h"



int main(int argc, char* argv[]){

	ifstream ulaz;

	ulaz.open(argv[1]);
	ofstream izlaz;
	izlaz.open(argv[2]);

	PrviProlaz* ob = new PrviProlaz();
	
	if (ulaz.fail()){
		cout << "Neuspesno otvranje fajla!\n";
	}
	else{
		ob->obrada(ulaz, izlaz);
		ob->drugiProlaz(ulaz, izlaz);

		ulaz.close();
		izlaz.close();
	}
	return 0;
}