#include <stdio.h>
#include <stdlib.h>
int minimumMoves(int n, char grid[100][100], int sx, int sy, int gx, int gy) {
    int vis[100][100]={0}, dist[100][100];
    int qx[10000], qy[10000], f=0, r=0;
    qx[r]=sx;
     qy[r++]=sy;
    vis[sx][sy]=1;
     dist[sx][sy]=0;
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    while(f<r){
        int x=qx[f], y=qy[f++];
        if(x==gx && y==gy) return dist[x][y];
        for(int d=0; d<4; d++){
            int nx=x, ny=y;
            while(1){
                nx+=dx[d]; ny+=dy[d];
                if(nx<0||ny<0||nx>=n||ny>=n||grid[nx][ny]=='X') break;

                if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    dist[nx][ny]=dist[x][y]+1;
                    qx[r]=nx; qy[r++]=ny;     
                    }      
                  }      
                 }   
                
                }
    return -1;
}
int main(){
    int n,sx,sy,gx,gy;
    char grid[100][100];
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",grid[i]);
    scanf("%d%d%d%d",&sx,&sy,&gx,&gy);
    printf("%d", minimumMoves(n,grid,sx,sy,gx,gy));
    return 0;
}
