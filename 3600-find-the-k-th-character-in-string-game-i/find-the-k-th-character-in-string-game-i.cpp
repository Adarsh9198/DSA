class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            string s="";
            for(char ch:word){
                s+=(ch=='z')? 'a':ch+1;
            }
            word+=s;
        }
        return word[k-1];
    }
};