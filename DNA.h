#ifndef DNA_H
#define DNA_H
#include"Sequence.h"
#include"RNA.h"

class RNA;
enum DNA_Type {promoter, motif, tail, noncoding};
class RNA;
class DNA:public Sequence
{
private:
    DNA_Type type;
    DNA * complementary_strand;
    DNA *new_comlementary_strand;
    int startIndex;
    int endIndex;

public:
    int length;
    DNA();
    DNA(char * seq, DNA_Type atype,int l);
    DNA(DNA& rhs);
    ~DNA();
    void makkingNewSequence(int newLength);
    void setSeq(string newSeq);
    class xInvalidDNAchar {};
    void Print();
    void LoadSequencefromFile(char *filename);
    void SaveSequenceToFile(char *filename);
    void BuildComplementaryStrand();
    RNA ConvertToRNA();
    friend bool operator !=(DNA & obj1, DNA& obj2);
    friend bool operator ==(DNA & obj1, DNA& obj2);
    friend ostream& operator<<(ostream& out,const DNA &obj);
    friend istream& operator>>(istream& in,DNA &obj);
    friend DNA operator+(DNA& obj1, DNA& obj2);
};

#endif // DNA_H
