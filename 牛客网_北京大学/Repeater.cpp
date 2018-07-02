#include <bits/stdc++.h>
using namespace std;
char base[5][5];
char mm[3000][3000];
int N,Q;
char w;//用来记录所用的特殊符号
struct point{
    int x,y;
    point(int a,int b):x(a),y(b){}
};
vector<point>mybase;//将坐标中心放到中心，而不是从左上角开始，存到这里，只记录符号w
struct point2{
    double x,y;
    point2(double a,double b):x(a),y(b){}
};
vector<point2>mybase2;//这个主要用于将奇数偶数计算中心的方法合并，只能用小数来算，
//不然形状就不是从中心发展（偶数情况）

void draw(int x,int y,int level){
    if(level==1){//level==1,直接将对应位置为w
        for(int i=0;i<mybase.size();i++)
        {
            mm[x+mybase[i].x][y+mybase[i].y]=w;
        }
    }
    else {
        //如果不是level1 ，就递归往下画
        for(int i=0;i<mybase.size();i++){
            draw(int(mybase2[i].x*pow(N,level-1)+x),int(mybase2[i].y*pow(N,level-1)+y),level-1);
        }
    }
}
void show(int x,int y,int level){
    //画的是N^level*N^level 的矩阵，找到其左上角和右下角的坐标
    int xlow,ylow,xhigh,yhigh;
    if(N%2==1){
        // n为奇数
        xlow=x-pow(N,level)/2+1;
        ylow=y-pow(N,level)/2+1;
        xhigh=x+pow(N,level)/2;
        yhigh=y+pow(N,level)/2;

    }
    else{
        xlow=x-pow(N,level)/2;
        ylow=y-pow(N,level)/2;
        xhigh=x+pow(N,level)/2-1;
        yhigh=y+pow(N,level)/2-1;
    }
    for(int i=xlow;i<=xhigh;i++){
        for(int j=ylow;j<=yhigh;j++){
            cout<<mm[i][j];
        }
        cout<<endl;
    }
}
int main(){
    while(scanf("%d",&N)!=EOF&&N){
        memset(base,' ',sizeof(base));
        memset(mm,' ',sizeof(mm));
        mybase.clear();
        mybase2.clear();
        int cx=N/2;
        int cy=N/2;
        double dcx=(N-1)/2.0;
        double dcy=dcx;
        getchar();//吸收换行符
        for(int i=0;i<N;i++){
            gets(base[i]);
            for(int j=0;j<N;j++){
                if(base[i][j]!=' '){
                    mybase.push_back(point(i-cx,j-cy));
                    mybase2.push_back(point2(i-dcx,j-dcy));
                    w=base[i][j];
                }
            }
        }
        cin>>Q;
        draw(1500,1500,Q);
        show(1500,1500,Q);
    }
    return 0;
}
