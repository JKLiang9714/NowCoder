#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题意：用t串中的字符替换s串中的字符，使s串字典序最大 
题解：排序，一层遍历 
*/

int cmp(char a, char b) {
	return a > b;
}

int main() 
{
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end(), cmp);
	int pos = 0; 
	for (int i = 0; i < s.size(); i++) { 
		if(s[i] < t[pos]) { 
			s[i] = t[pos]; 
			pos++; 
		} 
	}
	cout << s << endl;
	return 0;
}

/*
fedcba
ee 
*/
