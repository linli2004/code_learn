#include <iostream>

using namespace std;

//优化版的记忆化搜索
int n,t;
int tcos[103],mget[103];
int men[103][103];

int dfs(int pos,int tleft){
    if(men[pos][tleft]!=-1) return men[pos][tleft];
    if(pos==n+1)return men[pos][tleft]=0;
    int dfs1,dfs2=-0x3f3f3f3f;
    dsf1=dfs(pos+1,tleft);
    if(tleft>=tcos[pos]){
        dfs2=dfs(pos+1,tleft-tcos[pos])+mget[pos];
    }
    return men[pos][tleft]=max(dfs1,dfs2);
}

int main(){

    return 0;
}