#include "protein.h"
#include"Sequence.h"
#include<iostream>


using namespace std;
///Default Constructor
Protein:: Protein()
{
    A=new char[0];
    //type=Cellular_Function;
}
///Parametrized rhe error
Protein:: Protein(char * p,Protein_Type atype, int l)
{
    A = p;
    type = atype;
    this->length=l;
}
///Print function that prints the sequence & type of a Protein object
void Protein :: Print()
{
    cout << "The type of your Protein sequence is: "<< type <<endl;
    cout << "Your Protein sequence is: ";
    for(int i=0; i < length; i++)
    {
        cout << A[i];
    }
    cout<<endl;
}

void Protein :: LoadSequencefromFile(char *filename)
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

void Protein :: SaveSequenceToFile(char* filename)
{
    string typee,seqq;
    cout << "Please, Enter the type of the sequence: " << endl;
    cin >> typee;
    cout << "Please, Enter the sequence: " << endl;
    cin >> seqq;
    ofstream file;
    file.open(filename,ios::out);
    file << "Protein Sequence." << "\n";
    file <<"TYPE: " << typee << ".\n";
    file << "SEQUENCE: " << seqq << ".\n";
    file.close();
}
///Get DNA strand from Protein sequence
DNA* Protein:: GetDNAStrandsEncodingMe( const DNA & bigDNA)
{
    vector <string> allRightSequences ;
    char*AMINOACID = new char[length];
    char*CODON = new char[3];

    CodonsTable table;
    table.LoadCodonsFromFile("RNA_codon_table.txt");

    RNA*RNA_strand = new RNA;
    RNA_strand->seq = new char[bigDNA.length];

    char*separate = new char[length*3];
    //char*Aminoacid = new char[length];

    for(int i = 0; i < (bigDNA.length); i++)
    {
        if(bigDNA.seq[i] == 'T')
        {
            RNA_strand->seq[i] = 'U';
        }
        else
        {
            RNA_strand->seq[i] = bigDNA.seq[i];
        }
        //cout<<RNA_strand->seq[i];
    }
    int shift = 0;

    // cout<<endl;

    while(shift < bigDNA.length)
    {
        int Separate_Index = 0;
        int RNA_Index=shift;
        while(Separate_Index < (length*3))
        {
            separate[Separate_Index]=RNA_strand->seq[RNA_Index];
            RNA_Index++;
            Separate_Index++;
        }

        int AminoAcid_Index = 0;

        for(int i = 0; i < (length*3); i+=3)
        {
            CODON[0] = separate[i];
            CODON[1] = separate[i+1];
            CODON[2] = separate[i+2];

            if(AminoAcid_Index < length)
            {
                AMINOACID[AminoAcid_Index] = table.getAminoAcid(CODON).AminoAcid;
                AminoAcid_Index++;
            }
            else
            {
                break;
            }
        }

        int counter = 0;
        for(int i = 0; i < length; i++)
        {
            if(AMINOACID[i] == A[i])
            {
                counter++;
            }
        }
        if(counter == (length))
        {
            string sSeparate = separate ;
            allRightSequences.push_back(sSeparate);
            shift += ((length*3));
            for(int i = 0; i < (length*3); i++)
            {
                cout<<  separate[i];
            }
            cout<<endl;
        }

        else
        {
            shift++;
        }
    }
    DNA* newDNA = new DNA[allRightSequences.size()];
    for(int i=0; i < allRightSequences.size(); i++)
    {
        newDNA[i].makkingNewSequence(length*3);
        newDNA[i].setSeq(allRightSequences[i]);
    }
    return newDNA;
}
ostream& operator<<(ostream& out,const Protein &obj)
{
    out << "SEQUENCE: ";
    out << obj.A<<endl;
    out << "TYPE: ";
    out<< obj.type<<endl;
    out << "LENGTH: ";
    out<<obj.length<<endl;
    return out;
}

istream& operator>>(istream& in,Protein& obj)
{
    int type=0;

    cout << "Enter the number of the type of your Protein sequence: " << endl;
    in >> type;

    obj.type=static_cast <Protein_Type>(type);

    cout << "Enter the size of your Protein sequence: " << endl;
    in >> obj.length;

    /// char* arr=new char[(obj.length+1)];
    cout << "Enter your Protein sequence: " << endl;
    in >> obj.A;
    obj.A[(obj.length+1)]='\0';

    return in;
}
///Not Equal operator
bool operator !=(Protein& obj1, Protein& obj2)
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
                if (obj1.A[i] == obj2.A[i])
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
bool operator ==(Protein& obj1, Protein& obj2)
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
                if (obj1.A[i] == obj2.A[i])
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
///Addition operator
Protein operator+(Protein& obj1, Protein& obj2)
{

    Protein *new_strand=new Protein;
    new_strand->A= new char[(obj1.length+obj2.length+1)];
    if(obj1.type==obj2.type)
    {
        new_strand->A[(obj1.length+obj2.length+1)]='\0';
        for(int i=0; i<obj1.length; i++)
        {
            new_strand->A[i]=obj1.A[i];
        }
        int c=0;
        for(int i=obj1.length; i<(obj1.length+obj2.length); i++)
        {
            new_strand->A[i]=obj2.A[c];
            c++;
        }
    }
    Protein proteinn(new_strand->A,obj1.type,(obj1.length+obj2.length));
    cout << proteinn << endl;
    return (proteinn);
}
///Destructor
Protein::~Protein()
{
    delete [] A;
}
