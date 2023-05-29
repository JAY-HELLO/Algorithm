#include<iostream>
#include<vector>

using namespace std;
vector<vector<int>>vc(101,vector<int>(101,0));

/**
 * 문제 정의
 * 계단수란 각 인접한 자리의 수의 차가 1인 수
 * 
 * D[N] = N 번째 자리의 계단수의 갯수
 * 점화식 정의
 * D[N] = D[N][0] + ...D[N][9];
*/
long long dp(int n, int k){
    
    if(k<0 || k>9) return 0;
    if(n==0) return 0;
    if(n==1){
       if(k==0) return 0;
       vc[n][k]=1; return 1;
    }
    if(!vc[n][k]){
        vc[n][k] = (dp(n-1,k+1)%1000000000LL+dp(n-1,k-1)%1000000000LL)%1000000000LL;
    }
    return vc[n][k] % 1000000000LL;
    
}
int main(void){

    int n;
    int result=0;
    cin>>n;
    for(int i=0;i<=9;i++){
        result = (result + dp(n,i))%1000000000LL;
    }
    cout<<result;
    return 0;
}