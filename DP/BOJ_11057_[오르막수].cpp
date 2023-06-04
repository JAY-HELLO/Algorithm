#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>vc(1001,vector<int>(1001,0));
/**
 * 문제 정의 
 * 오르막 수는 수의 자리가 오름차순을 이루는 수를 말한다
 * 인접한 수가 같아도 오름차순으로 생각한다.
 * 
 * D[N] = 길이가 N인 오르막수의 갯수
 * D[N] = D[N][0] ... D[N][9] 의 합
 * 
*/
int dp(int n, int k){
    if(k<0||k>9) return 0;
    if(n==0) return 0;
    if(n==1){
        vc[n][k] = 1;
        return 1;
    }
    if(!vc[n][k]){
        int result = 0;
        for(int i=k;i<=9;i++){
            result = result+(dp(n-1,i) % 10007)%10007;
        }
        vc[n][k] = result;
    }
    return vc[n][k];

}
int main(void){
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    long long result = 0;
    cin>>n;

    for(int i=0;i<10;i++){
        result = (result + dp(n,i))%10007;
    }
    cout<<result;
    return 0;
}