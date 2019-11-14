#ifndef  MAXSIZE
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1 
#define FALSE 0
#define MAX 32767 
#include<stdio.h>
#include"FILE.h"

//������������������ 
struct HuffTree
{
 char Character;//�õ���ַ� 
 int Weight;//�ýڵ��Ȩֵ 
 int Lchild;//��¼���ӽ��  �������±� 
 int Rchild;//��¼�Һ��ӽ��������±�
 int Parent;//��¼���׽��������±�
};

 //������������������� 
struct HuffCode
{
	char code[MAX];
	int start;
};
static HuffTree Tree[MAXSIZE];
static HuffCode HCD[MAXSIZE];
// ��hfmTree�ļ���ʼ���� 
int Read_Tree();

//������ 
void Get_Data(int Data_len);

/* ѭ������ Huffman �� */
int Creat_HuffmanTree(int Data_len);

//��ʼ��ϵͳ 
int Initialization();

//�����ֽ��й��������� 
int Ecoding_Article(int Data_len);

// �Թ����������б��� 
void Ecoding(int Data_len);

//ͨ���ļ��е����ݽ����������� 
int Creat_HuffmanTree_byFile(int Data_len);

//����
void Decoding(int Data_len,int count,int Tree_len);

//��ӡ�����ļ� 
void Code_Print(int count);

//��ӡ�������� 
void Tree_Print(int LEN,int level);

//��ӡ�˵� 
void Display();

//����ѡ�� 
void Menu();

#endif
