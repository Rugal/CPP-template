/*
 * =====================================================================================
 *
 *       Filename:  BigInt.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月24日 10时31分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein (), ryujinwrath@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct BigInt BigInt;



//BigInt* createBigInt(unsigned int size);

void destroyBigInt(BigInt* bi);

BigInt* clearBigInt(BigInt* bi);

BigInt* setLength(BigInt* bi,unsigned int size);

BigInt* setSymbol(BigInt* bi,bool symbol);

BigInt* inputBigInt(char* string);

unsigned int* outputBigInt(BigInt* bi);

void printBigInt(BigInt* bi);

BigInt* plusBigInt(BigInt* a,BigInt* b);

BigInt* minusBigInt(BigInt* a,BigInt* b);

bool isPositive(BigInt* a);
