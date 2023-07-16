#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5;
vector<int> ans[N];
int subtreeXOR[N];
bool visited[N];

void dfs(int node, vector<int> ans[], bool *visited)
{
    subtreeXOR[node] = node;
    visited[node] = true;
    for (auto e : ans[node])
    {
        if (!visited[e])
        {
            visited[e] = true;
            dfs(e, ans, visited);
            subtreeXOR[node] = subtreeXOR[node] ^ subtreeXOR[e];
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i <= n; i++)
        {
            ans[i].clear();
            subtreeXOR[i] = 0;
            visited[i] = false;
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        dfs(0, ans, visited);
        while (q--)
        {
            int u;
            cin >> u;
            cout << subtreeXOR[u] << " ";
        }
    }
    return 0;
}