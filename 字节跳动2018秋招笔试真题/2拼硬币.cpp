#include <cstdio>
#include <iostream>
using namespace std;

/*
题解：
典型的背包问题，普通币是完全背包问题，纪念币是0/1背包问题
种背包问题做法类似，都是先枚举物品，再枚举容量
不同点在于完全背包问题要从小到大枚举容量，0/1背包问题要从大到小枚举容量
*/

const int N = 110, M = 100010, MOD = 1000000007;
int a[N], b[N];
int f[M];  // f[i]为当前背包重量为i时的可能种类数

int main()
{
    int n1, n2, m;
    scanf("%d%d%d", &n1, &n2, &m);
    for (int i = 0; i < n1; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n2; i++) scanf("%d", &b[i]);
    f[0] = 1;
    for (int i = 0; i < n1; i++) {
        for (int j = a[i]; j <= m; j++) {
            f[j] = (f[j] + f[j - a[i]]) % MOD;
        }
    }
    for (int i = 0; i < n2; i++) {
        for (int j = m; j >= b[i]; j--) {
            f[j] = (f[j] + f[j - b[i]]) % MOD;
        }
    }
    printf("%d\n", f[m]);
    return 0;
}

/*
3 1 5
1 2 3
1
*/