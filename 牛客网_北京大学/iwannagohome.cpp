// test.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int camp[605];
int dist1[605];
int dist2[605];
bool mark[605];
int n, m;
struct edge{
	int next;
	int c;
};
vector<edge>e[605];
void dijstra(int dist[], int c) {
	dist[c] = 0;
	int newP = c;
	mark[c] = 1;
	for (int i = 1; i <n; i++) {//遍历n-1次，把其它节点加进来
		for (int j = 0; j < e[newP].size(); j++) {//拿newP去更新其它不在K中的点
			int next= e[newP][j].next;
			if (camp[next]!=c)continue;
			if (mark[next] == true)continue;
			if (dist[next] == -1 || dist[next] > dist[newP] + e[newP][j].c) {
				dist[next] = dist[newP] + e[newP][j].c;
			}

		}
		int min = 123132131;
		for (int i = 1; i <= n; i++) {
			if (mark[i])continue;
			if (camp[i] != c)continue;
			if (dist[i] == -1)continue;
			if (dist[i] < min) {
				min = dist[i];
				newP = i;
			}
		}
		mark[newP] = 1;

	}
}
int getDis(int m, int n) {
	for (int i = 0; i < e[m].size();i++) {
		if (e[m][i].next == n) {
			//cout <<m<< ":" << n<< e[m][i].c << endl;
			return e[m][i].c;
		}
	}
	return -1;
}
int isExist(int x, int y) {
	for (int i = 0; i < e[x].size(); i++) {
		if (y == e[x][i].next)
			return i;
	}
	return -1;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	
	while (cin >> n&&n) {
		cin >> m;
		for (int i = 1; i <= n; i++) { 
			e[i].clear();
			dist1[i] = -1;
			dist2[i] = -1;
			mark[i] = 0;
		}
		for (int i = 0; i < m; i++) {
			int x, y, cost;
			cin >> x >> y >> cost;
			edge tmp;
			tmp.next = y;
			tmp.c = cost;
			int ret = isExist(x, y);
			if (ret == -1) {
				e[x].push_back(tmp);
				tmp.next = x;
				e[y].push_back(tmp);
			}
			
			else {
				if (e[x][ret].c > cost)
				{
					e[x][ret].c = cost;
					ret = isExist(y, x);
					e[y][ret].c = cost;
				}

			}
			
		}
		for (int i = 1; i <= n; i++) {
			cin >> camp[i];
		}
		dijstra(dist1, 1);
		dijstra(dist2, 2);
	
		int min =INT_MAX;
		int f = min;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (camp[i] != camp[j]) {
					if (camp[i] == 1) {
						if (dist1[i] == -1 || dist2[j] == -1)continue;
						int d = getDis(i, j);
						if (d == -1)continue;
						if (dist1[i] + dist2[j] + d < min) {
							min = dist1[i] + dist2[j] + d;
						}
					}
					else {
						if (dist2[i] == -1 || dist1[j] == -1)continue;
						int d = getDis(i, j);
						if (d == -1)continue;
						if (dist2[i] + dist1[j] + d < min) {
							min = dist2[i] + dist1[j] + d;
						}
					}
				}
			}
		}
		if (min == f)cout << -1 << endl;
		else cout << min << endl;
	}
	
    return 0;
}

