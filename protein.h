#ifndef PROTEIN_H
#define PROTEIN_H
#include"Sequence.h"
#include"RNA.h"
#include"DNA.h"
#include"codonstable.h"
#include <vector>
#include <cstring>

enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};
class DNA;
class RNA;
class CodonsTable;
class Protein:public Sequence
{
private:
    Protein_Type type;
    char *A;
public:
    int length;
    Protein();
    void Print();
    void LoadSequencefromFile(char *filename);
    void SaveSequenceToFile(char *filename);
    Protein(char * A,Protein_Type atype, int l);
    DNA* GetDNAStrandsEncodingMe( const  DNA & bigDNA);
    ~Protein();
    friend bool operator !=(Protein & obj1, Protein& obj2);
    friend bool operator ==(Protein & obj1, Protein& obj2);
    friend Protein operator+(Protein& obj1, Protein& obj2);
    friend ostream& operator<<(ostream& out,const Protein &obj);
    friend istream& operator>>(istream& in,Protein &obj);
};

#endif // PROTEIN_H
