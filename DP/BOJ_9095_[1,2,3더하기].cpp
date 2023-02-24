#include<iostream>
#include<vector>
using namespace std;

int operation(vector<int> &vc, int n){

    if(n<0) return 0;
    if(n==0) return 1;
    if(n==1) return 1;
    if(vc[n]>0){
        return vc[n];
    }else{
        vc[n] = operation(vc,n-1) + operation(vc,n-2) + operation(vc,n-3);
        return vc[n];
    }
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n;
        cin>>n;
        vector<int>vc(n+1,0);
        cout<<operation(vc,n)<<"\n";
    }
    return 0;
}