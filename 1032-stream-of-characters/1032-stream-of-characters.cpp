class StreamChecker 
{
public:
    StreamChecker(vector<string>& words) 
    {
        root = new Trie;
        cur.reserve(100);
        for (auto& w : words) 
        {
            Trie *tmp = root;
            reverse(w.begin(), w.end());
            for (auto& c : w)
            {
                if (tmp->next[c - 'a'] == nullptr) tmp->next[c - 'a'] = new Trie;
                tmp = tmp->next[c - 'a'];
            }
            tmp->isWord = true;
        }
    }
    
    bool query(char letter)
    {
        cur += letter;
        Trie *tmp = root;
        for (auto it = cur.rbegin(); it != cur.rend(); it++) 
        {
            if (tmp->isWord) return true;
            if (!tmp->next[*it - 'a']) return false;
            tmp = tmp->next[*it - 'a'];
        }
        return tmp->isWord;
    }

private:
    struct Trie 
    {
        std::array<Trie*, 26> next = {nullptr};
        bool isWord = false;
    };
    Trie *root;
    string cur;
};


/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */