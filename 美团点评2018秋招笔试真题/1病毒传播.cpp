#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int N = 1000;
vector<int> vec[N + 1]; // 邻接表，下标表示顶点

int main()
{
    int n = 0; // 顶点数
    int m = 0; // 边数
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int k = 0;
    int t = 0;
    scanf("%d%d", &k, &t);
    set<int> S;
    for (int i = 0; i < k; ++i) {
        int s;
        scanf("%d", &s);
        S.insert(s);
    }
    bool has = false;
    for (int v : S) {
        set<int> infect;
        queue<int> q; // 定义队列
        int visited[N + 1]; // 定义标记顶点是否已访问
        fill_n(visited, n + 1, -1); // 初始化为未访问
        infect.insert(v);
        visited[v] = 0; // 标记v已经访问
        q.push(v); // 入队v
        while (!q.empty()) { // 队列非空
            int now = q.front(); // 取出队首元素
            q.pop(); // 队首元素出队
            for (int i = 0; i < vec[now].size(); i++) { // 遍历v的邻接点
                int post = vec[now][i]; // 取出邻接点
                if (visited[post] == -1 && visited[now] < t) { // 判断邻接点是否访问
                    visited[post] = visited[now] + 1; // 标记邻接点已访问
                    infect.insert(post);
                    q.push(post); // 邻接点入队
                }
            }
        }
        if (S == infect) {
            printf("%d ", v);
            has = true;
        }
    }
    if (!has)
        printf("-1\n");
    return 0;
}

/*
4 3
3 2
1 2
1 4
3 2
4 2 1
*/
