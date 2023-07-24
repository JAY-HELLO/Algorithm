#include<bits/stdc++.h>
using namespace std;

int main(void){

    long long n;
    string result="";
    cin>>n;

    if(n==0) {cout<<0; return 0;}
    while(n!=0){
        if(n<0){
            result += to_string(abs(n%-2));
            n = (n-1)/-2;
        }else{
            result += to_string(n%-2);
            n = n/-2;
        }
    }

    for(long long i=result.length()-1;i>=0;i--){
        cout<<result[i];
    }

    return 0;
}