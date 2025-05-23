#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// 图的邻接表表示
using Graph = vector<vector<int>>;

// 打印集合
void printSet(const set<int> &s)
{
    cout << "{ ";
    for (int v : s)
        cout << v << " ";
    cout << "}" << endl;
}

// Bron-Kerbosch算法实现
void bronKerbosch(const Graph &graph, set<int> R, set<int> P, set<int> X)
{
    // 如果P和X都是空集，R是一个极大团
    if (P.empty() && X.empty())
    {
        cout << "极大团: ";
        printSet(R);
        return;
    }

    // 选择枢纽顶点u（P∪X中邻居最多的顶点）
    int u = -1;
    int maxNeighbors = -1;
    set<int> PunionX;
    for (int v : P)
        PunionX.insert(v);
    for (int v : X)
        PunionX.insert(v);

    for (int v : PunionX)
    {
        int neighborCount = 0;
        for (int neighbor : graph[v])
        {
            if (PunionX.count(neighbor))
                neighborCount++;
        }
        if (neighborCount > maxNeighbors)
        {
            maxNeighbors = neighborCount;
            u = v;
        }
    }

    // 处理P中所有不与u相邻的顶点
    set<int> candidates;
    for (int v : P)
    {
        bool isNeighborOfU = false;
        for (int neighbor : graph[u])
        {
            if (neighbor == v)
            {
                isNeighborOfU = true;
                break;
            }
        }
        if (!isNeighborOfU)
        {
            candidates.insert(v);
        }
    }

    // 如果没有这样的顶点，处理P中所有顶点
    if (candidates.empty())
    {
        candidates = P;
    }

    for (int v : candidates)
    {
        set<int> newR = R;
        newR.insert(v);

        set<int> newP;
        for (int neighbor : graph[v])
        {
            if (P.count(neighbor))
                newP.insert(neighbor);
        }

        set<int> newX;
        for (int neighbor : graph[v])
        {
            if (X.count(neighbor))
                newX.insert(neighbor);
        }

        bronKerbosch(graph, newR, newP, newX);

        P.erase(v);
        X.insert(v);
    }
}

int main()
{
    // 创建一个示例图（邻接表表示）
    // 注意：顶点编号从0开始
    Graph graph = {
        {1, 2, 3},    // 顶点0的邻居
        {0, 2},       // 顶点1的邻居
        {0, 1, 3, 4}, // 顶点2的邻居
        {0, 2, 4},    // 顶点3的邻居
        {2, 3}        // 顶点4的邻居
    };

    // 初始化集合
    set<int> R; // 空集
    set<int> P; // 所有顶点
    for (int i = 0; i < graph.size(); ++i)
    {
        P.insert(i);
    }
    set<int> X; // 空集

    // 调用Bron-Kerbosch算法
    bronKerbosch(graph, R, P, X);

    return 0;
}
