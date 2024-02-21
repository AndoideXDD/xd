#include "pasword.h"
#include <iostream>
#include <cmath>
#include <windows.h>
#include <fstream>

void copyArray (char* ArrayToCopy, char* ArrayEmpty, int size){
    for (int i = 0; i < size; i++)
    {
        ArrayEmpty[i]=ArrayToCopy[i];
    }
}

void resizePasword (Pasword& Pasword1 ,int newSize ,char fillerElement) {
    int ntimesToRun= newSize - Pasword1.size;
    for (int i = 0; i < ntimesToRun; i++)
    {
        char *copyContent = new char[Pasword1.size+1] ;
        copyArray(Pasword1.leters,copyContent,Pasword1.size);
        copyContent[Pasword1.size]=fillerElement;
        delete[] Pasword1.leters;
        Pasword1.leters = new char[Pasword1.size+1];
        Pasword1.size++;
        copyArray(copyContent,Pasword1.leters,Pasword1.size);
        delete[] copyContent;
    }
    
    
}

void showPasword(Pasword& Pasword1){
    for (int i = 0; i < Pasword1.size; i++)
    {
        std::cout << Pasword1.leters[i];
    }
    std::cout << "\n";   
}

void showPaswordValues(Pasword& Pasword1){
    for (int i = 0; i < Pasword1.size; i++)
    {
        std::cout << int(Pasword1.leters[i]) << " ";
    }
    std::cout << "\n";   
}

int calculeteIterations(int paswordSize){
    // It's elevated to paswordSize - 1 due that I have a for that runs for each iteration
    // ASCISIZE for the first position, so actually each time enter the loop we sum +1 
    // to the postion [1]
    // And ASCISIZE + 1 represent the base of the char
    return pow(ASCISIZE + 1 , paswordSize - 1) ;
}

void iteretePossiblePaswords(Pasword& Pasword1){
    long long int nTimesToRun = calculeteIterations(Pasword1.size);
    std::ofstream outFile ("paswords.txt");
    for (int i = 0; i < nTimesToRun; i++)
    {
        int positionPasword=0;
        for (int i = 0; i <= ASCISIZE; i++)
        {
            Pasword1.leters[positionPasword]++;
            
            //outFile << Pasword1.leters;
            
        }
        Pasword1.leters[positionPasword]=0;
        int value=Pasword1.leters[positionPasword+1]+1;
        if(value < ASCISIZE ) { Pasword1.leters[positionPasword+1]++; }
        else 
        {
            while (value > ASCISIZE)
            {
                positionPasword++;
                Pasword1.leters[positionPasword]=0;
                Pasword1.leters[positionPasword+1];
                value=Pasword1.leters[positionPasword+1]+1;
            }
            Pasword1.leters[positionPasword+1]++;
        }
    }
    outFile.close();
    showPasword(Pasword1);
    //std::cout << "\npositionPasword : " << positionPasword  << " Pasword size : " << Pasword1.size << "\n";
}
