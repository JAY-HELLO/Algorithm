#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/**
 * D[i] = i를 마지막으로 하는 가장 긴 감소하는 부분수열
 * 마찬가지로 조건이 중요
 * j<i 이고 v[j]>vc[i]이면 
 * D[i] = max(v[j]+1,v[i])
*/
int main(void){

    int num;
    cin>>num;
    vector<int>vc(num,0);
    vector<int>D(num,1);
    for(int i=0;i<num;i++){
        cin>>vc[i];
    }

    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(j<i && vc[j]>vc[i]){
                D[i] = max(D[j]+1,D[i]);
            }
        }
    }

    sort(D.begin(),D.end(),greater<int>());
    cout<<D[0];
    
    return 0;
}