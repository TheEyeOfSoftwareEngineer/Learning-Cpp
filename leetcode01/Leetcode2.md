## Leetcode 02 - 两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

示例 2：
```
输入：l1 = [0], l2 = [0]
输出：[0]
```
示例 3：
```
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

### C++
- 1
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra) {
            if (l1) extra += l1->val, l1 = l1->next;
            if (l2) extra += l2->val, l2 = l2->next;            
            p = p->next = new ListNode(extra % 10);
            extra /= 10;
        }
        return preHead.next;
    }
};

作者：feng-zi-53
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/c-ji-jian-dai-ma-by-feng-zi-53-zbub/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int add = 0;
        ListNode* r= NULL;
        ListNode* c = NULL;
        while(l1 && l2) {
            if(!r) {
                int value = l1->val + l2->val;
                if(value <=9) {
                    r = new ListNode(value);                    
                    add = 0;
                } else {
                    r = new ListNode(value-10);
                    add = 1;
                }
                c = r;
                l1 = l1->next;
                l2 = l2->next; 
            }
            else {
                int value = l1->val + l2->val + add;
                if(value <=9) {
                    c->next = new ListNode(value);
                    add = 0;
                } else {
                    c->next = new ListNode(value-10);
                    add = 1;
                }
                c = c->next;
                l1 = l1->next;
                l2 = l2->next;
            }  
        }
        if(!l1&!l2) {
            if(add==0)
                return r;
            else {
                c->next = new ListNode(add);
                return r;
            }

        }
        if(!l1) {
            while(l2) {
                int value = l2->val + add;

                if(value <=9) {
                    c->next = new ListNode(value);
                    add = 0;
                } else {
                    c->next = new ListNode(value-10);
                    add = 1;
                }            
                c = c->next;
                l2 = l2->next;
            }
            if(add != 0) {
                c->next = new ListNode(add);
            }            
        }
        if(!l2) {
            while(l1) {
                int value = l1->val + add;
                if(value <=9) {
                    c->next = new ListNode(value);
                    add = 0;
                } else {
                    c->next = new ListNode(value-10);
                    add = 1;
                }            
                c = c->next;
                l1 = l1->next;
            }
            if(add != 0) {
                c->next = new ListNode(add);
            }
        }
        return r;
    }
};
```
