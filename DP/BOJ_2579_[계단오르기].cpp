#include<iostream>
#include<vector>

using namespace std;
/**
 * D[i][j]는 i 번째 계단을 j번 연속으로 올라올때의 최대점수를 갖는 배열
 * 
*/
int main(void){

    int num;


    cin>>num;
    vector<int>vc(num+1,0);
    vector<vector<int>>D(num+1,vector<int>(3,0));

    for(int i=1;i<=num;i++){
        cin>>vc[i];
    }

    if(num==1){
        D[1][1] = vc[1];
    }else if(num==2){
        D[1][1] = vc[1];
        D[2][1] = vc[2];
        D[2][2] = D[1][1] + vc[2];
    }else{
        
        D[1][1] = vc[1];
        D[2][1] = vc[2];
        D[2][2] = D[1][1] + vc[2];
    }
     

    for(int i=3;i<=num;i++){
        D[i][1] = max(D[i-2][1], D[i-2][2]) + vc[i];
        D[i][2] = D[i-1][1] + vc[i];
    }
    
    cout<<max(D[num][1],D[num][2]);

    
    return 0;
}