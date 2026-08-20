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
    ListNode* create(vector<int>&k)
    {
        ListNode* head=new ListNode(k[0]);
        ListNode* tail=head;
        for(int i=1;i<k.size();i++)
        {
            tail->next=new ListNode(k[i]);
            tail=tail->next;
        }
        return head;
    }

public:
    ListNode* removeNodes(ListNode* head) {
        vector<int>nums;
        ListNode* curr=head;
        while(curr)
        {
            nums.push_back(curr->val);
            curr=curr->next;
        }
        stack<int>st;
        int n=nums.size();
        vector<int>ans(n);

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&st.top()<=nums[i])
            {
                st.pop();
            }
            if(st.empty())ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums[i]);
        }
        vector<int>k;
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==-1)
            {
                k.push_back(nums[i]);
            }
        }
       ListNode* final= create(k);
       return final;
        
        
    }
};