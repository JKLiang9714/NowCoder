#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

void Permutation(set<string>& res, string& s, size_t start) {
    if (start == s.length()) {
        res.insert(s);
        return;
    }
    // 从位置k往后，重新排列
    for (size_t i = start; i < s.length(); i++) {
        swap(s[start], s[i]); // 交换位置
        Permutation(res, s, start + 1);
        swap(s[start], s[i]); // 还原交换位置
    }
}

vector<string> Permutation(string str) {
    if (str.empty()) return vector<string>();
    set<string> res;
    Permutation(res, str, 0);
    return vector<string>(res.begin(), res.end()); // 把set转成vector
}

int main()
{
    string str;
    cin >> str;
    vector<string> res = Permutation(str);
    for (auto s : res) {
        cout << s << " ";
    }
    return 0;
}

/*
acc
*/
