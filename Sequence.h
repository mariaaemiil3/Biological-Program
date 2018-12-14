#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>

using namespace std;

class Sequence
{
public:
    char*seq;
    Sequence();
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    virtual void Print()= 0;
    virtual void SaveSequenceToFile(char *filename) = 0;
    virtual void LoadSequencefromFile(char *filename) = 0;
    friend char* Align(Sequence * s1, Sequence * s2,int m, int n);
    char* getSeq();
};

#endif // SEQUENCE_H
