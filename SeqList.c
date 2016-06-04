#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

//初始化线性表
void InitList(SeqList **ppList) {
    *ppList = (SeqList *)malloc(sizeof(SeqList));
    (*ppList)->len = 0;   //表长为零
}

//判表满
int ListFull(SeqList *pList) {
    return (pList->len == MAXSIZE) ? 1 : 0;
}

//判表空
int ListEmpty(SeqList *pList) {
    return (pList->len == 0) ? 1 : 0;
}

//打印警告语
void Error(char *msg) {
    printf("Error: %s\n", msg);
}

//插入表元素
int InsertElem(SeqList *pList, int i, ElemType elm) {
    if (ListFull(pList)) {
        Error("Insert element to a full list!");
        return 0;
    }
    if (i < 1 || i > pList->len + 1) {    //pList->len + 1 为表尾，超出表尾不可操作
        Error("Insert element out of range!");
        return 0;
    }
    pList->a[i] = elm;  //元素插入

    pList->len += 1;    //表长加一

    return 1;
}

//删除表元素
int DelElem(SeqList *pList, int i, ElemType *backup) {
    if (ListEmpty(pList)) {
        Error("Delete element from an empty list!");
        return 0;
    }
    if (i < 1 || i > pList->len) {
        Error("Delete element out of range!");
        return 0;
    }
    *backup = pList->a[i];  //备份被删除元素

    for (; i < pList->len; i ++)   pList->a[i] = pList->a[i+1]; //后续元素依次往前挪，补空位

    pList->len -= 1;    //表长减一

    return 1;
}
