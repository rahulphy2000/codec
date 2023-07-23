#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<fstream>
using namespace std;
float f(float x){
    return sin(x);
    
    //return x*x*exp(-x*x);
}
float fmax1(float a,float b){
    float f_max=f(a),x;
    for(x=a;x<=b;x+=.01){
        if(f_max<f(x)){
          f_max=f(x);
        }
    }
    if(f_max<0){
        f_max=0;
    }
    return(f_max);
}
float fmin1(float a,float b){
    float f_min=f(a),x;
    for(x=a;x<=b;x+=0.01){
        if(f_min>f(x)){
          f_min=f(x);
        }
    }
    if(f_min>0){
        f_min=0;
    }

    return(f_min);
}
float monte(int n){
    int i,nc1=0,nc2=0;
    float x,y,a=0,b=M_PI,integral,max,min;
     srand(time(NULL));
     max=fmax1(a,b);
     min=fmin1(a,b);
  for(i=0;i<n;i++){
    x=rand()/float(RAND_MAX);
    y=rand()/float(RAND_MAX);
    x=a+(b-a)*x;
    y=min+(max-min)*y;
    if(y>0)
    {
        if(y<f(x)){
            nc1+=1;
        }
    }
    else{
        if(y>f(x)){
            nc2+=1;
        }
    }
}
integral=(max-min)*(b-a)*(nc1-nc2)/(1.0*n);
return(integral);
}
int main(){
   int n;
ofstream out("data1.txt");
for(n=500;n<=20000;n=n+500){
cout<<"integral value is : "<<monte(n)<<endl;
out<<n<<" "<<monte(n)<<endl;
}

    return 0;

}