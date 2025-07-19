class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>result;
        sort(folder.begin(),folder.end());
        string fold=folder[0];
        result.push_back(fold);
        for(int i=1;i<folder.size();i++){
            if(folder[i].find(fold+'/')!=0){//if not found
                fold=folder[i];
                result.push_back(fold);
            }
        }
        return result;
    }
};