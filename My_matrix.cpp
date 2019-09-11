/*
 Implementation of the clas My_matrix
 */

#include "My_matrix.h"
#include <stdexcept>

My_matrix::My_matrix(): n(0), m(0), ptr(nullptr) {
}

void My_matrix::allocate_memory() {
	n = this->n;
	m = this->m;
	
	for (int i = 0; i < n; i++){
		ptr [n] = new int[m];
	}
}

My_matrix::My_matrix(int n1, int m1): n(n1), m(m1), ptr(new int*[n]) {

	for (int i = 0; i < n; i++){
		ptr[i] = new int[m];
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			ptr[i][j] = 0;
		}
	}
}

//copy constructor
My_matrix::My_matrix(const My_matrix& mat) {

	n = mat.n;
	m = mat.m;

	ptr = new int*[n];

	for (int i = 0; i < n; i++) {
		ptr[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ptr[i][j] = mat.ptr[i][j];
		}
	}
}

// move constructor
My_matrix::My_matrix(My_matrix&& mat) {
	this->ptr = mat.ptr;
	mat.ptr = nullptr;
}

//destructor
My_matrix::~My_matrix() {
	for (int i = 0; i < n; i++) {
		delete[] ptr[i];
	}
	delete[] ptr;
}

//copy assignment operator
My_matrix& My_matrix::operator=(const My_matrix& mat) {

	//delete previous data
	for (int i = 0; i < n; i++) {
		delete ptr[i];
	}
	delete[] ptr;

	n = mat.n;
	m = mat.m;

	ptr = new int*[n];

	for (int i = 0; i < n; i++) {
		ptr[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ptr[i][j] = mat.ptr[i][j];
		}
	}

	return *this;
}

// move assignment operator (optional)
My_matrix& My_matrix::operator=(My_matrix&& mat) {
	
	if (this != &mat){
		for (int i = 0; i < n; i++) {
		delete ptr[i];
		}
		delete[] ptr;
		
		this->ptr = mat.ptr;
		mat.ptr = nullptr;
	}
	
	return *this;
}

int My_matrix::number_of_rows() const {
	return n;
}

int My_matrix::number_of_columns() const {
	return m;
}

int* My_matrix::operator()(int i) const {
	return ptr[i];
}

int& My_matrix::operator()(int i, int j) {
	return ptr[i][j];
}

int My_matrix::operator()(int i, int j) const {
	return ptr[i][j];
}

int My_matrix::elem(int i, int j) const {
	if (i < 0 || i >= n)
		throw out_of_range("Out of range");
	if (j < 0 || j >= m)
		throw out_of_range("Out of range");

	return ptr[i][j];
}

int& My_matrix::elem(int i, int j) {
	if (i < 0 || i >= n)
		throw out_of_range("Out of range");
	if (j < 0 || j >= m)
		throw out_of_range("Out of range");

	return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat) {
	for (int i = 0; i < mat.number_of_rows(); i++) {
		for (int j = 0; j < mat.number_of_columns(); j++) {
			out << mat(i, j) << " ";
		}
		out << endl;
	}

	return out;
}

istream& operator>>(istream& in, My_matrix& mat) {

	for (int i = 0; i < mat.number_of_rows(); i++) {
		for (int j = 0; j < mat.number_of_columns(); j++) {
			in >> mat.elem(i,j);
		}
	}

	return in;
}

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2) {

	My_matrix temp(mat1.number_of_rows(), mat1.number_of_columns());

	if ((mat1.number_of_rows() == mat2.number_of_rows()) && (mat1.number_of_columns() == mat2.number_of_columns())) {

		for (int i = 0; i < mat1.number_of_rows(); i++) {
			for (int j = 0; j < mat1.number_of_columns(); j++) {
				temp(i,j) = mat1(i,j) + mat2(i,j);
			}
		}
		return temp;
	}
	else {
		cout << "Matrices must have the same dimensions for addition." << endl;
	}

}

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2) {

	My_matrix temp(mat1.number_of_rows(), mat2.number_of_columns());

	if (mat1.number_of_columns() == mat2.number_of_rows()) {
		for (int i = 0; i < mat1.number_of_rows(); i++) {
			for (int j = 0; j < mat2.number_of_columns(); j++) {
				for (int k = 0; k < mat1.number_of_columns(); k++){
					temp(i,j) += mat1(i,k)*mat2(k,j);
				}
			}
		}
		return temp;

	} else {
		cout << "Number of columns in the matrix 1 should be equal to the number of rows in matrix 2 for multiplication." << endl;
	}

}
