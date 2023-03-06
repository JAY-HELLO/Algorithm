#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>result(10002);

int operation(vector<int>p, int n){
    
    if(result[n][0]>0) return result[n][0];
    else{
    
        for(int i=1;i<=n;i++){
            result[n].push_back(p[i] + operation(p,n-i));
            sort(result[n].begin(),result[n].end(),greater<int>());
        }
        return result[n][0];
    }

}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int>p(n+2,0);


    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<operation(p,n);

    return 0;
}