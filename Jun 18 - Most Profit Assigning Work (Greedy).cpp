int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    vector<pair<int, int>> v1;
    int n = profit.size(), m = worker.size();
    for (int i = 0; i < n; i++)
    {
        v1.push_back({profit[i], difficulty[i]});
    }
    sort(v1.rbegin(), v1.rend());
    sort(worker.begin(), worker.end());
    int end = m, ans = 0;
    for (int i = 0; i < n; i++)
    {
        int index = lower_bound(worker.begin(), worker.end(), v1[i].second) - worker.begin();
        if (index < end)
        {
            ans += (end - index) * v1[i].first;
            end = index;
        }
    }
    return ans;

    // Find maximum ability in the worker array.
    int maxAbility = *max_element(begin(worker), end(worker));
    vector<int> jobs(maxAbility + 1, 0);
    for (int i = 0; i < difficulty.size(); i++)
    {
        if (difficulty[i] <= maxAbility)
            jobs[difficulty[i]] = max(jobs[difficulty[i]], profit[i]);
    }
    // Take maxima of prefixes.
    for (int i = 1; i <= maxAbility; i++)
        jobs[i] = max(jobs[i], jobs[i - 1]);

    int netProfit = 0;
    for (auto ability : worker)
    {
        int maxProfit = jobs[ability];
        netProfit += maxProfit;
    }
    return netProfit;
}