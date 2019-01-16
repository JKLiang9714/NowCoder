#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

/*
题意：通过一次调换，将括号匹配 
题解：用一个栈来模拟 
*/

const int MAXN = 1e5;
char str[MAXN + 1];
stack<char> stk;

int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int len = strlen(str);
		if (len == 2) {
			if (str[0] == '(' || str[1] == ')') {
				printf("No\n");
				continue;
			}
		}
		int i, flag = 1;	// flag 为 1 时表示还有一次调换的机会 
		for (i = 0; i < len; i++) {
			if (str[i] == '(') {
				stk.push('(');
			} else {
				if (!stk.empty()) stk.pop();
				else {
					if (!flag) break;
					flag = 0;
					stk.push('(');
				}
			}
		}
		if (i == len) {
			if (!flag && stk.size() == 2 || flag && stk.size() == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else {
			printf("No\n");
		}
	}
	return 0;
}

/*
2
())(
)))(((
*/
