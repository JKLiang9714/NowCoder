#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
vector<int> vec[N + 1]; //以邻接表的形式存边，下标表示起点，数据表示终点
vector<int> S_v[N + 1];
vector<int> T_v[N + 1];

int main()
{
    int n = 0; // 顶点数
    int m = 0; // 边数
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u = 0; // 起点
        int v = 0; // 终点
        scanf("%d%d", &u, &v);
        vec[u].push_back(v); // 保存关系
    }

    // BFS
    for (int i = 1; i <= n; i++) { // 遍历顶点
        queue<int> q;
        q.push(i);
        while (!q.empty()) { // 迭代方式BFS
            int now = q.front();
            q.pop();
            for (int j = 0; j < vec[now].size(); j++) { // 遍历now的后续顶点
                int post = vec[now][j];
                if (find(S_v[i].begin(), S_v[i].end(), post) == S_v[i].end()) {
                    S_v[i].push_back(post);
                    T_v[post].push_back(i);
                    q.push(post); // 记录后续节点
                }
            }
        }
    }
    // 统计结果
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (T_v[i].size() > S_v[i].size())
            ans++;
    }
    //计算重要节点的数量
    printf("%d\n", ans);
    return 0;
}

/*
4 3
2 1
3 1
1 4
*/
