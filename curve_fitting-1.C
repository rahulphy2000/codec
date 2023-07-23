#include<iostream>
#include<fstream>
using namespace std;

int main(void)
{
int i,n;
float x[100],y[100],sum_x,sum_y,sum_xx,sum_xy,m,c;

sum_x=0;
sum_y=0;
sum_xx=0;
sum_xy=0;

ifstream in("datain1.txt");
ofstream out("dataout1.txt");

cout<<"Give number of pair of data: ";
cin>>n;
cout<<"Datas:\n";
cout<<"x-data"<<"\t"<<"y-data"<<endl;
for(i=1;i<=n;i=i+1)
{
in>>x[i];
in>>y[i];
cout<<x[i]<<"\t "<<y[i]<<endl;
}

for(i=1;i<=n;i=i+1)
{
sum_x=sum_x+(x[i]*x[i])/n;
sum_y=sum_y+(y[i])/n;
sum_xx=sum_xx+(x[i]*x[i]*x[i]*x[i])/n;
sum_xy=sum_xy+(x[i]*x[i]*y[i])/n;
}

m=(sum_xy-(sum_x*sum_y))/(sum_xx-(sum_x*sum_x));
cout<<"Value of constant a= "<<m<<endl;
c=sum_y-(m*sum_x);
cout<<"Value of constant b= "<<c<<endl;

for(i=1;i<=n;i=i+1)
{
y[i]=m*x[i]*x[i]+c;
out<<x[i]<<"\t"<<y[i]<<endl;
}
return 0;
}
