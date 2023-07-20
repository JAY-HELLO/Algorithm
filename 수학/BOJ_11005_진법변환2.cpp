#include<bits/stdc++.h>
using namespace std;

int main(void){

    long long n;
    int b;
    cin>>n>>b;
    string str = "";
    string ostr = "";
    //10진법수 n을 b진법으로 바꿔 출력하는 프로그램
    while(n!=0){
        if(b>10){

            if(n%b>9){
                str+=('A'+(n%b-10));
            }else{
                str+= to_string(n%b);
            }

        }else{
           str += to_string(n%b);
        }
        n/=b;
        
    }
    for(long long i=str.length()-1;i>=0;i--){
        ostr += str[i];
    }
    cout<<ostr;

    return 0;
}