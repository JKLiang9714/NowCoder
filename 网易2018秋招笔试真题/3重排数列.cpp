#include <iostream>
#include <cstdio>
using namespace std;

/*
题意：重排数列A，使得对于任意i，满足A[i] * A[i + 1]是4的倍数
题解：
	思路？
		1. 能整除4的数，和任意数相乘后，还是能整除4
		2. 能整除2但不能整除4的数，只能和能整除2但不能整除4的数相乘后，才能整除4
		3. 不能整除2和4的数，和任意数相乘都不能整除4
	如何放？
		将第2类的数全部放一起，将第1类的数和第3类的数交叉放
	举例？
		1 2 3 4 5 6 8 10 16 -> (2 6 10) (4 1) (8 3) (16 5)
*/

const int MAXN = 1e5;
int a[MAXN + 1];

int main() 
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int mod2 = 0, mod4 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 4 == 0) mod4++;
			else if (a[i] % 2 == 0) mod2++;
		}
		if (n - mod2 - mod4 <= mod4) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

/*
4
3
1 10 100
4
1 2 3 4
8
1 2 3 4 5 6 8 10
9
1 2 3 4 5 6 8 10 16
*/
