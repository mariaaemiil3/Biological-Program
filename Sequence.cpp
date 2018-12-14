#include "sequence.h"
#include "DNA.h"
#include<cstdlib>
class DNA;
///Default Constructor
Sequence::Sequence()
{
    seq=new char[0];
}
///Parameterized Constructor
Sequence:: Sequence(int length)
{
    seq=new char[length];
}
///Copy Constructor
Sequence:: Sequence(Sequence& rhs)
{
    this->seq=rhs.seq;
}
///LCS alignment function
char* Align(Sequence * s1, Sequence * s2,int m,int n)
{
    int INDEX;
    int matt[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<= n; j++)
        {
            if(i == 0||j == 0)
            {
                matt[i][j] = 0;
            }
            else
            {
                if(s1->seq[i-1] == s2->seq[j-1])
                {
                    matt[i][j] = 1+(matt[i-1][j-1]);
                }
                else
                {
                    matt[i][j] = max(matt[i][j-1],matt[i-1][j]);
                }
            }
        }
    }
    INDEX = matt[m][n];
    char *lcs = new char [INDEX];
    char*lcs_Reversed = new char[INDEX];
    int counter;
    counter = (INDEX-1);
    int i = m;
    int j = n;
    while(i > 0&& j > 0)
    {
        if(matt[i][j] != max(matt[i][j-1],matt[i-1][j]))
        {
            lcs[(INDEX-1)-counter] = s1->seq[i-1];
            counter--;
            i--;
            j--;
        }
        else
        {
            if((matt[i][j-1]<matt[i-1][j]))
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    for(int i=0; i<INDEX; i++)
    {
        lcs_Reversed[i] = lcs[(INDEX-1)-i];
        cout<<lcs_Reversed[i];
    }
    return(lcs_Reversed);
}

char* Sequence:: getSeq()
{
    return this->seq;
}
///Destructor
Sequence:: ~Sequence()
{
    delete[]seq;
}

