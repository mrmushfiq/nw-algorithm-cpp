//NW Algorithm
//Md Mushfiqur Rahman
//Physics Department,FAU

#include <iostream>
#include <istream>
#include <ostream>
#include <cstdio>
#include <armadillo> // Using armadillo library for linear algebra. Esy to install in linux
#include <new>
#include <fstream>
#include <cmath>
#include <complex>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;
using namespace arma;



int main()
{
  int Ham,ro,coll,k,v;

 string seq2 ="MTTAVLENPGLGRKL";
 string seq1 ="MSAAVTPNPGLGKKS";
 char s1[200];
 char s2[200];
 strcpy(s1,seq1.c_str());
 strcpy(s2,seq2.c_str());
 ro = seq1.length() + 1;   // 1 row and column extra for 0s
 coll = seq2.length() + 1;
 mat H = zeros<mat>(ro,coll);
 cout<<s1[14]<<"--"<<s2[14]<<"row"<<ro<<endl;
  for (k=0;k<=ro-2;k++){
    for (v=0;v<=coll-2;v++)
    {
        if(s1[k] == s2[v])
        H(k,v)= 1.0 ;
    }
  }

  for(int i=ro-2; i>=0; i--)
   {
   for(int j=coll-2; j>=0; j--)
   {
     //max(H.submat(3,1,5,4).row(0))
     double max_r = max(H.submat(i+1,j+1,ro-1,coll-1).row(0));
     double max_c = max(H.submat(i+1,j+1,ro-1,coll-1).col(0));
     H(i,j) += max_r > max_c ? max_r : max_c;
   }
   }
   ofstream out;
   out.open("NW.txt");

for(int j=0; j<=coll-2; j++)
  {
    if (j==0) {
      cout<<"   "<<s2[j]<<" ";
      out<<"    "<<s2[j]<<" | ";
    }
    else if(j<coll-2)
     {
     cout<<s2[j]<<" ";
     out<<s2[j]<<" | ";
     }
  else{ cout<<s2[j]<<endl;
        out<<s2[j]<<endl;
    out<<"--------------------------------------------------------------- "<<endl;
     }
  }



for(int i=0; i<=ro-2; i++)
   {  cout<<s1[i]<<"  ";
      out<<s1[i]<<" | ";
   for(int j=0; j<=coll-2; j++)
    {
      out<<H(i,j)<<" | ";
      cout<<H(i,j)<<" ";
    } cout<<endl;
    out<<endl<<"--------------------------------------------------------------- "<<endl;
   }
   out.close();
   cout<< "output can also be found in NW.txt"<<endl;
}
