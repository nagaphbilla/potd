vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<set<int>> ans(n);
    vector<int> indegree(n, 0);
    for (auto edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }
    queue<int> q1;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q1.push(i);
    }
    while (!q1.empty())
    {
        int node = q1.front();
        for (auto adj_node : adj[node])
        {
            indegree[adj_node]--;
            ans[adj_node].insert(ans[node].begin(), ans[node].end());
            ans[adj_node].insert(node);
            if (indegree[adj_node] == 0)
                q1.push(adj_node);
        }
        q1.pop();
    }
    vector<vector<int>> v1;
    for (auto s1 : ans)
    {
        vector<int> temp(s1.begin(), s1.end());
        v1.push_back(temp);
    }
    return v1;
}