//matrix multiplication
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
 float sum=0;
 int m,n,i,j,k,p,q;
 ifstream in("mat.in");
 in >> n;
 in>>m;
 in>>p;
 in>>q;
 float a[n][m];
 for(i=0;i<n;++i)
 {
  for(j=0;j<m;j++)
  {
   in>>a[i][j];
  }
 }
 float b[p][q];
 for(i=0;i<p;i++)
 {
  for(j=0;j<q;j++)
  {
   in>>b[i][j];
  }
 }
 float c[n][q];
 if(m!=p)
 {
  cout<<"matrices are not multiplicable"<<endl;
 }
 else
 {
  for(i=0;i<n;i++)
  {
   for(j=0;j<q;j++)
   {
    for(k=0;k<p;k++)
    {
     sum=sum+a[i][k]*b[k][j]	;
    }
    c[i][j]=sum;
    sum=0;
   }
  }
  
  for(i=0;i<n;i++)
  {
   for(j=0;j<q;j++)
   {
    cout<<c[i][j]<<" ";
   }
   cout<<endl;
  }
 }
 return 0;
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//coordinate rotation
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
 int i,j;
 float r[3],p[3][3],rnew[3],x,s,c;
 cout<<"value of the angle of rotation  ";
 cin>>x;
 s=sin(x);
 c=cos(x);
 p[0][0]=c, p[0][1]=s,p[0][2]=0;
 p[1][0]=-s,p[1][1]=c,p[1][2]=0;
 p[2][0]=0, p[2][1]=0,p[2][2]=1;
 
 ifstream in("dataG.in");
 for(i=0;i<3;i=i+1)
 {
  in>>r[i];
 }
 cout<<"new vector after rotation is"<<endl;
 for(i=0;i<3;i=i+1)
 {
  rnew[i]=0;
  for(j=0;j<3;j=j+1)
  {
   rnew[i]=rnew[i]+p[i][j]*r[j];
  }
  cout<<rnew[i]<<endl;
 }
}
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//shorting
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
 int i,j;
 float a[20],temp,sum1,sum2,mean,meansqure,sd;
 ifstream in("test5.in");
 for(i=0;i<20;i=i+1)
 {
  in>>a[i];
 }
 for(j=0;j<19;j=j+1)
 {
  for(i=0;i<19;i=i+1)
  {
   if(a[i]>a[i+1])
   {
    temp=a[i];
    a[i]=a[i+1];
    a[i+1]=temp;
   }
  }
 }

 cout<<a[0]<<endl;
 
 cout<<a[19]<<endl;
 sum1=0;
 sum2=0;
 for(i=0;i<20;i=i+1)
 {
  sum1=sum1+a[i];
  sum2=sum2+a[i]*a[i];
 }
 mean=sum1/20;
 meansqure=sum2/20;
 sd=sqrt(meansqure-mean*mean);
 cout<<"mean= "<<mean<<" (mean)^2= "<<mean*mean<<" meansqure= "<<meansqure<<" standard deviation= "<<sd<<endl;
}
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//simpson 1/3
#include <iostream>
#include <cmath>
using namespace std;
float fx(float x)
{
 float y=(sin(x))/x;
 return(y);
}
float gx(float a)
{
 int n=10;
 float b=1,err=1,h,I,sum1,sum2,i,j,xodd,xeven;
 float I1;
 I=0;
 while(err>0.000001)
 {
  h=(b-a)/n;
  sum1=0;
  sum2=0;
  for(i=1;i<n;i=i+2)
  {
   xodd=a+i*h;
   sum1=sum1+fx(xodd);
  }
  for(j=2;j<n;j=j+2)
  {
   xeven=a+j*h;
   sum2=sum2+fx(xeven);
  }
  I1=h*(4*sum1+2*sum2+fx(a)+fx(b))/3;
  err=abs(I1-I);
  I=I1;
  n=n+10;
 }
 return(I1);
}
int main()
{
 float err2=1,I3=0,I2,a=0.1;
 
 while(err2>0.000001)
 {
  
  I2=gx(a);
  err2=abs(I2-I3);
  I3=I2;
  a=a/10;
 }
 cout<<I3<<endl;
 return(0);
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//complex root
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
 int m;
 float x,y,r,theta,R,I,n;
 cout<<"give real part";
 cin>>x;
 cout<<"give imaginary part";
 cin>>y;
 cout<<"what order root you want? ";
 cin>>n;
 r=sqrt(x*x+y*y);
 if(x<0)
 {
  theta = atan(y/x)+M_PI;
 }
 else
 {
  theta=atan(y/x);
 }
 cout<<theta<<endl;
 for(m=0;m<n;m=m+1)
 {
  R=(pow(r,(1/float(n))))*cos((theta+2*M_PI*m)/n);
  I=(pow(r,(1/float(n))))*sin((theta+2*M_PI*m)/n);
  if(I<0)
  {
  cout<<m+1<<"th root is : "<<R<<I<<"i"<<endl;
  }
  else
  {
   cout<<m+1<<"th root is :"<<R<<"+"<<I<<"i"<<endl;
  }
}
 }
 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 //simpson 1/3
 #include <iostream>
