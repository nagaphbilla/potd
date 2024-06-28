long long maximumImportance(int n, vector<vector<int>> &roads) {
    vector<int> v1(n, 0);
    for (auto road : roads)
    {
        v1[road[0]]++;
        v1[road[1]]++;
    }
    sort(v1.rbegin(), v1.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (long long)(n - i) * v1[i];
    }
    return ans;
}