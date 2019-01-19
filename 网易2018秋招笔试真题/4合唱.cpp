#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
题意：将一个数组的元素分给两个人，顺序不能乱，每个人的难度为各相邻元素之和，求两个人的最小难度和
题解：
	dp[i][j] 表示当前小Q唱到第 i 个音调，牛博士唱到第 j 个音调的难度和
	递归式：
		dp[i][j] = dp[i-1][j] + abs(v[i] - v[i-1]), 			j < i - 1 
		dp[i][i-1] = min{ dp[i-1][k] + abs(v[i] - v[k]) }, 		k < i - 1 
	初始化：
		初始情况是若当前有 i 个音调，可以让一个人只唱第一个或最后一个音调，剩下的音调都由另一个人唱 
		dp[i][0] = dp[i-1][0] + abs(v[i] - v[i-1]), 			i ≥ 2 
		dp[i][i-1] = dp[i-1][i-2] + abs(v[i-1] - v[i-2]), 		i ≥ 2
*/

const int MAXN = 2010;
int v[MAXN];
int cost[MAXN];
int dp[MAXN][MAXN];
int res = INT_MAX;

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		cost[i] = abs(v[i] - v[i - 1]);
	}
	for (int i = 2; i < n; i++) {
		dp[i][i - 1] = dp[i - 1][i - 2] + cost[i - 1];
	}
	for (int i = 2; i < n; i++) {
        for (int j = 0; j < i - 1; j++) {
            dp[i][j] = dp[i - 1][j] + cost[i];
            dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        res = min(res, dp[n - 1][i]);
    }
	printf("%d\n", res);
	return 0;
}

/*
5
1 5 6 2 1
*/
