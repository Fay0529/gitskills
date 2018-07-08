#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	int  n, k, i ;
	while(cin>>n>>k){
		i = 1;
		for (i; i <= 21; i++) {
			if (n*i >= 200 * pow(1 + k / 100.0, i - 1))break;
		}
		if (i > 21)cout << "Impossible\n";
		else cout << i << endl;
	}
    return 0;
}

