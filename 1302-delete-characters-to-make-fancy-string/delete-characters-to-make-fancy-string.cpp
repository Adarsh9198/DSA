class Solution {
public:
    string makeFancyString(string s) {
        string res="";
        int count=1;
        int n=s.size();
        res.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]==res.back()){
                if(count==2) continue;
            else{
                res.push_back(s[i]);
                count++;
                }
            }
        else{
            res.push_back(s[i]);
            count=1;
        }
    }
    return res;
    }
};