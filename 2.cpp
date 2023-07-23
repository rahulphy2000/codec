#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
int i,n,j;
float p[10][10],a[10],pa[10];
ifstream in("2.in");
in>>n;

for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
in>>p[i][j];
}
}

for(i=1;i<=n;i++)
{
in>>a[i];
}


for(i=1;i<=n;i++)
{
pa[i]=0;
for(j=1;j<=n;j++)
{
pa[i]=pa[i]+p[i][j]*a[j];
}
}

for(i=1;i<=n;i++)
{
cout<<pa[i]<<endl;
}
return 0;
}
 

