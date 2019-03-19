#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0; // 最大子串长度

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            int len = 0;    // 当前重复字符长度
            int now = i;    // 保存当前下表
            int post = j;   // 保存当前下表
            while (s[now] == s[post]) {
                now++;
                post++;
                len++;
            }
            res = max(len, res); // 最大重复字串长度
        }
    }
    printf("%d\n", res);
    return 0;
}

/*
ababcdabcefsgg
*/
