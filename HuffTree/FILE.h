#ifndef STATUS 
#define STATUS 1
#include<stdio.h> 
#include<stdlib.h>
#include"HuffmanTree.h"

//写hfmTree文件
bool Write_Tree(int Data_len);

//写CodeFile文件 
bool Write_Code(char Code[],int count);

//写TextFile文件
bool Write_Trans(char Translation[],int T);

//写CodePrin文件 
bool Write_Print(char Code[],int count);

//读CodeFile文件 
bool Read_Code(char Code[],int count);

// 读hfmTree文件初始化树 
int Read_Tree();

//通过文件内容建立树 
bool CreatTreeBYFile(int &Data_len,int &Tree_len);
#endif
