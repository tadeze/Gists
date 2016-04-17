/*
 * factorial.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: tadeze
 */

#include "factorial.hpp"

int factorial(int n) {
if(n<1)
	return 1;
int result =1;
for(int i=1;i<=n;i++)
	result *=i;
	return result;
}

