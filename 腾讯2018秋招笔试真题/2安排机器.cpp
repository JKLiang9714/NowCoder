#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
题解：排序，贪心（用满足任务耗时的最低等级机器来作业） 
*/

const int MAXN = 10000;
const int MAX_LEVEL = 100;
struct Node {
	int time;
	int level;
	bool operator < (Node &node) {
		if (time == node.time) return level > node.level;
		return time > node.time;
	}
};
Node machine[MAXN + 1], task[MAXN + 1];
int cnt[MAX_LEVEL + 1] = { 0 };

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &machine[i].time, &machine[i].level);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &task[i].time, &task[i].level);
	}
	sort(machine, machine + n);
	sort(task, task + n);
	int num = 0;
	long long res = 0;
	for (int i = 0, j = 0; i < m; i++) {
		while (j < n && machine[j].time >= task[i].time && machine[j].level >= task[i].level) {
			cnt[task[i].level]++;
			j++;
		}
		for (int k = task[i].level; k <= MAX_LEVEL; k++) {
			if (cnt[k]) {
				num++;
				cnt[k]--;
				res += (200 * task[i].time + 3 * task[i].level);
				break;
			}
		}
	}
	printf("%d %lld\n", num, res);
	return 0;
}

/*
6 1
886 79
987 60
69 22
397 74
552 12
932 40
394 96
*/
