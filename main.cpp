/*
 * main.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: Tadeze
 */
#include<iostream>
#include<fstream>
#include<cstdlib>
#include "classes.hpp"
using namespace std;
int main()
{
///Assume I have data in  two dimensional matrix
const int NROW=100;
const int NCOL=10;
double data[NROW][NCOL];
vector< vector<float> > dt;
for(int i=0;i<NROW;i++)
{ vector<float> x;
	for(int j=0;j<NCOL;j++)
	{
		data[i][j]=(j+i)*rand()/((float)RAND_MAX+1);
       // cout<<data[i][j]<<"\t";
	 x.push_back(data[i][j]);
	}
	dt.push_back(x);
	x.clear();
	//cout<<endl;
}
Data *train= new Data(dt,NCOL,NROW);
cout<<train->ncols;
int ntree=10;
IsolationForest *iff = new IsolationForest();
iff->buildForest(ntree,*train,ceil(log2(train->nrows)));






}




