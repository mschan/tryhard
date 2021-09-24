#include <ios>
#include <iostream>
#include <limits>
#include <ostream>
#include <vector>
/// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
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
    static inline ListNode* popFirst(ListNode*& l) {
        auto ret = l;
        l = l->next;
        return ret;
    }
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
        
        ListNode* resultHead = nullptr;
        if (l1->val <= l2->val) {
            resultHead = popFirst(l1);
        } else {
            resultHead = popFirst(l2);
        }
        
        auto result = resultHead;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                result->next = popFirst(l1);
            } else {
                result->next = popFirst(l2);
            }
            result = result->next;
        }
        
        if (!l1) {
            result->next = l2;
        }
        if (!l2) {
            result->next = l1;
        }
        
        return resultHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        
        size_t numLists = lists.size();
        size_t listsRemaining = numLists;
     
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }
};