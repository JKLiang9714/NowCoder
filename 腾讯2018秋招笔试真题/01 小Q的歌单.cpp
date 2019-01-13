#include <iostream>
#include <cstdio>
using namespace std;

/*
题解：从 a 中拿 i 首的个数 *  从 b 中拿 j 首的个数
难点：排列组合，主要用二维数组来模拟计算组合数 C(n, m) 
*/

const int MAXN = 100;
const int MOD = 1000000007;
long long c[MAXN + 1][MAXN +1] = { 0 };

// 存储组合数 C(n, m) 的值 
void init() {
	c[0][0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= MAXN; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

int main() 
{
	int k, a, x, b, y;
	scanf("%d%d%d%d%d", &k, &a, &x, &b, &y);
	init();
	long long ans = 0;
	for (int i = 0; i <= x; i++) {
		// 对于 a 类歌曲，从 x 中取 i 个 
		// 对于 b 类歌曲，从 y 中取 (k - i * a) / b 个
		if (i * a <= k && (k - i * a) % b == 0 && (k - i * a) / b <= y) {
			ans = (ans + (c[x][i] * c[y][(k - i * a) / b]) % MOD) % MOD;
		}
	} 
	printf("%lld\n", ans);
	return 0;
}

/*
5
2 3 3 3
*/
