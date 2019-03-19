#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/*
题解：用 string, istringstream 来处理输入。再来处理二维数组
*/

bool isYoungTableau(vector<vector<int>> matrix) {
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][j] < matrix[i][j-1]) return false;
            if (matrix[i][j] < matrix[i-1][j]) return false;
        }
        if (matrix[i].size() > matrix[i-1].size()) return false;
    }
    return true;
}

int main() 
{
	int n;
    scanf("%d\n", &n);
    while (n--) {
        string str;
        vector<vector<int>> matrix;
        while (getline(cin, str, '\n')) {
            if (str.empty()) break;
            istringstream iss(str);
            vector<int> temp;
            int x;
            while (iss >> x) {
                temp.push_back(x);
            }
            matrix.push_back(temp);
        }
        if (isYoungTableau(matrix)) printf("true\n");
        else printf("false\n");
    }
	return 0;
}

/*
2
1 3 4 5 6
2 7 10
8 9

2 5 8 9
7 11 10
*/
