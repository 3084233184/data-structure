#include<stdio.h> 
#include<stdlib.h>
#define Maxsize 121
bool flag=false;//��Ϸ״̬
int Map[11][10] = {  	
 {0,1,2,3,4,5,6,7,8,9},
 
 {1,0,0,1,0,0,0,1,0,1},
 
 {2,0,0,1,0,0,0,1,0,2},
 
 {3,0,0,0,0,1,1,0,1,3},
 
 {4,0,1,1,1,0,0,1,0,4},
 
 {5,0,0,0,1,0,0,0,0,5},
 
 {6,0,1,0,0,0,1,0,1,6},
 
 {7,0,1,1,1,1,0,0,1,7},
 
 {8,1,1,0,0,0,1,0,1,8},
 
 {9,1,1,0,0,0,0,0,0,9},
 
 {0,1,2,3,4,5,6,7,8,0}
 };//��ͼ
struct Box
{
 	int x;//������
	int y;//������
	int d;	//�²�����
};
 struct LinkStack
 {
 	Box Data;
 	LinkStack *next;
 };//
 LinkStack *CreatLinkStack()//��ʼ��ջ
 {
 	LinkStack *Top;
Top=(LinkStack*)malloc(sizeof (LinkStack));
Top->next=NULL;
return Top;
 }
 LinkStack *PushStack(LinkStack *Top,Box b1)//��ջ
 {
 	LinkStack *Point;
 	Point=(LinkStack*)malloc(sizeof (LinkStack));
 	Point->next=Top->next;
 	Point->Data=b1;
 	Top->next=Point;
 	return Top;
 }
 LinkStack *PopStack(LinkStack *Top)//��ջ
 {
 	LinkStack *Point;
 	Point=Top->next;
 	Top->next=Point->next;
 	free(Point);
 	return Top;
 }

 Box InitGame(LinkStack *Top)//��ʼ����Ϸ
 {
 	int fx,fy,sx,sy;
 	Box sb,fb;
 	LinkStack *Point;
 	printf("���������ĺ����꣺");
 	scanf("%d",&sx);
 	printf("���������������꣺");
 	scanf("%d",&sy);
 	printf("�������յ�ĺ����꣺");
 	scanf("%d",&fx);
 	printf("�������յ�������꣺");
 	scanf("%d",&fy);
 	
sb.x=sx;sb.y=sy;sb.d=-1;
fb.x=fx;fb.y=fy;
PushStack(Top,sb);
return fb;
}
bool IsEmpty(LinkStack *Top)
{
if(Top->next==NULL) return true;
return false;
}
LinkStack *FindAnswer(LinkStack *Top)
{
Box FinalPoint;
LinkStack *Point;
int xi,yi;
FinalPoint=InitGame(Top);

while(!IsEmpty(Top)&&!flag)
{
int di=-1;
Point=Top->next; 

while(di<4)
{
xi=Point->Data.x;
yi=Point->Data.y;
di++;
switch(di)
{
case 0:yi=yi-1;break;
case 1:xi=xi+1;break;
case 2:yi=yi+1;break;
case 3:xi=xi-1;break;
}	
if(yi<0||xi<0)continue;//������Ϊ�������������������ǰѭ��������һѭ���� 
if(Map[yi][xi]==0) break;
}
if(xi==FinalPoint.x&&yi==FinalPoint.y)//�����ǰ����Ϊ�Թ����յ㣬����ѭ�� 
  flag=true;//�ҵ��𰸺���Ϸ��־��ΪTrue 
if(Map[yi][xi]!=0)//�����ǰ�����ֵ����0�����á�������ǰѭ����������һѭ�� 
{
//	if(Map[yi][xi]!=-1)
Map[yi][xi]=2;
  PopStack(Top);
continue;
}
if(Map[yi][xi]==0)//�����ǰ�����ֵ��0������ǰ���ջ 
     	{
Box bi;
bi.x=xi;bi.y=yi;bi.d=di;
Map[yi][xi]=-1; 
PushStack(Top,bi);
}
}
return Top;
}

 void DispStack(LinkStack *Top)//���ջ
 {
 	int i=0;
 	int count=0;
 	LinkStack *Point;
 	Box Path[Maxsize];
 	//Point=Top->next;
 	if(IsEmpty(Top))
 	{
 	printf("���Թ��޽⣡");
return;	
}
while(!IsEmpty(Top))
{
Path[i++]=Top->next->Data;
PopStack(Top);
}
while(i>=1)
{
i--;
printf("(%d,%d,%d)",Path[i].x,Path[i].y,Path[i-1].d);
count++;
if(i>=1) printf("->");
if(count%5==0) printf("\n");
}

}
int main()
{
  LinkStack *Top;
  for(int i=0;i<11;i++)
  {
  for(int j=0;j<10;j++)
  printf("%2d  ",Map[i][j]);
  printf("\n");
  }
  Top=CreatLinkStack();
  Top=FindAnswer(Top);
  printf("     ����\n          0->�� 1->�� 2->�� 3->��\n"); 
  DispStack(Top);//����յ� 
printf("\n");
system("pause");
}
