/*
 * =====================================================================================
 *
 *       Filename:  Node.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/19/2012 08:06:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
/**
 * \file Node.h
 * \brief define API about struct Node
 */
#pragma once
#include<stdbool.h>
#include"util.h"
/** 
 * \def INIT_NODE_DATA  ((TYPE)0)
 * \brief the value setup in initial node
 */
#define INIT_NODE_DATA  ((TYPE)-1)
/**
 * \typedef typedef struct Node
 * \brief Node is a basic container of data.used by local project
 */
typedef struct Node Node;

/**
 * \fn Node* createNode()
 * \brief create an node initialized with a data value
 * \return the created and initialized node pointer
 */
Node* createNode();

/**
 * \fn void clearNode(Node* node)
 * \brief clear the node's data and both pointer
 * \param node the node which will be cleared
 */
void clearNode(Node* node);
/**
 * \fn Node* setNodeData(Node* node,TYPE data)
 * \brief set the data of this node
 * \param node the node that will be set
 * \param data the data that will be install
 * \return the dealed node pointer
 */
Node* setNodeData(Node* node,TYPE data);
/**
 * \fn Node* setNodePrevious(Node* node,Node* n)
 * \brief set the previous pointer of this node
 * \param node the node that will be set
 * \param n the previous pointer that will be
 * \return the dealed node pointer
 */
Node* setNodePrevious(Node* node,Node* n);
/**
 * \fn Node* setNodePosterior(Node* node,Node* n)
 * \brief set the posterior pointer of this node
 * \param node the node that will be set
 * \param n the posterior pointer that will be
 * \return the dealed node pointer
 */
Node* setNodePosterior(Node* node,Node* n);


/**
 * \fn TYPE getNodeData(Node* node)
 * \brief get the data inside this node
 * \param node the target node
 * \return the current node pointer
 */
TYPE getNodeData(Node* node);
/**
 * \fn Node* getNodePrevious(Node* node)
 * \brief get the previous pointer of this node
 * \param node the target  node
 * \return the current node pointer
 */
Node* getNodePrevious(Node* node);
/**
 * \fn Node* getNodePosterior(Node* node)
 * \brief get the posterior pointer of this node
 * \param node the target  node
 * \return the current node pointer
 */
Node* getNodePosterior(Node* node);
/**
 * \fn bool isEmptyNodeData(Node* node);
 * \brief judge if this node's data is null
 * \param node the target  node
 * \return true if is null pointer;false if has pointer
 */
bool isEmptyNodeData(Node* node);
/**
 * \fn bool isEmptyNodePrevious(Node* node);
 * \brief judge if this node's previous pointer is null
 * \param node the target node
 * \return true if has no pointer;false if not null
 */
bool isEmptyNodePrevious(Node* node);
/**
 * \fn bool isEmptyNodePosterior(Node* node);
 * \brief judge if this node's posterior pointer is null
 * \param node the target node
 * \return true if has no pointer;false if has pointer
 */
bool isEmptyNodePosterior(Node* node);
/**
 * \fn bool isEmptyNode(Node* node);
 * \brief judge if this node itself is null
 * \param node the target node
 * \return true if has this node is null;false if not null
 */
bool isEmptyNode(Node* node);
