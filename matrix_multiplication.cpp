#include<iostream>
#include<fstream>
using namespace std;
int main(){
float a[10][10],b[10][10],c[10][10],sum=0;
int n,i,j,k,r1,c1,r2,c2;
ifstream in("mat.in");
cout << "enter no. of row and column for matrix 1 :"<<endl;
cin >> r1>>c1;
cout << "enter no. of row and column for matrix 2 :"<<endl;
cin >> r2>>c2;
if(r2!=c1){
    cout<<"multiplication not possible"<<endl;
    goto jump;
}

for(i=0;i<r1;++i){
for(j=0;j<c1;j++){
in>>a[i][j];
}
}
for(i=0;i<r2;i++){
for(j=0;j<c2;j++){
in>>b[i][j];
}
}

for(i=0;i<r1;i++){
for(j=0;j<c2;j++){
sum=0;
for(k=0;k<c1;k++){
sum=sum+a[i][k]*b[k][j]	;
}

c[i][j]=sum;

}
}
cout<<"matrix mult is :"<<endl;
for(i=0;i<r1;i++){
for(j=0;j<c2;j++){
cout<<c[i][j]<<" ";
}
cout<<endl;
}
jump:

return 0;
}
