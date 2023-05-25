#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int cnt = 0;
vector<pair<int,int>>vc;

void hanoi(int a, int b, int n){
    // a = 출발기둥, b = 도착기둥, n 옮길 원판의 개수
    if(n==0) {return;}
    cnt ++;
    hanoi(a,6-a-b,n-1);//기둥 a에서 기둥6-a-b로 n-1개의 원판을 옮긴다.
    vc.push_back({a,b}); //기둥 a 에서 기둥b 로 n번 원판을 옮긴다.
    hanoi(6-a-b,b,n-1);//기둥 6-a-b에서 기둥 b 로 n-1개의 원판을 옮긴다.
    return;
}
int main(void){

    int n;
    cin>>n;
    hanoi(1, 3, n);
    cout<<cnt<<"\n";
    for(int i=0;i<vc.size();i++){
        cout<<vc[i].first<<" "<<vc[i].second<<"\n";
    }
    return 0;
}