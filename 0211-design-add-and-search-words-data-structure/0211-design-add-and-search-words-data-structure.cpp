struct trie
{
    trie *next[26];
    bool end;
};

class WordDictionary {
public:

    trie *head;
    WordDictionary() {
        head=new trie();
    }
    
    void addWord(string word) {
        trie *t=head;

        for(char c:word)
        {
            if(!t->next[c-'a'])
            t->next[c-'a']=new trie();

            t=t->next[c-'a'];
        }
        t->end=1;
    }

    bool search(string word,int i,int n,trie *t)
    {
        for(i;i<n;i++)
        {
            char c=word[i];
            if(c=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(t->next[j] && search(word,i+1,n,t->next[j]))
                        return 1;
                }

                return 0;
            }

            if(!t->next[c-'a'])
            return 0;

            t=t->next[c-'a'];
        }

        return t->end==1;
    }
    
    bool search(string word) {
        return search(word,0,word.length(),head);    
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */