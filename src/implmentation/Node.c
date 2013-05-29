#include<malloc.h>
#include<stdlib.h>
#include"Node.h"
#include"util.h"

#define NULLNODE -2
#define ISOLATED -1
#define HEAD 0
#define BODY 1
#define TAIL 2

struct Node
{
	TYPE data;
	struct Node *previous;
	struct Node *posterior;
};

bool isHeadNode(Node* node);
bool isTailNode(Node* node);
bool isBodyNode(Node* node);
bool isIsolatedNode(Node* node);
int  getPosition(Node* node);


void clearIsolatedNode(Node* node);
void clearHeadNode(Node* node);
void clearBodyNode(Node* node);
void clearTailNode(Node* node);
void freeNode(Node* node);



bool isEmptyNode(Node* node)
{
	if(node == NULL)
		return true;
	else
		return false;
}
bool isEmptyNodeData(Node* node)
{
	if(!isEmptyNode(node))
	  if(node->data==INIT_NODE_DATA)
		return true;
	return false;
}
bool isEmptyNodePrevious(Node* node)
{
	if(!isEmptyNode(node))
	  if(node->previous==NULL)
		return true;
	return false;
}
bool isEmptyNodePosterior(Node* node)
{
	if(!isEmptyNode(node))
	  if(node->posterior==NULL)
		return true;
	return false;
}
bool isHeadNode(Node* node)
{
	if(!isEmptyNode(node))
		if(isEmptyNodePrevious(node)&&!isEmptyNodePosterior(node))
		  return true;
	return false;
}
bool isTailNode(Node* node)
{
	if(!isEmptyNode(node))
		if(!isEmptyNodePrevious(node)&&isEmptyNodePosterior(node))
		  return true;
	return false;
}
bool isBodyNode(Node* node)
{
	if(!isEmptyNode(node))
		if(!isEmptyNodePrevious(node)&&!isEmptyNodePosterior(node))
		  return true;
	return false;
}
bool isIsolatedNode(Node* node)
{
	if(!isEmptyNode(node))
		if(isEmptyNodePrevious(node)&&isEmptyNodePosterior(node))
		  return true;
	return false;
}




int  getPosition(Node* node)
{
	if(!isEmptyNode(node))
	{
		if(isIsolatedNode(node))
		  return ISOLATED;
		if(isBodyNode(node))
		  return BODY;
		if(isHeadNode(node))
		  return HEAD;
		if(isTailNode(node))
		  return TAIL;
	}
	return NULLNODE;
}
TYPE getNodeData(Node* node)
{
	if(!isEmptyNode(node))
		return node->data;
	return INIT_NODE_DATA;
}
Node* getNodePrevious(Node* node)
{
	if(!isEmptyNodePrevious(node))
	  return node->previous;
	return NULL;
}
Node* getNodePosterior(Node* node)
{
	if(!isEmptyNodePosterior(node))
	  return node->posterior;
	return NULL;
}




Node* setNodeData(Node* node,TYPE data)
{
	if(isEmptyNode(node))
		node=createNode(data);
	node->data=data;
	return node;
}
Node* setNodePrevious(Node* node,Node* n)
{
	if(isEmptyNode(node))
	  node=createNode();
	node->previous=n;
	return node;
}
Node* setNodePosterior(Node* node,Node* n)
{
	if(isEmptyNode(node))
	  node=createNode();
	node->posterior=n;
	return node;
}
void freeNode(Node* node)
{
	node->previous=NULL;
	node->posterior=NULL;
	free(node);
	node=NULL;
}
void clearIsolatedNode(Node* node)
{
	freeNode(node);
}
void clearHeadNode(Node* node)
{
	Node* temp=node->posterior;
	temp->previous=NULL;
	freeNode(node);
	node=temp;
}
void clearBodyNode(Node* node)
{
	Node* prev=node->previous;
	Node* post=node->posterior;
	prev->posterior=post;
	post->previous=prev;
	freeNode(node);
	node=prev;
}
void clearTailNode(Node* node)
{
	Node* temp=node->previous;
	temp->posterior=NULL;
	freeNode(node);
	node=temp;
}
void clearNode(Node* node)
{
	if(!isEmptyNode(node))
	{
		int position=getPosition(node);
		switch(position)
		{
			case NULLNODE:break;
			case ISOLATED:clearIsolatedNode(node);break;
			case HEAD:clearHeadNode(node);break;
			case BODY:clearBodyNode(node);break;
			case TAIL:clearTailNode(node);break;
			default:break;
		}
	}
}
Node* createNode()
{
	Node* node=NULL;
	node=(Node*)malloc(sizeof(struct Node));
	node->data=INIT_NODE_DATA;
	node->posterior=NULL;
	node->previous=NULL;
	return node;
}
