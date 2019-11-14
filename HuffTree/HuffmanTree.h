#ifndef  MAXSIZE
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1 
#define FALSE 0
#define MAX 32767 
#include<stdio.h>
#include"FILE.h"

//定义哈夫曼树结点类型 
struct HuffTree
{
 char Character;//该点的字符 
 int Weight;//该节点的权值 
 int Lchild;//记录左孩子结点  的数组下标 
 int Rchild;//记录右孩子结点的数组下标
 int Parent;//记录父亲结点的数组下标
};

 //定义哈夫曼编码结点类型 
struct HuffCode
{
	char code[MAX];
	int start;
};
static HuffTree Tree[MAXSIZE];
static HuffCode HCD[MAXSIZE];
// 读hfmTree文件初始化树 
int Read_Tree();

//创建树 
void Get_Data(int Data_len);

/* 循环构造 Huffman 树 */
int Creat_HuffmanTree(int Data_len);

//初始化系统 
int Initialization();

//对文字进行哈夫曼编码 
int Ecoding_Article(int Data_len);

// 对哈夫曼树进行编码 
void Ecoding(int Data_len);

//通过文件中的数据建立哈夫曼树 
int Creat_HuffmanTree_byFile(int Data_len);

//译码
void Decoding(int Data_len,int count,int Tree_len);

//打印代码文件 
void Code_Print(int count);

//打印哈夫曼树 
void Tree_Print(int LEN,int level);

//打印菜单 
void Display();

//功能选择 
void Menu();

#endif
