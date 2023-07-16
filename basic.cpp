#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 5;
vector<int> ans[N];
int subtree[N];
bool visited[N];

void dfs(int node, vector<int> ans[], bool *visited)
{
    visited[node] = true;
    subtree[node] = node;
    for (int e : ans[node])
    {
        if (!visited[e])
        {
            visited[e] = true;
            dfs(e, ans, visited);
            subtree[node] = subtree[e] ^ subtree[node];
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
            visited[i] = false;
            ans[i].clear();
            subtree[i] = 0;
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
            cout << subtree[u] << " ";
            cout << endl;
        }
    }
    return 0;
}
