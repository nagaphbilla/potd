ListNode *mergeNodes(ListNode *head) {
    ListNode *new_head;
    ListNode *pointer = head;
    ListNode *prev = NULL;
    int sum = 0;
    while (pointer)
    {
        sum += pointer->val;
        if (pointer->val == 0 && sum > 0)
        {
            if (!prev)
            {
                new_head = new ListNode(sum);
                prev = new_head;
            }
            else
            {
                ListNode *new_node = new ListNode(sum);
                prev->next = new_node;
                prev = new_node;
            }
            sum = 0;
        }
        pointer = pointer->next;
    }
    return new_head;
}