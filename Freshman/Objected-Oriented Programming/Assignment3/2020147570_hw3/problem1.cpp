#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Matrix{
public:
	Matrix();
	Matrix(int n);
	Matrix(int ** mat, int n);
	void setMat(int i, int j, int val);
  
  // you have to complete 4 functions below
	Matrix transpose() const;
	friend const Matrix operator +(const Matrix& ref1, const Matrix& ref2);
	friend const Matrix operator -(const Matrix& ref1, const Matrix& ref2);
	friend const Matrix operator *(const Matrix& ref1, const Matrix& ref2);
	//
	friend ostream& operator <<(ostream& outputStream, const Matrix& ref);
	~Matrix();
private:
	int ** matrix_value;  //2d array that contains matrix value.
	int size_mat; //size of matrix
};

Matrix::Matrix()
{ 
	//If there are no argument of constructor, matrix size is set as zero.
	size_mat = 0;
}
Matrix::Matrix(int n)
{
	//input 'n' is size of matrix
	//allocate n*n array to matrix pointers
	
	matrix_value = new int*[n];
	for(int i=0; i<n; i++){
		matrix_value[i] = new int[n];
	}
	size_mat = n;
}
Matrix::Matrix(int ** mat, int n)
{ 
	//We can indicate the matrix value directly.
	//deep copy array 'mat' to int 2d array 'matrix_value'

	matrix_value = new int*[n];
	for(int i=0; i<n; i++)
	{
		matrix_value[i] = new int[n];
		for(int j=0; j<n; j++)
		{
			matrix_value[i][j] = mat[i][j];
		}
	}
	size_mat = n;
}
Matrix::~Matrix()
{
	//Destructor
	//deallocate n*n array
	for(int i=0; i<size_mat; i++)
	{
		delete[] matrix_value[i];
	}
	delete[] matrix_value;
}

void Matrix::setMat(int i, int j, int val)
{ 
	//Definition of setMat(i,j) function.
	//set (i,j)th value of matrix directly
	matrix_value[i][j]=val;
}

Matrix Matrix::transpose() const
{
	// Problem 1-1
	// You have to return transpose matrix of this object matrix. 
	// Return Matrix object that containing transpose of 'matrix_value'
	// Return Type : Matrix object
  
	Matrix t_matrix(size_mat);
	for (int i = 0; i < size_mat; i++)
		for (int j = 0; j < size_mat; j++)
			t_matrix.setMat(i, j, matrix_value[j][i]);
	return t_matrix;
}

const Matrix operator +(const Matrix& ref1, const Matrix& ref2)
{
	// Problem 1-2
	// You have to overload operator + for Matrix class. 
	// Return Matrix object that containing result of ref1+ref2
	// Return Type : Matrix object
  
	Matrix sum_matrix(ref1.size_mat);
	for (int i = 0; i < ref1.size_mat; i++)
		for (int j = 0; j < ref1.size_mat; j++)
			sum_matrix.setMat(i, j, ref1.matrix_value[i][j]+ref2.matrix_value[i][j]);
	return sum_matrix;
}

const Matrix operator -(const Matrix& ref1, const Matrix& ref2)
{
	// Problem 1-3
	// You have to overload operator - for Matrix class. 
	// Return Matrix object that containing result of ref1-ref2
	// Return Type : Matrix object
  
	Matrix sub_matrix(ref1.size_mat);
	for (int i = 0; i < ref1.size_mat; i++)
		for (int j = 0; j < ref1.size_mat; j++)
			sub_matrix.setMat(i, j, ref1.matrix_value[i][j]-ref2.matrix_value[i][j]);
	return sub_matrix;
}

const Matrix operator *(const Matrix& ref1, const Matrix& ref2)
{
	// Problem 1-4
	// You have to overload operator * for Matrix class. 
	// Return Matrix object that containing result of matrix multiplication, ref1*ref2
	// Return Type : Matrix object
  
	Matrix multi_matrix(ref1.size_mat);
	for (int i = 0; i < ref1.size_mat; i++)
		for (int j = 0; j < ref1.size_mat; j++) {
			int multi_ij = 0;
			for (int k = 0; k < ref1.size_mat; k++)
				multi_ij += ref1.matrix_value[i][k]*ref2.matrix_value[k][j];
			multi_matrix.setMat(i, j, multi_ij);
		}
	return multi_matrix;
}

/*
You MUST NOT touch the code below.
If modified temporally, make sure you've restored the code when submitting.
*/

ostream& operator <<(ostream& outputStream, const Matrix& ref)
{
	//overloading output stream operator << for Matrix class
	int n = ref.size_mat;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			outputStream << ref.matrix_value[i][j] << " ";
		}
		outputStream << endl;
	}
	return outputStream;
}


int main()
{
	int N;
	// take inputs
	ifstream infile("input1.txt");
	infile >> N;

	// allocate memory to pointers
	Matrix mat1(N);
	Matrix mat2(N);

	// take matrix 1
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			int val=0;
			infile >> val;
			mat1.setMat(i,j,val);
		}
	}	

  // take matrix 2
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{	
			int val=0;
			infile >> val;
			mat2.setMat(i,j,val);
		}
	}
	//display two input matrix
	cout << "matrix 1: " <<endl;
	cout << mat1;
	cout << "matrix 2: " <<endl;
	cout << mat2;
	
	// sum of a mat1 and mat2
	cout <<"sum of matrix 1 and matrix 2: "<< endl;
	cout << mat1+mat2;

	// subtract of a mat1 and mat2
	cout <<"subtract matrix 2 from matrix 1: "<< endl;
	cout << mat1-mat2;

	// matrix transpose
	cout <<"transposed matrix 1: " << endl;
	cout << mat1.transpose();
	cout <<"transposed matrix 2: " << endl;
	cout << mat2.transpose();

	// matrix multiplication
	cout <<"multiplication of matrices: " << endl;
	cout << mat1*mat2;
	return 0;
}
