#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
	
    int N;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    string Nstr;
	cin>>N;

    int board[N+1][N+1];
    vector<vector<bool>>check(N+1,vector<bool>(N+1,0));
    //bool check[N+1][N+1] = {0};
    
    vector<int>groupCnt(0); //단지수 저장
    int indexCnt = 0; // 단지내 아파트수 저장
    //vector<vector<int>>board2(N+1,vector<int>());

    //board 입력
    for(int i=0;i<N;i++){
        cin>>Nstr;
        for(int j=0;j<N;j++){
            board[i][j] = Nstr[j]-'0';
            //board2[i].push_back(Nstr[j]-'0');
        }
    }

    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            //board 에 갈 수 있는 영역이면서, 아직 방문하지 않은 영역의 경우 bfs를 수행
            if(check[i][j]==0 && board[i][j]){
                indexCnt = 0;

                queue<pair<int,int>>q;
                q.push({i,j}); check[i][j] = 1;
                while(!q.empty()){
                    int curx = q.front().first;
                    int cury = q.front().second;
                    q.pop();
                    indexCnt ++;
                    //현재점을 기준으로 상하좌우 확인
                    for(int a = 0;a<4;a++){
                        int nx = curx + dx[a];
                        int ny = cury + dy[a];

                        //상하좌우가 범위를 벗어난 값이면
                        if(nx<0 || nx>=N || ny<0 || ny>=N) continue;

                        //상하좌우가 방문한 점이거나 갈수 없는 점이면
                        if(check[nx][ny] || board[nx][ny]==0) continue;

                        q.push({nx,ny});
                        check[nx][ny]=1;
                    }
                }
                groupCnt.push_back(indexCnt);
            }
        }
    }
    cout<<groupCnt.size()<<"\n";
    
    sort(groupCnt.begin(),groupCnt.end());
    for(int i=0; i<groupCnt.size(); i++){
        cout<<groupCnt[i]<<"\n";
    }
    return 0;
}