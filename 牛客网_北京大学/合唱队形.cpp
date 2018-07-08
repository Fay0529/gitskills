// test.cpp: 定义控制台应用程序的入口点。
//
#include <bits/stdc++.h>
using namespace std;
int len[105];
int dp1[105];//从左到右的最长递增子序列dp[i]表示最长递增子序列要以len[i]结尾
int dp2[105];//从右到左的最长递增子序列

int main()
{	
	freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n) {
		for (int i = 1; i <= n; i++) {
			cin >> len[i];
		}
		for (int i = 1; i <= n; i++) {
			int tmax = 1;
			for (int j = 1; j < i; j++) {
				if(len[j]<len[i])
				tmax = max(tmax, dp1[j]+1);
			}
			dp1[i] = tmax;
		} 
		//反过来求
		for (int i = n; i > 0; i--) {
			int tmax = 1;
			for (int j = n; j > i; j--) {
				if (len[i] > len[j]) {
					tmax = max(tmax, dp2[j] + 1);
				}
			}
			
			dp2[i] = tmax;
		}
		int imax = 1;
		for (int i = 1; i <= n; i++) {
			if (dp1[i] + dp2[i] > imax)
				imax = dp1[i] + dp2[i];
		}
		cout << n - imax+1 << endl;
	}
    return 0;
}

