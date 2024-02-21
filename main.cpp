#include <iostream>
#include <fstream>
#include <string>
#include "pasword/pasword.cpp"
using namespace std;

int main(){
	Pasword firstPasword;
	firstPasword.leters[0]=0;
	firstPasword.size=1;
	resizePasword(firstPasword,4,0);	 
	showPasword(firstPasword);
	iteretePossiblePaswords(firstPasword);
}
