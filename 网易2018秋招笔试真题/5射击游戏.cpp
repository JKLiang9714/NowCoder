#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题意：
	给定一堆点，求画两条互相垂直的线，最多能覆盖多少点
题解：
	先选择3个不共线的点，前两个点构造一条直线，后面一个点构造一条垂直于前一条直线的直线，
	然后枚举剩下的点是否在这两条线上，更新最大值就行了
*/

const int MAXN = 51;
int x[MAXN], y[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    if (n <= 2) {
        printf("%d\n", n);
    } else {
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dx1 = x[j] - x[i];
                int dy1 = y[j] - y[i];
                for (int k = 0; k < n; k++) {
                    int cnt = 0;
                    if (i != k && j != k) {
                        for (int l = 0; l < n; l++) {
                            int dx2 = x[l] - x[i];
                            int dy2 = y[l] - y[i];
                            int dx3 = x[l] - x[k];
                            int dy3 = y[l] - y[k];
                            if (dy1 * dx2 == dy2 * dx1 || dy1 * dy3 == -dx3 * dx1) {
                                cnt++;
                            }
                        }
                    }
                    res = max(res, cnt);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
5
0 -1 1 1 -1
0 -1 -1 1 1
*/
