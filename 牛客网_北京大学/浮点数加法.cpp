// 链接：https://www.nowcoder.com/questionTerminal/ddec753f446e4ba4944e35378ba635c8
// 来源：牛客网

// 求2个浮点数相加的和 题目中输入输出中出现浮点数都有如下的形式： P1P2...Pi.Q1Q2...Qj 对于整数部分，P1P2...Pi是一个非负整数 对于小数部分，Qj不等于0 
// 输入描述:
// 对于每组案例，每组测试数据占2行，分别是两个加数。


// 输出描述:
// 每组案例是n行，每组测试数据有一行输出是相应的和。
// 输出保证一定是一个小数部分不为0的浮点数
// 示例1
// 输入
// 0.111111111111111111111111111111
// 0.111111111111111111111111111111
// 输出
// 0.222222222222222222222222222222

#include <bits/stdc++.h>
using namespace std;

struct bigfloat{
    int integer[100];
    int decimal[100];
    int iSize;
    int dSize;
    void init(){
        memset(integer,0,sizeof(integer));
        memset(decimal,0,sizeof(decimal));
        iSize=0;
        dSize=0;
    }
    void set(string s){
        init();
        int medium=0;//找到小数点的位置
        for(;medium<s.length();medium++){
            if(s[medium]==[.])break;
        }
        for(int i=medium-1,j=0,c=1;i>=0;i--){
            //整数部分
            integer[iSize]+=(s[i]-'0')*c;
            c=c*10;
            j++;
            if(j==4||i==0){
                j=0;
                c=1;
                iSize++;
            }

        }
        for(int i=s.length()-1,j=0,c=0;i>medium;i--){
            decimal[dSize]==(s[i]-'0')*c;
            c=c*10;
            j++;
            if(j==4||i==medium+1){
                j=0;
                c=1;
                dSize++;
            }
        }

    }
    void output(){
        for(int i=iSize-1;i>=0;i--){
            if(i==iSize-1){
                printf("%d",integer[i]);
            }else 
            printf("%04d",integer[i]);
        }
        cout<<".";
        for(int i=dSize-1;i>=0;i--){
            if(i==dSize-1){
              printf("%d",decimal[i]);
            }else 
            printf("%04d",decimal[i]);
        }
        cout<<endl;
    }
    
    bigfloat operator + (const bigfloat & a) const{
        bigfloat ret;
        ret.init();
        int carry=0;
        for(int i=0;i<dSize;i++){
            //小数部分
            int t=decimal[i]+a.decimal[i]+carry;
            carry=t/10000;
            t=t%10000;
            ret.decimal[ret.dSize++]=t;
        }
        for(int i=0;i<iSize;i++){
            int t=integer[i]+a.integer[i]+carry;
            carry=t/10000;
            t=t%10000;
            ret.integer[ret.iSize++]=t;
        }
        if(carry!=0)ret.integer[ret.iSize++]=carry;
        return ret;
    }
}
int main(){
    string str1,str2;
    while(cin>>str1>>str2){
        bigfloat a,b,c;
        a.set(str1);
        b.set(str2);
        c=a+b;
        c.output();
    }
}