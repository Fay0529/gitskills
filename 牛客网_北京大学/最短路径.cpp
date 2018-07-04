
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
#define mod 100000

int getDistance(int k) {
	int ret = 1;
	for(int i=0;i<k;i++){
		ret = (ret * 2) % mod;
	}
	return ret;
}
int dis[101][101];
int tree[101];
int findRoot(int x) {
	if (tree[x] == -1)return x;
	else {
		int tmp = findRoot(tree[x]);
		tree[x] = tmp;
		return tmp;
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = -1;
			}
			dis[i][i] = 0;
			tree[i] = -1;
		}
		int k = 0;
		while (m--) {
			int x, y;
			cin >> x >> y;
			int a = findRoot(x);
			int b = findRoot(y);
			int d = getDistance(k++);
			if (a != b) {
				dis[x][y] = d;
				dis[y][x] = d;
				tree[a] = b;
			}

		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (tree[i] == -1)cnt++;
		}
		if (cnt > 1) {
			cout << -1 << endl;
			continue;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dis[i][k] == -1 || dis[k][j] == -1)continue;
					if (dis[i][j] == -1 || dis[i][j] > dis[k][j] + dis[i][k]) {
						dis[i][j] = dis[k][j] + dis[i][k];
					}
				}
			}
		}
		for (int i = 1; i < n; i++) {
			cout << dis[0][i]%mod << endl;	
		}
	}
	
    return 0;
}

