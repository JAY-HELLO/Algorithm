#include<bits/stdc++.h>
using namespace std;

int main(void){

    string s;
    string result = "";
    string temp = "";
    cin>>s;

    if(s=="0") {cout<<s; return 0;}
    for(int i=s.length()-1;i>=0;i--){
        temp = "";
        int n = s[i]-'0';
        while(n!=0){
            temp += to_string(n%2);
            n/=2;
        }
        if(temp.length()!=3 && i!=0){
            while(temp.length()!=3){
                temp+='0';
            }
        }
        result += temp;
    }
    for(int i=result.length()-1;i>=0;i--){
        cout<<result[i];
    }
    return 0;
}