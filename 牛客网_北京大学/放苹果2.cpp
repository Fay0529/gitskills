
#include <bits/stdc++.h>
using namespace std;
int dp[21][21];//表示i个苹果放到j个盘子（一定要放满）的方法
/**
 * 利用整数划分的方法，假设整数m被划分成n个正整数，有多少种划分方法呢，用dp[i][j]表示整数i被划分成j个整数的种类 数
 * 第一种情况，如果i<j，显然不可能，所以dp[i][j]=0;
 * 第二种情况，i==j,这时候只能每个整数都等于1,所以dp[i][j]=1;
 * 第三种情况，i>j,这时候就需要根据这些小数种是否含有1来判断，如果有1个1，那么结果为dp[i-1][j-1]，实际上在填表的时候已经将2个1，
 * 3个1的情况都包含进去了，因为i j都是从小到大遍历的，在求dp[i-1][j-1]也会考虑1个1的情况，相对于dp[i][j]就是考虑了2个1的情况，以此类推
 * 如果没有1那么至少每个整数都大于等于2，所以将每个整数先减去一个1，结果一样，也就是dp[i-j][j],所以
 * dp[i][j]=dp[i-1][j-1]+dp[i-j][j]
 * 最后dp[m][n]只是将m个苹果放入n个盘子，每个盘子都要放苹果的,但是题目可以有些盘子不放，所以需要将dp[m][1..n]加起来
 * 
*/
int main()
{
	// freopen("in.txt", "r", stdin);
	int m,n;
	for (int i = 1; i <= 20; i++) {
		dp[i][0] = 0;
		dp[i][1] = 1;
		dp[i][i] = 1;
	}
	
	for (int i = 1; i <= 20; i++)
	{
		for (int j = 1; j <= 20; j++) {
			if (i > j) {
				
				dp[i][j] = dp[i - 1][j-1] + dp[i - j][j];
			}
			else if (i < j) dp[i][j] = 0;
		}
	}
	while (cin >> m>> n) {
		int res = 0;
		for (int i = 1; i <= n; i++)res += dp[m][i];
		cout << res << endl;
	}
    return 0;
}

