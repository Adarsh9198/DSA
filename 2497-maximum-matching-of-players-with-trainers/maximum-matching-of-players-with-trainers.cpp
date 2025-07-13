class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int res=0;
        for(int i=0;i<players.size();i++){
            for(int j=i;j<trainers.size();j++){
                if(players[i]<=trainers[j]){
                    res++;
                    trainers[j]=INT_MIN;//ek player ko assign ho gya
                    break;
                }
            }
        }
        return res;
    }
};