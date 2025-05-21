#include <iostream>
#include<queue>

using namespace std;
constexpr int MAXN=5010;
constexpr int MAXM=40010;
constexpr int INF=1e9;
int n,m,s,t,k,u,v,ww,H[MAXN],cnt[MAXN];
int cur,h[MAXN],nxt[MAXM],p[MAXM],w[MAXM];
int cur1,h1[MAXN],nxt1[MAXM],p1[MAXM],w1[MAXM];
bool vis[MAXN];

void add(int u,int v,int ww){
    nxt[++cur]=h[u];
    h[u]=cur;
    p[cur]=v;
    w[cur]=ww;
}

void add1(int u,int v,int ww){
    nxt1[++cur1]=h1[u]; 
    h1[u]=cur1;          
    p1[cur1]=v;          
    w1[cur1]=ww;         
}

struct node{
    int x,v;
    bool operator < (const node&a){
        return v + H[x] > a.v + H[a.x];
    }
};

struct node1{
    int x,v;
    bool operator < (cost node1&a){
        return v > a.v;
    }
}x;
priority_queue<node>q;
priority_queue<node1>Q;
int main(){

    cin>>n>>m>>s>>t>>k;
    while(m--){
        cin>>u>>v>>ww;
        add(u,v,ww);
        add1(u,v,ww);
    }
    for(int i=1;i<=n;i++) H[i] = INF;
    Q.push({t,0});
    while(!Q.empty()){
        x = Q.top();
        Q.pop();
        if(vis[x.x])continue;
        vis[x.x]=true;
        H[x.x]=x.v;
        for(int i = h1[x.x];i;i=net1[i]){
            Q.push({p1[i],w1[i]+x.v});
        }
    }
    q.push({s,0});
    while(!q.empty()){
        node u=q.top();
        q.pop();
        cnt[u.x]++;
        if(u.x==t && cnt[u.x]==k){
            cout<<u.v<<endl;
        }
        if(cnt[u.x]>k)continue;
        for(int i=h[u.x];i;i=net[i]){
            q.push({p[i],w[i]+u.v});
        }
    }
    return 0;
}