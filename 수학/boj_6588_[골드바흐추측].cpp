#include<iostream>

using namespace std;

bool arr[1000001];

int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    //소수구하기

    for(int i=2;i*i<1000001;i++){
        if(arr[i]) continue;
        for(int j = i*2; j<1000001; j+=i){
            arr[j] = 1;
        }
    }

    while(1){
        int x=0;
        int y = 0;
        int n;
        cin>>n;
        if(n == 0) break;
        for(int i=3; i<n;i+=2){
            if(!arr[i]){
                if(!arr[n-i]){ 
                    y = n-i;
                    x = i;
                    cout<<n<<" = "<<x<<" + "<<y<<"\n";  
                    break;
                }
            }
        }
    }

    return 0;
}