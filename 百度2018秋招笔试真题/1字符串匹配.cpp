#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_set> 
using namespace std;

/*
题意：A为01串，B为01?串，求B在A中出现的次数，?可表示为0或1 
题解：用unordered_set来模拟
注意：为避免重复计算，这里unordered_set存的是全部子串，而非匹配子串 
*/

string str1, str2, sub;
unordered_set<string> s;

int main() 
{
	cin >> str1 >> str2;
	int len1 = str1.length(), len2 = str2.length();
	int ans = 0;
	for (int i = 0; i < len1; i++) {
		if (i + len2 > len1) break;
		sub = str1.substr(i, len2);
		if (s.count(sub)) continue;
		s.insert(sub);
		int flag = 1;
		for (int j = 0; j < len2; j++) {
			if (sub[j] != str2[j]) {
				if (str2[j] == '?') continue;
				flag = 0;
				break;
			}
		}
		if (flag) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

/*
00010001
??
*/
