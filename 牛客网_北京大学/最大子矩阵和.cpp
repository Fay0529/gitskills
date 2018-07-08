#include <bits/stdc++.h>

using namespace std;
int maxsub(int a[], int len) {
	int imax = 0;
	int b = a[0];
	for (int i = 1; i < len; i++) {
		if (b > 0)b += a[i];
		else b = a[i];
		if (b > imax)imax = b;
	}
	return imax;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int data[100][100];
	int tmp[100];
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> data[i][j];
		int imax = 0;
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++) {
				//从i行到j行的最大子矩阵和，先将所有行加起来成为一行存到tmp中
				memset(tmp, 0, sizeof(tmp));
				for(int p=0;p<n;p++)
					for (int k = i; k <= j; k++) {
						tmp[p] += data[k][p];
					}
				int t = maxsub(tmp, n);
				if (t > imax)imax = t;
			}
		cout << imax << endl;
	}

    return 0;
}

