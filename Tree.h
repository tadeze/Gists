/*
 * Tree.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Tadeze
 */

#ifndef TREE_H_
#define TREE_H_
#include<classes.hpp>


class Tree {
	Tree *child;
	Tree *rightChild;
	Tree *parent;
	int splittingAtt;
	float splittingPoint;
	int depth;
	Tree(Data data, int height,int maxHeight);
	virtual ~Tree();
	double pathLength(vector<float> inst);
};

 /* namespace iForest */

#endif /* TREE_H_ */
