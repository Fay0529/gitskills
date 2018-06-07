#include <bits/stdc++.h>
using namespace std;
int m,n;
int dpProcess()
{
    int dp[12][12]={0};
    // dp[i][j]表示i个苹果j个盘子的最多放的方法
    for(int i=0;i<=m;i++){

        dp[i][1]=1;//只有一个盘子
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=1;//只有0个苹果
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j>i){
                //如果盘子数量大于苹果数量
                dp[i][j]=dp[i][i];
            }
            else{
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
            }
        }
    }
    return dp[m][n];
}

int main(){
    while(cin>>m>>n){
        int res=dpProcess();
        cout<<res<<endl;
    }
}
