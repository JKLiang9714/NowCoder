#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

/*
题解：判断一个数是否能拆成和相等的两个数
	将数字转换为字符串处理，排序后枚举拆分位置即可 
*/

const int MAXN = 1000000;
char str[MAXN + 1];

int cmp(int a, int b) {
	return a > b;
}

int fun(string &s) {
	int len = s.length();
	for (int i = 1; i < len; i++) {
		string x = s.substr(0, i);
		string y = s.substr(i, len - i);
		if (atoi(x.c_str()) == atoi(y.c_str())) {
			return 1;
		}
	}
	return 0;
}

int main() 
{
	int l, r, num;
	scanf("%d%d", &l, &r);
	int ans = 0;
	for (int i = l; i <= r; i++) {
		sprintf(str, "%d", i);
		sort(str, str + strlen(str), cmp);     // 从大到小排是为了保留前导0 
		sscanf(str, "%d", &num);
		string s = to_string(num);
		ans += fun(s);
	} 
	printf("%d\n", ans);
	return 0;
}

/*
1 50
*/
