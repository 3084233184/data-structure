#ifndef  Maxsize
#define Maxsize 121
#include<stdio.h>
#include<stdlib.h>
static bool flag=false;//游戏状态
static int Map[11][10] = {
  	
 {0,1,2,3,4,5,6,7,8,0},
 
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
//谜底答案结构 
struct Box
{
 	int x;//横坐标
    int y;//纵坐标
    int d;	//下步方向
 }; 
 
//栈结点类型定义 
struct LinkStack
{
 	Box Data;
 	LinkStack *next;
};
//初始化栈
LinkStack *CreatLinkStack();
//进栈
LinkStack *PushStack(LinkStack *Top,Box b1);
//出栈
LinkStack *PopStack(LinkStack *Top);
//判断栈空 
bool IsEmpty(LinkStack *Top);
//输出栈
 void DispStack(LinkStack *Top);

#endif
