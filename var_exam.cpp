#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int main()
{
	int i,n=0,b,j,k,mean;
	float a[100],e;
	ifstream in("sh1.in");
	e=a[0];
	in>>e;
	while(in>>a[n])
	{
		n=n+1;
	}
	//for small number
	for(i=1;i<n;i++)
	{
		if(e>a[i])
		{
			e=a[i];
		}
	}
	b=a[0];
	for(j=1;j<n;j++)
	{
		if(b<a[j])
		{
			b=a[j];
		}
		}
	float sum=0,v=0;
	for(k=0;k<n;k++)
	{
		sum=sum+a[k];
		v=v+a[k]*a[k];
	}
	float var=v/float(n+1);
	mean=sum/float(n+1);
	cout<<"the variable is "<<var<<endl;
	cout<<"the mean is "<<mean<<endl;
	cout<<"the value of e : "<<e<<endl;
	cout<<"the value of b : "<<b<<endl;
	return(0);
}

