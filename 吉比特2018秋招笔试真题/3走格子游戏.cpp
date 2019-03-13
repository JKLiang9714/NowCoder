#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/*
题解：
动态规划问题，状态s(x,y)为在位置为(x,y)时到达目标点所需的最小行动力，任何情况下，当前行动力不可小于1，分析可得状态转移方程为：
if x==col-1&&y==row-1
  s(x,y)=max(1-grid[x][y],1)
if x==col-1
  s(x,y)=max(s(x,y+1)-grid[x][y],1)
if y==row-1
  s(x,y)=max(s(x+1,y)-grid[x][y],1)
else
  s(x,y)=max(max(s(x,y+1)-grid[x][y],s(x+1,y)-grid[x][y]),1)

为什么要减去grid[x][y]?
	因为[x][y]可正可负，正表示当前格子增加行动力，负表示减少行动力。求解最小行动力，遇到正值，需要初始行动力小；遇到负值，表示需要初始行动力大。
为什么与1比较?
	小于1游戏失败，所以至少为1。
*/
int dp[1000][1000];

int solve(int x, int y, vector<vector<int> > & grid) {
	int row = (int)grid.size();
	int col = (int)grid[0].size();
	if (0 != dp[x][y]) return dp[x][y];
	int val = grid[y][x];
	if (x == col - 1 && y == row - 1) // 如果是最后一个位置(右下角)
		return dp[x][y] = max(1 - val, 1);
	else if (x == col - 1) // 到了最后一列，只能向下
		return dp[x][y] = max(solve(x, y + 1, grid) - val, 1);
	else if (y == row - 1) // 到了最后一行，只能向右
		return dp[x][y] = max(solve(x + 1, y, grid) - val, 1);
	else {
		int res1 = max(solve(x, y + 1, grid) - val, 1);// 选择向下
		int res2 = max(solve(x + 1, y, grid) - val, 1);// 选择向右
		return dp[x][y] = min(res1, res2);
	}
}

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	vector<vector<int> > grid;
	for (int i = 0; i < M; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			int K;
			scanf("%d", &K);
			row.push_back(K);
		}
		grid.push_back(row);
	}
	printf("%d\n", solve(0, 0, grid));
	return 0;
}

/*

*/
