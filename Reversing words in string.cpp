class Solution {
public:
    void removeMultipleSpaces(string &s){
        string temp;
        char prev = ' ';
        for(int i = 0 ; i < s.length() ; ++i){
            if(prev == s[i] and prev == ' ')
                continue;
            else{
                temp.push_back(s[i]);
                prev = s[i];
            }
        }
        s = temp;
        if(s[s.size()-1] == ' ')
            s.pop_back();
    }
    void breakIntoWords(string &s , vector<string> &v){
        string temp;
        for(auto x : s){
            if(x == ' '){
                v.push_back(temp);
                temp.clear();
            }
            else{
                temp.push_back(x);
            }
        }
        v.push_back(temp);
    }
    string reverseWords(string s) {
        vector<string> v;
        
        removeMultipleSpaces(s);
        breakIntoWords(s,v);
        s.clear();
        reverse(v.begin(),v.end());
        for(int i = 0 ; i < v.size() ; ++i){
            s+=v[i];
            s.push_back(' ');
        }
        s.pop_back();
        return s;
        
        
    }
};
