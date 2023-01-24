class Solution {
public:
      int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis((n*n)+1,0);
        queue<pair<int,int>> q;
        q.push({1,0});
        map<int,pair<int,int>> mp;
        int k=pow(n,2);
        int cnt=1;
        int flag;
        if(n%2==0){
            flag=0;
        }
        else{
            flag=1;
        }
        for(int i=0;i<n;i++){
            if(flag==0){
                for(int j=0;j<n;j++){
                    mp[k]={i,j};
                    k--;
                }
                flag=1-flag;
            }
            else if(flag==1){
                for(int j=n-1;j>=0;j--){
                    mp[k]={i,j};
                    k--;
                }
                flag=1-flag;
            }
        }
        vis[1]=1;
        while(!q.empty()){
            int cur=q.front().first;
            int oper=q.front().second;
            q.pop();
            
            if(cur==pow(n,2)){
                return oper;
                break;
            }
                
            for(int i=1;i<=6;i++){
                int next=cur+i;
                if(next<=pow(n,2)){
                    if(board[mp[next].first][mp[next].second]==-1 && vis[next]==0){
                        vis[next]=1;
                        q.push({next,oper+1});
                    }
                    else if(board[mp[next].first][mp[next].second]!=-1){
                        next=board[mp[next].first][mp[next].second];
                        if(vis[next]==0){
                            vis[next]=1;
                            q.push({next,oper+1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};