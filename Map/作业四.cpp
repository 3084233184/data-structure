//#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h> 
#define MAX_VERTEX_NUM 30 //��󶥵���� 

/* ͼ��������ȱ����͹�����ȱ��� */
//�ڽӱ�洢ͼ
typedef struct ArcNode
{
    int adjvex;        //�û���ָ��Ķ����λ�� 
    struct ArcNode *nextarc;   //ָ����һ������ָ�� 
    int *info;           //�û���ص���Ϣ��ָ�룬��Ȩֵ 
 }ArcNode;

 typedef struct VNode
 {
    char data;     //������Ϣ 
    ArcNode *firstarc;   //ָ���һ�������ڸö���Ļ�ָ�� 
 }VNode,AdjList[MAX_VERTEX_NUM];
 typedef struct
 {
    AdjList vertices;    
    int vexnum,arcnum;   //�������ͻ��� 
 }ALGraph;

//�������ڹ�����ȱ����Ķ���
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

//��ʼ��һ���ն��� 
PQueue initQueue()
{
    PQueue pqueue = (PQueue)malloc(sizeof(Queue));
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if(pqnode==NULL)
    {
        printf("����ͷ�ռ�����ʧ�ܣ�\n");
        exit(-1);
    }
    pqueue->front = pqueue->rear = pqnode;
    pqnode->qnext = NULL;
    return pqueue;
}

//��β���
void enQueue(PQueue pqueue,int data)
{
    PQNode pqnode = (PQNode)malloc(sizeof(QNode));
    if(pqnode==NULL)
    {
        printf("���н������ʧ�ܣ�\n");
        exit(-1);
    }
    pqnode->data = data;
    pqnode->qnext = NULL;
    pqueue->rear->qnext = pqnode;
    pqueue->rear = pqnode;
 } 
//�ж϶����Ƿ�Ϊ��
bool isEmpty(PQueue pqueue)
{
    if(pqueue->front == pqueue->rear)
        return true;
    return false;
 } 
//��ͷ����
int DeQueue(PQueue pqueue)
{
    if(isEmpty(pqueue))
    {
        printf("����Ϊ��\n");
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

//ȷ��ͼ�ж���λ�ñ�� 
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

//��������ͼ
void createALGraph(ALGraph *alg)
{
    int i,j,v,k;
	printf("����ͼ�Ķ�������1~30����\n");
    scanf("%d",&(*alg).vexnum);
    if((*alg).vexnum>30) createALGraph(alg) ;
    printf("����ͼ�ı�����");
    scanf("%d",&(*alg).arcnum); 
    printf("���붥������\n");
    //fflush(stdin); 
    getchar();
    for(i = 0;i<(*alg).vexnum;i++)
    {
        printf("�����%d����������:",i+1);
        scanf("%c",&(*alg).vertices[i].data); 
        (*alg).vertices[i].firstarc = NULL;
        // fflush(stdin);             
		//fflush(stdin)  getchar()����ϴ�����Ļ��� 
        getchar();
    }

    printf("����ͼ�ı���Ϣ\n");
    char v1,v2;
    ArcNode *s,*p;
    for(k = 0;k<(*alg).arcnum;k++)
    {
        printf("�����%d���ߵ������ڵ�v1 v2��",k+1);
        scanf("%c %c",&v1,&v2);
        i = locateVex((*alg),v1);
        j = locateVex((*alg),v2);
        
        //����������ͼ���һ������Ҫ���������ڵ� 
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

bool visited[MAX_VERTEX_NUM];  //��ǽ���Ƿ񱻱���������Ϊflase,��Ϊtrue;

//������ȱ�������ͼ 
void DFS(ALGraph alg,int v)
{
    //�ӵ�v����������ݹ��������ȱ���ͼalg
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
    //���ڽӱ�洢������ͼ����������ȱ���
    printf("������ȱ������У�");
    int v;
    for(v=0;v<alg.vexnum;v++)
        visited[v] = false;
    for(v=0;v<alg.vexnum;v++)
    {
        if(!visited[v])
            DFS(alg,v);
     } 
}

//������ȱ���
void BFSTraverse(ALGraph alg)
{
    printf("������ȱ������У�");
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
    createALGraph(&alg);   //��������ͼ 
    DFSTraverse(alg);
    printf("\n"); 
    BFSTraverse(alg);
    printf("\n"); 
    return 0;
}
