class Solution {
public:
    int count=0;
    unordered_map<long long,int>prefix;
    void dfs(TreeNode* root,long long currSum,int targetSum){
        if(root==NULL) return;
        currSum+=root->val;
        if(currSum==targetSum) count++;
        //agar pehle se woh diff exist krta hai toh
        count+=prefix[currSum-targetSum];

        prefix[currSum]++;
        dfs(root->left, currSum, targetSum);
        dfs(root->right, currSum, targetSum);
        // Backtrack: remove current prefix sum before going back up
        prefix[currSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return count;
    }
};