class Solution {
public:
    struct Trie{
    // struct to store TRIE node
    char c;
    map<char, Trie*> children;
    bool isWord;
    string word;
    
    Trie(char ch){
        c = ch;
        isWord = false;
     }
};
    void DFS(Trie* root, string& ans){
        if(!root->isWord) // if not word node, no need to go deeper
            return;       
        
        if(root->isWord){ // see if longest
            ans = root->word.size() > ans.size() ? root->word : ans;
        }
        
        for(auto itr = root->children.begin() ; itr != root->children.end() ; itr++){
            DFS(itr->second, ans);
        }
        return;
        
    }
    string longestWord(vector<string>& words) {
        // create a trie
        Trie* root = new Trie('/');
        
        for(int i = 0 ; i < words.size() ; i++){
            Trie* temp = root;
            
            for(int j = 0 ; j < words[i].size(); j++){
                 if(temp->children.find(words[i][j]) == temp->children.end()){
                    temp->children[words[i][j]] = new Trie(words[i][j]);
                }
                temp = temp->children[words[i][j]];
            }
            // save word and isWord flag at end of each word
            temp->isWord = true;
            temp->word = words[i];
        }
        string ans;
        
        // perform DFS
        for(auto itr = root->children.begin() ; itr != root->children.end() ; itr++){
            DFS(itr->second, ans);
        }
        
        return ans;
    }
};
