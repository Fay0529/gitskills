// test.cpp: 定义控制台应用程序的入口点。
//
#include <bits/stdc++.h>
using namespace std;
int mark[20];//值为0默认，为1表示重，为-1表示轻，为2表示ok
int check() {
	for (int i = 0; i <= 'L' - 'A'; i++) {
		if (mark[i] != 2)return i;
	}
	return -1;
}
int main()
{
	freopen("in.txt", "r", stdin);
	string left;
	string right;
	char balance[10];
	memset(mark, 0, sizeof(mark));
	while (cin >> left >> right >> balance) {
		if (strcmp(balance,"even")==0) {
			int len = left.size();
			for (int i = 0; i < len; i++) {
				mark[left[i] - 'A'] = 2;
				mark[right[i] - 'A'] =2;
			}
		}
		else if (strcmp(balance,"up")==0) {
			int len = left.size();
			for (int i = 0; i < len; i++) {
				if(mark[right[i] - 'A']==0)
				mark[right[i] - 'A'] = -1;
				else if (mark[right[i] - 'A'] == 1)mark[right[i] - 'A'] = 2;
				if(mark[left[i] - 'A']==0)
				mark[left[i] - 'A'] = 1;
				else if (mark[left[i] - 'A'] == -1)mark[left[i] - 'A'] = 2;
			}
			for (int i = 0; i < 'L'-'A'+1; i++) {
				char c = char(i + 'A');
				if (left.find(c) == string::npos&&right.find(c) == string::npos) {
					mark[i] = 2;
				}
			}
		}
		else {
			int len = left.size();
			for (int i = 0; i < len; i++) {
				if (mark[right[i] - 'A'] == 0)
					mark[right[i] - 'A'] = 1;
				else if (mark[right[i] - 'A'] == -1)mark[right[i] - 'A'] = 2;
				if (mark[left[i] - 'A'] == 0)
					mark[left[i] - 'A'] = -1;
				else if (mark[left[i] - 'A'] == 1)mark[left[i] - 'A'] = 2;
			}
			for (int i = 0; i < 'L' - 'A' + 1; i++) {
				char c = char(i + 'A');
				if (left.find(c) == string::npos&&right.find(c) == string::npos) {
					mark[i] = 2;
				}
			}
		}
	}
	int k = check();
	if (k != -1) {
		if (mark[k] == -1)printf("%c is the counterfeit coin and it is light.\n",char(k+'A'));
		else printf("%c is the counterfeit coin and it is heavy.\n", char(k + 'A'));
	}
    return 0;
}

