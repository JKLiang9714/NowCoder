#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
Ìâ½â£ºÌ°ÐÄ
*/

const int N = 11;
const int M = 101;

struct Bear {
	int fight;
	int hunger;
	friend bool operator < (Bear a, Bear b) {
		return a.fight > b.fight;
	}
};

int sweet[M], eated[M];
Bear bear[N];
int ans[N];

int main() 
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &sweet[i]);
		eated[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &bear[i].fight, &bear[i].hunger);
	}
	sort(bear, bear + n);
	for (int i = 0; i < n; i++) {
		int index = -1;
		for (int j = 0; j < m; j++) {
			if (!eated[j] && sweet[j] <= bear[i].hunger && (index == -1 || sweet[j] > sweet[index])) {
				index = j;
			}
		}
		if (index != -1) {
			bear[i].hunger -= sweet[index];
			eated[index] = 1;
			i--;
		} else {
			ans[i] = bear[i].hunger;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}

/*
2 5
5 6 10 20 30
4 34
3 35
*/
