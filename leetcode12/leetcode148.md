## Leetcode 148 - 排序链表

给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

进阶：

你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 
示例 1：
```
输入：head = [4,2,1,3]
输出：[1,2,3,4]
```

示例 2：
```
输入：head = [-1,5,3,4,0]
输出：[-1,0,3,4,5]
```

示例 3：
```
输入：head = []
输出：[]
```
 
提示：
```
链表中节点的数目在范围 [0, 5 * 104] 内
-105 <= Node.val <= 105
```

### C++
- 1 top-down
```c++
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
    ListNode* sortList(ListNode* head) {        
        if(!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(mid));
    }

private:
    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l && r) {
            if(l->val > r->val) swap(l, r);
            tail->next = l;
            l = l->next;
            tail = tail->next;
        }
        if(l) tail->next = l;
        if(r) tail->next = r;
        return dummy.next;
    }
};
```

- 2 bottom-up
```c++
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
    ListNode* sortList(ListNode* head) {        
        if (!head || !head->next) return head;
    
        int len = 1;
        ListNode* cur = head;
        while (cur = cur->next) ++len;
        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* l;
        ListNode* r;
        ListNode* tail;
        for (int n = 1; n < len; n <<= 1) {      
            cur = dummy.next; // partial sorted head
            tail = &dummy;
            while (cur) {
                l = cur;
                r = split(l, n);
                cur = split(r, n);
                auto merged = merge(l, r);
                tail->next = merged.first;
                tail = merged.second;
            }
        }      
        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int n) {
        while(--n && head) {
            head = head->next;
        }
        ListNode* rest = head ? head->next : nullptr;
        if(head) head->next = nullptr;
        return rest;
    }

    pair<ListNode*, ListNode*> merge(ListNode* l, ListNode* r) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l && r) {
            if(l->val > r->val) swap(l, r);
            tail->next = l;
            l = l->next;
            tail = tail->next;
        }
        tail->next = l ? l : r;
        while(tail->next) tail = tail->next;
        return {dummy.next, tail};
    }
};
```