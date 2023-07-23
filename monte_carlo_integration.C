#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<cmath>
using namespace std;

float f(float x)
{
float y;
y=sin(x);
return y;
}

int main(void)
{
int i,n,count;
float rand_x,rand_y,y,x,result,fmax,a,b,y1;

ofstream out("ran.txt");
ofstream out1("ran1.txt");

cout<<"Give value of n: ";
cin>>n;
cout<<"Give maximum and minimum limit:\n";
cin>>b>>a;

fmax=f(a);
for(x=a;x<=b;x=x+0.1)
{
y=f(x);
if(fmax<y)
{
fmax=y;
}
}

for(i=0;i<n;i=i+1)
{
rand_x=rand()/float(RAND_MAX);
rand_x=a+(b-a)*rand_x;
rand_y=rand()/float(RAND_MAX);
rand_y=fmax*rand_y;
y1=f(rand_x);

if(y1>rand_y)
{
count++;
out<<rand_x<<"\t\t"<<rand_y<<endl;
}
else
{
result=(b-a)*fmax*(1.0*count)/n;
out1<<rand_x<<"\t\t"<<rand_y<<endl;
}
}
cout<<"The integration result is "<<result<<endl;
return 0;
}
