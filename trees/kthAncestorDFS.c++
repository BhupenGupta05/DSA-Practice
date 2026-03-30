// Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// We can use DFS to find the node and keep track of ancestors in the recursive call stack.
// If we find the node and in left or right subtree, we decrement k and check if it becomes 0. 
// If it does, we have found the kth ancestor and we can store it in a global variable.

class TreeNode {
public:
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};

int ans = -1;

TreeNode* dfs(TreeNode* root, int& k, int node) {
    if(!root) return nullptr;
    
    if(root->data == node) return root;
    
    TreeNode* leftSubtree = dfs(root->left,k,node);
    TreeNode* rightSubtree = dfs(root->right,k,node);
    
    if(leftSubtree || rightSubtree) {
        k--;
        
        if(k == 0) {
            ans = root->data;
            return nullptr;
        }
        return root;
    }
    return nullptr;
}

int kthAncestor(TreeNode* root, int k, int node) {
    dfs(root,k,node);
    return ans;
}