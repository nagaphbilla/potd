int minIncrementForUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), ans = 0, prev = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] <= prev)
        {
            ans += prev + 1 - nums[i];
            prev++;
        }
        else
            prev = nums[i];
    }
    return ans;
}