#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

/*
题解：
	a^b = c^d，
	底数相等的情况： 
		1) 底数为1，即 1^b = 1^d 的情况：n * n 
		2) 底数不为1，即 a^b = a^b 的情况：(n - 1) * n
	底数不相等的情况： 
		拆成(i^x)^b = (i^y)^d，i^x <= n、j^y<=n 
		遍历i, 确定x和y的取值范围
		遍历x和y，取出x和y的最大公约数放到底数做i的指数
*/

const int MOD = 1000000007;

int gcd (int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() 
{
	int n;
	scanf("%d", &n);
	long long ans = (long long)(n * n + (n - 1) * n) % MOD;
	// 底数不相等的情况，即对于 (i^x)^b = (i^y)^d，讨论 x!=y 且 i>1
	set<int> s;
	for (int i = 2; i * i <= n; i++) {
		if (s.find(i) != s.end()) continue; 
		int tmp = i, cnt = 0;
		// 满足条件的底数，cnt为指数x和y的取值上限 
		while (tmp <= n) {
			s.insert(tmp);
			tmp *= i;
			cnt++;
		}
		// 相同的公约数，放到底数 
		for (int x = 1; x <= cnt; x++) {
			for (int y = x + 1; y <= cnt; y++) {
				ans = (ans + n / (y / gcd(x, y) ) * 2 ) % MOD;
			}
		} 
	}
	printf("%d\n", ans);
	return 0;
}

/*
2
*/ 
