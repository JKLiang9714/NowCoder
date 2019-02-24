#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100000;

struct Node {
    int prev; // 前一个数据
    int post; // 后一个数据
};
Node nodes[N + 1];

void Print(Node* nodes, int n, int head)
{
    int now = head;
    while (now != n + 1) {
        printf("%d\n", now);
        now = nodes[now].post; // 向后遍历
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    // prev为0表示开始
    // post为n+1表示结束
    for (int i = 1; i <= n; ++i) {
        nodes[i].prev = i - 1;
        nodes[i].post = i + 1;
    }
    // 遍历链表
    int head = 1;
    int m = 0;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int move = 0;
        scanf("%d", &move);
        if (move == head)
            continue; // 如果要移动的数据已经在头节点，不处理
        int prev = nodes[move].prev;
        int post = nodes[move].post;
        nodes[prev].post = post;
        nodes[post].prev = prev;
        nodes[move].prev = 0;
        nodes[move].post = head;
        nodes[head].prev = move;
        head = move; //  更换头节点下标
    }
    Print(nodes, n, head);
    return 0;
}

/*
5 3 
4 
2
5 
*/
