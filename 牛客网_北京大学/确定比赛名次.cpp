// 有N个比赛队（1<=N<=500），编号依次为1，2，3，。。。。，N进行比赛，比赛结束后，裁判委员会要将所有参赛队伍从前往后依次排名，但现在裁判委员会不能直接获得每个队的比赛成绩，只知道每场比赛的结果，即P1赢P2，用P1，P2表示，排名时P1在P2之前。现在请你编程序确定排名。
 

// Input
// 输入有若干组，每组中的第一行为二个数N（1<=N<=500），M；其中N表示队伍的个数，M表示接着有M行的输入数据。接下来的M行数据中，每行也有两个整数P1，P2表示即P1队赢了P2队。
 

// Output
// 给出一个符合要求的排名。输出时队伍号之间有空格，最后一名后面没有空格。

// 其他说明：符合条件的排名可能不是唯一的，此时要求输出时编号小的队伍在前；输入数据保证是正确的，即输入数据确保一定能有一个符合要求的排名。
 

// Sample Input
// 4 3
// 1 2
// 2 3
// 4 3
 

// Sample Output
// 1 2 4 3

// test.cpp: 定义控制台应用程序的入口点。
//

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <queue>
#include <string>

using namespace std;
int n,m;
vector<int>edge[505];
int inDegree[505];
priority_queue<int,vector<int>,greater<int> >q;

int main()
{	
	// freopen("in.txt", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 1; i <= n; i++) {
			inDegree[i] = 0;
			edge[i].clear();
		}
		while (false == q.empty())q.pop();
		while (m--) {
			int x, y;
			cin >> x >> y;
			inDegree[y]++;
			edge[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (0 == inDegree[i])q.push(i);
		}
		int first = true;
		while (false == q.empty()) {
			int t = q.top();
			if (first) {
				cout << t; first = false;
			}
			else cout << " " << t;
			q.pop();
			
			for (int i = 0; i < edge[t].size(); i++) {
				int next = edge[t][i];
				inDegree[next]--;
				if (0 == inDegree[next])q.push(next);
			}
		
		}
		cout << endl;
	}
    return 0;
}

