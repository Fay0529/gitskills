#include <bits/stdc++.h>
using namespace std;

char buf[105];
int idx;
struct Node{
    Node *lchild;
    Node *rchild;
    char c;
}Tree[100];
int loc=0;
Node *create(){
    Tree[loc].lchild=NULL;
    Tree[loc].rchild=NULL;
    return &Tree[loc++];
}
void inOrder(Node *T){
//中序遍历
    if(!T)return;
    if(T->lchild!=NULL)
        inOrder(T->lchild);
    cout<<T->c<<' ';
    if(T->rchild!=NULL){
        inOrder(T->rchild);
    }
}
Node *build(){
    //根据前序遍历结果还原树
    Node* ret=NULL;
    char c=buf[idx++];
    if(c!='#'){
        ret=create();
        ret->c=c;
        ret->lchild=build();
        ret->rchild=build();
    }

    return ret;
}

int main(){
    freopen("in.txt","r",stdin);
    while(cin>>buf){
        Node *tmp=build();
        inOrder(tmp);
        memset(buf,0,sizeof(buf));
    }
}
