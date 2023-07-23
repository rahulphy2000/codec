#include<iostream>
#include<cmath>
using namespace std;

int main(){
  int i,j,k;
  float t,sum;
    cout<<"enter the value of theta(in degree) ";
    cin>>t;
    t=t*(M_PI/180);
   float p[3][3]={{cos(t),sin(t),0},{-sin(t),cos(t),0},{0,0,1}};
   cout<<"rotation matrix is "<<endl;
   for(i=0;i<3;i++){
for(j=0;j<3;j++){
cout<<p[i][j]<<" ";
}
cout<<endl;
}
    float x[3][1]={{2},{1},{2}},x1[3][1];
    for(i=0;i<3;i++){
        for(j=0;j<1;j++)
        {
            sum=0;
         for(k=0;k<3;k++){
           sum=sum+p[i][k]*x[k][j];
         }
         x1[i][j]=sum;
        }
    }
    cout<<"matrix a\' is :"<<endl;
for(i=0;i<3;i++){
for(j=0;j<1;j++){
cout<<x1[i][j]<<" ";
}
cout<<endl;
}
    
    return 0;
}