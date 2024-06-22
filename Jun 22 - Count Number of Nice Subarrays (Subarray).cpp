int numberOfSubarrays(vector<int> &nums, int k) {
    int count = 0, ans = 0;
    map<int, int> m1;
    for (auto num : nums)
    {
        if (num % 2)
            count++;
        if (count == k)
            ans++;
        ans += m1[count - k];
        m1[count]++;
    }
    return ans;
}