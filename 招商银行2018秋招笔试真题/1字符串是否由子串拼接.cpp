#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
题意：判断一个字符串是否能由它的一个子串进行多次首尾拼接构成
题解：子串的长度必须是原串长度的因子，枚举即可
*/

int main()
{
	int i, j;
	string str;
	cin >> str;
	int len = str.length();
	for (i = 1; i <= len / 2; i++) {
		if (len % i != 0) continue;
		int substr_number = len / i;
		string sub_str = str.substr(0, i);
		for (j = 0; j < substr_number; j++) {
			string temp = str.substr(j * i, i);
			if (temp != sub_str) {
				break;
			}
		}
		if (j == substr_number) {
			cout << sub_str << endl;
			break;
		}
	}
	if (i > len / 2) cout << "false" << endl;
	return 0;
}

/*
abcbbcbbc
*/