#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
int i,j,k,m,n,p,q;
float a[20][20],b[20][20],c[20][20];

ifstream in("datmat.txt");

in>>m;
cout<<"Number of rows of matrix 1= "<<m<<endl;
in>>n;
cout<<"Number of columns of matrix 1= "<<n<<endl;
in>>p;
cout<<"Number of rows of matrix 2= "<<p<<endl;
in>>q;
cout<<"Number of columns of matrix 2= "<<q<<endl;

cout<<"Elements of matrix 1:\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
in>>a[i][j];
cout<<" "<<a[i][j];
}
cout<<"\n";
}

cout<<"Elements of matrix 2:\n";
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
in>>b[i][j];
cout<<" "<<b[i][j];
}
cout<<"\n";
}

if(n==p)
{
cout<<"Matrix multiplication is possible.\n";

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c[i][j]=0;
for(k=0;k<q;k++)
{
c[i][j]=c[i][j]+a[i][k]*b[k][j];
}
}
}
}
else
{
cout<<"Matrix multiplication is not possible.\n";
}

cout<<"The result is\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<" "<<c[i][j];
}
cout<<"\n";
}
return 0;
}
