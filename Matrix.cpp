#include "Matrix.h"

// destructor
Matrix::~Matrix(){

	Term* current = head;
	Term* tmp;
	// while current not null delete current pointer and move to next
	while (current != NULL) {

		tmp = current->next;
		delete  current;
		current = tmp;

	}
}

// setter for Row
void Matrix::setRow(int r){
	row = r;
}

// setter for col
void Matrix::setCol(int c){
	col = c;
}

//getter for row
int Matrix::getRow(){
	return row;
}

// getter for col
int Matrix::getCol(){
	return col;
}

double Matrix::getAtIndex(int r, int c){
	// index at [i][j] equal to r*col + c
	int index = r*col + c;
	Term* q = head;
	// loop until reach index
	for (int i = 0; i < index; i++)
		q = q->next;

	// return current is data
	return q->data;
}

void Matrix::push(double data){
	// create new Term
	Term *temp, *q;
	temp = new Term(data);
	// if no Term in LinkedList
	if (head == NULL)
	{
		temp->next = NULL;
		head = temp;
	}
	// if already There is Terms 
	else
	{
		// loop till find the last element
		q = head;
		while (q->next != NULL)
			q = q->next;

		// last node will point to New node, and new node is next to Null
		q->next = temp;
		temp->next = NULL;

	}

}

void Matrix::updateAtIndex(double data, int r, int c){

	// loop until get index [i][j]
	// then update its data
	int index = r*col + c;
	Term* q = head;

	for (int i = 0; i < index; i++)
		q = q->next;

	q->data = data;
}

ostream& operator<<(ostream& out_stream, const Matrix& mtx){

	// overload output operator
	Term* current = mtx.head;
	int i = 0;
	// loop until current == NULL
	// output data for each Term (Node)
	while (current != NULL){

		if (i%mtx.col == 0)
			out_stream << "| " << fixed << setprecision(1) << left << setw(0) << current->data;
		else
			out_stream << fixed << setprecision(1) << right << setw(7) << current->data;

		current = current->next;
		if ((i + 1) % mtx.col == 0)
			out_stream << " |\n";
		i = i + 1;
	}

	return out_stream;
}