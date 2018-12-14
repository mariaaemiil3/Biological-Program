#include "DNA.h"
#include"Sequence.h"
#include<iostream>

using namespace std;
///Default Constructor
DNA::DNA()
{
    seq=new char[0];
}
///Parametrized Constructor
DNA::DNA(char * seq, DNA_Type atype,int l)
{

    this->seq=seq;
    type=atype;
    this->length=l;
    for(int i=0; i<length; i++)
    {
        if(seq[i] != 'A' && seq[i]!='T' && seq[i]!='G' && seq[i]!='C')
        {
            throw xInvalidDNAchar();
        }
    }
}
///Copy Constructor
DNA::DNA(DNA& rhs)
{

    this->seq = new char [ rhs.length ];
    this->length = rhs.length;

    char * a = rhs.getSeq();
    for ( int i = 0; i < rhs.length; i++ )
        this->seq[ i ] = a[ i ];

    this->seq[ rhs.length ] = '\0';
    //cout << "F :: " << this->seq << endl;
}
///Print function that prints the sequence, type & length of an object from this class
void DNA::Print()
{

    cout << "The type of your sequence if from type: " << type <<endl;
    cout << "Your DNA sequence is: ";
    for(int i=0; i < length; i++)
    {

        cout<< this->seq[i];
    }
    cout << endl;
}
///Conversion to RNA function
RNA DNA ::ConvertToRNA()
{

    cout << "Enter start Index : ";
    cin >> startIndex;
    cout << "Enter end Index :";
    cin >> endIndex;

    DNA*new_comlementary_strand=new DNA;
    new_comlementary_strand->seq=new char [endIndex-startIndex];

    for(int i=startIndex; i <= endIndex; i++)
    {
        if(seq[i] == 'T')
        {
            new_comlementary_strand->seq[i]='U';
        }
        else
        {
            new_comlementary_strand->seq[i]=seq[i];
        }
        cout << new_comlementary_strand->seq[i];
    }
    cout<<endl;
    RNA new_RNA(new_comlementary_strand->seq,mRNA,(endIndex-startIndex));

    return(new_RNA);
}
///Function to make the complementary strand in this function
void DNA:: BuildComplementaryStrand()
{

    cout << "Enter start Index: ";
    cin >> startIndex;
    cout << "Enter end Index: ";
    cin >> endIndex;
    if (startIndex == -1 && endIndex == -1)
    {
        startIndex = 0;
        endIndex = length;
    }

    complementary_strand=new DNA;
    complementary_strand->seq=new char[endIndex-startIndex];

    for(int i=startIndex; i <= endIndex; i++)
    {
        if(seq[i] == 'A')
        {
            complementary_strand->seq[i] = 'T';
        }
        else if(seq[i] == 'T')
        {
            complementary_strand->seq[i] = 'A';
        }
        else if(seq[i] == 'C')
        {
            complementary_strand->seq[i] = 'G';
        }
        else if(seq[i] == 'G')
        {
            complementary_strand->seq[i] = 'C';
        }
    }
    for(int i=endIndex; i >= startIndex; i--)
    {

        cout<<complementary_strand->seq[i];
    }

    cout<<endl;
}
///Destructor
DNA::~DNA()
{
    delete [] seq;
}

ostream& operator<<(ostream& out, const DNA &obj)
{
    out << "SEQUENCE: ";
    out << obj.seq<<endl;
    out << "TYPE: ";
    out<< obj.type<<endl;
    out << "LENGTH: ";
    out<<obj.length<<endl;
    return out;
}

istream& operator>>(istream& in,DNA &obj)
{
    int type=0;

    cout << "Enter the number of the type of your DNA sequence: " << endl;
    in >> type;

    obj.type=static_cast <DNA_Type>(type);

    cout << "Enter the size of your DNA sequence: " << endl;
    in >> obj.length;

    // char* arr=new char[(obj.length+1)];
    cout << "Enter your DNA sequence: " << endl;
    in >> obj.seq;
    obj.seq[(obj.length+1)]='\0';


    return in;
}
///Not Equal operator
bool operator !=(DNA& obj1, DNA& obj2)
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
bool operator ==(DNA & obj1, DNA& obj2)
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
///Plus operator
DNA operator+(DNA& obj1, DNA& obj2)
{

    DNA *new_strand=new DNA;
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
    DNA Dna(new_strand->seq,obj1.type,(obj1.length+obj2.length));
    cout << Dna << endl;
    return (Dna);
}

void DNA::setSeq(string newSeq)
{
    for(int i=0; i<newSeq.size(); i++)
        seq[i]=newSeq[i];
}
void DNA:: makkingNewSequence(int newLength)
{
    seq = new char[newLength];
    seq[newLength] = NULL;
}

void DNA :: SaveSequenceToFile(char* filename)
{
    string typee,seqq;
    cout << "Please, Enter the type of the sequence: " << endl;
    cin >> typee;
    cout << "Please, Enter the sequence: " << endl;
    cin >> seqq;
    ofstream file;
    file.open(filename,ios::out);
    file << "DNA Sequence. \n";
    file <<"TYPE: " << typee << ".\n";
    file << "SEQUENCE: " << seqq << ".\n";
    file.close();
}

void DNA :: LoadSequencefromFile(char* filename)
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
    cout << temp << endl ;

}
