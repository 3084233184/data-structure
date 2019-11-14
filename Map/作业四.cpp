//#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h> 
#define MAX_VERTEX_NUM 30 //最大顶点个数 

/* 图的深度优先遍历和广度优先遍历 */
//邻接表存储图
typedef struct ArcNode
{
    int adjvex;        //该弧所指向的顶点的位置 
    struct ArcNode *nextarc;   //指向下一条弧的指针 
    int *info;           //该弧相关的信息的指针，如权值 
 }ArcNode;

 typedef struct VNode
 {
    char data;     //顶点信息 
    ArcNode *firstarc;   //指向第一条依附于该顶点的弧指针 
 }VNode,AdjList[MAX_VERTEX_NUM];
 typedef struct
 {
    AdjList vertices;    
    int vexnum,arcnum;   //顶点数和弧树 
 }ALGraph;

//创建用于广度优先遍历的队列
typedef struct QNode
{
    int data;
    struct QNode *qnext;
}QNode,*PQNode;

typedef struct Queue
{
    PQNode front;
    PQNode rear;
}Queue,*PQueue;

//初始化一个空队列 
PQueue initQueue()
{
    PQueue pqueue = (PQueue)malloc(sizeof(Queue));
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if(pqnode==NULL)
    {
        printf("队列头空间申请失败！\n");
        exit(-1);
    }
    pqueue->front = pqueue->rear = pqnode;
    pqnode->qnext = NULL;
    return pqueue;
}

//队尾入队
void enQueue(PQueue pqueue,int data)
{
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if(pqnode==NULL)
    {
        printf("队列结点申请失败！\n");
        exit(-1);
    }
    pqnode->data = data;
    pqnode->qnext = NULL;
    pqueue->rear->qnext = pqnode;
    pqueue->rear = pqnode;
 } 
//判断队列是否为空
bool isEmpty(PQueue pqueue)
{
    if(pqueue->front == pqueue->rear)
        return true;
    return false;
 } 
//队头出队
int DeQueue(PQueue pqueue)
{
    if(isEmpty(pqueue))
    {
        printf("队列为空\n");
        exit(-1);
    }

    PQNode pqnode = pqueue->front->qnext;
    pqueue->front->qnext = pqnode->qnext;
    if(pqnode == pqueue->rear)
        pqueue->rear = pqueue->front;
    int data = pqnode->data;
    free(pqnode);
    return data;

}

//确定图中顶点位置编号 
int locateVex(ALGraph alg,char v)
{
    int i;
    for(i=0;i<alg.vexnum;i++)
    {
        if(alg.vertices[i].data == v)
        return i;
    }
    return -1;
 } 

//创建无向图
void createALGraph(ALGraph *alg)
{
    int i,j,v,k;
	printf("输入图的顶点数（1~30）：\n");
    scanf("%d",&(*alg).vexnum);
    if((*alg).vexnum>30) createALGraph(alg) ;
    printf("输入图的边数：");
    scanf("%d",&(*alg).arcnum); 
    printf("输入顶点名称\n");
    //fflush(stdin); 
    getchar();
    for(i = 0;i<(*alg).vexnum;i++)
    {
        printf("输入第%d个顶点名称:",i+1);
        scanf("%c",&(*alg).vertices[i].data); 
        (*alg).vertices[i].firstarc = NULL;
        // fflush(stdin);             
		//fflush(stdin)  getchar()清除上次输入的缓存 
        getchar();
    }

    printf("输入图的边信息\n");
    char v1,v2;
    ArcNode *s,*p;
    for(k = 0;k<(*alg).arcnum;k++)
    {
        printf("输入第%d条边的两个节点v1 v2：",k+1);
        scanf("%c %c",&v1,&v2);
        i = locateVex((*alg),v1);
        j = locateVex((*alg),v2);
        
        //由于是无向图因此一条边需要设置两个节点 
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->nextarc = NULL;
        if((*alg).vertices[i].firstarc==NULL)
        {
            (*alg).vertices[i].firstarc = p;
        }
        else
        {
            s = (*alg).vertices[i].firstarc;
            while(s->nextarc!=NULL)
                s = s->nextarc;
            s->nextarc = p;
        }

        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = i;
        p->nextarc = NULL;
        if((*alg).vertices[j].firstarc==NULL)
        {
            (*alg).vertices[j].firstarc = p;
        }
        else
        {
            s = (*alg).vertices[j].firstarc;
            while(s->nextarc!=NULL)
                s = s->nextarc;
            s->nextarc = p;
        }
        //fflush(stdin);
    getchar();
    } 
 } 

bool visited[MAX_VERTEX_NUM];  //标记结点是否被遍历过，否为flase,是为true;

//深度优先遍历无向图 
void DFS(ALGraph alg,int v)
{
    //从第v个顶点出发递归的深度优先遍历图alg
    ArcNode *p;
    visited[v] = true;
    printf("%c ",alg.vertices[v].data);
    for(p = alg.vertices[v].firstarc;p!=NULL;p = p->nextarc)
    {
        if(!visited[p->adjvex])
            DFS(alg,p->adjvex);
     } 
 } 

void DFSTraverse(ALGraph alg)
{
    //对邻接表存储的无向图进行深度优先遍历
    printf("深度优先遍历序列：");
    int v;
    for(v=0;v<alg.vexnum;v++)
        visited[v] = false;
    for(v=0;v<alg.vexnum;v++)
    {
        if(!visited[v])
            DFS(alg,v);
     } 
}

//广度优先遍历
void BFSTraverse(ALGraph alg)
{
    printf("广度优先遍历序列：");
    PQueue pqueue = initQueue();
    ArcNode *p;
    int i;
    int v;
    for(i=0;i<alg.vexnum;i++)
        visited[i] = false;
    for(i=0;i<alg.vexnum;i++)
    {
        if(!visited[i])
        {
            visited[i] = true;
            printf("%c ",alg.vertices[i].data);
            enQueue(pqueue,i);
            while(!isEmpty(pqueue))
            {
                v = DeQueue(pqueue);
                for(p = alg.vertices[v].firstarc;p!=NULL;p = p->nextarc)
                {
                    if(!visited[p->adjvex])
                    {
                        printf("%c ",alg.vertices[p->adjvex].data);
                        visited[p->adjvex] = true;
                        enQueue(pqueue,p->adjvex);
                    }
                }
            }
        }
    }

 } 
int main() 
{
    ALGraph alg;
    createALGraph(&alg);   //创建无向图 
    DFSTraverse(alg);
    printf("\n"); 
    BFSTraverse(alg);
    printf("\n"); 
    return 0;
}
