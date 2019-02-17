#include <iostream>
#include <cstdio>
using namespace std;

int check(string const& str, int nums[4]) {
    int cur_n = nums[2];
    int cur_m = nums[3];
    int step = 0;
    for (int i = 0; i <= str.size(); i++) {
        step++;
        switch (str[i]) {
        case 'u':
            cur_n--;
            if (cur_n < 1) return step;
            break;
        case 'd':
            cur_n++;
            if (cur_n > nums[0]) return step;
            break;
        case 'r':
            cur_m++;
            if (cur_m > nums[1]) return step;
            break;
        case 'l':
            cur_m--;
            if (cur_m < 1) return step;
            break;
        }
    }
    return step;
}

int main() {
    string str;
    cin >> str;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int nums[4];
        for (int j = 0; j != 4; j++) {
            scanf("%d", &nums[j]);
        }
        int res = check(str, nums);
        printf("%d\n", res);
    }
    return 0;
}