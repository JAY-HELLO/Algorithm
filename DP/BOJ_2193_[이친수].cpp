#include<iostream>
#include<vector>
using namespace std;
/**
 * 문제정의
 * n 자리 이친수의 개수를 구하라
 * D[N] = N 자리 이친수의 개수로 정의
 * 점화식
 * D[N] = D[N-1] + D[N-2];
 * 이유 : N자리 이친수의 뒤에 올 수 있는 수는 0 또는 1
 * 뒤의 수가 1일 경우 1은 연속으로 올 수 없기 때문에, N-1의 수는 0으로 고정
 * 따라서 
 * N 번째 자리수가 1일 경우 D[N-2] 개
 * N 번째 자리수가 0일 경우 D[N-1] 개
 * D[N] = D[N-1] + D[N-2]
*/
vector<long long>vc(100,0);
long long dp(int n){
    if(n<=0) {vc[n] = 0; return 0;}
    if(n==1) {vc[n] = 1; return 1;}
    if(!vc[n]){
        vc[n] = dp(n-1) + dp(n-2);
    };
    return vc[n];
    
}
int main(void){

    int n;
    cin>>n;

    cout<<dp(n);
    return 0;
}