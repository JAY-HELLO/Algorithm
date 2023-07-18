#include<bits/stdc++.h>
using namespace std;

int main(void){

    string n;
    int b;
    cin>>n>>b;

    int result = 0;
    int d = 0;

    //b 진법 수 n
    for(int i=0;i<n.size();i++){
        if(n[i]>='A' && n[i]<='Z'){
            d = n[i]-'A'+10;
        }
        else{
            d = n[i]-'0';
        }
        result =  result * b + d;
    }
    cout<<result;
    return 0;
}