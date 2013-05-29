/*
 * =====================================================================================
 *
 *       Filename:  PrimeGenerator.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2012年10月23日 10时24分58秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Rugal Bernstein
 *   Organization:  
 *
 * =====================================================================================
 */

typedef struct PrimeGenerator PrimeGenerator;

PrimeGenerator* createPrimeGenerator(int size);
void destroyPrimeGenerator(PrimeGenerator* pg);
PrimeGenerator* execute(PrimeGenerator* pg);
void setTargetSize(PrimeGenerator* pg,int size);
