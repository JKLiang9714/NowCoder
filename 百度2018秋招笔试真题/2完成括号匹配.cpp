#include <iostream>
#include <cstdio>
using namespace std;

/*
题意：给定括号字符串，在首尾添加括号，使其匹配合法 
题解：string模拟 
*/

string str, prefix;

int main() 
{
	cin >> str;
	int len = str.length();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '[') cnt++;
		else cnt--;
		if (cnt < 0) {
			cnt++;
			prefix += "[";
		}
	}
	cout << prefix + str + string(cnt, ']') << endl;
	return 0;
}

/*
][
[]]]]
[[[[]
*/
