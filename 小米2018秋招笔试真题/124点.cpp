#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

/*
题解：递归，选与不选，时间复杂度为 2^n，n最多到30
*/

int a[30];
int n;
set<vector<int>> res;

// 深度遍历
void DFS(int sum, int pos, vector<int> path) {
	if (pos == n + 1) return;
    if (sum > 24) return;
	if (sum == 24) {
		res.insert(path);
		return;
	}
	DFS(sum, pos + 1, path);   // 不选择pos
	path.push_back(a[pos]);       // 选择pos
	DFS(sum + a[pos], pos + 1, path);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
	vector<int> path;
	DFS(0, 0, path); // 初始化为0，从0开始
	printf("%d\n", (int)res.size());
	return 0;
}

/*
4
1 2 22 23
*/
