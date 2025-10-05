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
    void fill(TreeNode* root,int sum,int targetSum,bool &answer){
        if(root==NULL) return;
        sum+=root->val;
        //check leaf node
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                answer=true;
            }
            return;
        }
        fill(root->left,sum,targetSum,answer);
        fill(root->right,sum,targetSum,answer);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool answer=false;
        fill(root,sum,targetSum,answer);
        return answer;
    }
};
