# Dynamic Programming 

DP 는 두가지 속성을 만족해야한다

1. Overlapping Subproblem  
겹치는 부분문제

- 큰 문제와 작은 문제를 같은 방법으로 풀 수 있어야 한다.  

- 문제를 더 작은 문제로 쪼갤 수 있어야 한다.

2. Optimal Substructure  
문제의 정답을 더 작은 문제에서 구할 수 있어야함 

- 최적 부분구조를 만족한다면 문제의 크기에 상관없이 어떤 한 문제의 정답은 일정하다

***
다이나믹 프로그래밍에서 각 문제는 한번만 풀어야한다.  
Optimal Substructure을 만족하기 때문에 같은 문제는 구할 때 마다 정답이 같다.  
따라서 이러한 정답을 배열에 저장해 두었다가 사용한다.

-> memoization 이라고 한다.




