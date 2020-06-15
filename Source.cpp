#include "Matrix.h"

int main()
{
	
	while (true){

	string operation;
	int r, c;
	double value;
	Matrix mx1, mx2, mx3;
	
	cout << "Matrix Operations Calculator\n";
	cout << "----------------------------\n";
	cout << "Select operation:\n";
	cout << "\t -------------- \n";
	cout << "\t| 1. Addition   |\n";
	cout << "\t| 2. Subtraction|\n";
	cout << "\t| 3. Multiply   |\n";
	cout << "\t| 4. Transpose  |\n";
	cout << "\t -------------- \n";
	cout << "Choice>> ";
	cin >> operation;
	
	
		try{
			if (operation == "1"){
				// addition
				// read Row and Columns
				cout << "Enter Matrices Row: ";
				cin >> r;
				cout << "Enter Matrices Column: ";
				cin >> c;
				mx1.setRow(r); mx1.setCol(c);
				mx2.setRow(r); mx2.setCol(c);
				mx3.setRow(r); mx3.setCol(c);

				// read data for each Matrix
				cout << "\nFill in 1st Matrix\n";
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						cout << "MX1[" << i << "][" << j << "]: ";
						cin >> value;
						mx1.push(value);
					}
				}

				cout << "\nFill in 2nd Matrix\n";
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						cout << "MX2[" << i << "][" << j << "]: ";
						cin >> value;
						mx2.push(value);
					}
				}

				// matrix 3 = matrix 1 + matrix2
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){

						mx3.push(mx1.getAtIndex(i, j) + mx2.getAtIndex(i, j));
					}
				}


				system("cls");

				cout << "Matrix 1:\n";
				cout << mx1;

				cout << "\nMatrix 2:\n";
				cout << mx2;

				cout << "\nMatrix 1 + Matrix 2 =\n";
				cout << mx3;

			}
			else if (operation == "2"){
				//Subtraction
				cout << "Enter Matrices Row: ";
				cin >> r;
				cout << "Enter Matrices Column: ";
				cin >> c;
				mx1.setRow(r); mx1.setCol(c);
				mx2.setRow(r); mx2.setCol(c);
				mx3.setRow(r); mx3.setCol(c);

				cout << "\nFill in 1st Matrix\n";
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						cout << "MX1[" << i << "][" << j << "]: ";
						cin >> value;
						mx1.push(value);
					}
				}

				cout << "\nFill in 2nd Matrix\n";
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						cout << "MX2[" << i << "][" << j << "]: ";
						cin >> value;
						mx2.push(value);
					}
				}

				// matrix 3 = matrix 1 - matrix2
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){

						mx3.push(mx1.getAtIndex(i, j) - mx2.getAtIndex(i, j));
					}
				}

				system("cls");

				cout << "Matrix 1:\n";
				cout << mx1;

				cout << "\nMatrix 2:\n";
				cout << mx2;

				cout << "\nMatrix 1 - Matrix 2 =\n";
				cout << mx3;
			}
			else if (operation == "3"){

				//Multiply
				cout << "Enter 1st Matrix Row: ";
				cin >> r;
				cout << "Enter 1st Matrix Column: ";
				cin >> c;
				mx1.setRow(r); mx1.setCol(c);

				cout << "Enter 2nd Matrix Row: ";
				cin >> r;
				cout << "Enter 2nd Matrix Column: ";
				cin >> c;
				mx2.setRow(r); mx2.setCol(c);

				// if Number of Columns of 1st Matrix != Number of Rows of 2nd Matrix
				// throw exception
				if (mx1.getCol() != mx2.getRow()){
					throw runtime_error("\nERROR: Number of Columns of 1st Matrix must equal Number of Rows of 2nd Matrix");
				}
				else{
					// else then read data for each matrix
					mx3.setRow(mx1.getRow()); mx3.setCol(mx2.getCol());

					cout << "\nFill in 1st Matrix\n";
					for (int i = 0; i < mx1.getRow(); i++){
						for (int j = 0; j < mx1.getCol(); j++){
							cout << "MX1[" << i << "][" << j << "]: ";
							cin >> value;
							mx1.push(value);
						}
					}

					cout << "\nFill in 2nd Matrix\n";
					for (int i = 0; i < mx2.getRow(); i++){
						for (int j = 0; j < mx2.getCol(); j++){
							cout << "MX2[" << i << "][" << j << "]: ";
							cin >> value;
							mx2.push(value);
						}
					}

					// multiplication 
					// multiply row of matrix1 by col of matrix 2 and sum result, and put value in matrix 3
					// repeat this process 
					double sum = 0.0;
					for (int i = 0; i < mx1.getRow(); i++){
						for (int j = 0; j < mx2.getCol(); j++){
							for (int k = 0; k < mx1.getCol(); k++)
							{
								sum += mx1.getAtIndex(i, k) * mx2.getAtIndex(k, j);

							}

							mx3.push(sum);
							sum = 0.0;
						}
					}

				}

				system("cls");

				cout << "Matrix 1:\n";
				cout << mx1;

				cout << "\nMatrix 2:\n";
				cout << mx2;

				cout << "\nMatrix 1 * Matrix 2 = \n";
				cout << mx3;


			}
			else if (operation == "4"){

				//Transpose
				cout << "Enter Matrix Row: ";
				cin >> r;
				cout << "Enter Matrix Column: ";
				cin >> c;
				mx1.setRow(r); mx1.setCol(c);

				mx3.setRow(c); mx3.setCol(r);

				cout << "\nFill in Matrix\n";
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						cout << "MX[" << i << "][" << j << "]: ";
						cin >> value;
						mx1.push(value);
					}
				}
				
				for (int i = 0; i < c; i++)
					for (int j = 0; j < r; j++)
						mx3.push(0.0);

				// Transpose of matrix [i]j] = [j][i]
				for (int i = 0; i < r; i++)
					for (int j = 0; j < c; j++)
						mx3.updateAtIndex(mx1.getAtIndex(i, j), j, i);
					
				

				system("cls");

				cout << "Matrix\n";
				cout << mx1;

				cout << "\nTranspose of Matrix = \n";
				cout << mx3;

			}
			else {
				throw runtime_error("\nERROR: Invalid Choice");
			}

		}
		// catch exceptions
		catch (exception const& e){
			cout << e.what() << "\n";
		}

		cout << "\nDo you want to exit program? (y/n): ";
		cin >> operation;
		if (operation == "y" || operation == "Y")
			break;
	}
	system("cls");
	cout << "Bye\n";

	system("pause");
	return 0;
}