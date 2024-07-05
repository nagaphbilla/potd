vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = NULL;
    int pos = 0, first = -1, last = -1, min_dist = INT_MAX;
    while (curr)
    {
        pos++;
        ListNode *next = curr->next;
        if (prev && next && ((curr->val < prev->val && curr->val < next->val) || (curr->val > prev->val && curr->val > next->val)))
        {
            if (first == -1)
                first = pos;
            else
                min_dist = min(min_dist, pos - last);
            last = pos;
        }
        prev = curr;
        curr = curr->next;
    }
    if (last == -1 || last == first)
        return {-1, -1};
    return {min_dist, last - first};
}