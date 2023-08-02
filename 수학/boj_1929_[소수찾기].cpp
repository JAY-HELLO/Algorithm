#include <iostream>
#include <vector>
using namespace std;

int main(void){

    int n, m;
    cin>>n>>m;
    vector<int>arr(1000001,1);

    // 소수이면 1 아니면 0;
    arr[1] = 0;
    arr[2] = 1;
    //소수찾기
    for(int i=2;i<1000001;i++){
        for(int j = i*2; j < 1000001; j += i){
            if(arr[j]) arr[j] = 0;
        }
    }

    for(int i=n;i<=m;i++){
        if(arr[i]) cout<<i<<"\n";
    }

    return 0;
}