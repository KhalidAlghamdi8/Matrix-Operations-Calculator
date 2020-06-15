#ifndef Matrix_H
#define Matrix_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Store Term of Matrix
struct Term {
	// store data of each node
	double data;
	// pointer to next node
	Term* next;

	Term(double d) {
		data = d;
	}
};


// Matrix class
class Matrix{

public:

	// store head of linkedList
	Term *head;
	// row and column of matrix
	int row, col;
	Matrix(){
		head = NULL;
	}
	// Destructor
	~Matrix();
	// setter of row and column
	void setRow(int r);
	void setCol(int c);
	// getters of row and column
	int getRow();
	int getCol();
	// get value at specific index [i][j] of matrix
	double getAtIndex(int r, int c);
	// modify value at index [i][j] of matrix
	void updateAtIndex(double data, int r, int c);
	// add Node to linked List
	void push(double data);
	//overload output operator
	friend ostream& operator<<(ostream& out_stream, const Matrix& mtx);

};

#endif