int findCenter(vector<vector<int>> &edges) {
    map<int, int> m1;
    int count = 0, ans = 0;
    for (auto edge : edges)
    {
        m1[edge[0]]++;
        m1[edge[1]]++;
        if (m1[edge[0]] > count)
        {
            count = m1[edge[0]];
            ans = edge[0];
        }
        if (m1[edge[1]] > count)
        {
            count = m1[edge[1]];
            ans = edge[1];
        }
    }
    return ans;
}