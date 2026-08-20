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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>ans1;
        ListNode* temp=list1;
        while(temp)
        {
            ans1.push_back(temp->val);
            temp=temp->next;
        }
        temp=list2;
        while(temp)
        {
            ans1.push_back(temp->val);
            temp=temp->next;
        }
        if(ans1.empty())
            return nullptr;
        sort(ans1.begin(),ans1.end());
        ListNode* k=new ListNode(ans1[0]);
        ListNode*tail=k;
        for(int i=1;i<ans1.size();i++)
        { 
            ListNode* temp=new ListNode(ans1[i]);
           tail->next=temp;
           tail=temp;
        }
        return k;

        
        
    }
};


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(!list1) return list2;
//         if(!list2) return list1;

//         // Make sure list1 always starts with the smaller value
//         if(list1->val > list2->val) {
//             ListNode* temp = list1;
//             list1 = list2;
//             list2 = temp;
//         }

//         // Declare variables BEFORE using them
//         ListNode* curr1 = list1;
//         ListNode* curr2 = list2;
//         ListNode* next1 = curr1->next;
//         ListNode* next2 = nullptr;
        
//         // If list1 only has one node, just point it to list2
//         if(!next1) {
//             curr1->next = curr2;
//             return list1;
//         }
        
//         while(next1 && curr2) {
//             // Changed < to <= to handle duplicate numbers
//             if(curr2->val >= curr1->val && curr2->val <= next1->val) {
//                 curr1->next = curr2;
//                 next2 = curr2->next;
//                 curr2->next = next1;
                
//                 curr1 = curr2;
//                 curr2 = next2;
//             }
//             else {
//                 curr1 = next1;
//                 next1 = next1->next;
                
//                 if(next1 == nullptr) {
//                     curr1->next = curr2;
//                     return list1;
//                 }
//             }
//         }
//         return list1;
//     }
// };