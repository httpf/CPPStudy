#include <stdio.h>
#include <stdlib.h>

/*
将数据分配到有限数量的桶里，然后分别对每个桶进行charu排序，拼接每个桶中的数据得到完整的序列。

桶排序时间复杂度为O(n)
局限性：
用空间换时间
桶排序需要较大的辅助空间，一般跟被排序数列的最大值和最小值有关。
桶排序适合分布比较均匀的数列，如：1，2，4，9，6，7，3；不适合跳跃较大的数列，如：0，999，201，4。
桶排序需要维护一个链表。
*/

typedef struct Node
{
    double key;
    struct Node *next;
} Node;

typedef struct Head
{
    Node *next;
    Head(): next(NULL){}
}Head;

void destroy(Head *head)
{
    Node *p;
    while (head->next)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
}

//该算法适合0~1的小数排序。
//n为序列a的元素数量
void bucket_sort(double *a, int n)
{
    int i, j, index;

    Head *head = new Head[10];  //分配10个头节点

    Node *p, *q, *node;
    for(i=0;i < n;i++)
    {
        node = new Node;
        node->key = a[i];
        node->next = NULL;

        index = a[i]*10;

        p = q = head[index].next;  //a为0~1的小数

        if(p == NULL)
        {
            head[index].next = node;//node为该桶的第一个节点
            continue;
        }
        
        while(p)  //在桶中找到合适的位置插入当前节点
        {
            if(node->key < p->key)
                break;
            q = p;
            p = p->next;
        }
        if(p == NULL)
        {
            q->next = node;
        }
        else
        {
            node->next = p;
            q->next = node;
        }
    }

    j = 0;
    for(i = 0; i < 10; i++)  //将10个桶中的数据复制到源数组中
    {
        p = (head+i)->next;
        while(p)
        {
            a[j++] = p->key;
            p = p->next;
        }
    }

    for(i=0;i<10;i++) //销毁链表
    {
        destroy(head+i);
    }

    delete [] head;

}

int main(int argc, char* argv[])
{
	int i;

	double a[13]={0.5,0.13,0.25,0.18,0.29,0.81,0.52,0.52,0.83,0.52,0.69,0.13,0.16};

	bucket_sort(a,13);

	for(i=0;i<=12;i++)  
		printf("%-6.2f",a[i]);

	printf("\n");  

	return 0;
}
