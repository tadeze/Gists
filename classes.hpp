/*
 * classes.hpp
 *
 *  Created on: Mar 26, 2015
 *      Author: Tadeze
 */

#ifndef CLASSES_HPP_
#define CLASSES_HPP_
#include<string>
#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<vector>
using namespace std;

class Data{
public:
int ncols;
int nrows;
vector<vector<float> > data;
 Data(vector<vector<float> > dt,int ncols,int nrows);
};

 Data::Data(vector<vector<float> > dt,int ncols,int nrows)
{
this->data=dt;
this->ncols=ncols;
this->nrows=nrows;
}
class Tree {
	Tree *leftChild;
	Tree *rightChild;
	Tree *parent;
	int nodeSize;
	int splittingAtt;
	double splittingVal;
	int depth;
	Tree();
    Tree(Data data, int height,int maxHeight);
	virtual ~Tree();
};

class IsolationForest {
public:
    Tree *trees;
    Data *data;
	IsolationForest();
	virtual ~IsolationForest();
	void readData(string filename);
	void buildForest(int ntree, Data data,int maxheight);
	void AnomalyScore();
};


float c(int nodeSize){
	return NULL;
}

#endif /* CLASSES_HPP_ */
