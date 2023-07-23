#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
float p;
p=sin(x);
return p;
}

int main(void)
{
int i,n;
float a,b,h,sum,integration;

sum=0;

cout<<"Give upper limit and lower limit respectively:\n";
cin>>b>>a;
cout<<"Give value of n: ";
cin>>n;

h=(b-a)/n;

sum=f(b)+f(a);

for(i=1;i<n;i=i+1)
{
sum=sum+2.0*f(a+i*h);
}
integration=sum*(h/2.0);
cout<<"The integration result is "<<integration<<endl;
return 0;
}
