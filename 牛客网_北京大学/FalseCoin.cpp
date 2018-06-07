    #include <bits/stdc++.h>
    using namespace std;
   /**
 * 这题折腾了我几个小时，怀疑自己的智商了。
 * 解题的思路就是，有四种状态组，一种是轻的组-1，一种是重的组1，一种是正常组0，一种是未确认组2
 * 如果出现不等号，那么未出现在这个不等号两边的硬币一定是正常的，并且将不等号两边的分别加入各自的组
 * 如果一个硬币即出现在重组又出现在轻组，那么这个硬币一定是正常的
 * 最后看看正常的个数是不是N-1,是的话就能判断，不是就不能
 * 
*/
int N,K;
int mark[1005];//有四种状态组，一种是轻的组-1，一种是重的组1，一种是正常组0，一种是未确认组2
int tmp[1000];//记录下参与称重的硬币号
int pi;//记录参与称重的硬币数
bool notIn(int n){//判断当前硬币是不是参与称重了，不是返回true
    for(int i=0;i<2*pi;i++){
        if(n==tmp[i])return false;
    }
    return true;
}
    int main(){
       // freopen("in.txt","r",stdin);
        cin>>N>>K;
        int flag=0;//标记可疑的银币下标
        for(int i=1;i<=N;i++)mark[i]=2;//初始化

        for(int i=0;i<K;i++){//之前智障的设成了2K，调了好久才发现= =

            cin>>pi;

            for(int i=0;i<2*pi;i++){
                cin>>tmp[i];
            }
            char s;
            cin>>s;
            if(s=='='){//如果相等，说明两边都是正常的
                for(int i=0;i<2*pi;i++){
                    mark[tmp[i]]=0;
                }
            }
            else if(s=='<'){
                // 左边加入轻组，右边加入重组
                int i=0;
                for(i;i<pi;i++){
                    if(mark[tmp[i]])//正常的不考虑，也就是等于0不考虑
                        {
                            if(mark[tmp[i]]==1)mark[tmp[i]]=0;//如果一个硬币即出现在重组又出现在轻组，那么这个硬币一定是正常的
                            else mark[tmp[i]]=-1;
                        }
                }
                for(i;i<2*pi;i++){
                     if(mark[tmp[i]])
                        if(mark[tmp[i]]==-1)mark[tmp[i]]=0;//如果一个硬币即出现在重组又出现在轻组，那么这个硬币一定是正常的
                        else mark[tmp[i]]=1;

                }
                for(int i=1;i<=N;i++){
                    // 未出现在这个不等号两边的硬币一定是正常的
                    if(notIn(i)){
                        mark[i]=0;
                    }
                }
            }
            else if(s=='>'){
                //同上
                int i=0;
                for(i;i<pi;i++){
                    if(mark[tmp[i]])
                         if(mark[tmp[i]]==-1)mark[tmp[i]]=0;
                         else mark[tmp[i]]=1;
                }
                for(i;i<2*pi;i++){
                    if(mark[tmp[i]])
                        if(mark[tmp[i]]==1)mark[tmp[i]]=0;
                        else mark[tmp[i]]=-1;

                }
                for(int i=1;i<=N;i++){
                    if(notIn(i)){
                        mark[i]=0;
                    }
                }

            }
        }

        int cnt=0;
        for(int i=1;i<=N;i++){
            if(!mark[i])cnt++;
            else flag=i;
        }
        if(cnt==N-1)
        cout<<flag<<endl;
        else cout<<0<<endl;
        return 0;
    }
