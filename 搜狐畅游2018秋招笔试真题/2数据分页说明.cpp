#include <iostream>
#include <cstdio>
using namespace std;

/*
注意：根据题意，页号从0开始
*/

int main() 
{
	int n = 0;
	scanf("%d", &n);
	int *nums = new int[n + 1];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int page = 0; // 页码
	int size = 0; // 每页显示数据个数
	scanf("%d%d", &page, &size);
	if (page*size >= n) {
		printf("超过分页范围\n");
	}
	for (int i = page * size; i < (page + 1)*size; ++i) {
		printf("%d\n", nums[i]);
	}
	return 0;
}

/*
6
1 2 3 4 5 6
1
2
*/
