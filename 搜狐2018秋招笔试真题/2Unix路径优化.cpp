#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/*
Unix路径有如下规则：
    路径由文件名和文件描述符/构成。
    多个连续的/当作为单个/。
    .表示本级目录。
    ..表示返回上级目录。
    最开始的/表示根目录，向上返回到根目录，不能再向上返回 
*/

int main() 
{
	string path;
    vector<string> dir;
    cin >> path;
    int len = path.size();
    for (int i = 0; i < len; i++) {
        if (path[i] == '/') continue;
        if (path[i] == '.') {
            if (i + 1 < len && path[i + 1] == '/') {
                i++;
                continue;
            } else if (i + 1 < len && path[i + 1] == '.') {
                i += 2;
                if (!dir.empty()) dir.pop_back();
                continue;
            }
        }
        string name;
        name.append(1, path[i]);
        while (path[++i] != '/') {
            name.append(1, path[i]);
        }
        dir.push_back(name);
    }
    if (dir.empty()) printf("/\n");
    else {
        int dirSize = dir.size();
        for (int i = 0; i < dirSize; i++) {
            cout << '/' << dir[i];
        }
    }
	return 0;
}

/*
/a/./b/../../c/
*/
