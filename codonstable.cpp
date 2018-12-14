#include "codonstable.h"
#include"Sequence.h"
#include<fstream>
#include<iostream>
#include"codonstable.h"

using namespace std;
///Default Constructor
CodonsTable:: CodonsTable()
{

    value1 = new char[3];
    value3 = new char[3];
    for(int i = 0; i < 64; i++)
    {
        codons[i].value[i]='\0';
        codons[i].AminoAcid='\0';
    }

}
///Destructor
CodonsTable::~CodonsTable()
{
    delete [] value1;
    delete [] value3;
}
///Function to load the codons from the file
void CodonsTable::LoadCodonsFromFile(string codonsFileName)
{
    string data="",temp="";
    char filename[20];
    for (int i=0; i<codonsFileName.size(); i++)
    {
        filename[i]=codonsFileName[i];
    }
    ifstream file;
    file.open(filename,ios::in);

    while((!file.eof()))
    {
        for(int i = 0; i < 64; i++)
        {
            file >> codons[i].value[0];
            file >> codons[i].value[1];
            file >> codons[i].value[2];
            file >> codons[i].AminoAcid;
        }
    }

    file.close();
}

Codon CodonsTable:: getAminoAcid(char*t)
{

    value1 = t;

    LoadCodonsFromFile("RNA_codon_table.txt");
    for(int i = 0; i < 64; i++)
    {
        if(codons[i].value[0] == value1[0] && codons[i].value[1] == value1[1] && codons[i].value[2] == value1[2])
        {
            return (codons[i]);
        }
    }
}

void CodonsTable:: setCodon(char * value2, char AminoAcid1, int index)
{

    value3=value2;
    amino=AminoAcid1;

    LoadCodonsFromFile("RNA_codon_table.txt");
    codons[index].value[0]=value3[0];
    codons[index].value[1]=value3[1];
    codons[index].value[2]=value3[2];
    codons[index].AminoAcid=amino;

    cout << codons[index].value[0];
    cout << codons[index].value[1];
    cout << codons[index].value[2];
    cout << codons[index].AminoAcid;

}
