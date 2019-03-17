#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题意：给定一个数组，添加元素使其回文，要求添加后的回文数组元素和最小
题解：双指针，递归
*/

int n = 0;

int solve(int i, int j, int *nums) {
	if (i > j) return 0;
	if (i == j) return nums[i];
	if (nums[i] == nums[j]) {
		return 2 * nums[i] + solve(i + 1, j - 1, nums); // 首尾两个数相同
	} else {
		return min(2 * nums[i] + solve(i + 1, j, nums),
			2 * nums[j] + solve(i, j - 1, nums));
	}
}

int main() 
{
	int nums[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	printf("%d\n", solve(0, n - 1, nums));
    return 0;
}

/*
8
51 23 52 97 97 76 23 51
*/
