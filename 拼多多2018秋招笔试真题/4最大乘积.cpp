#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题解：考虑3种情况
1、全是正数 2、全是负数 3、有正有负。前两种情况都只需要取得最大的3个数相乘即可。
第三种情况最好的情况肯定是两个最小的负数相乘得到一个正数，然后跟一个最大的正数相乘，这样得到的数和三个最大数相乘的结果中较大的那个肯定是最大的数。
问题转化成求出数组中最大的三个数：max1，max2，max3，两个最小的数min1，min2，然后比较max1*max2*max3和max1*minl*min2的大小。
*/

int main() 
{
	int n;
   	scanf("%d", &n);
   	long long nums[101];
   	fill_n(nums, n, 0);
   	for (int i = 0; i < n; i++) {
       	scanf("%lld", &nums[i]);
   	}
   	sort(nums, nums + n);
   	long long m = max(nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[0]*nums[1]);
   	printf("%lld\n", m);
	return 0;
}

/*
4
3 4 1 2
*/
