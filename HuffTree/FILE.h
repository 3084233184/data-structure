#ifndef STATUS 
#define STATUS 1
#include<stdio.h> 
#include<stdlib.h>
#include"HuffmanTree.h"

//дhfmTree�ļ�
bool Write_Tree(int Data_len);

//дCodeFile�ļ� 
bool Write_Code(char Code[],int count);

//дTextFile�ļ�
bool Write_Trans(char Translation[],int T);

//дCodePrin�ļ� 
bool Write_Print(char Code[],int count);

//��CodeFile�ļ� 
bool Read_Code(char Code[],int count);

// ��hfmTree�ļ���ʼ���� 
int Read_Tree();

//ͨ���ļ����ݽ����� 
bool CreatTreeBYFile(int &Data_len,int &Tree_len);
#endif
