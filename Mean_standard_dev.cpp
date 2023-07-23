#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int main(){
ifstream in("data4.in");
int i;
float a[20],b[20],sum=0;
for(i=0;i<20;i++){
    in>>a[i];
}
for(i=0;i<20;i++){
sum+=a[i];
}
float avg=sum/20;
for(i=0;i<20;i++){
    b[i]=a[i]*a[i];
}
sum=0;
for(i=0;i<20;i++){
sum+=b[i];
}
float avg1=sum/20;
    float sd=sqrt(avg1-avg*avg);
    cout << "mean "<<avg<<endl<<"sd "<<sd<<endl;
    return 0;
}