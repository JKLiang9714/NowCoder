#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
题解：
穷举法，需要遍历每个矩形，遍历过程中与前面矩形是否有重叠(顶点是否重合)，
并调整最小公共父矩形的数值，最后判断所有矩形面积是否与父矩形一样
*/

bool isRectangleCover(vector<vector<int>>& rectangles) {
	unordered_set<string> st; // 顶点集合 
	int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;
	int area = 0; // 所有矩形面积之和
	for (auto rect : rectangles) { // 遍历所有矩形 
		// 所能组成最大矩形
		min_x = min(min_x, rect[0]);
		min_y = min(min_y, rect[1]);
		max_x = max(max_x, rect[2]);
		max_y = max(max_y, rect[3]);

		area += (rect[2] - rect[0]) * (rect[3] - rect[1]); // 面积求和
		// 四个顶点
		string s1 = to_string(rect[0]) + "_" + to_string(rect[1]); // bottom-left 
		string s2 = to_string(rect[0]) + "_" + to_string(rect[3]); // top-left 
		string s3 = to_string(rect[2]) + "_" + to_string(rect[3]); // top-right
		string s4 = to_string(rect[2]) + "_" + to_string(rect[1]); // bottom-right
		// 每个顶点三种情况
		if (st.count(s1)) st.erase(s1); else st.insert(s1);
		if (st.count(s2)) st.erase(s2); else st.insert(s2);
		if (st.count(s3)) st.erase(s3); else st.insert(s3);
		if (st.count(s4)) st.erase(s4); else st.insert(s4);
	}
	// 最大矩形的四个顶点
	string t1 = to_string(min_x) + "_" + to_string(min_y);
	string t2 = to_string(min_x) + "_" + to_string(max_y);
	string t3 = to_string(max_x) + "_" + to_string(max_y);
	string t4 = to_string(max_x) + "_" + to_string(min_y);
	if (!st.count(t1) || !st.count(t2) || !st.count(t3) || !st.count(t4) || st.size() != 4)
		return false;
	// 面积
	return area == (max_x - min_x) * (max_y - min_y);
}

int main() 
{
	int n = 0;
	scanf("%d", &n);
	vector<vector<int>> rect;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < 4; j++) {
			int x;
			scanf("%d", &x);
			v.push_back(x);
		}
		rect.push_back(v);
	}
    int res = isRectangleCover(rect);
	if (res) printf("true\n");
	else printf("false\n");
	return 0;
}

/*
5
1 1 3 3
3 1 4 2
3 2 4 4
1 3 2 4
2 3 3 4
*/
