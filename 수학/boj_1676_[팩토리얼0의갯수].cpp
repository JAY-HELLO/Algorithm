#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/**
 * 팩토리얼 0의 갯수
 * 2와 5가 동시에 들어있는 갯수
 * D[N][0] = n에서의 2의 갯수
 * D[N][1] = n에서의 5의 갯수
 * D[N][0] = D[N-1][0] + A[N][0];
*/
vector<vector<int>>D(501,vector<int>(2,0));

int main(void){

    D[2][0] = 1;
    for(int i=3; i<501; i++){

        //A[n]에서의 2와 5의 갯수 구하기.
        int temp = i;
        while(!(temp%2)) {D[i][0]++; temp/=2;}
        while(!(temp%5)) {D[i][1]++; temp/=5;}

        D[i][0] += D[i-1][0];
        D[i][1] += D[i-1][1];

    }

    int n;
    cin>>n;

    int minv = D[n][0];
    int result = min(minv, D[n][1]);
    cout<<result;
    return 0;
}