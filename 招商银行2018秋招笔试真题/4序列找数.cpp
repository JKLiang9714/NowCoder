#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
题意：从非负整数序列0，1，2，.，n中给出包含其中n个数的子序列，请找出未出现在该子序列中的那个数
题解：哈希表
*/

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<bool> vec(n + 1, false);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vec[t] = true;
	}
    for (int i = 0; i < n; i++) {
        if (!vec[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

/*
3 3 0 1
*/
