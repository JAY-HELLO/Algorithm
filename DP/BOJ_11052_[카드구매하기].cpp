#include<iostream>
#include<vector>
using namespace std;

vector<int>result(10001,0);

int operation(vector<int> &p, int n){
    
    int max = 0;
    int temp = 0;
    if(result[n] == 1) return p[1];
    if(result[n]>0){
        return result[n];
    }else{
        //pi 갯수만큼 돌면서, 최대값 찾아야함
        for(int i=1;i<=p.size();i++){
            if(n-i<0){
                temp = 0;
            }else{
                temp = p[i] + operation(p,n-i);
            }
            if(max<temp) max = temp;
        }
        result[n] = max;
        return max;
    }

}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int>p(1001,0);


    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    cout<<operation(p,n);

    return 0;
}