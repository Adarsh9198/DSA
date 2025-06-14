class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string maxVal=s;
        string minVal=s;
        int n=s.length();
        char rep='/0';
        for(int i=0;i<n;i++){
            if(maxVal[i]!='9'){
                rep=maxVal[i];
                break;
            }
        }
        if(rep!='/0'){
            for(int i=0;i<n;i++){
                if(maxVal[i]==rep){
                    maxVal[i]='9';
                }
            }
        }
        char rep_min=minVal[0];
        for(int i=0;i<n;i++){
            if(minVal[i]==rep_min){
                minVal[i]='0';
            }
        }
        int min=stoi(minVal);
        int max=stoi(maxVal);
        return max-min;
    }
};