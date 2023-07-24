#include<bits/stdc++.h>
using namespace std;

int main(void){

    int n;
    int cnt = 0;
    cin>>n;

    for(int i=0; i<n;i++){
        int temp = 0;
        cin>>temp;
        if(temp==1) continue;
        bool flag = false;
        for(int i=2; i*i<=temp; i++){
            if(!(temp%i)) {flag = true;break;}
        }
        if(flag) continue;
        cnt ++;
    }
    cout<<cnt;
    return 0;
}