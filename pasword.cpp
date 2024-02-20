#include "pasword.h"
#include <iostream>
void copyArray (char* ArrayToCopy, char* ArrayEmpty, int size){
    for (int i = 0; i < size; i++)
    {
        ArrayEmpty[i]=ArrayToCopy[i];
    }
}

void resizePasword (Pasword& Pasword1 ,int newSize ,char fillerElement) {
    char *copyContent = new char[Pasword1.size+1] ;
    copyArray(Pasword1.leters,copyContent,Pasword1.size);
    copyContent[Pasword1.size]=fillerElement;
    Pasword1.leters = new char[Pasword1.size+1];
    Pasword1.size++;
    copyArray(copyContent,Pasword1.leters,Pasword1.size);
}

void showPasword(Pasword& Pasword1){
    for (int i = 0; i < Pasword1.size; i++)
    {
        std::cout << Pasword1.leters[i];
    }
    
}