#include"LinkStack.h"


//��ʼ����Ϸ
//��ʼ��ջ
LinkStack *CreatLinkStack()
{
 	LinkStack *Top;
    Top=(LinkStack*)malloc(sizeof (LinkStack));
    Top->next=NULL;//����ջΪ�� 
    return Top;
}

//��ջ
LinkStack *PushStack(LinkStack *Top,Box b1)
{
 	LinkStack *Point;
 	Point=(LinkStack*)malloc(sizeof (LinkStack));
 	Point->next=Top->next;
 	Point->Data=b1;
 	Top->next=Point;
 	return Top;
}

//��ջ
LinkStack *PopStack(LinkStack *Top)
{
 	LinkStack *Point;
 	Point=Top->next;
 	Top->next=Point->next;
 	free(Point);
 	return Top;
}

//�ж�ջ�� 
bool IsEmpty(LinkStack *Top)
{
    if(Top->next==NULL) return true;
    return false;
}
//���ջ
 void DispStack(LinkStack *Top)
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
