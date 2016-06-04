#ifndef SeqList_H
#define SeqList_H

#define MAXSIZE 20

//线性表相关操作

typedef int ElemType;

//存储方式--线性（静态数组）
typedef struct {
    ElemType a[MAXSIZE+1];
    int len;
} SeqList;

void InitList(SeqList **ppList);   //初始化线性表
int ListFull(SeqList *pList);    //判表满
int ListEmpty(SeqList *pList);  //判表空
void Error(char *msg);  //打印警告语
int InsertElem(SeqList *pList, int i, ElemType elm);    //插入表元素
int DelElem(SeqList *pList, int i, ElemType *backup);   //删除表元素

#endif // SeqList_H
