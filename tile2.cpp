#include <iostream>
#include <cstdio>

using namespace std;
int D[1001];

/*
2*n 타일링 문제로서 점화식을 구하면
D[n] = D[n-1] + D[n-2]이다
이유는 2*1 하나 오는 경우에는 D[n-1]의 경우의 수를 구하면 되고
1*2 타일 2개가 오는 경우는 D[n-2]의 경우의 수를 구하면 되기
때문이다
작은 문제 단계 하나와 큰문제 단계를 연결시켜 점화식을 완성하였다
*/
int solution(int n)
{
    if(n == 1) D[n] = 1;
    else if(n == 2) D[n] = 2;
    else if(D[n-1] > 0 && D[n-2] > 0)
    {
        D[n] = (D[n-1] + D[n-2])% 10007;
    }
    else{
        D[n] = (solution(n-1) + solution(n-2)) % 10007;
    }

    return D[n];
}
int main()
{
    int N;
    /*
    입력 변수 N 범위는 1부터 1000까지
     */

    scanf("%d",&N);
    printf("%d",solution(N));

    return 0;
}
