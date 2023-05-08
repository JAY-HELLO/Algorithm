#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

/**
 * 주의점
 * M은 가로를 나타낸다 M 은 좌표상 Y 이다 따라서 COL 이다.
 * N은 세로를 나타낸다 N 은 좌표상 X 이다 따라서 ROW 이다.
 * 배열은 ARRAY[COL][ROW]로 표현했다.
*/
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(void){

    //M = 배추밭의 가로길이
    //N =  세로길이
    //배추가 심어져 있는 개수 ( 위치로 주어지로 X,Y 좌표로 주어진다.)
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int result = 0;
        int M=0;
        int N=0;
        int K=0;
        cin>>M>>N>>K;
        // flood fill 이다.
        vector<vector<bool>>board(N+1,vector<bool>(M+1,0));
        vector<vector<bool>>check(N+1,vector<bool>(M+1,0));
        vector<pair<int, int>>v({});
        queue<pair<int,int>>q;
        
        
        for(int j=0;j<K;j++){
            int x, y;
            cin>>x>>y;
            board[y][x] = 1;
            v.push_back({y,x});
        }
        
        //bfs 시작
        for(int j=0;j<v.size();j++){

            // 이미 방문한 점이면 패스
            if(check[v[j].first][v[j].second]) continue;
            
            q.push({v[j].first,v[j].second}); 
            check[v[j].first][v[j].second] = 1;

            while(!q.empty()){
                pair<int, int>cur = q.front();
                q.pop();
                for(int a=0;a<4;a++){
                    
                    int nx = cur.second + dx[a];
                    int ny = cur.first + dy[a];

                    if(ny>=N || ny<0 || nx>=M || nx<0) continue;
                    if(!board[ny][nx] || check[ny][nx]) continue;

                    q.push({ny,nx});
                    check[ny][nx] = 1;
                }
            }
            result ++;
        }
        cout<<result<<"\n";
    }
    return 0;
}