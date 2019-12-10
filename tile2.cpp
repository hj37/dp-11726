#include <iostream>
#include <cstdio>

using namespace std;
int D[1001];

/*
2*n Ÿ�ϸ� �����μ� ��ȭ���� ���ϸ�
D[n] = D[n-1] + D[n-2]�̴�
������ 2*1 �ϳ� ���� ��쿡�� D[n-1]�� ����� ���� ���ϸ� �ǰ�
1*2 Ÿ�� 2���� ���� ���� D[n-2]�� ����� ���� ���ϸ� �Ǳ�
�����̴�
���� ���� �ܰ� �ϳ��� ū���� �ܰ踦 ������� ��ȭ���� �ϼ��Ͽ���
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
    �Է� ���� N ������ 1���� 1000����
     */

    scanf("%d",&N);
    printf("%d",solution(N));

    return 0;
}
