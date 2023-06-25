#include<bits/stdc++.h>

using namespace std;

int main(void){

    int num;
    int temp;
    cin>>num;
    vector<int>vc(num,0);
    vector<int>D(num,0);

    for(int i=0;i<num;i++){
        cin>>temp;
        vc[i] = temp;
        D[i] = temp;
    }
    for(int i=1;i<num;i++){
        //D[i]는 i를 마지막으로 하는 제일 큰 연속합.
        //i까지의 합이 양수가 아닌 음수인 경우
        //i번째 까지의 가장 큰 수는 i번째 수 그 자체이다.
        D[i] = max(D[i-1],0)+vc[i];
    }
    sort(D.begin(),D.end(),greater<int>());

    cout<<D[0];

    return 0;
}