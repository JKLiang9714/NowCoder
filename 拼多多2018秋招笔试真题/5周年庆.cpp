#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct ChildInfo {
	int child;    // 子城市下标
	int distance; // 到子城市的距离
};

void dfs(vector<vector<ChildInfo> > &lnk, int u, vector<int> &seq) {
	for (int k = 0; k != lnk[u].size(); ++k) {
		dfs(lnk, lnk[u][k].child, seq);
	}
	seq.push_back(u);
}
int main() {
	int m = 0; // 花灯道路总长度上限
	int n = 0; // 城市个数
	while (scanf("%d%d", &m, &n) == 2) {
		vector<vector<ChildInfo> > lnk(n); // 下标是父城市，元素是子程序与距离数组
		vector<int> in(n, 0);// 子城市统计
		for (int i = 1; i < n; ++i) {
			int u = 0; // 父城市
			int v = 0; // 子城市
			int d = 0; // 距离
			scanf("%d%d%d", &u, &v, &d);
			in[v]++;
			// 构建树
			lnk[u].push_back(ChildInfo{ v, d });
		}

		// 查找根节点
		int root; // 根节点
		for (int i = 0; i < n; ++i) {
			if (in[i] == 0) {
				root = i;
				break;
			}
		}

		// 后序遍历，排列城市顺序
		vector<int> seq;
		dfs(lnk, root, seq);

		// 统计
		vector<int> mem[n];
		for (int i = 0; i != n; ++i) {
			int u = seq[i];
			// 第一种情况，不选择
			mem[u].push_back(0);
			// 第二种情况，选择一个子城市
			for (int k = 0; k != lnk[u].size(); ++k) {
				int v = lnk[u][k].child;
				int dist = lnk[u][k].distance;
				vector<int> memv = mem[v];
				for (auto &value : memv) {
					int d = value + dist;
					if (mem[u].end() == find(mem[u].begin(), mem[u].end(), d)) {
						mem[u].push_back(d);
					}
				}
			}
			// 第三种情况，选择两个子城市
			for (int k1 = 0; k1 != lnk[u].size(); ++k1)
				for (int k2 = k1 + 1; k2 != lnk[u].size(); ++k2) {
					int v1 = lnk[u][k1].child;
					int dist1 = lnk[u][k1].distance;
					vector<int> memv1 = mem[v1];
					int v2 = lnk[u][k2].child;
					int dist2 = lnk[u][k2].distance;
					vector<int> memv2 = mem[v2];
					for (auto &value1 : memv1)
						for (auto &value2 : memv2) {
							int d = value1 + dist1 + value2 + dist2;
							if (mem[u].end() == find(mem[u].begin(), mem[u].end(), d)) {
								mem[u].push_back(d);
							}
						}
				}
		}
		// 找到满足条件的最大值
		int result = 0;
		for (auto &value : mem[root])
			if (value <= m) { // 必须小于花灯道路总长度上限
				result = max(result, value);
			}
		printf("%d\n", result);
	}
	return 0;
}

/*
5
5
0 1 1
0 2 2
0 3 3
0 4 4
*/
