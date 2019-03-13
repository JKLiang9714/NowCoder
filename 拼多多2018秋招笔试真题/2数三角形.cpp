#include <iostream>
#include <cstdio>
using namespace std;

struct Point {
	int x, y;
};

Point a[100]; 
int n;

int main() 
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if ((a[j].x - a[i].x) * (a[k].y - a[i].y) - (a[k].x - a[i].x) * (a[j].y - a[i].y) != 0) {
					ans++;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}

/*
4
0 0
0 1
1 0
1 1
*/
