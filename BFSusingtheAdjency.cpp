#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(int node, vector<int> ans[], int n)
{
    queue<int> pendingNodes;
    pendingNodes.push(node);
    vector<bool> visited(n, false);
    visited[node] = true;
    while (pendingNodes.size() != 0)
    {
        int front = pendingNodes.front();
        cout << front << " ";
        pendingNodes.pop();
        for (auto e : ans[front])
        {
            if (!visited[e])
            {
                pendingNodes.push(e);
                visited[e] = true;
            }
        }
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> ans[n];
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            ans[u].push_back(v);
            ans[v].push_back(u);
        }
        bfs(1, ans, n);
    }
    return 0;
}