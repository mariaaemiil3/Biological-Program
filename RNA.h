#ifndef RNA_H
#define RNA_H
#include"Sequence.h"
#include"protein.h"
#include"DNA.h"
#include"codonstable.h"

class Protein;
class CodonsTable;
class DNA;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
private:
    RNA_Type type;
    int length;
public:
    RNA();
    RNA(char * seq, RNA_Type atype,int l);
    RNA(RNA& rhs);
    ~RNA();
    class xInvalidRNAchar {};
    class xInvalidProteinSize {};
    void Print();
    void LoadSequencefromFile(char *filename);
    void SaveSequenceToFile(char *filename);
    Protein ConvertToProtein( CodonsTable & table);
    DNA ConvertToDNA();
    friend bool operator !=(RNA & obj1, RNA& obj2);
    friend bool operator ==(RNA & obj1, RNA& obj2);
    friend RNA operator+(RNA& obj1, RNA& obj2);
    friend ostream& operator<<(ostream& out,const RNA &obj);
    friend istream& operator>>(istream& in,RNA& obj);
};

#endif // RNA_H
