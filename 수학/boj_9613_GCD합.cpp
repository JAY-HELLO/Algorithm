#include<bits/stdc++.h>
using namespace std;

int gcd (int x, int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int main(void){

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int idx;
        cin>>idx;
        vector<int>vc(idx,0);
        //배열 초기화
        for(int j=0;j<idx;j++){
            cin>>vc[j];
        }

        long long result = 0;
        //gcd
        for(int j=0;j<idx-1;j++){
            for(int k=j;k<idx-1;k++){
                result += gcd(vc[j],vc[k+1]);
            }
        }
        cout<<result<<"\n";
    }
    return 0;
}