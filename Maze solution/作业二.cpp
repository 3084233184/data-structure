#include<stdio.h> 
#include<stdlib.h>
#define Maxsize 121
bool flag=false;//游戏状态
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
 };//地图
struct Box
{
 	int x;//横坐标
	int y;//纵坐标
	int d;	//下步方向
};
 struct LinkStack
 {
 	Box Data;
 	LinkStack *next;
 };//
 LinkStack *CreatLinkStack()//初始化栈
 {
 	LinkStack *Top;
Top=(LinkStack*)malloc(sizeof (LinkStack));
Top->next=NULL;
return Top;
 }
 LinkStack *PushStack(LinkStack *Top,Box b1)//进栈
 {
 	LinkStack *Point;
 	Point=(LinkStack*)malloc(sizeof (LinkStack));
 	Point->next=Top->next;
 	Point->Data=b1;
 	Top->next=Point;
 	return Top;
 }
 LinkStack *PopStack(LinkStack *Top)//出栈
 {
 	LinkStack *Point;
 	Point=Top->next;
 	Top->next=Point->next;
 	free(Point);
 	return Top;
 }

 Box InitGame(LinkStack *Top)//初始化游戏
 {
 	int fx,fy,sx,sy;
 	Box sb,fb;
 	LinkStack *Point;
 	printf("请输入起点的横坐标：");
 	scanf("%d",&sx);
 	printf("请输入起点的纵坐标：");
 	scanf("%d",&sy);
 	printf("请输入终点的横坐标：");
 	scanf("%d",&fx);
 	printf("请输入终点的纵坐标：");
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
if(yi<0||xi<0)continue;//当坐标为负数，重置坐标结束当前循环进入下一循环。 
if(Map[yi][xi]==0) break;
}
if(xi==FinalPoint.x&&yi==FinalPoint.y)//如果当前坐标为迷宫的终点，结束循环 
  flag=true;//找到答案后将游戏标志置为True 
if(Map[yi][xi]!=0)//如果当前坐标的值不是0，重置。结束当前循环，进入下一循环 
{
//	if(Map[yi][xi]!=-1)
Map[yi][xi]=2;
  PopStack(Top);
continue;
}
if(Map[yi][xi]==0)//如果当前坐标的值是0，将当前点进栈 
     	{
Box bi;
bi.x=xi;bi.y=yi;bi.d=di;
Map[yi][xi]=-1; 
PushStack(Top,bi);
}
}
return Top;
}

 void DispStack(LinkStack *Top)//输出栈
 {
 	int i=0;
 	int count=0;
 	LinkStack *Point;
 	Box Path[Maxsize];
 	//Point=Top->next;
 	if(IsEmpty(Top))
 	{
 	printf("该迷宫无解！");
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
  printf("     方向：\n          0->上 1->右 2->下 3->左\n"); 
  DispStack(Top);//输出谜底 
printf("\n");
system("pause");
}
