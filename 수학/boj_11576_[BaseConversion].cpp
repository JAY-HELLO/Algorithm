#include<bits/stdc++.h>
using namespace std;
/**
 * string 으로 할 경우 string은 아스키 코드 기반으로 숫자를 저장하기 때문에
 * 10 이라는 숫자가 to_string을 통해 저장되면
 * '10' 이 저장 되는 것이 아닌, 1과 0이 따로따로 저장된다.
*/
int main(void){

    int a, b;
    int m;
    cin>>a>>b>>m;
    int midResult = 0;
    //a 진법을 10진법으로 변환
    for(int i=0;i<m;i++){
        int temp = 0;
        cin>>temp;
        midResult = midResult*a + temp;
    }

    vector<int>result;
    while(midResult!=0){
        result.push_back(midResult%b);
        midResult /= b;
    }

    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i]<<" ";
    }


    return 0;
}