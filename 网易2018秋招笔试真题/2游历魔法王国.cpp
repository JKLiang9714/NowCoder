#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题解：
1.如果是L <= maxLen，那么就直接输出L
2.否则利用贪心思想，先遍历除了深度最深的那条链（主链）之外的链，
（因为走的越深，回路上重复的节点走的就越多），遍历时需要留给主链maxLen的步数 
即：min(n, 1 + maxLen + (L - maxLen) / 2)
*/

int parent[51];
int dp[101];

int main() 
{
	int n, L;
    scanf("%d%d", &n, &L);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &parent[i]);
    }
    int mx = 0;		// 树的最大深度 
    for(int i = 0; i < n - 1; i++) {
        dp[i + 1] = dp[parent[i]] + 1;
        mx = max(mx, dp[i + 1]);
    }
    int d = min(L, mx);
    printf("%d\n", min(n, 1 + d + (L - d)/2));
	return 0;
}

/*
5 2
0 1 2 3
*/
