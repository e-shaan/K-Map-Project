/* A C++ program to calculate SOP(Sum Of Products)
expression for a given input using a 2x4 8-variable K-Map.*/

#include <iostream> //including I/O functions
#include <conio.h>
using namespace std;

int pair_ctr=0; //global variable to count no. of horizontal pairs

void Result(int ar[26]) //function to display the resultant SOP expression
{
    int length;
    string expression="Expression = ";
    if(ar[0]==0)
        expression+="A' + ";
    if(ar[1]==1)
        expression+="B + ";
    if(ar[2]==2)
        expression+="A + ";
    if(ar[3]==3)
        expression+="B' + ";
    if(ar[4]==4)
        expression+="A'B' + ";
    if(ar[5]==5)
        expression+="A'B + ";
    if(ar[6]==6)
        expression+="AB + ";
    if(ar[7]==7)
        expression+="AB' + ";
    if(ar[8]==8)
        expression+="A'C' + ";
    if(ar[9]==9)
        expression+="BC' + ";
    if(ar[10]==10)
        expression+="AC' + ";
    if(ar[11]==11)
        expression+="B'C' + ";
    if(ar[12]==12)
        expression+="A'C + ";
    if(ar[13]==13)
        expression+="BC + ";
    if(ar[14]==14)
        expression+="AC + ";
    if(ar[15]==15)
        expression+="B'C + ";
    if(ar[16]==16)
        expression+="C' + ";
    if(ar[17]==17)
        expression+="C + ";
    if(ar[18]==18)
        expression+="A'B'C' + ";
    if(ar[19]==19)
        expression+="A'BC' + ";
    if(ar[20]==20)
        expression+="ABC' + ";
    if(ar[21]==21)
        expression+="AB'C' + ";
    if(ar[22]==22)
        expression+="A'B'C + ";
    if(ar[23]==23)
        expression+="A'BC + ";
    if(ar[24]==24)
        expression+="ABC + ";
    if(ar[25]==25)
        expression+="AB'C + ";

    length=expression.length();
    expression[length-2]=' ';
    cout<<expression<<endl<<endl;
}
bool Octet(int kmap[2][4]) //function to check for an octet
{
    int ctr=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        {
            if(kmap[i][j]==1)
            {
                 ctr++;
            }
        }
   // if(ctr==8)
      //  return true;
   // else
        return false;
}
bool Null_Map(int kmap[2][4]) //function to check for nullity
{
    int ctr=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<4;j++)
        {
            if(kmap[i][j]==1)
            {
                 ctr++;
            }
        }
   // if(ctr==0)
     //   return true;
  //  else
        return false;
}
void Quad(int ar[26],int kmap[2][4]) //function to check for quads
{
    int ctr=0;
    for(int i=0; i<4; i++)
    {
        if(kmap[0][i]==1)
            ctr++;
    }
    if(ctr==4)
    {
        ar[16]=16;
    }
    ctr=0;
    for(int i=0; i<4; i++)
    {
        if(kmap[1][i]==1)
            ctr++;
    }
    if(ctr==4)
    {
        ar[17]=17;
    }

    for(int i=0; i<3; i++)
    {
        if(kmap[0][i]==1)
        {
            if((kmap[0][i+1]==1) && (kmap[1][i]==1) && (kmap[1][i+1]==1))
            {
                ar[i]=i;
            }
        }
    }
    if((kmap[0][0]==1) && (kmap[1][0]==1) && (kmap[0][3]==1) && (kmap[1][3]==1))
    {
         ar[3]=3;
    }
}
void Pair_Veritcal(int ar[26],int kmap[2][4]) //function to check for vertical pairs
{
    for(int i=0; i<4; i++)
    {
        if(kmap[0][i]==1)
        {
            if(kmap[1][i]==1)
            {
                ar[i+4]=i+4;
            }
        }
    }
}
void Pair_Row1(int ar[26],int kmap[2][4]) //function to check for pairs in row1
{
    for(int i=0; i<3; i++)
    {
        if((kmap[0][i]==1))
        {
            if(kmap[0][i+1]==1)
            {
                ar[i+8]=i+8;
                pair_ctr++;
            }
        }
    }
    if((kmap[0][0]==1) && (kmap[0][3]==1))
    {
         ar[11]=11;
         pair_ctr++;
    }
}
void Pair_Row2(int ar[26],int kmap[2][4]) //function to check for pairs in row2
{
    for(int i=0; i<3; i++)
    {
        if((kmap[1][i]==1))
        {
            if(kmap[1][i+1]==1)
            {
                ar[i+12]=i+12;
                pair_ctr++;
            }
        }
    }
    if((kmap[1][0]==1) && (kmap[1][3]==1))
    {
         ar[15]=15;
         pair_ctr++;
    }
}
void Duplication_Check(int ar[26],int kmap[2][4]) //function to remove duplicates
{
    for(int i=0;i<3;i++)
    {
        if(ar[i]==i)
        {
            ar[i+4]=ar[i+5]=ar[i+8]=ar[i+12]=-1;
        }
    }
    if(ar[3]==3)
    {
        ar[4]=ar[7]=ar[11]=ar[15]=-1;
    }
    if(ar[4]==4)
    {
        if( (ar[8]==8 || ar[11]==11) && (ar[12]==12 || ar[15]==15) )
        {
            ar[4]=-1;
        }
    }
    for(int i=5;i<8;i++)
    {
        if(ar[i]==i)
        {
            if( (ar[i+3]==(i+3) || ar[i+4]==(i+4)) && (ar[i+7]==(i+7) || ar[i+8]==(i+8)) )
            {
                ar[i]=-1;
            }
        }
    }

    if(pair_ctr==4)
    {
        if(kmap[0][1]==0)
        {
            ar[6]=6;
            ar[10]=-1;
            ar[13]=-1;
        }
        else if (kmap[0][2]==0)
        {
            ar[5]=5;
            ar[8]=-1;
            ar[13]=-1;
        }
        else if (kmap[1][1]==0)
        {
            ar[6]=6;
            ar[9]=-1;
            ar[14]=-1;
        }
        else
        {
            ar[5]=5;
            ar[9]=-1;
            ar[12]=-1;
        }
    }
}
void Isolation_Check(int ar[26],int kmap[2][4]) //function to check for isolated 1s
{
    if(ar[3]==-1 && ar[0]==-1 && ar[16]==-1 && ar[4]==-1 && ar[11]==-1 && ar[8]==-1 && kmap[0][0]==1)
        ar[18]=18;
    for(int i=0;i<3;i++)
        if(ar[i+0]==-1 && ar[i+1]==-1 && ar[16]==-1 && ar[i+5]==-1 && ar[i+8]==-1 && ar[i+9]==-1 && kmap[0][i+1]==1)
            ar[i+19]=i+19;
    if(ar[3]==-1 && ar[0]==-1 && ar[17]==-1 && ar[4]==-1 && ar[15]==-1 && ar[12]==-1 && kmap[1][0]==1)
        ar[22]=22;
    for(int i=0;i<3;i++)
        if(ar[i+0]==-1 && ar[i+1]==-1 && ar[17]==-1 && ar[i+5]==-1 && ar[i+12]==-1 && ar[i+13]==-1 && kmap[1][i+1]==1)
            ar[i+23]=i+23;

}
void Swap(int *x,int *y) //function to swap two integers
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void Print_Kmap(int kmap[2][4]) //function to display the K-Map
{
    cout<<"\t\t\tKMAP\n"<<endl;
    cout<<"\t    A'B'   A'B      AB      AB'"<<endl<<endl;
    cout<<"\tC'|";

    for(int i=0;i<4;i++)
        cout<<"   "<<kmap[0][i]<<"\t|";
    cout<<endl<<"  \t   ______________________________"<<endl;
    cout<<endl<<"\tC |";

    for(int i=0;i<4;i++)
        cout<<"   "<<kmap[1][i]<<"\t|";
    cout<<endl<<endl;
}
int main()
{
    int ctr=0, kmap[2][4], ar[26];

    for(int i=0;i<26;i++)  //initialising array to -1
    {
        ar[i]=-1;
    }

    cout<<"\t      A C++ program to calculate SOP(Sum Of Products)\n\texpression for a given input using a 2x4 3-variable K-Map."<<endl;
    cout<<"\n\nEnter 0 or 1 for the minterms:\n"<<endl;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<"m"<<ctr<<"= ";
            cin>>kmap[i][j];
            ctr++;
        }
    }
    cout<<endl;

    Swap(&kmap[0][2],&kmap[0][3]);
    Swap(&kmap[1][2],&kmap[1][3]);

    Print_Kmap(kmap);

    if(Octet(kmap))
    {
        cout<<"Expression: One(1)"<<endl;
    }
    else if(Null_Map(kmap))
    {
        cout<<"Expression: Zero(0)"<<endl;
    }
    else
    {
        Quad(ar,kmap);
        Pair_Veritcal(ar,kmap);
        if(ar[16]!=16)
        {
            Pair_Row1(ar,kmap);
        }
        if(ar[17]!=17)
        {
            Pair_Row2(ar,kmap);
        }
        Duplication_Check(ar,kmap);
        Isolation_Check(ar,kmap);
        Result(ar);
    }
for(int i=0;i<26;i++)  //initialising array to -1
    {
        cout<<ar[i];
    }
    cout<<"\t\t\t\t\tMapped By:\n\t\t\t\t\tEshaan Gupta"<<endl;
    return 0;
}
