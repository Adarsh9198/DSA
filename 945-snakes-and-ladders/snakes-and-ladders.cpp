class Solution {
public:
    int n;
    pair<int,int>getCoord(int num){
        int row_from_top=(num-1)/n;
        int row_from_bottom= (n-1)-row_from_top;

        int col=(num-1)%n;
        if((n%2==0 && row_from_bottom%2==0)||(n%2==1 && row_from_bottom%2==1 )){
            col=(n-1)-col;
        }
        return make_pair(row_from_bottom,col);
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        queue<int>que;
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[n-1][0]=true;
        que.push(1);
        int steps=0;
        while(!que.empty()){
            int N=que.size();
            while(N--){
                int x=que.front();
                que.pop();
                if(x==n*n) return steps;
                for(int k=1;k<=6;k++){
                    int val=x+k;
                    if(val>n*n) break;

                    pair<int,int>coord=getCoord(val);
                    int r=coord.first;
                    int c=coord.second;

                    if(visited[r][c]==true) continue;
                    visited[r][c]=true;
                    if(board[r][c]==-1){
                        que.push(val);
                    }
                    else{
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};