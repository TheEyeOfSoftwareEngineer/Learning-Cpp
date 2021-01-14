## Leetcode 23 - 

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
```
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
```

示例 2：
```
输入：lists = []
输出：[]
```

示例 3：
```
输入：lists = [[]]
输出：[]
```

提示：
```
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
```

### C++
- 1
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        auto comp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> q(comp);

        for(ListNode* list : lists) {
            if(list) q.push(list);
        }

        while(!q.empty()) {
            cur->next = q.top();
            q.pop();
            cur = cur->next;
            if(cur->next) {
                q.push(cur->next);
            }
        }

        return dummy.next;

    }
};
```

- 2
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
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(l1 && l2) {
            if(l1->val > l2->val) {
                swap(l1, l2);
            }
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }

        cur->next = l1? l1:l2;
        return dummy.next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l > r) return nullptr;
        if(l==r) return lists[l];
        if(l+1==r) return mergeTwoLists(lists[l], lists[r]);
        int mid = l + (r-l) / 2;
        auto l1 = merge(lists, l, mid);
        auto l2 = merge(lists, mid+1, r);
        return mergeTwoLists(l1, l2);
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};
```