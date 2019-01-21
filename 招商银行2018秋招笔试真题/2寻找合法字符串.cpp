#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/*
题意：给出n个'('和n和')'，问有多少种括号的组合方式满足匹配
题解：dfs
*/

int n;

void dfs(int pos, int l, int r, string str, vector<string> &res) {
	if (pos == 2 * n) {
		res.push_back(str);
		return;
	}
	if (l < n) {
		dfs(pos + 1, l + 1, r, str + "(", res);
	}
	if (r < n && r < l) {
		dfs(pos + 1, l, r + 1, str + ")", res);
	}
}

int main()
{
	scanf("%d", &n);
	vector<string> res;
	string str = "";
	dfs(0, 0, 0, str, res);
	int len = res.size();
	for (int i = 0; i < len; i++) {
		cout << res[i];
		if (i < len - 1) cout << ",";
	}
	return 0;
}

/*
4
*/
