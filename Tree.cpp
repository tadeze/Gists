/*
 * Tree.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Tadeze
 */
#include "classes.hpp"
using namespace std;
Tree::~Tree() {
	// TODO Auto-generated destructor stub
}


Tree::Tree(Data data,int height,int maxheight)
{
	if(this->parent==NULL)
	{
		this->depth=0;

	}

	// Set size of the node
  this->nodeSize=data.nrows;
  if(data.nrows<2 || height==maxheight)
	  return;
  //compute min and max
 double minmax[2][data.ncols];
 for(int j=0;j<data.ncols;j++)
 {
	 minmax[0][j]=data.data[0][j];
	 minmax[1][j]=minmax[0][j];
 }
 for(int i=0;i<data.nrows;i++) {
    float* inst= data.data[i];
	 for(int j=0;j<data.ncols;j++)
	 {
		 if(inst[j]<minmax[0][j])
			 minmax[0][j]=inst[j];
		 if(inst[j]>minmax[1][j])
			 minmax[1][j]=inst[j];
	 }

 }
 vector<int> attributes = new vector<int>();
 for(int j=0;j<data.ncols;j++)
 {
	 if(minmax[0][j]<minmax[1][j]){
		 attributes.push_back(j);
	 }
 }
 if(attributes.size()==0)
	 return ;
//Randomly pick an attribute and split point

 this->splittingAtt = attributes[ceil(attributes.size()* rand()/(float)RAND_MAX)];
 this->splittingPoint = rand()/(float)RAND_MAX *(minmax[1][this->splittingAtt] - minmax[0][this->splittingAtt]);
 //Create sub-treee
 vector<vector<float> > lnodeData;
 vector<vector<float> > rnodeData;
 //divide the data into left and righ tree
 for(int j=0;j<data.nrows;j++)
 {
	 if(data.data[j][this->splittingAtt] > this->splittingPoint)
	 {
		 lnodeData.push_back(data.data[j]);
	 }
	 else
	 {
		 rnodeData.push_back(data.data[j]);
	 }


 this->leftChild=new Tree(new Data(lnodeData,data.ncols,lnodeData.size()),height+1,maxheight);
 this->leftChild->parent=this;
 this->leftChild->depth = this->depth +1;

 this->rightChild=new Tree(new Data(lnodeData,data.ncols,lnodeData.size()),height+1,maxheight);
 this->rightChild->parent=this;
 this->rightChild->depth = this->depth +1;
 }
//now split the data in the node,
  //send the node and the data to a function
 //choose random attribute
 //choose max and min of the attribute a
 //
}

