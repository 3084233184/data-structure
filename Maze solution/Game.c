#include"Game.h"
#include"LinkStack.h"


Box InitGame(LinkStack *Top)
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

//Ѱ���յ� 
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
         /*printf("��ջ�ˣ�\n");
         system("pause"); */
         PopStack(Top);
         continue;
    }
    if(Map[yi][xi]==0)//�����ǰ�����ֵ��0������ǰ���ջ 
    {
        Box bi;
        bi.x=xi;bi.y=yi;bi.d=di;
        Map[yi][xi]=-1; 
       /* printf("��ջ�ˣ�\n");
        system("pause");*/
        PushStack(Top,bi);
    }
    }
    return Top;
}

