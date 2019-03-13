#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(int a, int b) {
  	if (isdigit(a) && isalpha(b)) return false;
  	if (isdigit(b) && isalpha(a)) return true;
  	return a < b;
}

int main()
{
   	string s;
   	cin >> s;
   	sort(s.begin(), s.end(), cmp);
   	cout << s;
   	return 0;
}

/*
a31bz
*/
