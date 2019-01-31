#include <cstdio>
#include <iostream>
#include <set>
#include <numeric>
using namespace std;

int find_min(set<double>& s, double a, double b)
{
    if (s.size() == 1) return -1;
    int min_num = INT_MAX;
    for (auto num : s) {
        if (num < min_num && num < a && num > b) {
			min_num = num;
		}
    }
    if (min_num == INT_MAX) return -1;
    return min_num;
}

int main()
{
    int n, m, num;
    scanf("%d%d", &n, &m);
    set<double> set_n, set_m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        set_n.insert(num);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        set_m.insert(num);
    }
    double sum_n = accumulate(set_n.begin(), set_n.end(), 0.0);
    double ave_n = sum_n / set_n.size();
    double sum_m = accumulate(set_m.begin(), set_m.end(), 0.0);
    double ave_m = sum_m / set_m.size();

    if (ave_n < ave_m) {		// 交换，使集合n为出，m为入
        swap(ave_n, ave_m);
        swap(sum_n, sum_m);
        swap(set_n, set_m);
    }
    // 查找用于交换的最小值
    int min_num = find_min(set_n, ave_n, ave_m);
    int step = 0;
    while (min_num != -1) {
        set_n.erase(min_num);	// 从n中取值
        sum_n -= min_num;
        ave_n = sum_n / set_n.size();

        set_m.insert(min_num);	// 加到m中
        sum_m += min_num;
        ave_m = sum_m / set_m.size();

        step++;
        min_num = find_min(set_n, ave_n, ave_m);
    }
    printf("%d\n", step);
    return 0;
}

/*
3 5
1 2 5
2 3 4 5 6
*/
