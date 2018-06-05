#include <bits/stdc++.h>
using namespace std;
/**
 * 测试用例有bug，无法通过，代码没问题，题目有歧义
*/
int *data;
bool check(int n){

    for(int i=1;i<n;i++){
        if(data[i]!=data[i-1]) return true;//存在不相等，则不结束循环，返回true
    }

    return false;
}
void round(int n){
    int *tmp=new int[n];
    for(int i=0;i<n;i++){//同时将自己的一半给右边
        if(data[i]%2==1) data[i]++;//奇数的话老师给一个
        tmp[(i+1)%n]=data[i]/2;
        data[i]=data[i]/2;
    }
    for(int i=0;i<n;i++){//同时获得左边给的那一半
        data[i]+=tmp[i];
        if(data[i]%2==1) data[i]++;//奇数的话老师给一个
    }
    delete [] tmp;
}
void print(int n){

    for(int i=0;i<n;i++){
        cout<<setw(5)<<data[i];
    }
    cout<<endl;
}
int main(){
  //  freopen("in.txt","r",stdin);

    int  n;
    while(cin>>n&&n){
            data=new int[n];
        for(int i=0;i<n;i++){
            cin>>data[i];
        }
       // print(n);
        int cnt=0;
        while(check(n)){
            cnt++;
            round(n);
          //  print(n);
        }

        cout<<cnt<<" "<<data[0]<<endl;
        delete []data;
    }

    return 0;
}
