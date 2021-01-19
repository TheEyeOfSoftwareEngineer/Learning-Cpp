## Leetcode 124 - 二叉树中的最大路径和

路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径 至少包含一个 节点，且不一定经过根节点。

路径和 是路径中各节点值的总和。

给你一个二叉树的根节点 root ，返回其 最大路径和 。

示例 1：
```
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6
```

示例 2：
```
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
```

提示：
```
树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000
```

### C++
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
private:
    int maxPathSum(TreeNode* node, int& ans) {
        if(!node) return 0;
        int l = max(0, maxPathSum(node->left, ans));
        int r = max(0, maxPathSum(node->right, ans));
        int sum = l + r + node->val;
        ans = max(ans, sum);
        return max(l, r) + node->val;
    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }
};
```