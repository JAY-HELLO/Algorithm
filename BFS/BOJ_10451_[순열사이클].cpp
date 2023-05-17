#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        int idx;
        int cnt = 0;

        cin>>idx;
          
        vector<int>vc(idx+1,0);
        vector<bool>chk(idx+1,0);
        queue<int>q;
        for(int a=1;a<=idx;a++){
            int temp = 0;
            cin>>temp;
            vc[a] = temp;
        }
 
        for(int j=1;j<=idx;j++){

            if(chk[j]) continue;
            q.push(j); chk[j]=1;
            while(!q.empty()){
                int cur = q.front();
                q.pop();

                if(chk[vc[cur]]) continue;

                q.push(vc[cur]);
                chk[vc[cur]]=1;
            }
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}