#include<iostream>
#include<vector>

using namespace std;

int func(vector<int> &vc, int n){
    // n == 0 일때 1을 두는 이유는 아무것도 없는 것 뒤에 1-2 막대를 두개 둠으로써 2*2를 만들 수 있다.
    // 따라서 아무것도 없지만 1개의 방법으로 취급하면 n==2 부터의 계산이 편해진다.
    if(n == 0) return 1;
    if(n == 1) return 1;
    if(vc[n]>0) return vc[n];
    else{
        int temp1 = func(vc,n-1)%10007;
        int temp2 = func(vc,n-2)%10007;
        vc[n] = (temp1 + temp2) % 10007;
        return vc[n];
    }
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int>vc(1001,0);

    cout<<func(vc,n);


    return 0;
}