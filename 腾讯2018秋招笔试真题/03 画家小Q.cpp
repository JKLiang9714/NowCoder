#include <iostream>
#include <cstdio>
using namespace std;

/*
题解：DFS 
处理画板时，对于颜色是Y,B,G的单元格，
根据不同的颜色，按不同的方向递归将其线上的颜色进行变换
*/

const int MAXN = 50;
char str[MAXN + 1][MAXN + 1];
int n, m;

void dfs_Y(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && (str[x][y] == 'Y' || str[x][y] == 'G')) {
		if (str[x][y] == 'Y') str[x][y] = 'X';
		else str[x][y] = 'B';
		dfs_Y(x - 1, y - 1);
		dfs_Y(x + 1, y + 1);
	}
}

void dfs_B(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m && (str[x][y] == 'B' || str[x][y] == 'G')) {
		if (str[x][y] == 'B') str[x][y] = 'X';
		else str[x][y] = 'Y';
		dfs_B(x + 1, y - 1);
		dfs_B(x - 1, y + 1);
	}
}

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (str[i][j] == 'Y') {
				dfs_Y(i, j);
				cnt++;
			}
			else if (str[i][j] == 'B') {
				dfs_B(i, j);
				cnt++;
			}
			else if (str[i][j] == 'G') {
				dfs_Y(i, j);
				dfs_B(i, j);
				cnt += 2;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}

/*
4 4
YXXB
XYGX
XBYY
BXXY
*/
