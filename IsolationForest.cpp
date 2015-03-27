/*
 * IsolationForest.cpp
 *
 *  Created on: Mar, 2015
 *      Author: Tadeze
 */
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cmath>
#include "classes.hpp"
using namespace std;


//build ntree forest from the data
void IsolationForest::buildForest(int ntree, Data data,int maxheight)
{

this->trees = new Tree[ntree];
for(int n=0;n<ntree;n++)
{
	//Data shuffling or randomizing operation
	//rotating data method put her
	this->trees[n] = new Tree(data, ceil(log2(data.nrows)),maxheight);

}


}

