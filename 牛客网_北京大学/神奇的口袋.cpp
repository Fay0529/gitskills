// test.cpp: 定义控制台应用程序的入口点。
//
#include <bits/stdc++.h>
using namespace std;
int w[20];
int n;
int sz;
int main()
{
	freopen("in.txt", "r", stdin);
	while (cin >> n) {
		sz = 0;
		while (n--) {
			int t;
			cin >> t;
			if (t > 40) continue;
			w[sz++] = t;
		}
		int bin = 0;
		int cnt = 0;
		while(bin<pow(2,sz)){
			int sum = 0;
			int tmp = bin;
			for (int i = 0; i < sz; i++) {
				sum += w[i] * (tmp & 1);
				tmp = tmp >> 1;
			}
			if (sum == 40)cnt++;
			bin++;
		}
		cout << cnt << endl;
	}
    return 0;
}

