#include<iostream>
#include<vector>

using namespace std;
/**
 * Di[a] = a를 마지막으로 하는 가장 긴 증가하는 수열
 * Dd[a] = a를 마지막으로 하는 가장 긴 감소하는 수열
 * 바이토닉 부분수열은 한 IDX를 기점으로 증가하던 것이 감소해야함으로
 * 두개의 수열 배열을 돌면서 해당 INDEX기점의 가장 큰 값을 계산하면 된다.
*/
int main(void){

    int num = 0;
    cin>>num;
    vector<int>vc(num,0);
    vector<int>Di(num,1); // increase 
    vector<int>Dd(num,1); // decrease

    for(int i=0;i<num;i++){
        cin>>vc[i];
    }
    //증가하는 수열
    for(int i=0;i<num;i++){
        for(int j=0;j<i;j++){
            if(j<i && vc[j]<vc[i]){
                Di[i] = max(Di[j]+1,Di[i]);
            }
        }
    }
    //감소하는 수열
    for(int i=num-1;i>=0;i--){
        for(int j=num-1;j>i;j--){
            if(j>i && vc[j]<vc[i]){
                Dd[i] = max(Dd[j]+1,Dd[i]);
            }
        }
    }

    int result = 0;
    int temp = 0;
    for(int i=0;i<num;i++){
        result = max(temp,Di[i]+Dd[i]);
        temp = result;
    }/*
    for(int i=0;i<num;i++){
        cout<<Di[i]<<" ";
    }
    cout<<"\n";
    for(int j=0;j<num;j++){
        cout<<Dd[j]<<" ";
    }*/
    cout<<result-1;
    return 0;
}