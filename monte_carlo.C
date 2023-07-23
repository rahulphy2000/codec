#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
using namespace std;

int main(void)
{
int i,n,count;
float rand_x,rand_y,z,pi;

ofstream out("dat.txt");
ofstream out1("dat1.txt");

count=0;
srand(time(0));

cout<<"Give the value of n: ";
cin>>n;

for(i=0;i<n;i++)
{
rand_x=rand()/float(RAND_MAX);
rand_x=-1+2*rand_x;
rand_y=rand()/float(RAND_MAX);
rand_y=-1+2*rand_y;

z=rand_x*rand_x+rand_y*rand_y;

if(z<=1)
{
count++;
out<<rand_x<<"\t\t"<<rand_y<<endl;
}
else
{
pi=((1.0*count)/n)*4;
out1<<rand_x<<"\t\t"<<rand_y<<endl;
}
}
cout<<"The value of pi is "<<pi<<endl;
}
