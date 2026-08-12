/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    int solve(ListNode* &head)
    {
        int ans=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ans++;
            temp=temp->next;
        }
        return ans;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        int getlen=solve(head);
        int k=getlen/2;
        ListNode* node=head;
        while(cnt<k){
            node=node->next;
            cnt++;
        }
        return node;
        
    }
};