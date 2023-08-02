#include<iostream>

using namespace std;
/**
 * 소인수 분해란 합성수를 소수의 곱으로 나타내는 것.
*/
bool prime[10000001];
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    int t = 2;
    cin>>n;
    
    //소인수 생성
    for(int i=2; i*i<=n; i++){
        if(!prime[i]) continue;
        for(int j=i*2;j<=n;j+=i){
            //소수가 아닐경우 true 반환
            prime[j]=true;
        }
    }
    int temp = n;
    
    for(int i=2;i<=n;i++){
        if(prime[i]) continue; //소수가 아닐 경우 패스
        
        while(!(temp%i)){
            cout<<i<<"\n";
            temp/=i;
        }
    }

    return 0;
}