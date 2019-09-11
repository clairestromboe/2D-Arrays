// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
#include "My_matrix.h"

int main() {

	// Some test cases are expected to throw an exception.
	// Add more try and catch blocks as necessary for your code
	// to finish execution.

	try {
	  
		/*
		 // Test 1 - COMPLETE
		 // * Create an object of type My_matrix, called m1, using constructor
		 My_matrix m1(3, 2);

		 // * Initialize m1 in main (by assigning numbers to matrix elements)
		 m1(0,0) = 1;
		 m1(1,0) = 2;
		 m1(2,0) = 3;
		 m1(0,1) = 4;
		 m1(1,1) = 5;
		 m1(2,1) = 6;

		 // * Display m1 on the screen using the operator <<
		 	 cout << m1 << endl;
		*/


	     /*
	  	 // Test 2 - COMPLETE
		 // * Create an object of type My_matrix, called m2, using (default)
		 //   constructor
		 My_matrix m2();
		 
		 // * Open an input file containing a matrix (row by row)
		 ifstream inFS;
		 inFS.open("mymat.txt");
		 if (inFS.is_open()){

		 // * Initialize m2 by reading from the input file using
		 //   the operator >>

		 int n, m;
		 inFS >> n >> m;

		 My_matrix m2(n,m);
		 int numcount;

		 for (int i = 0; i < n; i++){
		   for (int j = 0; j < m; j++){
		     int num;
		     ++numcount;
		     inFS >> num;
		     m2(i,j) = num;
		   }
		 }
		 cout << m2;
		 
		 if (numcount == (n*m)){
		   // * Open an output file (can be empty)
		   filebuf fb;
		   fb.open ("newmymat.txt", ios::out);
		   ostream os(&fb);
		 
		
		   // * Write m2 to the output file using the operator <<

		   for (int i = 0; i < n; i++){
		   for (int j = 0; j < m; j++){
		     os << m2(i,j) << " ";
		   }
		 
		   os << char(13) << endl;
		   }

		   fb.close();
		 }
		 else{
		   cout << "Incorrect dimensions.";
		 }
		

		 inFS.close();
		 }
		 
		 else{
		   cout << "File did not open." << endl;
		 }
	     */
	 
	  
	  
		 /*
		 // Test 3 - COMPLETE
		 // * Use the copy constructor to make a copy of m1 called m3
		 My_matrix m3 = m1;
		 // * Apply the copy assignment to m1 called m4
		 My_matrix m4;
		 m4 = m1;
		 // * Display m3 and m4 on the screen using the operator <<
		 cout << m3 << "is m3" << endl;
		 cout << m4 << "is m4" << endl;
		 */


		 /*
		 // Test 4 - COMPLETE
		 // * Test the matrix multiplication operator (operator*)
		 My_matrix m100(2,2);
		 m100(0,0) = 2;
		 m100(0,1) = 2;
		 m100(1,0) = 2;
		 m100(1,1) = 2;

		 cout << m100;


		 // * Apply the multiplication operator to valid and invalid cases
		 //	 My_matrix m5 = m1 * m100;
		 
	       
		 // * Display the resulting matrix and its number of rows and columns
		 // cout << m5 << endl;
		 // cout << m5.number_of_rows() << " rows, " << m5.number_of_columns() << " columns.";
		 
		 // My_matrix m200 = m1 * m1;
		 */
		 
		 
		 /*
		 // Test 5 - COMPLETE
		 // * Test the matrix addition operator (operator+)
		 // * Apply the addition operator to valid and invalid cases
		 My_matrix m6 = m1 + m1;
		 // * Display the resulting matrix and its number of rows and columns
		 cout << m6 << endl;
		 cout << m6.number_of_rows() << " rows, " << m6.number_of_columns() << " columns.";

		 //My_matrix m200 = m1 + m100;
		 */
		 
		 
		 /*
		 // move constructor
			My_matrix m2(m1);
			cout << m2 << endl;
		 */
		


	} catch (exception &error) {
		cerr << "Error: " << error.what() << endl;
	}

}