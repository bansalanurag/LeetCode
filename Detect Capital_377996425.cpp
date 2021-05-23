class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size(); if(n==0) return true;
        int c=0;
        for(int i=0;i<n;i++){
            if(isupper(word[i])) c++;
        }
        if(c==0 || c==n) return true;
        if(c==1) if(isupper(word[0])) return true;
        return false;      
    }
};
