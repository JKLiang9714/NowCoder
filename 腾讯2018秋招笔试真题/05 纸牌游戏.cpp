#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

const int MAXN = 100000;
int card[MAXN + 1];

bool cmp(int a, int b) {
	return a > b;
}

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &card[i]);
	}
	sort(card, card + n, cmp);
	long long res = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) res -= card[i];
		else res += card[i];
	}
	printf("%lld\n", res);
	return 0;
}

/*
3
2 7 4
*/
