/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "X,";
        return to_string(root->val) + ',' + serialize(root->left) + serialize(root->right); 
    }
    int to_int(string s){
        stringstream geek(s);
        int val;
        geek>>val;
        return val;
    }
    // Decodes your encoded data to tree.
    queue<string> helper(string s){
        queue<string> q;
        string temp;
        for(int i=0;i<s.size();i++){
            if(s[i]==','){
                q.push(temp);
                temp.clear();
            }
            else{
                temp+=s[i];
            }
        }
        q.push(temp);
        return q;
    }
    TreeNode* deserialize(string data) {
        queue<string> q = helper(data);
        return go(q);
    }
    TreeNode* go(queue<string> &q){
        auto x = q.front();
       // cout<<"we have in q "<<x<<endl;
        q.pop();
        if(x == "X")
            return nullptr;
        TreeNode* root = new TreeNode(to_int(x));
        root->left = go(q);
        root->right = go(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
