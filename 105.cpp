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
    TreeNode* build(vector<int>& preorder, int pIndexStart, int pIndexEnd,
                    vector<int>& inorder, int iIndexStart, int iIndexEnd){
        if(pIndexStart>pIndexEnd){
            return nullptr;
        }
        int rootVal =  preorder[pIndexStart];
        int rootIndex = 0;//Index in inorder
        for(int i = iIndexStart; i <= iIndexEnd; i++){
            if(inorder[i] == rootVal) {
                rootIndex = i;
                break;
            }
        }
        
        int leftSize = rootIndex - iIndexStart;
        TreeNode * rootNew = new TreeNode(rootVal);
        rootNew->left = build(preorder, pIndexStart + 1, pIndexStart + leftSize,
                              inorder, iIndexStart, rootIndex-1);
        rootNew->right = build(preorder, pIndexStart + leftSize + 1, pIndexEnd,
                              inorder, rootIndex+1, iIndexEnd);
        return rootNew;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};
