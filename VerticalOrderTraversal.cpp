class Solution {
public:
    map<int,vector<pair<int,int>>> m;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    m.clear();
     vector<vector<int>> ans;
     if(!root){
         return ans;
     }
     queue<pair<TreeNode*,pair<int,int>>> q;
     q.push(make_pair(root,make_pair(0,0)));
     while(!q.empty()){
         auto node = q.front();
         int x = node.second.first;
         int y = node.second.second;
         m[x].push_back(make_pair(y,node.first->val));
         q.pop();
         if(node.first->left){
             q.push({node.first->left,{x-1,y+1}});
         }
         if(node.first->right){
             q.push({node.first->right,{x+1,y+1}});
         }
         
     }
        int index = 0;
        ans.resize(m.size());
        for(auto x : m){
            auto temp = x.second;
            sort(temp.begin(),temp.end());
            for(auto x : temp){
                ans[index].push_back(x.second);
            }
            ++index;
        }
        return ans;
    }
};
