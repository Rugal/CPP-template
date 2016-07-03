/**
 * \file util.h
 * \brief define and include some basic&important method*macro.
 * used by all of this project
 */
#pragma once
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

/**
 * \def SWAP(a,b)
 * \brief exchange this two integer by bit-level.
 */
#define SWAP(a,b) ((a^=b);(b^=a);(a^=b);)
/**
 * \def TYPE int 
 * \brief define the general data type in this project.
 */
#define TYPE int
/**
 * \def timing(end,start)
 * \brief define a timing macro used to calculate the elapsed.
 */
#define timing(end,start) (((double)(end)-(start))/CLOCKS_PER_SEC)
/**
 * \def NUMBER 10000
 * \brief the number of generated data used to be sorted.
 */
#define NUMBER 10
/**
 * \def RAGNE 50000
 * \brief the ceil range of generated number in,started from 0.
 */
#define RANGE 60000
/**
 * \typedef typedef TYPE* (*SORTMETHOD)(TYPE* array, int length)
 * \brief defined a function pointer.
 * used in point to different sorting method
 */
typedef TYPE* (*SORTMETHOD)(TYPE* array, int length);
/**
 * \fn TYPE* generate(int number)
 * \brief A function that can generate some random number.
 * used in main.c file
 * \param number is the number of integer data that should be generated
 * \return A pointer of TYPE* type
 */
TYPE* generate(int number);
/**
 * \fn void SORT(SORTMETHOD f,TYPE* origin,int length,char* name)
 * \brief A function that used to do a sorting tast.
 * used in main.c file.
 * including data-copy,sorting,time elapse calculation,destroy the copied data.
 * \param f is a function pointer that can point to any sorting function that defined in this project.
 * \param origin is the original data pointer that supply a basic data source.Should not be influented by any sorting method.
 * \param length is the length in this array that should be sorted,started by 0.
 * \param name represent the name of this sorting method for display on stdout.
 */
void SORT(SORTMETHOD f,TYPE* origin,int length,char* name);
