/*
 * =====================================================================================
 *
 *       Filename:  LinkedList.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2012 07:11:47 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal bernstein
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * \file LinkedList.h
 * \brief API of struct LinkedList
 */
#include <stdlib.h>
#include "Node.h"
#include "util.h"

/** 
 * \typedef typedef struct LinkedList LinkedList
 * \brief a declaration of struct LinkedList
 */
typedef struct LinkedList LinkedList;


/**
 * \fn LinkedList* createList()
 * \brief create a LinkedList
 * \return given a LinkedList pointer
 */
LinkedList* createList();


/**
 * \fn void destroyList(LinkedList* list)
 * \brief destroy and revoke the memory of LinkedList
 * \param list the target list
 */
void destroyList(LinkedList* list);


/**
 * \fn LinkedList* clearList(LinkedList* list)
 * \brief clear a target linked list
 * \param list the target linked list
 * \return given a list pointer
 */
LinkedList* clearList(LinkedList* list);
/**
 * \fn Node* pushListHead(LinkedList* list,TYPE data)
 * \brief push a data on the head of list
 * \param list the target linked list
 * \param data the number that will be put
 * \return the Node pointer that just pushed
 */
Node* pushListHead(LinkedList* list,TYPE data);
/**
 * \fn Node* pushListTail(LinkedList* list,TYPE data)
 * \brief push a data on the tail of list
 * \param list the target linked list
 * \param data the number that will be put
 * \return a Node pointer that just pushed
 */
Node* pushListTail(LinkedList* list,TYPE data);
/**
 * \fn LinkedList* popListHead(LinkedList* list)
 * \brief pop a data from head
 * \param list the container linked list
 * \return that target list
 */
LinkedList* popListHead(LinkedList* list);
/**
 * \fn LinkedList* popListTail(LinkedList* list)
 * \brief pop a data from tail
 * \param list the container linked list
 * \return that target list
 */
LinkedList* popListTail(LinkedList* list);
/**
 * \fn Node* insertList(LinkedList* list,Node* position,TYPE data)
 * \brief insert a data into a node of a linked list
 * \param list the container list
 * \param position the location that will be inserted
 * \param data the data that will be inserted
 * \return the node that just inserted
 */
Node* insertList(LinkedList* list,Node* position,TYPE data);
/**
 * \fn void deleteListNode(LinkedList* list,Node* position)
 * \brief delete a node from a list
 * \param list the container linked list
 * \param position the node that will be deleted
 */
void deleteListNode(LinkedList* list,Node* position);


/**
 * \fn bool isEmptyList(LinkedList* list)
 * \brief judge if the list is empty(not null)
 * \param list the target  list
 * \return will be true if this list is really empty(not null);other will be false,including null list or not empty list
 */
bool isEmptyList(LinkedList* list);
/**
 * \fn bool isNullList(LinkedList* list)
 * \brief judge if the list is really null
 * \param list the target  list
 * \return will be true if this list is really null;or will be false if if not null
 */
bool isNullList(LinkedList* list);
/**
 * \fn Node* getListHead(LinkedList* list)
 * \brief get the head node of this list
 * \param list the target  list
 * \return get the head node if not empty;but will return null if list is null or empty
 */
Node* getListHead(LinkedList* list);
/**
 * \fn Node* getListTail(LinkedList* list)
 * \brief get the tail node of this list
 * \param list the target  list
 * \return get the tail node if not empty;but will return null if list is null or empty
 */
Node* getListTail(LinkedList* list);
/**
 * \fn Node* getListNextNode(Node* node)
 * \brief get the next node of this node
 * \param node the target node
 * \return the node pointer
 */
Node* getListNextNode(Node* node);
/**
 * \fn Node* getListPrevNode(Node* node)
 * \brief get the previous node of this node
 * \param node the target node
 * \return the node pointer
 */
Node* getListPrevNode(Node* node);
/**
 * \fn Node* getListNode(LinkedList* list,int position)
 * \brief get the node at this position of target linked list
 * \param list the target linked list
 * \param position is the location of required node
 * \return the node pointer;null if beyond the range of this list;
 */
Node* getListNode(LinkedList* list,int position);
