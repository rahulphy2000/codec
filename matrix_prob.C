#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

typedef struct
{
float x[50][50];
}array;

float trace(array z)
{
float y;
int i,n;
y=0;
for(i=0;i<n;i=i+1)
{
y=y+z.x[i][i];
}
return y;
}

array norm(array a,int n)
{
int i;
float p;
p=0;
for(i=0;i<n;i++)
{
p=p+a.x[i][i]*a.x[i][i];
}
return (sqrt(p));
}

array trans(array a,int m,int n)
{
int i,j;
array b;
float m;

for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
m=a.x[i][j];
b.x[j][i]=m;
}
}
return b;
}

array add(array a,array b,int m,int n)
{
int i,j;
array c;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c.x[i][j]=a.x[i][j]+b.x[i][j];
}
}
return c;
}

array sub(array a,array b,int m,int n)
{
int i,j;
array c;
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
c.x[i][j]=a.x[i][j]-b.x[i][j];
}
}
return c;
}

int main(void)
{
int i,j,m,n,p,q;
array a,b,c,d;
float e,f;

ifstream in("datamax.txt")

in>>m;
cout<<"Number of rows of matrix 1= "<<m<<endl;
in>>n;
cout<<"Number of columns of matrix 2= "<<n<<endl;
in>>p;
cout<<"Number of rows of matrix 1= "<<p<<endl;
in>>q;
cout<<"Number of columns of matrix 2= "<<q<<endl;

if(m==p && n==q)
{
cout<<"Matrix addition and subtrucation are possible.\n";

cout<<"Elements of matrix1:\n";
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
in>>a[i][j];
cout<<" "<<a.x[i][j];
}
cout<<"\n";
}

cout<<"Elements of matrix2:\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
in>>b[i][j];
cout<<" "<<b.x[i][j];
}
cout<<"\n";
}
}

cout<<"The addition of two matrices is\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<"  "<<add(a,b).x[i][j];
}
cout<<"\n";
}

cout<<"The subtruction of two matrices is\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<" "<<sub(a,b).x[i][j];
}
cout<<"\n";
}

}
else
{
cout<<"Matrix addition and subtruction are not possible.\n";
}

if(m==n)
{
cout<<"Norm and trace of matrix are possible\n";
cout<<"Trace of matrix1 is "<<trace(a,m)<<"\nTrace of matrix2 is "<<trace(b,m)<<endl;
cout<<"Norm of matrix1 is "<<norm(a,m)<<"\nNorm of matrix2 is "<<norm(b,m)<<endl;
}
else
{
cout<<"Norm and trace of matrix are not possible\n";
}

cout<<"Transpose of matrix1 is\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<"  "<<trans(a,m,n);
}
cout<<"\n";
}
cout<<"Transpose of matrix2 is\n";
for(i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
cout<<"  "<<trans(b,m,n);
}
cout<<"\n";
}
return 0;
}
