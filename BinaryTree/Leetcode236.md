## Leetcode 236 - Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
![img1](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
```

Example 2:
![img2](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)
```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
```

Example 3:
```
Input: root = [1,2], p = 1, q = 2
Output: 1
```
Constraints:
```
The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
```

### C++
#### 1
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* node, TreeNode* target, vector<TreeNode*> &path, vector<TreeNode*> &rtn, int &finish) {
        
        if(!node || finish==1) {
            return;
        }
        
        path.push_back(node);
        if(node==target) {
            finish=1;
            rtn = path;
        }
        
        preorder(node->left, target, path, rtn, finish);
        preorder(node->right, target, path, rtn, finish);
        path.pop_back();
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path;
        vector<TreeNode*> node_p_path;
        vector<TreeNode*> node_q_path;
        int finish = 0;
        
        preorder(root, p, path, node_p_path, finish);
        path.clear();
        finish = 0;
        preorder(root, q, path, node_q_path, finish);
        
        int path_len = 0;
        if(node_p_path.size()<node_q_path.size()) {
            path_len = node_p_path.size();
        } else {
            path_len = node_q_path.size();
        }
        
        TreeNode* rtn = 0;
        for(int i = 0; i < path_len; i++) {
            if(node_p_path[i]==node_q_path[i]) {
                rtn = node_p_path[i];
            }
        }
        return rtn;
    }
};
```
#### 2
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left && right) {
            return root;
        }
        
        return left ? left : right;
    }
};
```
### Java
#### 1
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    int finish = 0;
    List<TreeNode> path;
    List<TreeNode> p_path;
    List<TreeNode> q_path;
    
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        path = new ArrayList<TreeNode>();
        p_path = new ArrayList<TreeNode>();
        q_path = new ArrayList<TreeNode>();
        
        preorder(root, p, path, p_path);
        path.clear();
        finish = 0;
        preorder(root, q, path, q_path);
        
        int path_len = 0;
        if(p_path.size()<q_path.size()) {
            path_len = p_path.size();
        } else {
            path_len = q_path.size();
        }
        TreeNode rtn = null;
        for(int i = 0; i < path_len; i++) {
            if(p_path.get(i) == q_path.get(i)) {
                rtn = p_path.get(i);
            }
        }
        
        return rtn;
    }
    
    private void preorder(TreeNode node, TreeNode target, List<TreeNode> path, List<TreeNode> result) {
        if(node==null || finish==1) {
            return;
        }
        
        path.add(node);
        if(node==target) {
            finish = 1;

            for(int i = 0; i < path.size(); i++) {
                result.add(path.get(i));
            }
            
        }
        
        preorder(node.left, target, path, result);
        preorder(node.right, target, path, result);
        
        path.remove(path.size()-1);
        
    }
}
```
#### 2
```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null  || root==p || root==q) {
            return root;
        }
        
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        
        if(left != null && right != null) {
            return root;
        }
        
        return left != null ? left : right;
    }
}
```
