#include<iostream>
using namespace std;

int gcd(int x, int y){
    if(y==0) return x;
    return gcd(y, x%y);
}
int main(void){

    int a, b;
    cin>>a>>b;
    int gcdv = gcd(a,b);
    cout<<gcdv<<"\n"<<a*b/gcdv;

    return 0;
}