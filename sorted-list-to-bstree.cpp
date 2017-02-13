//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        int n  = 1;
        ListNode* cur = head;
        while(cur->next != NULL) {
            cur = cur->next;
            n++;
        }
        cout << n << endl;
        return createBST(&head, n);
    }
    
    TreeNode* createBST(ListNode **head, int n) {
        if (n < 1) {
            return NULL;
        }
        
        TreeNode *left = createBST(head, n/2 );
        TreeNode *node = new TreeNode((*head)->val);
        node->left = left;
        
        *head = (*head)->next;
        node->right = createBST(head, n - n/2 - 1 );
        return node;
    }
};
