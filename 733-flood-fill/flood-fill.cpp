class Solution {
public:
    void bfs(vector<vector<int>>& image, int sr, int sc,int c, int color){
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dirn[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto d:dirn){
                int nx=x+d[0];
                int ny=y+d[1];
                if(nx>=0 && ny>=0 && nx < n && ny < m && image[nx][ny] == c){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c=image[sr][sc];
        if(c==color) return image;
        bfs(image,sr,sc,c,color);
        return image;
    }
};