struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* Head = malloc(sizeof(struct ListNode));
    Head->val = 0;
    Head->next = NULL;
    
    struct ListNode* current = Head;
    int carry = 0;
    
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int x = (l1 != NULL) ? l1->val : 0;
        int y = (l2 != NULL) ? l2->val : 0;
        int sum = x + y + carry;
        
        carry = sum / 10;
        
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = sum % 10;
        current->next->next = NULL;
        
        current = current->next;
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    struct ListNode* result = Head->next;
    free(Head); 
    return result;
}
