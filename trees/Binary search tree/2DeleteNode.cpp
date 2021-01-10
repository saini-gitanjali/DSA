// problem link : https://leetcode.com/problems/delete-node-in-a-bst/
/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
*/
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
    TreeNode *findSucc(TreeNode *t){
        if(t==NULL)
            return NULL;
        while(t->left)
            t=t->left;
    return t;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(!root)
            return root;
        else if(root->val < key)
        {
           root->right = deleteNode(root->right, key);
            return root;
        }
        else if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
            return root;
        }
        else{
                if(root->left == NULL && root->right == NULL)
                {
                    delete root;
                    return NULL;
                }
            /*Node has both left and right children.
         * Find the min value in the right subtree
         * replace node value with min.
         * And again call the remove function to delete the node which has the min value.
         * Since we find the min value from the right subtree call the remove function with root->right.
         */
                if(root->left && root->right){
                    TreeNode *temp = findSucc(root->right);
                    root->val = temp->val;
                    root->right = deleteNode(root->right, temp->val);
                }
                else
                {
                    if(root->right)
                    {
                        TreeNode *temp = root->right;
                        delete root;
                        return temp;
                    }
                    else if(root->left)
                    {
                        TreeNode *temp = root->left;
                        delete root;
                        return temp;
                    }
                }
        }

        
        
        
        return root;
    }
};