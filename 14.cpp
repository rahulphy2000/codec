#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
int i,n;
float x[100],y[100],s_y,s_xxy,s_xx,s_x4,a_y,a_xxy,a_xx,a_x4,a,b;
ifstream in("14.in");
s_y=0;
s_xxy=0;
s_xx=0;
s_x4=0;
in>>n;

for(i=0;i<n;i++)
{
in>>x[i]>>y[i];
s_y=s_y+y[i];
s_xxy=s_xxy+(x[i]*x[i]*y[i]);
s_xx=s_xx+(x[i]*x[i]);
s_x4=s_x4+(x[i]*x[i]*x[i]*x[i]);
}

cout<<"Sum of y = "<<s_y<<endl;
cout<<"Sum of x^2*y = "<<s_xxy<<endl;
cout<<"Sum of xx = "<<s_xx<<endl;
cout<<"Sum of x^4 = "<<s_x4<<endl;

a_y=s_y/n;
a_xxy=s_xxy/n;
a_xx=s_xx/n;
a_x4=s_x4/n;

cout<<"Avg of y = "<<a_y<<endl;
cout<<"Avg of x^2*y = "<<a_xxy<<endl;
cout<<"Avg of xx = "<<a_xx<<endl;
cout<<"Avg of x^4 = "<<a_x4<<endl;

a=(a_xxy-(a_xx*a_y))/(a_x4-(a_xx*a_xx));
b=a_y-(a*a_xx);

cout<<"The value of a = "<<a<<endl;
cout<<"The value of b = "<<b<<endl;
return 0;
}
