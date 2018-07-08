// test.cpp: 定义控制台应用程序的入口点。
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	string s;
	int sum = 0;
	while (cin >> s) {
		if (s == "0") {
			cout << sum << endl;
			sum = 0;
		}
		string e;
		int miles;
		char c;
		cin >> e >> miles >> c;
		if (c == 'F')sum += 2 * miles;
		else if (c == 'B')sum += miles + int((miles + 1) / 2);
		else if (c == 'Y') {
			if (miles <= 500)sum += 500;
			else sum += miles;
		}
	}
    return 0;
}

