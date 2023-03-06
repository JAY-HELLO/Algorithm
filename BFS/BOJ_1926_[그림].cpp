#include<iostream>
#include<queue>
#include<utility> // pair 자료형 사용을 위함.
using namespace std;

/**
 * 도화지속 그림의 갯수와 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력
 * 그림의 갯수는 bfs가 시작하고 끝난 횟수
 * 그림의 넓이는 bfs가 호출됫 횟수
*/
int board[501][501];
bool visit[501][501];

//dx, dy 의 조합으로 상하좌우 확인
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


int N,M; //행과 열
int cnt=0; // 그림의 갯수
int width=0; // 그림의 넓이

void bfs(int x, int y){
    
    width = 0;
    //BFS 의 흐름은 현재에서 갈수 있는 곳 PUSH, 그리고 넣으면서 그 위치 CHECK(visit), 현재위치 POP 의 흐름.
    
    //갈수없는 곳이거나 방문했던 곳이면 반환
    if(!board[x][y] ||  visit[x][y]) return;

    //그림 수 증가.
    cnt++;
    queue<pair<int,int>> Q; //bfs는 큐로 구현

    Q.push({x,y});
    visit[x][y] = 1;
    while(!Q.empty()){
        pair<int,int>cur = Q.front(); 
        Q.pop();
        //큐의 원소마다 그림의 넓이증가
        width ++;
        //cur 기준 상하좌우 확인
        for(int dir = 0; dir<4;dir++){
            int ny = cur.second + dy[dir];
            int nx = cur.first + dx[dir];
            // 그림이 없는 장소이거나, 이미 방문한 장소이면 continue;
            if(!board[nx][ny] || visit[nx][ny]) continue;
            //범위를 벗어나면 continue
            if(ny>=M || ny <0 || nx>=N || nx < 0) continue;
            // 방문 가능한 곳은 방문 표시
            visit[nx][ny] = true;
            Q.push({nx,ny});
        }
    }
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N>>M;
    int maxwidth = 0;
    /**
     * board 초기화
    */
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            bfs(i,j);//시작점과 끝점을 제공
            if(maxwidth<width){
                maxwidth = width;
            }
        }
    }
    cout<<cnt<<"\n";
    cout<<maxwidth;
    return 0;
}