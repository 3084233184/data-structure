//��������
// ����ҵһ.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

LinkList *Head, *Last;//��������ȫ��ָ�����ͷ����β��� 
LinkList *CreatLinkList(int n)//��������
{

	LinkList *NewNode, *L;
	int keyword;
	L = (LinkList *)malloc(sizeof(LinkList));
	Head= L;
	for (int i = 1; i <= n; i++)
	{
		NewNode = (LinkList *)malloc(sizeof(LinkList));
		printf("������%d�ŵ����룺", i);
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
int NodeDelete(LinkList *Front_Node)//ɾ�����
{
	LinkList *p,*s;
	LinkList *L;
	int Keyword;
	int ID;
	L = Front_Node->next;
	p = Head->next;
	if (L == p)
	{
		p = L->next;//�ѵ�ǰ��һ��������һ�������Ϊ�µĵ�һ�����
		Last->next = p;//��β���ָ���µĵ�һ�����

	}

	else
	{
		if(L==Last) {Last=Front_Node;}
		Front_Node->next = L->next;
	}
	Keyword = L->Keyword;
	ID = L->ID;
	printf("������");
	Sleep(200);
	for(int j=0;j<3;j++)
	{
		Sleep(300);
		printf(".");
	}
	printf("\n");
	printf("���%d����̭������Ϊ%d��\n",ID,Keyword);
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
		printf("�����������Ϊ��\n"); 
	for(int i=0;i<PlayerNumber;i++)
	{
		printf("��%d���˵������ǣ�%d\n",p->ID,p->Keyword);
		p=p->next;
	}
		printf("\n\n");
}
int main()
{
	int PlayerNumber;
	int Fist_Keyword;
	LinkList *P;

	printf("����������Ϸ��������");
	scanf("%d",&PlayerNumber);	
	P=CreatLinkList(PlayerNumber);
	printf("�������ʼ���룺");
	scanf("%d",&Fist_Keyword);//�������ݽ��������� 
	system("cls");
	
	
	Disp(PlayerNumber);//��ʾ��������� 
	Game(P,Fist_Keyword,PlayerNumber);
	printf("\n���%dʤ����",Last->next->ID);
	return 0;
}
