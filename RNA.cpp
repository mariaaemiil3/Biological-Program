#include "RNA.h"
#include"DNA.h"
#include<iostream>

using namespace std;
///Default Constructor
RNA::RNA()
{
    seq=new char[0];
    //type=mRNA;
}
///Parametrized Constructor
RNA:: RNA(char * seq, RNA_Type atype,int l)
{
    this->seq=seq;
    type=atype;
    this->length=l;
    for(int i=0; i<length; i++)
    {
        if(seq[i] != 'A' && seq[i] != 'U' && seq[i] != 'G' && seq[i] != 'C')
        {
            throw xInvalidRNAchar();
        }
    }
}
///Copy Constructor
RNA::  RNA(RNA& rhs)
{
    this->seq = new char [ rhs.length ];
    this->length = rhs.length;

    char * a = rhs.getSeq();
    for ( int i = 0; i < rhs.length; i++ )
        this->seq[ i ] = a[ i ];

    this->seq[ rhs.length ] = '\0';
}
///Print function that prints the sequence & type of an RNA object
void RNA::Print()
{
    cout << "The type of your RNA sequence is: "<< type <<endl;
    cout << "Your RNA sequence is: ";
    for(int i=0; i < length; i++)
    {
        cout << this->seq[i];
    }
    cout<<endl;
}

void RNA :: LoadSequencefromFile(char *filename)
{
    string data,temp;
    ifstream filee;
    filee.open(filename,ios::in);
    while(!filee.eof())
    {
        getline(filee,data);
        temp+=data;
    }
    filee.close();
    cout << temp << endl;
}

void RNA :: SaveSequenceToFile(char* filename)
{
    string typee,seqq;
    cout << "Please, Enter the type of the sequence: " << endl;
    cin >> typee;
    cout << "Please, Enter the sequence: " << endl;
    cin >> seqq;
    ofstream file;
    file.open(filename,ios::out);
    file << "RNA Sequence \n";
    file <<"TYPE: " << typee << "\n";
    file << "SEQUENCE: " << seqq << "\n";
    file.close();
}
///Conversion to Protein Function
Protein RNA::ConvertToProtein( CodonsTable & table)
{
    RNA* Protein_strand=new RNA;
    Protein_strand->seq=new char[length];

    if(length%3==0)
    {
        for(int i=0; i<length; i+=3)
        {
            for(int j=0; j<64; j++)
            {
                if((seq[i]==table.codons[j].value[0]) && (seq[i+1]==table.codons[j].value[1]) && (seq[i+2]==table.codons[j].value[2]))
                {
                    Protein_strand->seq[i]=table.codons[j].AminoAcid;
                }
            }
            cout << Protein_strand->seq[i];
        }
        Protein new_Protein(Protein_strand->seq,Cellular_Function,Protein_strand->length);
        return (new_Protein);
    }
    else
    {
        throw xInvalidProteinSize();
    }
}
///Conversion to DNA function
DNA RNA:: ConvertToDNA()
{
    RNA*DNA_strand=new RNA;
    DNA_strand->seq=new char [length];

    for(int i = 0; i < length; i++)
    {

        if(seq[i] == 'U')
        {
            DNA_strand->seq[i] = 'T';
        }
        else
        {
            DNA_strand->seq[i] = seq[i];
        }
        cout<< DNA_strand->seq[i];
    }

    DNA new_DNA(DNA_strand->seq,promoter,length);

    return(new_DNA);
}
///Not Equal operator
bool operator !=(RNA& obj1, RNA& obj2)
{

    int counter=0;
    if (obj1.type != obj2.type)
    {
        ///cout << "The two Sequences are not equal";
        return true;
    }
    else
    {
        if (obj1.length != obj2.length)
        {
            ///cout << "The two sequences are not equal";
            return true;
        }
        else
        {
            for (int i=0; i < obj1.length; i++ )
            {
                if (obj1.seq[i] == obj2.seq[i])
                {
                    counter++;
                }
            }
            if ( counter == obj1.length)
            {
                ///cout << "ERROR, The two sequences are equal";
                return false;
            }
            else
            {
                ///cout << "The two sequences are not equal";
                return true;
            }
        }
    }
}
///Equal operator
bool operator ==(RNA & obj1, RNA& obj2)
{

    int counter=0;
    if (obj1.type != obj2.type)
    {
        ///cout << "The two Sequences are not equal";
        return false;
    }
    else
    {
        if (obj1.length != obj2.length)
        {
            ///cout << "The two sequences are not equal";
            return false;
        }
        else
        {
            for (int i=0; i < obj1.length; i++ )
            {
                if (obj1.seq[i] == obj2.seq[i])
                {
                    counter++;
                }
            }
            if ( counter == obj1.length)
            {
                ///cout << "The two sequences are equal";
                return true;
            }
            else
            {
                ///cout << "ERROR, The two sequences are not equal";
                return false;
            }
        }
    }
}

ostream& operator<<(ostream& out, const RNA &obj)
{
    out << "SEQUENCE: ";
    out << obj.seq<<endl;
    out << "TYPE: ";
    out<< obj.type<<endl;
    out << "LENGTH: ";
    out<<obj.length<<endl;
    return out;
}

istream& operator>>(istream& in,RNA &obj)
{
    int type=0;

    cout << "Enter the number of the type of your RNA sequence: " << endl;
    in >> type;

    obj.type=static_cast <RNA_Type>(type);

    cout << "Enter the size of your RNA sequence: " << endl;
    in >> obj.length;

    //char* arr=new char[(obj.length+1)];
    cout << "Enter your RNA sequence: " << endl;
    in >> obj.seq;
    obj.seq[(obj.length+1)]='\0';


    return in;
}
///Operator +
RNA operator+(RNA& obj1, RNA& obj2)
{

    RNA *new_strand=new RNA;
    new_strand->seq= new char[(obj1.length+obj2.length+1)];
    if(obj1.type==obj2.type)
    {
        new_strand->seq[(obj1.length+obj2.length+1)]='\0';
        for(int i=0; i<obj1.length; i++)
        {
            new_strand->seq[i]=obj1.seq[i];
        }
        int c=0;
        for(int i=obj1.length; i<(obj1.length+obj2.length); i++)
        {
            new_strand->seq[i]=obj2.seq[c];
            c++;
        }
    }
    RNA Rna(new_strand->seq,obj1.type,(obj1.length+obj2.length));
    cout << Rna << endl;
    return (Rna);
}
///Destructor
RNA::~RNA()
{
    delete []seq;
}
