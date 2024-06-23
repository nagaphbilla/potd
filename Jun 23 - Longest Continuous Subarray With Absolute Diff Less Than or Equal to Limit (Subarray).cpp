int longestSubarray(vector<int> &nums, int limit) {
    multiset<int> s1;
    int n = nums.size();
    int i = 0, j = 0, ans = 1;
    while (j < n)
    {
        s1.insert(nums[j]);
        while (*s1.rbegin() - *s1.begin() > limit)
        {
            s1.erase(s1.find(nums[i++]));
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}