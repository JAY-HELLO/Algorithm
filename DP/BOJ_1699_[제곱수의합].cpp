#include<bits/stdc++.h>
using namespace std;

int main(void){

    int num = 0;
    cin>>num;
    vector<int>D(num+1,0);
    //초기화 모두 1의 제곱으로 이루어진 항이 가장 작다고 가정.
    for(int i=1;i<=num;i++){
        D[i] = i;
    }
    
    for(int i=1;i<=num;i++){
        for(int j = 1;j*j<=i;j++){
            D[i] =min(D[i],D[i - j*j] + 1); 
        }
    }
    
    cout<<D[num];
    return 0;
}