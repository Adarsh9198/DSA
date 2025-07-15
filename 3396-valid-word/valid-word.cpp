class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        bool vow=false;
        bool consonant=false;
        for(int i=0;i<word.length();i++){
            if(!isalnum(word[i])) return false;//check if it is alphabet aur number
            if(isalpha(word[i])){
                char ch=tolower(word[i]);
                if(ch=='a' || ch=='e'||ch=='i'||ch=='o'|| ch=='u'){
                    vow=true;
                }
                else{
                    consonant=true;
                }
            }
        }
        return vow && consonant;
    }
};