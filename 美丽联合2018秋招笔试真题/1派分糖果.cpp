#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*注意：不能排序*/

int solve(int* nums, int n) {
	int *counts = new int[n+1]; // 存放每个小孩分配糖果数
	fill_n(counts, n, 0); // 结果清零
	counts[0] = 1;

	for (int i = 1; i < n; ++i) {// 遍历所有分值
		if (nums[i] == nums[i - 1]) { // 分值相等糖果相等
			counts[i] = counts[i - 1];
		}
		else if (nums[i] > nums[i - 1]) { // 当前学生比前一个学生分值高，多分1个糖果
			counts[i] = counts[i - 1] + 1;
		}
		else { // 当前学生比前一个学生分值低
			if (counts[i - 1] > 1) { // 前一个学生糖果数多于1
				counts[i] = counts[i - 1] - 1; // 当前学生比前一个学生糖果数少1
			}
			else { // 如果前一个学生糖果数为1
				counts[i] = 1;// 当前学生糖果数为1
				for (int j = i; j >= 1; --j) {// 把前面连续高分数的学生糖果都加1
					if (nums[j - 1] < nums[j]) break; // 直到遇到分数低的学生为止
					if (nums[j - 1] >= nums[j]) counts[j - 1]++;
				}
			}
		}
	}
	// 统计所有的糖果
	return accumulate(counts, counts + n, 0);
}

int main() {
	vector<int> nums;
	int num = 0;
	while (cin >> num) {
		nums.push_back(num);
		char c = cin.peek(); // 获取下个字符
		if ('\n' == c) break; // 回车表示输入结束
		cin.ignore(1, ','); // 除去逗号分割符
	}
	printf("%d\n", solve(nums.data(), nums.size()));
	return 0;
}

/*
0,1,0
*/
