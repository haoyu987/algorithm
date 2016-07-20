// http://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
class UF
{
private:
  int *id;
  int *rank;
  int count;
  
public:
  UF(int N)
  {
    count = N;
    id = new int[N];
    rank = new int[N];
    for(int i=0;i<N;i++){
      id[i] = i;
      rank[i] = 0;
    }
  }

  ~UF
  {
    delete[] id;
    delete[] rank;
  }
  
  int find(int p) {
    while(id[p]!=p){
      id[p] = id[id[p]];
      p = id[p];
    }
    return p;
  }
  
  int getCount() {
    return count;
  }
  
  bool connected(int p,int q) {
    return find(p)==find(q);
  }
  
  void union(int p,int q) {
    int i=find(p);
    int j=find(q);
    if(i==j) return;
    if(rank[i]<rank[j]) id[i] = j;
    else if(rank[j]<rank[i]) id[j] = i;
    else{
      id[i] = j;
      rank[j]++;
    }
    
    count--;
  }
};

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if(n==0)    return;
        int m = board[0].size();
        UF uf = UF(n*m+1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0||i==n-1||j==0||j==m-1)&&board[i][j]=='O') // if a 'O' node is on the boundry, connect it to the dummy node
                    uf.connect(i*m+j,n*m);
                else if(board[i][j]=='O') // connect a 'O' node to its neighbour 'O' nodes
                {
                    if(board[i-1][j]=='O')
                        uf.connect(i*m+j,(i-1)*m+j);
                    if(board[i+1][j]=='O')
                        uf.connect(i*m+j,(i+1)*m+j);
                    if(board[i][j-1]=='O')
                        uf.connect(i*m+j,i*m+j-1);
                    if(board[i][j+1]=='O')
                        uf.connect(i*m+j,i*m+j+1);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!uf.connected(i*m+j,n*m)){ // if a 'O' node is not connected to the dummy node, it is captured
                    board[i][j]='X';
                }
            }
        }
    }
};
