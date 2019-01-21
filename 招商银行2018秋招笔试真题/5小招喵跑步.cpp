#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题意：当前在0点，要去x点，可以+1，-1，*2，求最快走法
题解：递归
	x为偶数时，一直走*2即可
	x为奇数时，需要多走一步，即+1后*2，或-1后*2
*/

int countStep(int x) {
	if (x < 0) x = -x;
	if (x == 0 || x == 1 || x == 2) return x;
	int step;
	if (x % 2 == 0) step = countStep(x / 2) + 1;
	else {
		int s1 = countStep((x + 1) / 2) + 2;
		int s2 = countStep((x - 1) / 2) + 2;
		step = min(s1, s2);
	}
	return step;
}

int main() 
{
	int x;
	scanf("%d", &x);
	int res = countStep(x);
	printf("%d\n", res);
	return 0;
}

/*
3
*/
