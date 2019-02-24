#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
题解：
把公交车看成一个图上的节点，因为站点的编号从1到n，公交车的编号从1到m，存在重复。所以，把公交车的编号改为从n+1到n+m
问题变成从站点1到n最短距离。注意每个站点中间增加了公交车节点，最后求解的距离要除以2
*/

const int N = 200002;
vector<int> vec[N]; // 从1开始
queue<int> q; // 定义队列
int visited[N]; // 定义标记顶点是否已访问

int main()
{
    int n = 0; // 站点数
    int m = 0; // 公交车数
    scanf("%d%d", &n, &m);
    // 建图同一辆公交车通过的点建一条边到这辆公交车的抽象点，再从抽象点建一条边到这些点
    for (int i = 1; i <= m; i++) {
        int t = 0;
        scanf("%d", &t); // 公交车数经过站点数
        for (int j = 1; j <= t; j++) {
            int a = 0;
            scanf("%d", &a); // 公交车数经过站点
            vec[a].push_back(i + n); // 同一站点经过的公交车
            vec[i + n].push_back(a); // 同一辆公交车通过的站点
        }
    }
    fill_n(visited, N, -1); // 初始化为未访问
    visited[1] = 0; // 标记v已经访问
    q.push(1); // 入队v
    while (!q.empty()) { // 队列非空
        int now = q.front(); // 取出队首元素
        q.pop(); // 队首元素出队
        for (int i = 0; i < vec[now].size(); i++) { // 遍历v的邻接点
            int post = vec[now][i]; // 取出邻接点
            if (visited[post] == -1) { // 判断邻接点是否访问
                visited[post] = visited[now] + 1; // 标记邻接点已访问
                q.push(post); // 邻接点入队
            }
        }
    }
    if (visited[n] == -1)
        printf("-1\n");
    else
        printf("%d\n", visited[n] / 2);
}

/*
5 3
3 1 2 3
3 3 4 2
3 3 5 4
*/
