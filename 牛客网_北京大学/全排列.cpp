#include <bits/stdc++.h>
using namespace std;
/**
 * 本题偷懒采用递归实现，还可以使用字典序实现
*/
set<string>res;
void fullArray(string s,int index){
    int len=s.length();
    if(index>=len){
        res.insert(s);
        return;
    }
    for(int i=index;i<len;i++){
        swap(s[i],s[index]);
        fullArray(s,index+1);
        swap(s[i],s[index]);
    }
}
int main(int argc, char const *argv[])
{
    string input;
    cin>>input;
    fullArray(input,0);
    /* code */
    for(set<string>::iterator it=res.begin();it!=res.end();it++){
        cout<<*it<<endl;
    }
    cout<<endl;
    return 0;
}

