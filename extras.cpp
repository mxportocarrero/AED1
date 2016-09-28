#include "extras.h"

int min3(int a, int b, int c)
 {
     if (a<=b and a<=c) return a;
     if (b<=c and b<=a) return b;
     if (c<=b and c<=b) return c;
 }

int Levinstein(string A, string B)
 {
 int As = A.size(), Bs = B.size();
 int D[As+1][Bs+1];
 for (int i=0;i<=As;i++) D[i][0]=i;
 for (int i=0;i<=Bs;i++) D[0][i]=i;
 int peso;
 for (int i=1;i<=As;i++)
  for (int j=0;j<=Bs;j++)
   {
   if (A[i+1]==B[j+1]) peso = 0;
   else peso = 1;
   D[i][j] = min3(D[i-1][j]+1,D[i][j-1]+1,D[i-1][j-1]+peso);
   }
 //cout << A[0]; BR;
 //return A.size()+B.size();
   return D[As][Bs];
 }
