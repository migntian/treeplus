#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#define HEADER printf("\n==============%s==============\n",__FUNCTION__)
typedef char treenodetype;
typedef struct treenode{
    treenodetype data;
    struct treenode *lchild;
    struct treenode *rchild;
}treenode;
void treenode_Init(treenode **root);//初始化二叉树
void treenode_PreOrder(treenode *root);//先序遍历
void treenode_InOrder(treenode *root);//中序遍历
void treenode_PostOrder(treenode *root);//后序遍历
void treenode_LevelOrder(treenode *root);//层序遍历
treenode *_treecreat(treenodetype data[],size_t size,size_t *index,treenodetype null_node);
treenode *_treeCreat(treenodetype data[],size_t size,char null_node);
treenode * treenode_clone(treenode *root);
size_t treeleafsize(treenode *root);
size_t treeKlevelsize(treenode *root,int k);
size_t treehight(treenode *root);
treenode *treefind(treenode *root,treenodetype to_find);
void PreOrderByLoop(treenode *root);
void InOrderByLoop(treenode *root);
void PostOrderByLoop(treenode *root);
void TreeMirror(treenode *root);
int iscompletetree(treenode *root);
