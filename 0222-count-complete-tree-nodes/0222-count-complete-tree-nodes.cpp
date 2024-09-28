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
    int left_height(TreeNode* root)
    {
        int h=0;
        while(root!=NULL)
        {
            h++;
            root=root->left;
        }
        return h;
    }

    int right_height(TreeNode* root)
    {
        int h=0;
        while(root!=NULL)
        {
            h++;
            root=root->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
      if(root==NULL)
        return 0;
      int lh=left_height(root);
      int rh=right_height(root);
      if(lh==rh) 
         return (1<<lh)-1;            // by formula 2^h - 1
      return 1+countNodes(root->left)+countNodes(root->right);     // by recursion
    }
};