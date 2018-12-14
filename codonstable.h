#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include"iostream"
#include<string>
#include<fstream>

using namespace std;

struct Codon
{
    char value[4];
    char AminoAcid;
};

class CodonsTable
{
private:

    char*value1;
    char*value3;
    char amino;

public:
    Codon codons[64];
    CodonsTable();
    ~CodonsTable();
    void LoadCodonsFromFile(string codonsFileName);
    Codon getAminoAcid(char *t);
    void setCodon(char *value, char AminoAcid, int index);
};

#endif // CODONSTABLE_H
