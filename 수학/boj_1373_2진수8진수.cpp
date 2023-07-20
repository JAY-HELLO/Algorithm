#include<bits/stdc++.h>
using namespace std;

int main(void){


    string num;
    string result = "";
    int temp = 0;
    cin>>num;
    int k = 0;
    for(int i=num.length()-1;i>=0;i--){
        if(k>2) {k = 0; result += to_string(temp); temp = 0;}
        temp += ((num[i]-'0') * pow(2,k));
        k++;
    }
    result += to_string(temp);
    for(int i=result.length()-1;i>=0;i--){
        cout<<result[i];
    }
    return 0;
}