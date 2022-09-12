class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
         sort(tokens.begin(),tokens.end());
        int tokn = 0,i=0,j=tokens.size()-1;
        while(i<=j){
            if(tokens[i] <= power)
            {
                power -= tokens[i];
                tokn++;
                i++;
            }
            else if(tokn > 0)
            { 
                if(j - i == 0)
                    break;
                power += tokens[j];
                tokn--;
                j--;
            }
            else
            {
                break;
            }
        }
        return tokn;
    }
};