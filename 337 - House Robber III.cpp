class Solution {
    pair<int,int> dfs(TreeNode* root){
        if(!root)
            return {0,0};
        pair<int,int> leftPair = dfs(root->left);
        pair<int,int> rightPair = dfs(root->right);
        
        int withRoot = root->val + leftPair.second + rightPair.second;
        int withoutRoot = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);
        
        return {withRoot, withoutRoot};
    }

public:
    int rob(TreeNode* root) {
        pair<int,int> res;
        res = dfs(root);
        return max(res.first,res.second);
    }
};
