#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int n = 6;

int solve(int *nums) {
    int count = 0;
    // 4*4 5*5必须占一个箱子
    for (int i = 3; i < n; i++) {
        count += nums[i];
    }
    // 3*3的箱子可以四个放一起
    count += (nums[2] + 3) / 4;

    // 计算剩余空间
    // 5*5剩余空间，可以容纳1*1的空间个数
    int emptyFor1 = nums[4] * 11;
    // 4*4剩余空间，可以容纳2*2的空间个数
    int emptyFor2 = nums[3] * 5;
    // 3*3剩余空间
    switch (nums[2] % 4) {
    case 1:
        emptyFor2 += 5;
        emptyFor1 += 7;
        break;
    case 2:
        emptyFor2 += 3;
        emptyFor1 += 6;
        break;
    case 3:
        emptyFor2 += 1;
        emptyFor1 += 5;
        break;
    }

    // 计算填充空间
    // 用2*2填充空间
    if (nums[1] < emptyFor2) {
        // 剩余空间用1*1填充
        emptyFor1 += (emptyFor2 - nums[1]) * 4;
    } else {
        int leaveFor2 = nums[1] - emptyFor2;
        count += (leaveFor2 + 8) / 9;
        emptyFor1 += (9 - leaveFor2 % 9) * 4;
    }
    // 用1*1填充空间
    if (nums[0] > emptyFor1) {
        count += (nums[0] - emptyFor1 + 35) / 36;
    }
    return count;
}

int main() 
{
	vector<int> res;
	while (true) {
		int nums[n];
		int finish = true;
		for (int i = 0; i != n; i++) {
			scanf("%d", &nums[i]);
			if (nums[i] != 0) {
                finish = false;
            }
		}
		if (finish) break;
		res.push_back(solve(nums));
	}
	for (int i = 0; i != res.size(); i++) {
        printf("%d\n", res[i]);
    }
}

/*
0 0 4 0 0 1
7 5 1 0 0 0
0 0 0 0 0 0
*/
