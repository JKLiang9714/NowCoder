#include <iostream>
#include <cstdio>
using namespace std;

/*
题解：n个数的最小公倍数 
*/

const int MAXN = 100000;
long long a[MAXN + 1];

int gcd(int a, int b) {
	return a % b == 0 ? b : gcd(b, a % b);
}

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= n; i++) {
		a[i] = a[i] / gcd(a[i - 1], a[i]) * a[i - 1];
	}
	printf("%d\n", a[n]);
	return 0;
}

/*
3
*/
