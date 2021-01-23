## Leetcode 230 - 二叉搜索树中第K小的元素

给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。

说明：
你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。

示例 1:
```
输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 1
```

示例 2:
```
输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 3
```

进阶：
```
如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？
```

### C++
- 1
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        dfs(root, k, ans);
        return ans;
    }

private:
    void dfs(TreeNode* node, int& k, int& ans) {
        if(!node) {
            return;
        }
        dfs(node->left, k, ans);
        k--;
        if(k==0) {
            ans = node->val;
            return;
        }
        dfs(node->right, k, ans);
    }
};
```

- 2
```c++
class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    return inorder(root, k);
  }
private:
  int inorder(TreeNode* root, int& k) {
    if (!root) return -1;
    int x = inorder(root->left, k);
    if (k == 0) return x;
    if (--k == 0) return root->val;
    return inorder(root->right, k);
  }
};
```