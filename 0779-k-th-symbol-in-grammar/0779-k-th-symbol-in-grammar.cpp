class Solution {
public:
    int kthGrammar(int n, int k)
    {
         if(k<=2)
            return k-1;
        if(k%2)
            return kthGrammar(n, k/2+1);
        else
            return 1^kthGrammar(n, k/2);
    }
};