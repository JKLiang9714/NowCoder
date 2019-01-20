#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
题意：在s串中连续的子串有多少个 
题解：枚举 
*/

int main() 
{
	string s;
	cin >> s;
	int len = s.size();
	int cnt = 1;
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) cnt++;
	}
	double ans = len * 1.0 / cnt;
	printf("%.2lf\n", ans);
	return 0;
}

/*
aaabbaaac
*/
