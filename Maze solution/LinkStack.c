#include"LinkStack.h"


//初始化游戏
//初始化栈
LinkStack *CreatLinkStack()
{
 	LinkStack *Top;
    Top=(LinkStack*)malloc(sizeof (LinkStack));
    Top->next=NULL;//设置栈为空 
    return Top;
}

//进栈
LinkStack *PushStack(LinkStack *Top,Box b1)
{
 	LinkStack *Point;
 	Point=(LinkStack*)malloc(sizeof (LinkStack));
 	Point->next=Top->next;
 	Point->Data=b1;
 	Top->next=Point;
 	return Top;
}

//出栈
LinkStack *PopStack(LinkStack *Top)
{
 	LinkStack *Point;
 	Point=Top->next;
 	Top->next=Point->next;
 	free(Point);
 	return Top;
}

//判断栈空 
bool IsEmpty(LinkStack *Top)
{
    if(Top->next==NULL) return true;
    return false;
}
//输出栈
 void DispStack(LinkStack *Top)
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
