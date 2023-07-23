#include<iostream>
#include<cmath>
using namespace std;

float f(float x)
{
float y;
y=sin(x);
return y;
}

float trapizoidal(float b,float a,int n)
{
int i;
float h,sum;

h=(b-a)/n;
sum=(f(a)+f(b));

for(i=1;i<n;i=i+1)
{
sum=sum+2*f(a+i*h);
}
sum=(h/2)*sum;
return sum;
}

int main(void)
{
int n;
float h,sum,sum1,b,a,err;

err=1;
sum=0;
sum1=0;

cout<<"Give values of upper limit and lower limit respectively:\n";
cin>>b>>a;
cout<<"Give value of number of steps n: ";
cin>>n;

while(err>0.0001)
{
sum=trapizoidal(b,a,n);
err=abs(sum-sum1);
sum1=sum;
n=n+1;
}
cout<<"The integration result is "<<sum<<endl;
return 0;
}
