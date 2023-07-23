#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
float y;
y=sin(x);
return y;
}

float simson(float b,float a,int n)
{
int i;
float h,sum,sum_even,sum_odd;
h=(b-a)/n;
sum=f(a)+f(b);
sum_even=0;
sum_odd=0;

for(i=1;i<n;i=i+1)
{
if(i%2==0)
{
sum_even=sum_even+4*f(a+i*h);
}
else
{
sum_odd=sum_odd+2*f(a+i*h);
}
}
sum=(h/3.0)*(sum+sum_even+sum_odd);
return sum;
}

int main(void)
{
int n;
float a,b,h,sum1,sum,err;

cout<<"Give values of upper limit and lower limit respectively:\n";
cin>>b>>a;
cout<<"Give value of n:";
cin>>n;

sum=0;
sum1=0;
err=1;

while(err>0.001)
{
sum=simson(b,a,n);
err=abs(sum-sum1);
sum1=sum;
n=n+1;
}
cout<<"The result of integration is "<<sum<<endl;
return 0;
}

