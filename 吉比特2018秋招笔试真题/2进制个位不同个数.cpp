#include <iostream>
#include <cstdio>
using namespace std;

/*
题意：输入两个整数，求两个整数二进制格式有多少个个位不同
题解： 两个数进行异或，将异或的结果与其减一进行与操作（1的位数加1），直至为零，就是二进制不同位数的数量
*/

int main() 
{
	int m, n;
	scanf("%d%d", &m, &n);
	int num = m ^ n;
	int count = 0;
	while (num) {
		num = num & (num - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}

/*
22 33
*/
