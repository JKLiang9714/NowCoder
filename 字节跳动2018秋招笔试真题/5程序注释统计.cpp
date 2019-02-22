#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  string code;// 代码
  // 获取输入，直至Ctrl+Z
  char c = getchar(); // 获取输入字符
  while (c != EOF){
    code += c;
    c = getchar();
  }
  
  // 解析代码
  int res = 0;// 注释统计个数
  bool c1 = false;// 第一种注释方式(单行注释)
  bool c2 = false; // 第二种注释方式(多行注释)
  bool qs = false;// 双引号处理

  // 遍历代码中的每一字符
  for (int i = 0; i < code.size(); i++) {
    if (code[i] == '\n') { // 遇到换行
      c1 = false;// 单行注释结束
    } else if (c1) {
    } else if (c2) {
      // 统计
      if (i + 1 < code.size() 
          && code[i] == '*'
          && code[i + 1] == '/') { // 多行注释结尾判断
        c2 = false;
        i++;
      }
    } else if (qs) {
      if (code[i] == '"'){ // 双引号结束判断
        int t = false;
        for (int j = i - 1; j >= 0; j--)
          if (code[j] == '\\') {
            t++;
          } else {
            break;
          }
          if (t % 2 == 0) qs = 0;
        }
    } else if (code[i] == '"') { // 双引号开始
      qs = true;
    } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '/') { // 单行注释开始
      c1 = true;
      res++;
      i++;
    } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '*') { // 多行注释开始
      c2 = true;
      res++;
      i++;
    } else if (code[i] == '\'') {// 转义字符
      if (code[i + 1] == '\\')
        i += 3;
      else
        i += 2;
    }
  }
  printf("%d",res);
  return 0;
}

/*
// line comment
// line comment2
int main() {
  return 0;
}
*/
