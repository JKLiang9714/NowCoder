#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题解：扩展欧几里得算法，裴蜀定理
参考：https://www.acwing.com/blog/content/17/
*/

typedef long long LL;

LL extend_gcd(LL a, LL b, LL &x, LL &y)	// 扩展欧几里德算法
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL q = extend_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return q;
}

int main()
{
	int N;
	cin >> N;
	while (N--) {
		LL a, b, c, x, y;
		cin >> a >> b >> c;
		int d = extend_gcd(a, b, x, y);  // ax + by = d
		if(c > a && c > b || c % d) {  // 不可能完成
			cout << 0 << endl;
			continue;
		}
		if(c == a || c == b) {  // 1次操作完成
			cout << 1 << endl;
			continue;
		}

		if(y > 0) {  // xy < 0，令x > 0（x < 0时将a、b，x、y交换）
			swap(x, y);
			swap(a, b);
		}
		
		// 使ax + by = c （d是c的因子，即对上面式子ax + by = d两边同时乘以c / d）
		x *= c / d;  
		y *= c / d;
		
		LL a2 = a / d, b2 = b / d;
		LL k = x / b2;
		x -= k * b2;  // 使这组(x, y)最接近0（x > 0时的整数解）
		y += k * a2;
		
		LL res;
		if(c > a) // 情况(1)
			res = 2 * (x - y);
		else // 情况(2)
			res = 2 * (x - y - 1);
		
		x -= b2;  // 使这组(x, y)最接近0（y > 0时的整数解）
		y += a2;
		if(c > b) // 情况(1)
			res = min(res, 2 * (y - x));  // 上文分析中假设x > 0，这里y > 0
		else // 情况(2)
			res = min(res, 2 * (y - x - 1));
			
		cout << res << endl;
	}
	return 0;
}

/*
2
3 4 2
2 3 4
*/
