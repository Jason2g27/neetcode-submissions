struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool endWord = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endWord = true;
    }
    
    bool search(string word) {
        return traverse(word, 0, root);
    }

    bool traverse(string word, int x,TrieNode* root){
        for(int i = x; i < word.length(); i++){
            if(root->children.find(word[i]) == root->children.end()){
                if(word[i] == '.'){
                    for(auto& child : root->children){
                        if(traverse(word, i+1, child.second))
                            return true;
                    }
                }
                return false;
            }
            root = root->children[word[i]];
        }
        return root->endWord;
    }
};
