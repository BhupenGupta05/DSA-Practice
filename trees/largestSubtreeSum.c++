// Given a binary tree. The task is to find subtree with maximum sum in the tree and return its sum.

    int maxSubtreeSum = INT_MIN;
    
    int solve(Node* root) {
        if(!root) return 0;
        
        
        int subtreeSum = root->data + 
        solve(root->left) + 
        solve(root->right);
        
        maxSubtreeSum = max(subtreeSum,maxSubtreeSum);
        return subtreeSum;
    }
    
    int findLargestSubtreeSum(Node* root) {
        // Write your code here
        solve(root);
        return maxSubtreeSum;
        
    }