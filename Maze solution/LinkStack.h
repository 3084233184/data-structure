#ifndef  Maxsize
#define Maxsize 121
#include<stdio.h>
#include<stdlib.h>
static bool flag=false;//��Ϸ״̬
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
 };//��ͼ
//�յ״𰸽ṹ 
struct Box
{
 	int x;//������
    int y;//������
    int d;	//�²�����
 }; 
 
//ջ������Ͷ��� 
struct LinkStack
{
 	Box Data;
 	LinkStack *next;
};
//��ʼ��ջ
LinkStack *CreatLinkStack();
//��ջ
LinkStack *PushStack(LinkStack *Top,Box b1);
//��ջ
LinkStack *PopStack(LinkStack *Top);
//�ж�ջ�� 
bool IsEmpty(LinkStack *Top);
//���ջ
 void DispStack(LinkStack *Top);

#endif
