#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/**
 * d[i] 는 i번째 항을 마지막으로 사용하는 가장긴증가하는 수열
 * 문제에서는 이미 수열을 이루는 수가 주어진다 했음으로
 * 수열을 이루지 않는 경우에 대해서 신경쓸 필요가 없다.
 * i에서의 가장 긴 증가하는 수열은
 * i-1에서 +1 하거나
 * 
*/
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