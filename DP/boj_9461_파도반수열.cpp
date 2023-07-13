#include<bits/stdc++.h>
using namespace std;

long long dp(vector<long long> &d,int n){

    if(d[n]) return d[n];
    else{
        d[n] = dp(d,n-2) + dp(d,n-3);
        return d[n];
    }

}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;

    vector<long long>d(101,0);
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;

    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        cout<<dp(d,n)<<"\n";
    }
    
    return 0;
}