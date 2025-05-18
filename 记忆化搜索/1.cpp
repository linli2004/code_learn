#include <iostream>

using namespace std;

int n,t;
int tcos[103],mget[103];
int ans=0;
void dfs(int pos,int tleft,int tans){
    if(tlef<0)return0;
    if(pos==n+1){
        ans=max(ans,tans);
        return;
    }
    dfs(pos+1,tleft,tans);
    dfs(pos+1,tleft-tcos[pos],tans+mget[pos]);
}
int main(){

    return 0;   
}