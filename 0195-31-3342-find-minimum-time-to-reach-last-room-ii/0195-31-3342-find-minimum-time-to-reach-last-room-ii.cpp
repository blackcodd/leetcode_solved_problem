
class state{
    public:

        int x,y,w;
        state(int x,int y,int w):x(x),y(y),w(w){};
    };
class Solution{

public:
    int minTimeToReach(vector<vector<int>>& mov) {
        int n=mov.size();
        int m=mov[0].size();
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        vector<vector<int>>dis(n,vector<int>(m,9999999999));
        vector<vector<int>>vis(n,vector<int>(m,0));
        auto cmp=[](const state&a,const state&b){
         return a.w>b.w;
        };
        dis[0][0]=0;
        priority_queue<state,vector<state>,decltype(cmp) >q(cmp);
        q.push(state(0,0,0));
        while(!q.empty()){
            state  st=q.top();
            if(vis[st.x][st.y]) continue;
            vis[st.x][st.y]=1;
            if(st.x==n-1 && st.y==m-1) break;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=st.x+dx[i];
                int ny=st.y+dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m ) continue;
                int dist=max(dis[st.x][st.y],mov[nx][ny])+(st.x+st.y)%2+1;
                if(dist<dis[nx][ny]){
                    dis[nx][ny]=dist;
                    q.push(state(nx,ny,dist));
                }
            }
        }
        return dis[n-1][m-1];
        
    }
};