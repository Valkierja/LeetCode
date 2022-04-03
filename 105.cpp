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

 https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/1906451/simple-solution
 
 */
#include<algorithm>

class Solution {
    
public:
   
        int result = INT_MIN;
        
        int solve(TreeNode* root){    
        if ( !root ){ return 0; }
        int left =  solve(root->left);
        int right = solve(root->right);
        int LM = left + root->val;
        int MR = root->val + right;
        int LMR = left + right + root->val;
        int  compare_temp = max(max(LM,MR),max(LMR,root->val)); 
        result = max( compare_temp, result);
        return max(max(LM,MR),root->val);
        }
 
       
    
    
        int maxPathSum(TreeNode* root) {
            solve(root);
            return result;
        
    }
};