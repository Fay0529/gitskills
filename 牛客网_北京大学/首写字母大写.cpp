// test.cpp: 定义控制台应用程序的入口点。
//
#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);
	
	char s[200];
	while (cin.getline(s,100)) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (i == 0 && isalpha(s[i]))s[i] = char(toupper(s[i]));
			else if (isspace(s[i]))continue;
			else if(isalpha(s[i])&&isspace(s[i-1]))s[i]=char(toupper(s[i]));
		}
		for (int i = 0; i < len; i++)cout << s[i];
	}

	
    return 0;
}

