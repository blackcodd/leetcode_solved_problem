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
class FindElements {
    private:
    //  void show (TreeNode*root){
    //     if(!root){
    //         cout<<"null"<<" ";
    //         return;
    //     }
    //     cout<<root->val<<" ";
    //     show(root->left);
    //     show(root->right);
    //  }
    private:
    void built(TreeNode*root ,unordered_map<int,int>&mp){
        if(!root->left && !root->right ) return;
        if(root->val==-1){
            root->val=0;
            mp[0]=1;
        }
        if(root->left){
            root->left->val=root->val*2+1;
            mp[root->val*2+1]=1;
            built(root->left,mp);
        }
        if(root->right){
            root->right->val=root->val*2+2;
            mp[root->val*2+2]=1;
            built(root->right,mp);
        }
    }
public:
     unordered_map<int,int>mp;
    FindElements(TreeNode* root) {
      //  show(root);
        
       
        built(root,mp);
       // cout<<"after built"<<endl;
      //  show(root);
        
    }
    
    bool find(int target) {
        if(mp[target]) return true;
        else return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */