#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

/*
题意：即能否找到奇数 X和偶数 Y满足 X * Y = N，2 <= N < 2^63
题解：类似于双指针，头尾指针每次乘除 2 
*/

int main() 
{
	int t;
	long long n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n & 1) printf("No\n");
		else {
			long long x = n / 2, y = 2;
			while (!(x & 1)) {
				x /= 2;
				y *= 2;
			}
			printf("%lld %lld\n", x, y);
		}
	} 
	return 0;
}

/*
2
10
5
*/
