#include"Game.h"
#include"LinkStack.h"


Box InitGame(LinkStack *Top)
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

//寻找谜底 
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
         /*printf("出栈了！\n");
         system("pause"); */
         PopStack(Top);
         continue;
    }
    if(Map[yi][xi]==0)//如果当前坐标的值是0，将当前点进栈 
    {
        Box bi;
        bi.x=xi;bi.y=yi;bi.d=di;
        Map[yi][xi]=-1; 
       /* printf("进栈了！\n");
        system("pause");*/
        PushStack(Top,bi);
    }
    }
    return Top;
}

