#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<fstream>
using namespace std;

float f(float x)
{
float y;
y=sin(x);
return y;
}

float max(float a,float b)
{
float x,y,fmax;
fmax=f(a);
for(x=a;x<=b;x=x+0.1)
{
y=f(x);
if(y>fmax)
{
fmax=y;
}
}
return (fmax);
}

float min(float a,float b)
{
float x,y,fmin;
fmin=f(a);
for(x=a;x<=b;x=x+0.1)
{
y=f(x);
if(y<fmin)
{
fmin=y;
}
}
return (fmin);
}

int main(void)
{
int i,n,count;
float fmax,fmin,a,b,y,x,count1,count2,y1,s;
count1=0;
count2=0;

ofstream output1("dataran1.txt");
ofstream output2("dataran2.txt");

cout<<"Give value of n:";
cin>>n;
cout<<"Give value of maximum and minimum limit:\n";
cin>>b>>a;

fmax=max(a,b);
if(fmax<0)
{
fmax=0;
}
fmin=min(a,b);
if(fmin>0)
{
fmin=0;
}

for(i=0;i<n;i=i+1)
{
x=rand()/float(RAND_MAX);
x=a+(b-a)*x;
y=rand()/float(RAND_MAX);
y=fmin+(fmax-fmin)*y;
y1=f(x);
if(y>0)
{
if(y1>y)
{
count1++;
output1<<x<<"\t\t"<<y<<endl;
}
}
if(y<0)
{
if(y1<y)
{
count2++;
output2<<x<<"\t\t"<<y<<endl;
}
}
}
s=(b-a)*(fmax-fmin)*(count1-count2)/n;
cout<<"The integration result is "<<s<<endl;
return 0;
}



