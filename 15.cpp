#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
float z;
z=(x*x*x)-6*(x*x)+(11*x)-6;
return z;
}

int main()
{
float x,x1,x2,a,b;
loop:cout<<"The initial guess values are"<<endl;
cin>>a>>b;

if (f(a)*f(b)>0)
{
goto loop;
}
if (f(a)<0)
{
x1=a;
x2=b;
}
else
{
x1=b;
x2=a;
}

x1=a;
x2=b;

while(abs(f(x))>0.001)
{
x=(x1+x2)/2;
if(f(x)<0)
{
x1=x;
}
else
{
x2=x;
}
}
cout <<"The root is "<<x<<endl;
return 0;
}
