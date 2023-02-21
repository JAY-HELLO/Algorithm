#include<iostream>
#include<vector>
using namespace std;

/*문제 정의
세준이는 정수N 에 대해서 3가지 연산을 적용해 1을 만드려고 한다.
3가지 연산을 사용하는 횟수의 최소값을 출력하라

문제 풀이

정의 : D[N] 은 N에서 1을 만들기 위한 만들기 위한 연산의 최소 횟수이다.

연산은 3가지
N/3, N/2 N-1

즉 어떤 값이 D[N]에 도달하기 위해서 3가지의 연산을 사용할 수 있고,
연산 1번을 사용하면 +1 의 연산 횟수가 추가된다.

따라서 점화식은 D[N] = MIN(D[N/2]+1, D[N/3]+1, D[N-1]+1) 으로 해결할 수 있다.
*/

int _operation(vector<int>&vc, int n){

    int temp = 0;
    if(n == 1) return 0;
        
    if(vc[n]>0){
        return vc[n];
    }else{
        // 이 n 에 도달하기 위해서 1을 빼는 것이 가장 많은 연산이 필요할 것임으로
        // 처음 계산하고 이후 해당 값과 비교하면서 변경한다.
        vc[n] = _operation(vc,n-1)+1;

        if(n%2 == 0){ //결과가 저장된 것 보다 작으면 대체
            temp = _operation(vc,n/2)+1;
            if(vc[n]>temp) vc[n] = temp;
        }
        if(n%3 == 0){ // 결과가 저장된 것 보다 작으면 대체
            temp = _operation(vc,n/3)+1;
            if(vc[n]>temp) vc[n] = temp;
        } 
        
        
    }
    return vc[n];
}
int main(void){

    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>> N;

    vector<int>vc(N+1,0);

    cout<<_operation(vc,N);

    return 0;
}