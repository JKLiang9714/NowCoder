#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题意：在s串中求字典序最大的子序列 
题解：为减少代码量，可用algorithm库里的max_element方法 
*/

int main() 
{
	string s, t;
	cin >> s;
	while (!s.empty()) {
		auto it = max_element(s.begin(), s.end());
		t += *it;
		s.erase(s.begin(), it + 1);
	}
	cout << t << endl;
	return 0;
}

/*
test
*/
