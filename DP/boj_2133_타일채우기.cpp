#include<bits/stdc++.h>
using namespace std;
/**
 * 해당 문제에 대한 점화식을 다시 제대로 세워볼 필요가 있다.
*/
int dp(vector<int>&d, int n){
    if(n%2) return 0;
    if( n<=1 ) return 1;
    if( n==2 ) return 3;
    if(d[n]) return d[n];
    else{
        d[n] = dp(d,n-2)*3;
        for(int i=n-4;i>=0;i-=2){
            d[n] += 2*dp(d,i); 
        }
        return d[n];
    }
}
int main(void){

    int n;
    cin>>n;

    //d[n] = 3*n 타일을 채우는 경우의수
    //d[n] = d[n-2]*3 + d[n-4]*2
    vector<int>d(n+1,0);
    d[1] = 1;
    d[0] = 1;
    cout<<dp(d,n);
    
    return 0;
}