#include <cmath>
using namespace std;
float fx(float x)
{
 float y=sin(x)/x;
return(y);
}
float gx(float ll)
{

 int i,n=10;
float h,b,err1=1;
float I=0,I1,xeven=0,xodd,oddsum,evensum=0;
 b=1; // uper limit
 while(err1>0.00001)
{

 h=(b-ll)/float(n); 

  xodd=0;
  oddsum=0;
 for(i=1;i<n;i=i+2)
 {
 xodd=ll+i*h;
 oddsum=oddsum+fx(xodd);
 }

  for(i=0;i<n;i=i+2)
 {
 xeven=ll+i*h;
 evensum=evensum+fx(xeven);
 }
I1 = h*(fx(ll)+fx(b)+4*oddsum+2*evensum)/3;
err1=abs(I1-I);
 I=I1;
n=n+100;
}
return(I1);
}
int main()
{
 float a,m=0.1,err2=1,I2,I3=0;
 a=m;
 while(err2>0.0000001)
 {
  I2=gx(a);
  err2=abs(I2-I3);
  I3=I2;
  m=m/10;
 }
 cout<<I3<<endl;
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//monte carlo
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;
float f(float x)
{
 float y=(sin(x));
 return(y);
}
float g(float a,float b)
{
 float fmax,x;
 fmax=f(a);
 for(x=a;x<=b;x=x+0.01)
 {
  float y1=f(x);
  if(fmax<y1)
  {
   fmax=y1;
  }
 }
 return(fmax);
}
float h(float a,float b)
{
 float fmin,x;
 fmin=f(a);
 for(x=a;x<=b;x=x+0.01)
 {
  float y2=f(x);
  if(fmin>y2)
  {
   fmin=y2;
  }
 }
 return(fmin);
}
int main()
{
 float a,b,I,x,y,fmin,fmax;
 int i,j,n,nc=0,nc2=0;
//cout<<"value of n ";
//cin>>n;
 cout<<"lower limit ";
 cin>>a;
 cout<<"uper limit ";
 cin>>b;

 srand(time(NULL));
 
 fmin=h(a,b);
 if(fmin>0)
 {
  fmin=0;
 }
 fmax=g(a,b);
 if(fmax<0)
 {
  fmax=0;
 }
 ofstream out("test.dat");
 
 for(j=0;j<40;j++)
 {
  n=1000*(1+j);
 for(i=0;i<n;i=i+1)
 {
  x=rand()/float (RAND_MAX);
  x=a+(b-a)*x;
  y=rand()/float(RAND_MAX);
  y=fmin+(fmax-fmin)*y;
  if(y>0)
  {
  if(y<f(x))
  {
   nc=nc+1;
  }
  }
  if(y<0)
  {
  if(y>f(x))
  {
   nc2=nc2+1;
  }
  }
 }
 I=(1.0*((fmax-fmin)*(b-a)*(nc-nc2)/n));
 cout<<I<<endl;
 out<<I<<endl;
 nc=0;
 nc2=0;
 
 }
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//monte carlo
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
float f(float x)
{
 return(cos(x));
}
float g(float a, float b)
{
 float x, y,fmax;
 fmax=f(a);
 for(x=a;x<=b;x=x+0.01)
 {
  y=f(x);
  if(fmax<y)
  {
   fmax=y;
  }
 }
 return(fmax);
}
float h(float a,float b)
{
 float x,y1,fmin;
 fmin=f(a);
 for(x=a;x<=b;x=x+0.01)
 {
  y1=f(x);
  if(fmin>y1)
  {
   fmin=y1;
  }
 }
 return(fmin);
}
int main()
{
 int i,j,n,nc1,nc2;
 float fmax,fmin,x,y,b,a,I;
 cout<<" a,b ";
 cin>>a>>b;
 srand(time(NULL));
 fmax=g(a,b);
 if(fmax<0)
 {
  fmax=0;
 }
 fmin=h(a,b);
 if(fmin>0)
 {
  fmin=0;
 }
 
 for(j=0;j<=40;j++)
 {
  nc1=0,nc2=0,n=500*(1+j);
 for(i=0;i<n;i=i+1)
 {
  x= rand()/float(RAND_MAX);
  x=a+(b-a)*x;
  y=rand()/float(RAND_MAX);
  y=fmin+(fmax-fmin)*y;
  if(y>0)
  {
  if(y<f(x)) 
  {
  
   nc1=nc1+1;
  }
  }
  if(y<0)
  {
  if(y>f(x))
  
  {
   nc2=nc2+1;
  }
  }
  
  
 }
 I=1.0*(b-a)*(fmax-fmin)*(nc1-nc2)/n;
 cout<<I<<" "<<n<<endl;
}
}
  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  //simpson graph
  #include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float f(float x)
{
 return(2*exp(-x*x));
}
float sim1(float a,float b,float n)
{
 float sum1,sum2,xodd,xeven,h,I;
 int i;
 h=(b-a)/float(n);
 sum1=0;
 sum2=0;
 for(i=1;i<n;i=i+2)
 {
  xodd=a+i*h;
  sum1=sum1+f(xodd);
 }
 for(i=2;i<n;i=i+2)
 {
  xeven=a+i*h;
  sum2=sum2+f(xeven);
 }
 I=h*(f(a)+f(b)+4*sum1+2*sum2)/3;
 return(I);
}
float sim2(float a,float b,float n)
{
 float I1,I2,err1=1;
 
 I2=0;
 while(err1>0.00001)
 {
  I1=sim1(a,b,n);
  err1=abs(I2-I1);
  I2=I1;
  n=n+10;
 }
 return(I2);
}
float sim3(float a,float b,float n)
{
 float I3,err2=1,I4;
 I3=0;
 
 while(err2>0.00001)
 {
  I4=sim2(a,b,n);
  err2=abs(I3-I4);
  I3=I4;
  b=b+10;
 }
 return(I3);
}
int main()
{
 float a,b,I6,err3=1,I5=0;
 int n;
 cout<<" n , a ,b ";
 cin>>n>>a>>b;
 while(err3>0.00001)
 {
  I6=sim3(a,b,n);
  err3=abs(I6-I5);
  I5=I6;
  a=a/10;
 }
 cout<<I5;
} 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//simpson graph
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float f(float x)
{
 return(cos(M_PI*(x*x/2)));
}
float sim1(float a,float b,float n)
{
 float sum1,sum2,xodd,xeven,h,I;
 int i;
 h=(b-a)/float(n);
 sum1=0;
 sum2=0;
 for(i=1;i<n;i=i+2)
 {
  xodd=a+i*h;
  sum1=sum1+f(xodd);
 }
 for(i=2;i<n;i=i+2)
 {
  xeven=a+i*h;
  sum2=sum2+f(xeven);
 }
 I=h*(f(a)+f(b)+4*sum1+2*sum2)/3;
 return(I);
}
float sim2(float a,float b,float n)
{
 float I1,I2,err1=1;
 
 I2=0;
 while(err1>0.00001)
 {
  I1=sim1(a,b,n);
  err1=abs(I2-I1);
  I2=I1;
  n=n+10;
 }
 return(I2);
}

int main()
{
 float a=0,b,err3=1,I5=0;
 int n,j;
 cout<<" n , a ";
 cin>>n;
 ofstream out("test.out");
 
 for(j=0;j<40;j++)
 {
  b=0.05+j*0.05;
  I5=sim2(a,b,n);
  cout<<I5<<" "<<endl;
  out<<I5<<endl;
 }
} 
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//runge kutta complex
#include <iostream>
#include <cmath>
using namespace std;
typedef struct
{
 float z1,z2,z3,z4,z5,z6;
}a;
a f(float x,float y)
{
 a u;
 u.z1=x*x-y*y+2*x+5;//u
 u.z2=2*x*y+2*y;// v
 u.z3=2*x+2;//ux
 u.z4=-2*y;//uy
 u.z5=2*y;//vx
 u.z6=2*x+2;//vy
 return (u);
}

int main()
{
 float x0,y0,D;
 cout<<"gause value of x0 and y0  ";
 cin>>x0>>y0;
 a v=f(x0,y0);
 while(abs(v.z1*v.z1+v.z2*v.z2)>0.0001)
 {
  D=(v.z3*v.z6-v.z4*v.z5);
  x0=x0-(v.z6*v.z1-v.z4*v.z2)/D;
  y0=y0-(-v.z5*v.z1+v.z3*v.z2)/D;
  v=f(x0,y0);
 }
 if(y0>0)
 {
 cout<<x0<<"+"<<y0<<"i"<<endl;
 }
 else
 {
  cout<<x0<<""<<y0<<"i"<<endl;
 }
}
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//rk4
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float f(float y1,float y2,float t,float a,float B,float q)//x0=y1,y0=y2,z0=t
{
 return(B*y1+(a+q)*y2);
}
float g(float y1,float y2,float t,float a,float B,float q)
{
 return ((a-q)*y1-B*y2);
}
int main()
{
 int i,n;
 float x0,y0,z0,w0,h,b,k1,m1,k2,m2,k3,m3,k4,m4,a,B,q;
 cout<<"give intial value time,initial displacement and initial velocity : ";
 
 cin>>x0>>y0>>z0;
 cout<<"number of chopping: ";
 cin>>n;
 cout<<"maximum displacement" ;
 cin>>b;
 cout<<"give the value of frequency";
 cin>>a>>B>>q;
 h=(b-x0)/n;
 ofstream out("test.out");
 for(i=0;i<n;i=i+1)
 {
 out<<x0<<" "<<y0<<endl;
 k1=h*f(x0,y0,z0,a,B,q);
 m1=h*g(x0,y0,z0,a,B,q);
 k2=h*f(x0+h/2,y0+k1/2,z0+m1/2,a,B,q);
 m2=h*g(x0+h/2,y0+k1/2,z0+m1/2,a,B,q);
 k3=h*f(x0+h/2,y0+k2/2,z0+m2/2,a,B,q);
 m3=h*g(x0+h/2,y0+k2/2,z0+m2/2,a,B,q);
 k4=h*f(x0+h,y0+k3,z0+m3,a,B,q);
 m4=h*g(x0+h,y0+k3,z0+m3,a,B,q);
 y0=y0+(k1+2*k2+2*k3+k4)/6;
 z0=z0+(m1+2*m2+2*m3+m4)/6;
 x0=x0+h;
 } 
}
 
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
