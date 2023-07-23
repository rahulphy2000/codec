//mean deviation
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
 int i;
 float x[10],y[10],barxxy=0,bary=0,barxx=0,barxxxx=0,z,a,b;
 ifstream in("test.in");

 for(i=0;i<6;i++)
 {
  in>>x[i]>>y[i];
  cout<<x[i]<<" "<<y[i]<<endl;
 }
 for(i=0;i<6;i++)
 {
  barxxy=barxxy+x[i]*x[i]*y[i]/6.0;
  bary=bary+y[i]/6.0;
  barxx=barxx+x[i]*x[i]/6.0;
  barxxxx=barxxxx+x[i]*x[i]*x[i]*x[i]/6.0;
 }
 
 a=(barxxy-bary*barxx)/float(barxxxx-(barxx*barxx));
 b=bary-a*barxx;
 cout<<"a="<<a<<"and b="<<b<<endl;
 ofstream out("test1.out");
 for(z=0;z<6;z=z+0.1)
 {
  out<<z<<" "<<((a*z*z)+b)<<endl;
  cout<<z<<" "<<((a*z*z)+b)<<endl;
 }
}
 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 //bisection
 #include <iostream>
#include <cmath>
using namespace std;
float f(float x)
{
 return (x*x*x)-6*(x*x)+11*x-6;
}
int main()
{
float x1,x2,x,a,b;
cout<<" gauss value of a and b";
cin>>a>>b;
loop: f(a)*f(b);
if(f(a)*f(b)>0)
{ 
 cout<< "put another gauss value";
 cin>>a>>b;
 goto loop;
}
if(f(a)<0)
{
 x1=a;
 x2=b;
}
else
{
 x2=a;
 x1=b;
}
while(abs(f(x))>0.0001)
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
 cout<<"answer "<<x<<endl;
 }
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 //newton interpolation
 #include <iostream>
#include <fstream>
using namespace std;
int main()
{
 int i,j,n;
 cout<<"give number of data point";
 float x[100],y[100][100],h,s,x0,term,sum;
 cin>>n;
 cin>>x0;
 
 
 ifstream in("data1.in");
 for(i=0;i<n;++i)
 {
  in>>x[i]>>y[0][i];
 }
 for(j=1;j<n;++j)
 {
  for(i=0;i<n-j;++i)
  {
   y[j][i]=y[j+1][i-1]-y[j+1][i];
  }
 }
  
  h=x[1]-x[0];
  s=(x0-x[0])/h;
  term=1;
  sum=y[0][0];
  for(i=1;i<n;++i)
  {
   term=term*(s+1-i)/i;
   sum=sum+term*y[i][0];
  }
  cout<<x0<<sum; 
 } 
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 //lagrange interpolation
 #include <iostream>
#include <fstream>
using namespace std;
int main()
{
 int i,j;
 float xp,x[100],y[100],p,n,yp=0;
 cout<<"enter the number of data points";
 cin>>n;
 
 
 for(i=0;i<n;i=i+1)
 {
  cout<<"[x"<<i<<"]=";
  cin>>x[i];
  cout<<"[y"<<i<<"]=";
  cin>>y[i];
 }
 cout<<"interpolation point";
 cin>>xp;
 for(i=0;i<n;i=i+1)
 {
  p=1;
  for(j=0;j<n;j=j+1)
  {
   if(i!=j)
   {
    p=p*(xp-x[j])/(x[i]-x[j]);
   }
  }
  yp=yp+p*y[i];
 }
 cout<<"interpolated result at x= "<<xp<<" is "<<yp<<endl;
}
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//jacobi
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
int i,j,n=4;
float a[5][5],b[5],xnew[5],xold[5],D;
ifstream in("test20.in");
for(i=1;i<=4;i=i+1)
{
for(j=1;j<=4;j+j+1)
{
in>>a[i][j];
}
}
for(i=1;i<=;i=i+1)
{
in>>b[i];
xold[i]=1.0;
}
D=1;
while(D>0.0001)
{
for(i=1;i<5;i=i+1)
  {
   xnew[i]=b[i]/a[i][i];
   for(j=1;j<i;j=j+1)
   {
    xnew[i]=xnew[i]-(a[i][j]/a[i][i])*xnew[j];
   }
   for(j=i+1;j<5;j=j+1)
   {
    xnew[i]=xnew[i]-(a[i][j]/a[i][i])*xold[j];
   }
  }
  D=0;
  for(i=1;i<=n;i=i+1)
  {
   D=D+abs(xnew[i]-xold[i]);
   xold[i]=xnew[i];
  }
 }
 for(i=1;i<=n;i=i+1)
 {
  cout<<"[x"<<i<<"]="<<xnew[i]<<endl;
 }
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
