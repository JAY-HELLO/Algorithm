#include<iostream>
#include<queue>
#include<utility>
#include<vector>

using namespace std;

int main() {
    
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int w, h;
    int dx[8] = {1,1,0,-1,-1,-1,0,1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};
    int groupCnt = 0;
    
    cin>>w>>h;
    while(w && h){

        int board[h+1][w+1];
        vector<vector<bool>>check(h+1,vector<bool>(w+1,0));
        
        groupCnt=0;
        // board 초기화
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>board[i][j];
            }
        }
        
        //모든 점 확인
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                
                // 갈 수 없는 곳이거나 이미 방문한 점이면 pass.
                if(!board[i][j] || check[i][j]) continue;
                
                //BFS 를 통한 탐색 시작
                queue<pair<int,int>>q;
                q.push({i,j}); check[i][j] =1;
                while(!q.empty()){
                    int curx = q.front().first;
                    int cury = q.front().second;
                    q.pop();
                    //8 방위 확인
                    for(int a=0;a<8;a++){
                        int nx = curx + dx[a];
                        int ny = cury + dy[a];
                        
                        if(nx<0 || nx>=h || ny<0 || ny>=w) continue;
                        if(!board[nx][ny] || check[nx][ny]) continue;
                        
                        q.push({nx,ny}); check[nx][ny] = 1;      
                        //큐에서 뺄때 체크하지 않으면 같은 값이 큐에 여러번 들어가게 된다.
                        //따라서 메모리가 낭비되고 메모리초과가 발생한다.              
                    }
                }
                groupCnt++;
            }
        }
        cout<<groupCnt<<"\n";
        cin>>w>>h;
    }
    
    return 0;
}
