#include <bits/stdc++.h>
using namespace std;
int N,M;
int **metrix;
int main(){
    //freopen("in.txt","r",stdin);
        cin>>N>>M;
        //申请空间：
        metrix=new int*[N];
        for(int i=0;i<N;i++){
            metrix[i]=new int[M];
            for(int j=0;j<M;j++){
                metrix[i][j]=0;
            }
        }
        int *t=new int[N];//记录输入的N个读者借的书编号
        for(int i=0;i<N;i++){
            cin>>t[i];
            metrix[i][t[i]-1]=1;
        }

        //统计每本书的人数
        int *a=new int[M];//记录每列和
        for(int i=0;i<M;i++){
            int sum=0;
            for(int j=0;j<N;j++){
                sum+=metrix[j][i];
            }
            a[i]=sum;
        }
        //得到每个人朋友数
        for(int i=0;i<N;i++){
            if(a[t[i]-1]>1)cout<<a[t[i]-1]-1<<endl;
            else cout<<"BeiJu"<<endl;
        }
       //释放空间
       for(int i=0;i<N;i++)delete metrix[i];
       delete [] a;
       delete []t;

    return 0;
}
