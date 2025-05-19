#include <iostream>
#include <vector>
#include <queue>

using namespace std;
constexpr int N=5050,M=2e5+10;

struct E{
    int v,w,x;
}e[M*2];
int h[N],cnte;

void add(int u,int v,int w){
    e[++cnte]=E{v,w,h[u]};
    h[u]=cnte;
}

struct S{
    int u,d;
};
bool operator < (const S& a,const S& b){
    return a.d>b.d;
}  

priority_queue<S> q;
int dist[N];
bool vis[N];
int n,m;
int res=0,cnt=0;
void prim(){
    memset(dist,0x3f,sizeof(dist));
    dist[1]=0;
    q.push({1,0});
    while(!q.empty()){
        if(cnt>=n) break;
        int u=q.top().u,d=q.top().d;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        cnt++;
        for(int i=h[u];i;i=e[i].x){
            int v=e[i].v,w=e[i].w;
            if(dist[v]>w){
                dist[v]=w;
                q.push({v,w});
            }
        }
    }
}
int main() {

    return 0;
}