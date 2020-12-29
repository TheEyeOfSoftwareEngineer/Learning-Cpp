## Leetcode 114 - Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:
```
    1
   / \
  2   5
 / \   \
3   4   6
```
The flattened tree should look like:
```
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
private:
    void preorder(TreeNode* node, TreeNode* &last) {
        if(!node) {
            return;
        }
        
        if(!node->left && !node->right) {
            last = node;
            return;
        }
        
        TreeNode* left = node->left;
        TreeNode* right = node->right;
        TreeNode* left_last = NULL;
        TreeNode* right_last = NULL;
        
        if(left) {
            preorder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if(right) {
            preorder(right, right_last);
            if(left_last) {
                left_last->right = right;
            }
            last = right_last;
        }
        
    }
    
public:
    void flatten(TreeNode* root) {
        TreeNode* last = NULL;
        preorder(root, last);
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* node, vector<TreeNode*> &nodeList) {
        if(!node) {
            return;
        }
        
        nodeList.push_back(node);
        preorder(node->left, nodeList);
        preorder(node->right, nodeList);
    }
    
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> nodeList;
        preorder(root, nodeList);
        for(int i = 1; i < nodeList.size(); i++) {
            nodeList[i-1]->left = NULL;
            nodeList[i-1]->right = nodeList[i];
        }
    }
};
```

### Java
#### 1
```java
class Solution {
    public void flatten(TreeNode root) {
        if(root == null) return;

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);
        while(!stack.isEmpty()){
            TreeNode curr = stack.pop();
            if(curr.right != null) stack.push(curr.right);
            if(curr.left != null) stack.push(curr.left);

            if(!stack.isEmpty()){
                curr.right = stack.peek();
            }

            curr.left = null;
        }
    }
}
```
#### 2
```java
class Solution {
    TreeNode prev = null;
    public void flatten(TreeNode root) {
        if(root == null) return;
        flatten(root.right);
        flatten(root.left);
        root.right = prev;
        root.left = null;
        prev = root;
    }
}
```
