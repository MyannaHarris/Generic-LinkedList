/**
 * @file mainC.h
 * @author Myanna Harris
 * @date 12-10-14
 *
 * Main driver for testing purposes
 */

#include <iostream>

#include "LinkedLst.h"
#include "LinkedLstDbl.h"

using namespace std;

int main()
{
 cout << "" << endl;
 cout << "Make linked lists" << endl;
 LinkedLst<int>* LL1 = new LinkedLst<int>();
 LinkedLstDbl<int>* LLDbl1 = new LinkedLstDbl<int>();

 return 0;
}
