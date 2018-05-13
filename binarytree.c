#include <unistd.h>
#include<string.h>
#include "binarytree.h"
#include "seqqueue.h"
#include "seqqueue.c"
#include "seqstack.c"
#include "seqstack.h"

void treenode_Init(treenode **root)
{
    if(root == NULL)
    {
        return;
    }
    *root = NULL;
    return;
}

treenode* treenode_creatnode(treenodetype value)
{

    treenode *newnode = (treenode *)malloc(sizeof(treenode));
    newnode->data = value;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}
void treenode_PreOrder(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    printf("[%c] ",root->data);
    treenode_PreOrder(root->lchild);
    treenode_PreOrder(root->rchild);
}

void treenode_InOrder(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    treenode_InOrder(root->lchild);
    printf("[%c] ",root->data);
    treenode_InOrder(root->rchild);
}

void treenode_PostOrder(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    treenode_PostOrder(root->lchild);
    treenode_PostOrder(root->rchild);
    printf("[%c] ",root->data);
    
}

void treenode_LevelOrder(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    seqqueue queue;
    seqqueue_init(&queue);
    seqqueue_push(&queue,root);
    while(1)
    {
        seqqueuetype top;
        int ret = seqqueue_gettop(&queue,&top);
        //printf("top data is %c, top lchild %p,queue size is %lu\n",top->data, top->lchild,queue.size); 

        if(ret == 0)
        {
            break;
        }
        printf("[%c] ",top->data);
        seqqueue_pop(&queue);
        if(top->lchild != NULL)
        {
            seqqueue_push(&queue,top->lchild);
        }
        if(top->rchild != NULL)
        {
            seqqueue_push(&queue,top->rchild);
        }
    }
}

treenode *_treecreat(treenodetype data[],size_t size,size_t *index,treenodetype null_node)
{
    if(index == NULL)
    {
        return NULL;//非法输入
    }
    if((*index) >= size)
    {
        return NULL;//遍历完了
    }
    if(data[*index] == null_node)
    {
        return NULL;//返回空树
    }
    treenode *newnode = treenode_creatnode(data[*index]);
    ++(*index);
    newnode->lchild = _treecreat(data,size,index,null_node);
    ++(*index);
    newnode->rchild = _treecreat(data,size,index,null_node);
    return newnode; 

}
treenode *treecreat(treenodetype data[],size_t size,treenodetype null_node)
{
    size_t index;
    treenode *newnode = _treecreat(data,size,&index,null_node);
    return newnode;

}

treenode *treenode_clone(treenode *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    treenode *newnode = treenode_creatnode(root->data);
    newnode->lchild = treenode_clone(root->lchild);
    newnode->rchild = treenode_clone(root->rchild);
    return newnode;

}

size_t treeleafsize(treenode *root) 
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    return treeleafsize(root->lchild) + treeleafsize(root->rchild);
}
size_t treeKlevelsize(treenode *root,int k)
{
    if(root == NULL)
    {
        return 0;
    }
    if(k == 1)
    {
        return 1;
    }
    return treeKlevelsize(root->lchild,k-1) + treeKlevelsize(root->rchild,k-1);
}
size_t treehight(treenode *root)
{
    if(root == NULL)
    {
        return 0;
    }
    size_t rhight = treehight(root->rchild);
    size_t lhight = treehight(root->lchild);
    return 1+(rhight > lhight ? rhight : lhight);
}
treenode *treefind(treenode *root,treenodetype value)
{
    if(root == NULL)
    {
        return;
    }
    seqqueue queue;
    seqqueuetype front;
    seqqueue_init(&queue);
    seqqueue_push(&queue,front);
    while(1)
    {
        seqqueue_gettop(&queue,&front);
        if(front->data = value)
        {
            return front;
        }
        if(front->lchild != NULL)
        {
            seqqueue_push(&queue,front->lchild);
        }
        if(front->rchild != NULL)
        {
            seqqueue_push(&queue,front->rchild);
        }
        seqqueue_pop(&queue);
    }
}
void PreOrderByLoop(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    seqstack s;
    treenode *top; 
    treenode *cur = root;
    seqstack_init(&s);
    while(s.size != 0 || cur != NULL)
    {
        while(cur != NULL)
        {
            printf("%c ",cur->data);
            seqstack_pushback(&s,cur);
            cur = cur->lchild;
        }
        seqstack_gettop(&s,&top);
        seqstack_popback(&s);
        cur = top->rchild;
    }
}
void InOrderByLoop(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    seqstack s;
    treenode *cur = root;
    treenode *top;
    seqstack_init(&s);    
    while(s.size != 0 || cur != NULL)
    {
        while(cur != NULL)
        {
            seqstack_pushback(&s,cur);
            cur = cur->lchild;
        }
        seqstack_gettop(&s,&top);
        printf("%c ",top->data);
        seqstack_popback(&s);
        cur = top->rchild;
    }
}
void PostOrderByLoop(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    seqstack s;
    treenode *cur = root;
    treenode *top;
    treenode *prev = NULL;
    seqstack_init(&s);
    while(s.size != 0 || cur != NULL)
    {
        while(cur != NULL)
        {
            seqstack_pushback(&s,cur);
            cur = cur->lchild;
        }
        seqstack_gettop(&s,&top);
        if(top->rchild == NULL || top->rchild == prev)
        {
            printf("%c ",top->data);
            prev = top;
            seqstack_popback(&s);
        }
        else
        {
            cur = top->rchild;
        }
    }
}
void swap(treenode **a,treenode **b)
{
    treenode *t = *a;
    *a = *b;
    *b = t;
}
void TreeMirror(treenode *root)
{
    if(root == NULL)
    {
        return;
    }
    swap(&root->lchild,&root->rchild);
    if(root->lchild != NULL)
    {
        TreeMirror(root->lchild);
    }
    if(root->rchild != NULL)
    {
        TreeMirror(root->rchild);
    }
}







