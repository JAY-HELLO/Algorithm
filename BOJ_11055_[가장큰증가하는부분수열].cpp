#include<iostream>
#include<vector>

using namespace std;

int main(void){

    int num = 0;
    cin>>num;
    vector<int>vc(num,0);
    vector<int>dp(num,0);

    for(int i=0;i<num;i++){
        cin>>vc[i];
    }


    return 0;
}