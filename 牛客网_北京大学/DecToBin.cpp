#include <bits/stdc++.h>
using namespace std;

string bigIntegerDivision(string s,int d){
    string res="";
    int b=0;
    for(int i=0;i<s.length();i++){
        b=b*10+s[i]-'0';
        int t=b/d;
        res+=(char)(t+'0');
        b=b%d;
    }
    int i=0;
    while(res[i]=='0')i++;
    return res.substr(i);
}

int main(int argc, char const *argv[])
{
    /* code */
    string input;

    while(cin>>input){
        string res="";
        do {
            res+=(char)((input[input.length()-1]-'0')%2+'0');
            //cout<<"res:"<<res<<endl;
            input=bigIntegerDivision(input,2);

        }while(input!="");
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }
    return 0;
}
