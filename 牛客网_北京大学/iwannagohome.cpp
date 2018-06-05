//#pragma once
#include <bits/stdc++.h>
using namespace std;

int N,M;
int A,B,T;
//path[v],表示到达v城市的上一个定点，path[0]=-1,path[1]=-1;

//dist1[V],城市1表示到达v城市的最短距离，dist1[0]为0.从起点到不可达的顶点的距离均为无限大
int *dist1;
int *dist2;
//邻接矩阵graph[i][j]表示城市i到城市j的时间
int **graph;
//camp[i]表示城市i的阵营
int *camp;
//先求出城市1到达其他阵营1 的所有点的最小距离和城市2到达其他阵营2的所有点的最小距离
//visit[i]表示城市i已经加入到最短路径树中
int *visit;
int num1,num2;//记录每个阵营的数量
void pgraph(){
 cout<<"graph"<<endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }
}
void pdist(){
    cout<<"dist1"<<endl;
    for(int i=0;i<N;i++){
        cout<<dist1[i]<<" " ;
    }
    cout<<endl<<"dist2"<<endl;
    for(int j=0;j<N;j++)
        cout<<dist2[j]<<" ";
    cout<<endl;
}
void init(){
        cin>>M;
        //申请空间
        graph=new int*[N];
        dist1=new int[N];
        dist2=new int[N];

        camp=new int[N];
        visit=new int[N];
        num1=0;
        num2=0;
        for(int i=0;i<N;i++){
            graph[i]=new int[N];
            for(int j=0;j<N;j++){
                if(i==j)graph[i][j]=0;
                else graph[i][j]=INT_MAX;
            }
        }
        for(int i=0;i<M;i++){//初始化graph数组
            cin>>A>>B>>T;
            
            if(A-1<N&&B-1<N&&T<graph[A-1][B-1]){

                graph[A-1][B-1]=T;
                graph[B-1][A-1]=T;
            }

        }
        //打印graph
      //  pgraph();
        for(int i=0;i<N;i++){//初始化camp数组
            int tmp;
            cin>>tmp;
            camp[i]=tmp;
            if(tmp==1)num1++;
            else num2++;

        }

        visit[0]=1;//起点放到集合中
        visit[1]=1;
        for(int i=2;i<N;i++)visit[i]=0;//初始化visit数组
        for(int i=0;i<N;i++){

           dist1[i]=graph[0][i];
           dist2[i]=graph[1][i];
        }
      //  pdist();

}

void distroy(){
    delete []dist1;
    delete []dist2;
    delete []camp;
    delete []visit;
    for(int i=0;i<N;i++){
            delete graph[i];
    }

}
int dijkstra(){
    int cnt1=1;
    int cnt2=1;
    while(cnt1<num1||cn2<num2){
        int tmp1=0;//记录找到的最小的顶点的下标
        int tmp2=1;//记录找到的最小的顶点的下标
        int MIN1=INT_MAX;//记录最小值;
        int MIN2=INT_MAX;//记录最小值;

        for(int i=2;i<N;i++){
            if(camp[i]==1&&!visit[i]){
                if(dist1[i]<MIN1){
                    MIN1=dist1[i];
                    tmp1=i;
                }
            }
            else if(camp[i]==2&&dist2[i]<MIN2&&!visit[i]){
                    MIN2=dist2[i];
                    tmp2=i;
                }
            }
        }
        visit[tmp1]=1;
        visit[tmp2]=1;
        if(cnt1<num1)cnt1++;
        if(cnt2<num2)cnt2++;

       for(int i=2;i<N;i++){
            if(camp[i]==1&&!visit[i]&&graph[tmp1][i]!=INT_MAX&&dist1[tmp1]!=INT_MAX&&graph[tmp1][i]+dist1[tmp1]<dist1[i]){
                dist1[i]=graph[tmp1][i]+dist1[tmp1];
            }
            if(camp[i]==2&&!visit[i]&&graph[tmp2][i]!=INT_MAX&&dist2[tmp2]!=INT_MAX&&graph[tmp2][i]+dist2[tmp2]<dist2[i])
            {
                dist2[i]=graph[tmp2][i]+dist2[tmp2];
            }
        }
    }
    //pdist();
    int MIN=INT_MAX;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(camp[i]==1&&camp[j]==2&&graph[i][j]!=INT_MAX&&dist1[i]!=INT_MAX&&dist2[j]!=INT_MAX&&dist1[i]+dist2[j]+graph[i][j]<MIN){
                MIN=dist1[i]+dist2[j]+graph[i][j];
            }
             if(camp[i]==2&&camp[j]==1&&graph[i][j]!=INT_MAX&&dist2[i]!=INT_MAX&&dist1[j]!=INT_MAX&&dist2[i]+dist1[j]+graph[i][j]<MIN){
                MIN=dist2[i]+dist1[j]+graph[i][j];
            }
        }
    }
    if(MIN!=INT_MAX)
    return MIN;
    else return -1;
}
int main(){

    //freopen("in.txt","r",stdin);
    while(cin>>N&&N){
        //初始化
        init();
        cout<<dijkstra()<<endl;
        //析构数组
        distroy();

    }
    return 0;
}
