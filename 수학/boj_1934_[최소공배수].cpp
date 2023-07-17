#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(void){

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int a, b;
        cin>>a>>b;

        int gcdv = gcd(a,b);
        cout<<a*b/gcdv<<"\n";
    }
    return 0;
}