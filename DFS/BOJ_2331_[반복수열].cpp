#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<utility>
using namespace std;

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int a,p;
    stack<int>st;
    vector<int>check;

    cin>>a>>p;

    st.push(a);
    check.push_back(a);

    while(!st.empty()){

        int cur = st.top(); st.pop();
        int sum = 0;
        int result = 0;
        string strCur = to_string(cur);

        //계산
        for(int i=0;i<strCur.length();i++){
            int ocalc = strCur[i]-'0';
            sum = 0;
            int temp = 1;
            for(int j=0;j<p;j++){
                temp *=ocalc;
            }
            sum += temp;
            result += sum;
        }
        //계산결과(sum) 가 이미 check에 있는지 확인 
        for(int i=0;i<check.size();i++){
            //계산 결과가 이미 방문한 점인 경우
            if(result == check[i]){
                cout<<i;
                return 0;
            }
        }
        //방문하지 않은 점인 경우
        st.push(result);
        check.push_back(result);
    }

    return 0;
}