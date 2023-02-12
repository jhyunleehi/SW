#include<stdio.h>
#include<malloc.h>

#define MINX 1
#define MINY 1
#define MAXX 1000
#define MAXY 1000

typedef struct node *pnode;
typedef struct node{
    int y,x,s;
    pnode next;
};
int qlen;
pnode qhead=NULL;
pnode qtail=NULL;

char visit[MAXY+1][MAXX+1];
int By,Bx,Dy,Dx,Jy,Jx;

void enque(int y,int x, int s){
    struct node *temp =(pnode)malloc(sizeof(struct node));
    temp->y=y, temp->x=x, temp->s=s;
    if (qlen<=0) qhead=qtail=temp;
    else {
        qtail->next=temp;
        qtail=temp;
    }
    qlen++;
}

void dequeue(){
    if (qlen<=0) return;
    struct node* temp=qhead;
    qhead=qhead->next;
    free(temp);
    qlen--;
}

int bfs_bessie(int y, int x){
    int dx[8]={-1,0,1,-1,1,-1,0,1};
    int dy[8]={-1,-1,-1,0,0,1,1,1};
    visit[y][x]=1;
    enque(y,x,0);
    while(qlen>0){
        int ny,nx,s;
        y=qhead->y;x=qhead->x;s=qhead->s;        
        if (y==Jy && x==Jx){
            return s;
        }
        dequeue();
        for (int i=0; i<8; i++){
            ny=y+dy[i]; nx=x+dx[i];
            if (ny<MINY || ny>MAXY || nx<MINX||nx>MAXX)continue;
            if (visit[ny][nx]==0){
                visit[ny][nx]=1;
                enque(ny,nx,s+1);
            }
        }
    }
}

int bfs_daisy(int y, int x){
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    visit[y][x]=1;
    enque(y,x,0);
    while(qlen>0){
        int ny,nx,s;
        y=qhead->y;x=qhead->x;s=qhead->s;        
        if (y==Jy && x==Jx){
            return s;
        }
        dequeue();
        for (int i=0; i<4; i++){
            ny=y+dy[i]; nx=x+dx[i];
            if (ny<MINY || ny>MAXY || nx<MINX||nx>MAXX)continue;
            if (visit[ny][nx]==0){
                visit[ny][nx]=1;
                enque(ny,nx,s+1);
            }
        }
    }
}

int main(){
    freopen("data.txt","r",stdin);
    scanf("%d %d", &By,&Bx);
    scanf("%d %d", &Dy,&Dx);
    scanf("%d %d", &Jy,&Jx);
    qlen=0;qhead=NULL;qtail=NULL;
    int bans=bfs_bessie(By,Bx);
    while (qlen) dequeue();
    for (int y=1; y<=MAXY;y++ ) for (int x=1; x<MAXX; x++) visit[y][x]=0;
    qlen=0;qhead=NULL;qtail=NULL;
    int dans=bfs_daisy(Dy,Dx);
    if (bans<dans) printf("bessie");
    else if (bans>dans) printf("daisy");
    else printf("tie");
}