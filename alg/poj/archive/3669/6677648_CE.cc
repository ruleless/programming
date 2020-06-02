#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;

int M,res;

struct Node
{
    int x,y,time;
}node[50003];

int visited[500][500];

struct Node move[5]={{0,0,0},{-1,0,0},{0,-1,0},{1,0,0},{0,1,0}};

int check(int x,int y,int time)
{
    int i,j,flag=1;
    for(i=0;i<M;i++)
    {
        for(j=0;j<5;j++)
        {
            int tempx,tempy;
            tempx=node[i].x+move[j].x;
            tempy=node[i].y+move[j].y;
            if(tempx>=0&&tempy>=0)
            {
                if(time>=node[i].time)
                {
                    if(tempx==x&&tempy==y)
                    {
                        return 0;
                    }
                }
                else 
                {
                    if(tempx==x&&tempy==y)
                    {
                        flag=0;
                    }
                }
            }
        }
    }
    if(flag)
    {
        return 2;
    }
    return 1;
}

int bfs()
{  
    stack<struct Node>sta;
    memset(visited,0,sizeof(visited));
    visited[0][0]=1;
    struct Node temp;
    int x,y,time,tempx,tempy,i;
    res=0;
    if(check(0,0,0)==0)
    {
        res=-1;
        return 0;
    }
    else if(check(0,0,0)==2)
    {
        return 1;
    }
    temp.x=0;temp.y=0;temp.time=0;
    sta.push(temp);
    while(!sta.empty())
    {
        temp=sta.top();
        x=temp.x;
        y=temp.y;
        time=temp.time;
        sta.pop();
        for(i=1;i<5;i++)
        {
            tempx=x+move[i].x;
            tempy=y+move[i].y;
            if(tempx>=0&&tempy>=0&&!visited[tempx][tempy])
            {
                int m=check(tempx,tempy,time+1);
                if(m==1)
                {
                    visited[tempx][tempy]=1;
                    temp.x=tempx;
                    temp.y=tempy;
                    temp.time=time+1;
                    sta.push(temp);
                }
                else if(m==2)
                {
                    //printf("%d %d\n",tempx,tempy);
                    res=time+1;
                    return 1;
                }
            }
        }
    }
    res=-1;
    return 0;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    int i;
    scanf("%d",&M);
    for(i=0;i<M;i++)
    {
        scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].time);
    }
    bfs();
    printf("%d\n",res);
    //while(1);
  
  //system("PAUSE");	
  return 0;
}
