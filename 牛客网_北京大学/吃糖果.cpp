#include <bits/stdc++.h>
using namespace std;


int main()
{	
	freopen("in.txt", "r", stdin);
	int n;
	int f[30];
	f[1] = 1;
	f[2] = 2;
	for (int i = 3; i < 30; i++)f[i] = f[i - 1] + f[i - 2];
	while (cin >> n&&n) {
		cout << f[n] << endl;
	}
    return 0;
}

