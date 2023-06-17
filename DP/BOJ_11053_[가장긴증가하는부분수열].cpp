#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){

    int num;
    int cnt = 1;
    cin>>num;
    
    vector<int>vc(num,0);
    vector<int>dp(num+1,1);
    for(int i=0;i<num;i++){
        cin>>vc[i];
    }
    
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(vc[j]<vc[i] && dp[j]>=dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }
    sort(dp.begin(),dp.end(),greater<int>());
    cout<<dp[0];

    return 0;
}