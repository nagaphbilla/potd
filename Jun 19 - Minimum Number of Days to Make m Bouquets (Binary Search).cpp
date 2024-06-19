int check(vector<int> &bloomDay, int day, int k) {
    int count = 0, ans = 0;
    for (auto flower : bloomDay)
    {
        if (flower <= day)
            count++;
        else
            count = 0;
        if (count == k)
        {
            ans++;
            count = 0;
        }
    }
    return ans;
}

int minDays(vector<int> &bloomDay, int m, int k) {
    int start = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (check(bloomDay, mid, k) >= m)
        {
            end = mid - 1;
            ans = mid;
        }
        else
            start = mid + 1;
    }
    return ans;
}