#include<iostream>
#include<fstream>
using namespace std;

typedef struct
{
float x[50][50];
}array;

array mult(array a,array b,int m,int n,int q)
{
array c;
int i,j,k;

for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c.x[i][j]=0;
for(k=0;k<q;k++)
{
c.x[i][j]=c.x[i][j]+a.x[i][k]*b.x[k][j];
}
}
}
return c;
}

int main(void)
{
int i,j,k,m,n,p,q;
array a,b;

ifstream in("datmat1.txt");

in>>m;
cout<<"Number of rows of matrix1= "<<m<<endl;
in>>n;
cout<<"Number of columns of matrix1= "<<n<<endl;
in>>p;
cout<<"Number of rows of matrix2= "<<p<<endl;
in>>q;
cout<<"Number of columns of matrix2= "<<q<<endl;

if(n==p)
{
cout<<"Matrix multiplication is possible.\n";
cout<<"Elements of matrix1:\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
in>>a.x[i][j];
cout<<" "<<a.x[i][j];
}
cout<<"\n";
}

cout<<"Elements of matrix2:\n";
for(i=0;i<p;i++)
{
for(j=0;j<q;j++)
{
in>>b.x[i][j];
cout<<" "<<b.x[i][j];
}
cout<<"\n";
}

cout<<"The result is\n";
for(i=0;i<m;i++)
{
for(j=0;j<q;j++)
{
cout<<" "<<mult(a,b,m,n,q).x[i][j];
}
cout<<"\n";
}
}

else
{
cout<<"Matrix multiplication is not possible.\n";
}

return 0;
}
