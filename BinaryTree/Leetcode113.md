## Leetcode 113 - Path Sum II
这个题目要注意C++和Java在语言上的不同。
> c++中容器元素都是副本。
就是说，vector中添加元素的时候，是将元素值复制到容器里。就是说容器中存放的是原始元素的副本。被复制的原始值与新容器中的元素各不相关，此后，容器内元素值发生变化时，被复制的原值不会受到影响，反之亦然。

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:
```
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
```

Return:
```
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    void preorder(TreeNode *node, int &path_value, int sum, vector<int> &path, vector<vector<int>> &rtn) {
        if(!node) {
            return;
        }
        
        path_value += node->val;
        
        path.push_back(node->val);
        
        if(!node->left && !node->right && path_value == sum) {
            rtn.push_back(path);
        }
        preorder(node->left, path_value, sum, path, rtn);
        preorder(node->right, path_value, sum, path, rtn);
        
        path_value -= node->val;
        path.pop_back();
        
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> rtn;
        vector<int> path;
        int path_value = 0;
        
        preorder(root, path_value, sum, path, rtn);
        
        return rtn;
        
        
        
    }
};
```

### Java
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    List<List<Integer>> rtn;

    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        rtn = new ArrayList<>();
        
        preorder(root,  0, sum, new ArrayList<Integer>());
        
        return rtn;
    }
    
    private void preorder(TreeNode node, int path_value, int sum, List<Integer> path) {
        
        if(node==null) {
            return;
        }
        
        path_value += node.val;
        path.add(node.val);
                
        if(node.left == null && node.right == null && path_value == sum) {
            rtn.add(new ArrayList<>(path));
        }
        
        preorder(node.left, path_value, sum, path);
        preorder(node.right, path_value, sum, path);
        
        path_value -= node.val;
        path.remove(path.size()-1);
    }
    
}
```