///////////////////////
//测试
//////////////////////
void test_PreOrder()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_PreOrder(a);
    printf("\n");

}

void test_InOrder()
{

    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_InOrder(a);
    printf("\n");
}

void test_PostOrder()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_PostOrder(a);
    printf("\n");

}

void test_LevelOrder()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_LevelOrder(a);
    printf("\n");


}
void test_creat()
{
    HEADER;
    treenodetype data[] = "abd##eg###c#f##";
    treenode *root = treecreat(data,strlen(data),'#');
    printf("先序");
    treenode_PreOrder(root);
    printf("\n");

    printf("中序");
    treenode_InOrder(root);
    printf("\n");
    
    printf("后序");
    treenode_PostOrder(root);
    printf("\n");

    printf("层序");
    treenode_LevelOrder(root);
    printf("\n");
}
void test_clone()
{

    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode *newnode = treenode_clone(a);
    printf("先序");
    treenode_PreOrder(newnode);
    printf("\n");

    printf("中序");
    treenode_InOrder(newnode);
    printf("\n");
    
    printf("后序");
    treenode_PostOrder(newnode);
    printf("\n");

    printf("层序");
    treenode_LevelOrder(newnode);
    printf("\n");

}
void test_treeleafsize()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    printf("%d\n",treeleafsize(a));

}
void test_treeKlevelsize()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    printf("%d\n",treeKlevelsize(a,3));

}
void test_treefind()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode *ret = treefind(a,'c');
    printf("%c\n",ret->data);

}
void test_PreOrderByLoop()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_PreOrder(a);
    printf("\n");
    PreOrderByLoop(a);
    printf("\n");

}
void test_InOrderByLoop()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_InOrder(a);
    printf("\n");
    InOrderByLoop(a);
    printf("\n");

}
void test_PostOrderByLoop()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    e->lchild = g;
    c->rchild = f;
    treenode_PostOrder(a);
    printf("\n");
    PostOrderByLoop(a);
    printf("\n");

}

void test_TreeMirror()
{
    HEADER;
    treenode *a = treenode_creatnode('a');
    treenode *b = treenode_creatnode('b');
    treenode *c = treenode_creatnode('c');
    treenode *d = treenode_creatnode('d');
    treenode *e = treenode_creatnode('e');
    treenode *f = treenode_creatnode('f');
    treenode *g = treenode_creatnode('g');
    a->lchild = b;
    a->rchild = c;
    b->lchild = d;
    b->rchild = e;
    c->lchild = f;
    c->rchild = g;
    treenode_PreOrder(a);
    printf("\n");
    treenode_InOrder(a);
    printf("\n");
    treenode_PostOrder(a);
    printf("\n");
    TreeMirror(a);
    treenode_PreOrder(a);
    printf("\n");
    treenode_InOrder(a);
    printf("\n");
    treenode_PostOrder(a);
    printf("\n");

}

int main()
{
    test_PreOrder();
    test_InOrder();
    test_PostOrder();
    test_LevelOrder();
    test_creat();
    test_clone();
    test_treeleafsize();
    test_treeKlevelsize();
    test_treefind();
    test_PreOrderByLoop();
    test_InOrderByLoop();
    test_PostOrderByLoop();
    test_TreeMirror();
    return;
}


