#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){

    int num = 0;
    cin>>num;
    vector<int>vc(num,0);
    vector<int>dp(num,0);

    for(int i=0;i<num;i++){
        cin>>vc[i];
        dp[i]=vc[i];
        //자기자신이 가장 큰 경우일 수도 있음으로 이렇게 초기화.
    }
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(j<i && vc[j]<vc[i]){
                dp[i] = max(dp[i], dp[j]+vc[i]);
            }
        }
    }
    /*
    for(int i=0;i<num;i++){
        cout<<dp[i]<<" ";
    }*/
    sort(dp.begin(), dp.end(), greater<int>());

    cout<<dp[0];


    return 0;
}