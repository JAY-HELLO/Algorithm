#include<iostream>
#include<vector>

using namespace std;

/**
 * 2차원 배열 문제풀이
 * d[i][j] = i 번째 포토주가 연속으로 j번 마신경우의 최대값
 * n 번쨰 잔을 0번 연속으로 마셨다면 n-1 번째 잔을 0번, 1번, 2번 연속으로
 * 마신 것 중 최대값을 선택
 * d[n][0] = max(d[n-1][0], d[n-1][1], d[n-1][2])
 * n 번째 잔을 1번 연속으로 마셨다면,(1번째 잔이라면)
 * n-1번쨰 잔은 마시지 않는다
 * d[n][1] = d[n-1][0] + a[n]
 * n 번쨰 잔이 2번 연속으로 마신 잔이라면 (2번째 잔이라면)
 * n-1 번쨰 잔은 한번 마신다.
 * d[n][2] = d[n-1][2] + a[n]  
*/
vector<int>vc(10001,0);
vector<vector<int>>result(10001,vector<int>(3,0));

int num = 0;
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>num;
    for(int i=1;i<=num;i++){
        cin>>vc[i];
    }
    result[1][1] = vc[1];

    for(int i=2; i<=num;i++){
        result[i][0] = max(max(result[i-1][0],result[i-1][1]),result[i-1][2]);
        result[i][1] = result[i-1][0] + vc[i];
        result[i][2] = result[i-1][1] + vc[i];
    }
    cout<<max(max(result[num][0],result[num][1]),result[num][2]);

    return 0;
}