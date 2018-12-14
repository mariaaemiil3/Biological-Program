#include <iostream>
#include<fstream>
#include "DNA.h"
#include "codonstable.h"
using namespace std;

void DisplayMenu(int choice);

int main()
{

    int choice;
    DisplayMenu(choice);

    return 0;
}
void DisplayMenu(int choice)
{
    while(true)
    {
        cout << "If you want to get The complementary strand of DNA please press 1" <<endl;
        cout << "If you want to convert from DNA to RNA please press 2" <<endl;
        cout << "If you want to convert from RNA to DNA please press 3" <<endl;
        cout << "If you want to see if the two sequences are equal please press 4" <<endl;
        cout << "If you want to see if the two sequences are not equal please press 5" <<endl;
        cout << "If you want to add two sequences please press 6" << endl;
        cout << "If you want to save data to a file please press 7" << endl;
        cout << "If you want to load data from a file please press 8" << endl;
        cout << "If you want to convert from RNA to Protein please press 9" << endl;
        cout << "If you want to align two sequences using LCS Alignment please press 10" << endl;
        cout << "If you want to convert from protein to DNA please press 11" << endl;
        cout << "If you want to exit please press 0" << endl;
        cout << "Insert your choice, please:";
        cin >> choice;

        CodonsTable c;
        c.LoadCodonsFromFile("RNA_codon_table.txt");

        if (choice == 1)
        {
            string x;
            cout << "Enter the sequence, Please: ";
            cin >> x;
            const int result = x.size();

            char * new_arr = new char[result];
            for( int i = 0; i < result; i++)
            {
                new_arr[i] = x[i];
            }

            try
            {
                DNA sequencee(new_arr,promoter,x.size());
                sequencee.BuildComplementaryStrand();
            }
            catch(DNA::xInvalidDNAchar)
            {
                cout << "Error: Invalid DNA Character was entered!" << endl ;
            }
        }
        if (choice == 2)
        {
            string x;
            cout << "Enter the sequence, Please: ";
            cin >> x;
            const int result = x.size();
            char * new_arr = new char[result];
            for( int i = 0; i < result; i++)
            {
                new_arr[i] = x[i];
            }
            try
            {
                DNA sequencee(new_arr,promoter,x.size());
                sequencee.BuildComplementaryStrand();
                sequencee.Print();
            }
            catch(DNA::xInvalidDNAchar)
            {
                cout << "Error: Invalid DNA Character was entered!" << endl ;
            }
        }
        if (choice == 3)
        {
            string x;
            cout << "Enter the sequence, Please: ";
            cin >> x;
            const int result = x.size();
            char * new_arr = new char[result];
            for( int i = 0; i < result; i++)
            {
                new_arr[i] = x[i];
            }

            try
            {
                RNA N(new_arr,mRNA,x.size());
                N.ConvertToDNA();
            }
            catch(RNA::xInvalidRNAchar)
            {
                cout << "Error: Invalid RNA Character was entered!" << endl ;
            }
        }
        if (choice == 4)
        {
            int choice1;
            cout << "If your two sequences are DNA, please press 1"<<endl;
            cout << "If your two sequences are RNA, please press 2"<<endl;
            cout << "If your two sequences are Protein, please press 3"<<endl;
            cin >> choice1;
            if(choice1==1)
            {
                DNA N;
                cin >> N;
                DNA M;
                cin >> M;

                if(N == M)
                {
                    cout << "The two sequences are equal" << endl ;
                }
                else
                {
                    cout << "The two sequences are not equal" << endl;
                }
            }
            if(choice1==2)
            {
                RNA N;
                cin >> N;
                RNA M;
                cin >> M;


                if(N == M)
                {
                    cout << "The two sequences are equal" << endl ;
                }
                else
                {
                    cout << "The two sequences are not equal" << endl;
                }
            }
            if(choice1==3)
            {
                Protein N;
                cin >> N;
                Protein M;
                cin >> M;
                if(N == M)
                {
                    cout << "The two sequences are equal"  << endl;
                }
                else
                {
                    cout << "The two sequences are not equal" << endl;
                }
            }

        }
        if (choice == 5)
        {
            int choice1;
            cout << "If your two sequences are DNA, please press 1"<<endl;
            cout << "If your two sequences are RNA, please press 2"<<endl;
            cout << "If your two sequences are Protein, please press 3"<<endl;
            cin >> choice1;
            if(choice1==1)
            {
                DNA N;
                cin >> N;
                DNA M;
                cin >> M;

                if(N != M)
                {
                    cout << "The two sequences are not equal" << endl ;
                }
                else
                {
                    cout << "The two sequences are equal" << endl;
                }
            }
            if(choice1==2)
            {
                RNA N;
                cin >> N;
                RNA M;
                cin >> M;


                if(N != M)
                {
                    cout << "The two sequences are not equal" << endl ;
                }
                else
                {
                    cout << "The two sequences are equal" << endl;
                }
            }
            if(choice1==3)
            {
                Protein N;
                cin >> N;
                Protein M;
                cin >> M;

                if(N != M)
                {
                    cout << "The two sequences are not equal" << endl;
                }
                else
                {
                    cout << "The two sequences are equal" << endl;
                }
            }


        }
        if (choice == 6)
        {
            int choice1;
            cout << "If your two sequences are DNA, please press 1"<<endl;
            cout << "If your two sequences are RNA, please press 2"<<endl;
            cout << "If your two sequences are Protein, please press 3"<<endl;
            cin >> choice1;
            if(choice1==1)
            {
                try
                {
                    DNA N;
                    cin >> N;
                    DNA NA;
                    cin >> NA;
                    N+NA;
                }
                catch(DNA::xInvalidDNAchar)
                {
                    cout << "ERROR, Invalid DNA character!" << endl;
                }

            }
            if(choice1==2)
            {
                try
                {
                    RNA N;
                    cin >> N;
                    RNA NA;
                    cin >> NA;
                    N+NA;
                }
                catch(RNA::xInvalidRNAchar)
                {
                    cout << "ERROR, Invalid RNA character!" << endl;
                }
            }
            if(choice1==3)
            {

                Protein P;
                cin >> P;
                Protein P2;
                cin >> P2;
                P+P2;
            }

        }
        if(choice == 7)
        {
            int choice1;
            cout << "If your sequence is DNA, please press 1"<<endl;
            cout << "If your sequence is RNA, please press 2"<<endl;
            cout << "If your sequence is Protein, please press 3"<<endl;
            cin >> choice1;
            char name[20];
            string n;
            cout << "Please enter the name of your file: " << endl;
            cin >> n;
            for(int i=0; i<n.size(); i++)
            {
                name[i]=n[i];
            }
            if(choice1==1)
            {
                DNA d;
                d.SaveSequenceToFile(name);
            }
            if(choice1==2)
            {
                RNA R;
                R.SaveSequenceToFile(name);
            }
            if(choice1==3)
            {
                Protein P;
                P.SaveSequenceToFile(name);
            }
        }
        if(choice==8)
        {
            int choice1;
            cout << "If your sequence is DNA, please press 1"<<endl;
            cout << "If your sequence is RNA, please press 2"<<endl;
            cout << "If your sequence is Protein, please press 3"<<endl;
            cin >> choice1;
            char name[20];
            string n;
            cout << "Please enter the name of your file: " << endl;
            cin >> n;
            for(int i=0; i<n.size(); i++)
            {
                name[i]=n[i];
            }
            if(choice1==1)
            {
                DNA D;
                D.LoadSequencefromFile(name);
            }
            if(choice1==2)
            {
                RNA R;
                R.LoadSequencefromFile(name);
            }
            if(choice1==3)
            {
                Protein P;
                P.LoadSequencefromFile(name);
            }
        }
        if(choice == 9)
        {
            const int result =100;
            string x;
            cout << "Enter the sequence, Please: ";
            cin >> x;
            char * new_arr = new char[result];
            for( int i = 0; i < result; i++)
            {
                new_arr[i] = x[i];
            }

            try
            {
                RNA N(new_arr,mRNA,x.size());
                try
                {
                    N.ConvertToProtein(c);
                }
                catch(RNA::xInvalidProteinSize)
                {
                    cout << "ERROR: Invalid RNA size,Unable to convert it to Protein!" << endl;
                }
            }
            catch(RNA::xInvalidRNAchar)
            {
                cout << "Error: Invalid RNA Character was entered!" ;
            }
        }
        if(choice==10)
        {
            string x;
            cout << "Enter the First sequence, Please: ";
            cin >> x;
            char * new_arr = new char[x.size()];
            for( int i = 0; i < x.size(); i++)
            {
                new_arr[i] = x[i];
            }


            string y;
            cout << "Enter the second sequence, Please: ";
            cin >> y;
            char * new1_arr = new char[(y.size())];
            for( int i = 0; i < y.size(); i++)
            {
                new1_arr[i] = y[i];
            }
            try
            {
                Sequence *seq=new DNA(new_arr,promoter,x.size());
                try
                {
                    Sequence *seq1=new DNA(new1_arr,promoter,y.size());
                    Align(seq,seq1,x.size(),y.size());
                }
                catch(DNA::xInvalidDNAchar)
                {
                    cout << "Error: Invalid DNA Character was entered!" ;
                }
            }
            catch(DNA::xInvalidDNAchar)
            {
                cout << "Error: Invalid DNA Character was entered!" ;
            }

        }
        if(choice==11)
        {
            try
            {
                DNA d;
                cin >> d;
                Protein p("HPR",Cellular_Function,3);
                p.GetDNAStrandsEncodingMe(d);
            }
            catch(DNA::xInvalidDNAchar)
            {
                cout << "ERROR! Invalid DNA character" << endl;
            }
        }
        if(choice==0)
        {
            break;
        }
    }
}
