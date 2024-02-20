#include <iostream>
#include <fstream>
#include <string>
#include "pasword.cpp"
using namespace std;

int main(){
	Pasword firstPasword;
	firstPasword.leters[0]='a';
	showPasword(firstPasword);
	resizePasword(firstPasword,firstPasword.size,'a');
	showPasword(firstPasword);
}
