#include<iostream>
#include<vector>
using namespace std;

int operation(vector<int> &vc, int n){

    if(n==0) return 1;
    if(n==1) return 1;
    
    if(vc[n]>0){
        return vc[n];
    }else{
        vc[n] = (operation(vc,n-1)%10007 + 2*(operation(vc,n-2)%10007))%10007;
        return vc[n];
    }
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int>vc(n+1,0);
    cout<<operation(vc,n);

    return 0;
}