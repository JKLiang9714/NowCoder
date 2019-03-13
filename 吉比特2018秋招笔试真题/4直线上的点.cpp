#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
题解：两个点决定一条直线，所以两层遍历，可以遍历所有直线，并在遍历的过程中，把直线缓存起来，
下次再遇到的相同直线时候就只是把这条直线对应的存在的点的个数累加。
这样我们就可以算出经过某个点的某条直线上最多的点的个数。
要注意的是第二层遍历的时候，可以只遍历从i + 1 ~ size – 1的直线，
因为与之前的点能够组成的直线已经处理过，不需要再处理(a,b决定的直线和 b,a决定的直线是一样的)。
注意：两点相同也算共线。
*/

class Point3D {
public:
	int x, y, z;
	Point3D() { x = y = z = 0; }
	Point3D(int a, int b, int c) { x = a; y = b; z = c; }
	bool equal(const Point3D& pt) const {
		return x == pt.x && y == pt.y && z == pt.z;
	}
};

class Line3D {
public:
	// dx / dz
	float kx;
	// dy / dz
	float ky;
	// dz == 0 ?
	bool bz;
	bool operator==(const Line3D &l) const {
		return kx == l.kx && ky == l.ky && bz == l.bz;
	}
	bool operator<(const Line3D &l) const {
		return kx < l.kx || (kx == l.kx && ky < l.ky);
	}
};

int maxPoints(vector<Point3D> points) {
	int maxNum = 0;
	for (size_t i = 0; i < points.size(); ++i) {// 遍历所有点
		int sameNum = 0;
		int ptMaxCount = 0;
		map<Line3D, int> lineMap;
		for (size_t j = i + 1; j < points.size(); ++j) {// 遍历除了i之外的其他点
			auto &p1 = points[i];
			auto &p2 = points[j];

			if (p1.equal(p2)) { // 两个点刚好相同
				sameNum++;
				continue;
			}

			// 斜率相等三点共线
			Line3D line;
			int dz = p2.z - p1.z;
			if (dz == 0) {
				line.bz = true;
				line.kx = line.ky = 0;
			}
			else {
				line.bz = false;
				line.kx = (float)(p2.x - p1.x) / dz;
				line.ky = (float)(p2.y - p1.y) / dz;
			}

			// 计数
			int count;
			if (lineMap.find(line) == lineMap.end())
				count = lineMap[line] = 1;
			else
				count = ++lineMap[line];

			ptMaxCount = max(ptMaxCount, count);
		}
		// 
		maxNum = max(ptMaxCount + sameNum + 1, maxNum);
	}
	return maxNum;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	vector<Point3D> points;
	while (n--) {
		Point3D p;
		scanf("%d%d%d", &p.x, &p.y, &p.z);
		points.push_back(p);
	}
	printf("%d\n", maxPoints(points));
	return 0;
}

/*
4 
0 0 0 
1 1 1
-1 -1 -1 
0 1 0
*/
