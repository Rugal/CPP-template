#define ERROR -1
#define STDLEN 1
#include<malloc.h>
#include"LinkedList.h"
struct _Node
{
	Node* previous;
	Node* posture;
	type data;
};
struct _LinkedList
{
	LinkedList* head;
	LinkedList* tail;
	int size;
};

int increaseSize(LinkedList* list)
{
	if(isEmptyLinkedList(list))
	{
		return ERROR;
	}
	list->size+=STDLEN;
	return list->size;
}

int decreaseSize(LinkedList* list)
{
	if(isEmptyLinkedList(list))
	{
		return ERROR;
	}
	list->size-=STDLEN;
	return list->size;
}

Node* createNode(type data)
{
	Node* node=NULL;
	node=(Node*)malloc(sizeof(Node));
	node->previou=node->posture=NULL;
	node->data=data;
	return node;
}

LinkedList* createLinkedList()
{
	LinkedList* list=NULL;
	list=(LinkedList*)malloc(sizeof(LinkedList));
	list->head=list->tail=NULL;
	list->size=0;
	return  list;
}

int isEmptyLinkedList(LinkedList* list)
{
	if(0==list->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
Node* clearNode(Node* node)
{
	node->data=0;
	node->previou=node->posture=NULL;
	return node;
}
LinkedList* clearLinkedList(LinkedList* list)
{
	while(!isEmptyLinkedList(list))
	{
		popHead(list);
	}
	return list;
}

int getSize(LinkedList* list)
{
	return list->size;
}

LinkedList* copyLinkedList(LinkedList* to,LinkedList* from)
{
	Node* current=NULL;
	for(current=from->head;NULL!=current;current=current->posture)
	{
		pushHead(to,current->data);
	}
}

void pushHead(LinkedList* list,type data)
{
	Node* node=createNode(data);
	if(isEmptyLinkedList(list))
	{
		list->head=list->tail=node;
	}
	else
	{
		Node* oldhead=list->head;
		node->posture=oldhead;
		oldhead->previou=node;
		list->head=node;
	}
	increaseSize(list);
}

void pushTail(LinkedList* list,type data)
{
	Node* node=createNode(data);
	if(isEmptyLinkedList(list))
	{
		list->head=list->tail=node;
	}
	else
	{
		Node* oldtail=list->tail;
		node->previou=oldtail;
		oldtail->posture=node;
		list->tail=node;
	}
	increaseSize(list);
}

void popHead(LinkedList* list)
{
	if(!isEmptyLinkedList(list))
	{
		Node* node=list->head;
		list->head=node->posture;
		decreaseSize(list);
		destroyNode(node);
		if(isEmptyLinkedList(list))
		{
			list->head=list->tail=NULL;
		}
	}
}

void popTail(LinkedList* list)
{
	if(!isEmptyLinkedList(list))
	{
		Node* node=list->tail;
		list->tail=node->previou;
		decreaseSize(list);
		destroyNode(node);
		if(isEmptyLinkedList(list))
		{
			list->head=list->tail=NULL;
		}
	}
}

Node* getHead(LinkedList* list)
{
	return list->head;
}

Node* getTail(LinkedList* list)
{
	return list->tail;
}

void destroyNode(Node* node)
{
	node->previou=node->posture=NULL;
	free(node);
	node=NULL;
}

void destroyLinkedList(LinkedList* list)
{
	clearLinkedList(list);
	free(list);
}

Node* getNodeFromHead(LinkedList* list,int position)
{
	Node* node=NULL;
	if(position<=list->size&&position>0)
	{
		int count=1;
		for(node=list->head;count<position;count++,node=node->posture);
	}
	return node;
}
Node* getNodeFromTail(LinkedList* list,int position)
{
	Node* node=NULL;

		int count=list->size;
		for(node=list->tail;count>position;count--,node=node->previou);
	return node;
}

Node* insertNode(LinkedList* list,Node* position,type data)
{
	if(isEmptyLinkedList(list))
	{
		pushTail(list,data);
		return getTail(list);
	}
	else
	{
		if(1==isContain(list,position))
		{
			if(isHead(list,position))
			{
				pushHead(list,data);
				return getHead(list);
			}
			if(isTail(list,position))
			{
				pushTail(list,data);
				return getTail(list);
			}
			Node* before=position->previou;
			Node* node=createNode(data);
			node->previou=before;
			node->posture=position;
			before->posture=node;
			position->previou=node;
			increaseSize(list);
			return node;
		}
		else
		{
			return NULL;
		}
	}

}
int isContain(LinkedList* list,Node* node)
{
	if(NULL==list||NULL==node)
	{
		return 0;
	}
	if(isEmptyLinkedList(list))
	{
		return 0;
	}
	Node* cur=NULL;;
	for(cur=getHead(list);cur!=NULL;cur=cur->posture)
	{
		if(cur==node)
		{
			return 1;
		}
	}
	return 0;
}

int isHead(LinkedList* list ,Node* node)
{
	if(isEmptyLinkedList(list))
	{
		return 0;
	}
	if(NULL==node)
	{
		return 0;
	}
	if(node==getHead(list))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isTail(LinkedList* list ,Node* node)
{
	if(isEmptyLinkedList(list))
	{
		return 0;
	}
	if(NULL==node)
	{
		return 0;
	}
	if(node==getTail(list))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int  deleteNode(LinkedList* list,Node* position)
{
	if(1==isContain(list,position))
	{
		if(1==isHead(list,position))
		{
			popHead(list);
			return 1;
		}
		if(1==isTail(list,position))
		{
			popTail(list);
			return 1;
		}
		Node* before=position->previou;
		Node* after=position->posture;
		before->posture=after;
		after->previou=before;
		destroyNode(position);
		decreaseSize(list);
		return 1;
	}
	return 0;
}
