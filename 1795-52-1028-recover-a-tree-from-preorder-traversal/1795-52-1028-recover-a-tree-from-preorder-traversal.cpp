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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            // Count the number of dashes to determine depth
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Extract the node's value (can be more than one digit)
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Create a new node
            TreeNode* node = new TreeNode(value);

            // If the stack size is greater than depth, pop until the stack size equals depth
            while (st.size() > depth) {
                st.pop();
            }

            // Attach the node as the left or right child of the top node in the stack
            if (!st.empty()) {
                if (!st.top()->left) {
                    st.top()->left = node;
                } else {
                    st.top()->right = node;
                }
            }

            // Push the current node onto the stack
            st.push(node);
        }

        // The root is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }
        return st.top();
    }
};
