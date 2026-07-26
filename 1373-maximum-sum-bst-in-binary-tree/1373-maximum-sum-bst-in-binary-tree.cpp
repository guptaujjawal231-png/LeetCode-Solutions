class Solution {
public:
    int ans = 0;

    struct Node {
        bool isBST;
        int mn, mx, sum;
    };

    Node dfs(TreeNode* root) {
        if (!root)
            return {true, INT_MAX, INT_MIN, 0};

        Node left = dfs(root->left);
        Node right = dfs(root->right);

        if (left.isBST && right.isBST &&
            left.mx < root->val &&
            root->val < right.mn) {

            int currSum = left.sum + right.sum + root->val;
            ans = max(ans, currSum);

            return {
                true,
                min(left.mn, root->val),
                max(right.mx, root->val),
                currSum
            };
        }

        return {false, 0, 0, 0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};