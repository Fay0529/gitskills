
#include<bits/stdc++.h>

using namespace std;

string s;
bool mark[10];
char res[10];
void dfs(int num) {

	//num表示已经放入结果中的字符个数
	if (num == s.length()) {
		for (int i = 0; i < s.length(); i++) {
			cout << res[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < s.length(); i++) {
		if (mark[i])continue;
		res[num] = s[i];
		mark[i] = true;
		dfs(num + 1);
		mark[i] = false;
	}
}

int main()
{	
	//freopen("in.txt", "r", stdin);
	
	while (cin >> s) {
		for (int i = 0; i < s.length(); i++) {
			mark[i] = false;
		}
        sort(s.begin(), s.end());
		dfs(0);
        cout<<endl;
	}
    return 0;
}