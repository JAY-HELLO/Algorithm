#include<iostream>
#include<vector>
using namespace std;

/*문제 정의
피보나치 함수 fibonacci(N)을 호출햇을때 0 과 1이 각각 볓 번 출력되는지를 구하는 프로그램 작성

//시간초과 해결방안
각 fibonacci 함수에 0 과 1이 몇번씩 들어가 있는지를 미리 저장한다
즉 fibo (1)에는 1 이 1번 0 이 0번 이라는 것을 저장한다.

*/
int cnt_zero;
int cnt_one;
vector<vector<int>>vc(41,vector<int>(2,0));


int fibonacci(int n, int num){

    if(num){ // num ==1
        if(n==1){
            return vc[1][1];
        }
        else if (n==0){
            return vc[0][1];
        }
        else if(vc[n][1]>0){
            return vc[n][1];
        }else{
            vc[n][1] = fibonacci(n-1,1)+fibonacci(n-2,1);
            return vc[n][1];
        }

        
    }else{ // num ==0
        if(n==1){
            return vc[1][0];
        }
        else if (n==0){
            return vc[0][0];
        }
        else if(vc[n][0]>0){
            return vc[n][0];
        }else{
            vc[n][0] = fibonacci(n-1,0)+fibonacci(n-2,0);
            return vc[n][0];
        }
    }
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base  :: sync_with_stdio(false);

    vc[0][0] = 1;
    vc[0][1] = 0;
    vc[1][0] = 0;
    vc[1][1] = 1;

    int T;
    int n;
    cin>>T;
    for(int i=0;i<T;i++){
        cnt_one = 0;
        cnt_zero = 0;
        cin>>n;
        //n 까지의 수에는 각각 0과 1 이 들어간 횟수를 저장하고 있다

        
        cout<<fibonacci(n,0)<<" "<<fibonacci(n,1)<<"\n";
    }

    return 0;
}