#include <iostream>
#include <cstring>
using namespace std;
constexpr int MAXN = 105;

struct MaxClique
{
    int g[MAXN][MAXN];
    int n, dp[MAXN], st[MAXN][MAXN], ans;
    // dp[u] 表示从顶点 u 开始（包括 u）能组成的最大团大小
    // st[num][i] 表示第 num 层搜索时的候选顶点集合
    void init(int n)
    {
        this->n = n;
        memset(g, 0, sizeof(g));
    }
    void addedge(int u, int v, int w)
    {
        g[u][v] = w;
    }

    bool dfs(int sz, int num)
    {
        if (sz == 0)
        {
            if (num > ans)
            {
                ans = num;
                return true;
            }
            return false;
        }
        for (int i = 0; i < sz; i++)
        {
            if (sz - i + num <= ans)
            {
                return false;
            }
            int u = st[num][i];
            if (dp[u] + num <= ans)
                return false;
            int cnt = 0;
            for (int j = i + 1; j < sz; j++)
            {
                if (g[u][st[num][j]])
                    st[num + 1][cnt++] = st[num][j];
            }
            if (dfs(cnt, num + 1))
                return true;
        }
        return false;
    }
    int solve()
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = n; i >= 1; i--)
        {
            int cnt = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (g[i][j])
                    st[1][cnt++] = j;
            }
            dfs(cnt, 1);
            dp[i] = ans;
        }
        return ans;
    }
};