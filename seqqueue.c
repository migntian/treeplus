#include <stdio.h>
#include"seqqueue.h"

void seqqueue_init(seqqueue *seq)
{
    if(seq == NULL)
    {
        return;//非法输入
    }
    else
    {
        seq->head = 0;
        seq->tail = 0;
        seq->size = 0;
    }
}
void seqqueue_destory(seqqueue*seq)
{
    if(seq == NULL)
    {
        return;
    }
    seq->head = 0;
    seq->tail = 0;
    seq->size = 0;
    return;
}
void seqqueue_print(seqqueue *seq)
{
    if(seq == NULL)
    {
        return;
    }
    if(seq->size == 0)
    {
        return;//空顺序表
    }
    else
    {
        size_t i = seq->head;
        for(;i<seq->tail;i++)
        {
            if(i >= MAXSIZE)
            {
                i=0;
            }
            printf("[%c] ",seq->data[i]);
        }
        printf("\n");
    }
}
void seqqueue_push(seqqueue *seq,seqqueuetype value)
{
    if(seq == NULL)
    {
        return;
    }
    if(seq->size>= MAXSIZE)
    {
        return;
    }
    //if(seq->size == 0)
    //{
    //    seq->data[seq->head] = value;
    //    seq->tail++;
    //    seq->size++;
    //}
        seq->data[seq->tail++] = value;

    if(seq->tail>= MAXSIZE)
    {
        seq->tail = 0;
    }
        seq->size++;
}
void seqqueue_pop(seqqueue *seq)
{
    if(seq == NULL)
    {
        return;
    }
    if(seq->size == 0)
    {
        return;
    }
    else
    {
        seq->head++;
        //seq->tail--;
        if(seq->head>=MAXSIZE)
        {
            seq->head = 0;
        }
        seq->size--;
    }
}
int seqqueue_gettop(seqqueue *seq,seqqueuetype *value)
{
    if(seq == NULL || value == NULL)
    {
        return 0;
    }
    if(seq->size == 0)
    {
        return 0;
    }
    else
    {
        *value = seq->data[seq->head];
        return 1;
    }
}










/////////////////////
//测试函数
/////////////////////
//void test_seqpush()
//{
//    HEADER;
//    seqqueue seq;
//    seqqueue_init(&seq);
//    seqqueue_push(&seq,'a');
//    seqqueue_push(&seq,'b');
//    seqqueue_push(&seq,'c');
//    seqqueue_push(&seq,'d');
//    seqqueue_print(&seq);
//}
//
//void test_seqpop()
//{
//    HEADER;
//    seqqueue seq;
//    seqqueue_init(&seq);
//    seqqueue_push(&seq,'a');
//    seqqueue_push(&seq,'b');
//    seqqueue_push(&seq,'c');
//    seqqueue_push(&seq,'d');
//    seqqueue_pop(&seq);
//    seqqueue_print(&seq);
//    seqqueue_pop(&seq);
//    seqqueue_print(&seq);
//    seqqueue_pop(&seq);
//    seqqueue_print(&seq);
//    seqqueue_pop(&seq);
//    seqqueue_print(&seq);
//}
//
//void test_seqgettop()
//{
//    HEADER;
//    seqqueue seq;
//    seqqueue_init(&seq);
//    seqqueue_push(&seq,'a');
//    seqqueue_push(&seq,'b');
//    seqqueue_push(&seq,'c');
//    seqqueue_push(&seq,'d');
//    seqqueuetype value;
//    int ret = seqqueue_gettop(&seq,&value);
//    printf("expected ret is 1,actul ret is %d\n",ret);
//    printf("expected value is a,actul value is %c\n",value);
//}
//int main()
//{
//    test_seqpush();
//    test_seqpop();
//    test_seqgettop();
//    return 0;
//
//}







