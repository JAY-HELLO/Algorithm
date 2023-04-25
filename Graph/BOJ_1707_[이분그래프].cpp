#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int K,V,E;
    int a,b;
    cin>>K; //TEST CASE의 개수
    for(int i=0;i<K;i++){
        bool flag = true;
        cin>>V>>E; //정점의 갯수와 간선의 개수
        //adjust list 형태로 그래프 구현
        vector<vector<int>>vc(V+2,vector<int>());
        //방문한 점을 저장하기 위한 배열.
        vector<int>check(V+1,0);
        queue<int>Q;
        //그래프 초기화.
        for(int j=0;j<E;j++){
            cin>>a>>b;
            //양방향 그래프
            vc[a].push_back(b);
            vc[b].push_back(a);

        }
        // linked list를 탐색하면서 이분 그래프인지 여부를 확인.
        // 그래프 탐색임으로 bfs 또는 dfs 를 사용해야함.
        for(int c=1;c<=check.size();c++){
            if(check[c]==0){
                Q.push(c); check[c] = 1;
                while(!Q.empty()){
                    int cur = Q.front(); Q.pop(); 
                    //cout<<"cur : "<<cur<<" ";

                    for(int g=0;g<vc[cur].size();g++){

                        //방문한적 없다면 q 에 넣고 방문체크
                        if(check[vc[cur][g]]==0){
                            Q.push(vc[cur][g]);
                            check[vc[cur][g]]=3-check[cur];
                            //cout<<"vc[cur][g] : "<<vc[cur][g]<<" ";
                        }
                        //방문한적이 있는 경우 인접한 점과 다른 색인지 확인
                        //cout<<"vc[cur][g] : "<<vc[cur][g]<<" ";
                        else if(check[vc[cur][g]]){
                            //인접한 점과 현재점이 같은 색일 경우
                            //cout<<vc[cur][g]<<" "<<check[cur]<<" "<<"확인";
                            if(check[vc[cur][g]]==check[cur]) {flag = false; break;}
                            
                        }
                        
                    }
                }
            }
            
        }
        /*cout<<"\n";
        for(int c=0;c<check.size();c++){
            cout<<"check : "<<check[c]<<" ";
        }*/
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}