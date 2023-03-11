// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
ListNode* findMid(ListNode* head)
    {
        ListNode* slow = head,*fast = head->next->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if(head==NULL)
        return NULL;
        if(head->next==NULL)
        return new TreeNode(head->val);
        ListNode* mid = findMid(head);
        TreeNode* root = NULL;
        if(mid!=NULL)
        {
            root = new TreeNode(mid->next->val);
            ListNode* righthalf = mid->next->next;
            mid->next=NULL;
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(righthalf);
        }
        return root;
    }
