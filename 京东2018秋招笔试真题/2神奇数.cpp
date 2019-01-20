#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*
题意：判断一个数是否能拆成两个数，它们的和相等
题解：将数字打散存入arry数组，之后用01背包，判断能装下最大的数和一半是否相等
*/

bool isNum(int x) {
    vector<int> vec;
    int num = x, half = 0;
    while (num) {
        vec.push_back(num % 10);
        half += num % 10;
        num /= 10;
    }
    // 和为奇数的不满足情况
    if (half % 2 != 0) return false;
    half /= 2;
    vector<int> dp(half + 1);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = half; j >= vec[i]; j--) {
            dp[j] = max(dp[j], dp[j - vec[i]] + vec[i]);
        }
    }
    return dp[half] == half;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (isNum(i)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

/*
6354 234363
*/