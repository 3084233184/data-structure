//代码如下
// 新作业一.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//#include "pch.h"
#include <stdio.h>
#include<stdlib.h>
#include<windows.h>

struct LinkList
{
	int Keyword;
	int ID;
	LinkList *next;
};

LinkList *Head, *Last;//定义两个全局指针变量头结点和尾结点 
LinkList *CreatLinkList(int n)//建立链表
{

	LinkList *NewNode, *L;
	int keyword;
	L = (LinkList *)malloc(sizeof(LinkList));
	Head= L;
	for (int i = 1; i <= n; i++)
	{
		NewNode = (LinkList *)malloc(sizeof(LinkList));
		printf("请输入%d号的密码：", i);
		scanf("%d", &keyword);
		NewNode->Keyword = keyword;
		NewNode->ID = i;
		L->next = NewNode;
		L = NewNode;
	}
	Last = L;
	Last->next = Head->next;
	return Last; 
}
int NodeDelete(LinkList *Front_Node)//删除结点
{
	LinkList *p,*s;
	LinkList *L;
	int Keyword;
	int ID;
	L = Front_Node->next;
	p = Head->next;
	if (L == p)
	{
		p = L->next;//把当前第一个结点的下一个结点作为新的第一个结点
		Last->next = p;//让尾结点指向新的第一个结点

	}

	else
	{
		if(L==Last) {Last=Front_Node;}
		Front_Node->next = L->next;
	}
	Keyword = L->Keyword;
	ID = L->ID;
	printf("报数中");
	Sleep(200);
	for(int j=0;j<3;j++)
	{
		Sleep(300);
		printf(".");
	}
	printf("\n");
	printf("玩家%d被淘汰，密码为%d！\n",ID,Keyword);
	free(L);
	return Keyword;
} 
static int j=0;
void Game(LinkList *P,int Keyword,int PlayerNumber)
{
	LinkList *L,*Front_Node,*NewP;
	L=P;
	

	for (int i = 0; i < Keyword; i++)
	{
		Front_Node=L;
		L = L->next;
	}
	j++;
	if(j==PlayerNumber) return;
	Keyword=NodeDelete(Front_Node);
	NewP= Front_Node;

	Game(NewP,Keyword,PlayerNumber);
}

void Disp(int PlayerNumber)
{
	LinkList *p;
	p=Head->next;
		printf("\n\n");
		printf("你输入的数据为：\n"); 
	for(int i=0;i<PlayerNumber;i++)
	{
		printf("第%d个人的密码是：%d\n",p->ID,p->Keyword);
		p=p->next;
	}
		printf("\n\n");
}
int main()
{
	int PlayerNumber;
	int Fist_Keyword;
	LinkList *P;

	printf("请输入玩游戏的人数：");
	scanf("%d",&PlayerNumber);	
	P=CreatLinkList(PlayerNumber);
	printf("请输入初始密码：");
	scanf("%d",&Fist_Keyword);//输入数据建立单链表 
	system("cls");
	
	
	Disp(PlayerNumber);//显示输入的数据 
	Game(P,Fist_Keyword,PlayerNumber);
	printf("\n玩家%d胜出！",Last->next->ID);
	return 0;
}
