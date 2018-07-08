#include <bits/stdc++.h>
using namespace std;

struct bin {
	int data[16];
	void set(int n) {
		memset(data, 0, sizeof(data));
		int i = 15;
		while (n > 0) {
			int t = n % 2;
			n = n >> 1;
			data[i--] = t;
		}
	}
	bin operator <<(const int & n) {
		int t = data[0];//只考虑左移一位
		for (int i = 0; i < 15; i++) {
			data[i] = data[i + 1];
		}
		data[15] = t;
		return *this;
	}
	bool operator == (const bin&a) const {
		for (int i = 0; i < 16; i++) {
			if (data[i] != a.data[i])return false;
		}
		return true;
	}
};
int main()
{
	//freopen("in.txt", "r", stdin);
	
	int n,m;
	while (cin >> n>>m) {
		bin a, b;
		a.set(n);
		b.set(m);
		int cnt = 0;
		while (! (a == b)) {
			a = a << 1;
			cnt++;
			if (cnt == 16)break;
		}
		if (cnt == 16)cout << "NO" << endl;
		else cout << "YES" << endl;

	}
    return 0;
}

