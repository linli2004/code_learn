#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <array>
using namespace std;

// 使用数组存储邻接表和度数（节点编号从1开始）
void welshPowell(int n, const vector<vector<int>> &adj)
{
    vector<pair<int, int>> nodes(n); // {度数, 节点编号}
    vector<int> color(n + 1, -1);    // 颜色数组，节点编号对应索引

    // 初始化节点度数和编号
    for (int i = 1; i <= n; ++i)
    {
        nodes[i - 1] = {static_cast<int>(adj[i].size()), i};
    }

    // 按度数降序排序节点
    sort(nodes.begin(), nodes.end(), greater<pair<int, int>>());

    // 依次着色
    for (const auto &[deg, u] : nodes)
    {
        unordered_set<int> used;
        // 收集邻接节点的颜色
        for (int v : adj[u])
        {
            if (color[v] != -1)
                used.insert(color[v]);
        }
        // 寻找最小可用颜色
        int c = 0;
        while (used.count(c))
            ++c;
        color[u] = c;
    }

    // 输出结果
    cout << "图着色结果（颜色从0开始）：" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << "节点 " << i << ": 颜色 " << color[i] << endl;
    }
}

int main()
{
    // 示例：无向图邻接表（节点1~5）
    vector<vector<int>> adj(6); // adj[0] 未使用
    adj[1] = {2, 3, 4};
    adj[2] = {1, 3, 5};
    adj[3] = {1, 2, 5};
    adj[4] = {1, 5};
    adj[5] = {2, 3, 4};

    welshPowell(5, adj);
    return 0;
}
