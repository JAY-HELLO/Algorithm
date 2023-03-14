#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;

int visit[101][101];
int board[101][101];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue<pair<int,int>> Q;
    
    int N;
    int M;
    string str;
    cin>>N>>M;

    // 1은 이동 가능한 칸, 0은 이동이 불가능한 칸
    
    /**
     * board 초기화
     * 각각의 수들이 붙어서 입력으로 주어짐으로 그부분을 처리해줘야함.
    */
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<M;j++){
            board[i][j] = str[j]-'0';
        }
    }

    Q.push({0,0});
    visit[0][0]=1;
    while(!Q.empty()){
        pair<int,int>cur = Q.front(); Q.pop();
        // 상하 좌우 확인
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            //방문한 점이거나 방문할 수 없는 점이면 넘어감
            if(visit[nx][ny]>0 || !board[nx][ny]) continue;
            //상하좌우가 범위에서 벗어나면 넘어감
            if(nx<0 || nx>=N || ny<0 || ny>=M) continue;

            //방문하게 되면 방문했다고 표시하고
            visit[nx][ny] = visit[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout<<visit[N-1][M-1];

    return 0;
}