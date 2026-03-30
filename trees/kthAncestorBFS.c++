// Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
// Note:
// 1. It is guaranteed that the node exists in the tree.
// 2. All the nodes of the tree have distinct values.

// Create a mapping of each node to its parent using BFS and find the node as well.
// Then, traverse up the tree k times to find the kth ancestor using parent mapping.

class Node
{
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

int kthAncestor(Node *root, int k, int node)
{
    unordered_map<Node*, Node*> parent;
    Node *target = nullptr;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if (curr->data == node)
            target = curr;

        if (curr->left)
        {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    while (k > 0 && target)
    {
        target = parent[target];
        k--;
    }

    return target ? target->data : -1;
}