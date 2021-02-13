
/*mymatrix.h*/
 
// << Daniela Chavez>>
// U. of Illinois, Chicago
// CS 251: Spring 2020
// Project #02
//
    
#include <iostream>
#include <string>
#include "mymatrix.h"

using namespace std;

/********************************* TEST CASE 1***************************************/
/* This outputs a default 4x4 matrix with only zero's in it*/
void TestCase1(mymatrix<int> TEST){
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 1******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "This outputs a default 4x4 matrix" << endl;
    TEST._output();
}
/************************************************************************************/


/******************************** TEST CASE 2 ***************************************/
/* This outputs a parameterized matrix. Rows and Columns are of the users choice
 * I want to use this new matrix later on, so i'll pass it by reference  */
 void TestCase2(mymatrix <int> &M){
     int R = 0;
     int C = 0;
     cout <<"*******************************"<< endl;
     cout <<"******This is Test Case 2******"<< endl;
     cout <<"*******************************"<< endl;
     cout << "Please input the number of Rows you would like ---> "; cin >> R;
     cout << "Please input the number of columns you would like ---> "; cin >> C;
     cout << endl;
     cout << "This is your matrix:" << endl;
     
     mymatrix<int> TEST(R,C); //TEST is my temporary matrix
     M = TEST; // I might want to use M later on.
     TEST._output();
 }
/************************************************************************************/


/******************************* TEST CASE 3 ****************************************/
/* This function will add values into the matrix, replacing the default zero's */
 void TestCase3(mymatrix<int>&TEST){
     cout <<"*******************************"<< endl;
     cout <<"******This is Test Case 3******"<< endl;
     cout <<"*******************************"<< endl;
     cout << "A new 7x7 matrix has been created for you." << endl;
     cout <<"We have replaced some zero's with other integers!" << endl;
     cout << "This is your matrix"<< endl;
     TEST(0,0) = 1;     TEST(4,4) = 5;
     TEST(1,1) = 2;     TEST(5,5) = 6;
     TEST(2,2) = 3;     TEST(6,6) = 7;
     TEST(3,3) = 4;     
     
     TEST._output();
    
 }
/************************************************************************************/


/******************************** TEST CASE 4 ***************************************/
/* This test will be using the copy consructor. This will copy an existing matrix into
 * a new one. */
void TestCase4(mymatrix<int>TEST){
    
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 4******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "We are going to make a copy of the prior 7x7 matrix!" << endl;
    
//     TEST2.grow(rows, cols);
    mymatrix<int>TEST2 = TEST;
    TEST2._output();
 }
/************************************************************************************/


/********************************* TEST CASE 5 **************************************/
/* Returns the number of rows of a chosen matrix*/
void TestCase5(mymatrix<int>TEST1,mymatrix<int>TEST2, mymatrix<int>TEST3 ){
    
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 5******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "Returns the number of rows of a couple chosen matrices"<< endl;
    cout << "In this case, we are returning the number of rows of M3, M2, and M1" << endl;
    cout << "M3 Number of Rows : " << TEST1.numrows() << endl;
    cout << "M2 Number of Rows : " << TEST2.numrows() << endl;
    cout << "M1 Number of Rows : " << TEST3.numrows() << endl; cout << endl;    
}
/************************************************************************************/


/********************************** TEST CASE 6 *************************************/
/* Returns the number of columns of a chosen matrix */
void TestCase6(mymatrix<int>TEST1,mymatrix<int>TEST2, mymatrix<int>TEST3){
    int rows1 = TEST1.numrows();
    int rows2 = TEST2.numrows();
    int rows3 = TEST3.numrows();
    
    int Test1Cols = TEST1.numcols(rows1 - 1);
    int Test2Cols = TEST2.numcols(rows2 - 1);
    int Test3Cols = TEST3.numcols(rows3 - 1);
    
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 6******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "Returns the number of columns of a couple chosen matrices"<< endl;
    cout << "In this case, we are returning the number of columns of M3, M2, and M1" << endl;
    cout << "M3 Number of Columns : " << Test1Cols << endl;
    cout << "M2 Number of Columns : " << Test2Cols << endl;
    cout << "M1 Number of Columns : " << Test3Cols << endl; cout << endl;
    
}
/************************************************************************************/


/********************************** TEST CASE 7 *************************************/
/* We are taking an existing matrix, and we are going to increase the number of columns
 of a row. The number of columns increased at a certaon row will be chosen by the user 
 in this case. */
void TestCase7(mymatrix<int>&TEST){
    int row = 0;
    int newCols = 0;
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 7******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "The user (you) is going to chose the number of columns we want to increase"<< endl;
    cout << "You are also going to chose the row where the number of columns will be increased" << endl;
    cout << "This is your current matrix: " << endl; cout << endl;
    TEST._output();
    cout << "Pick a row ---> "; cin >> row; cout << endl;
    cout << "Pick a new number of cols for row " << row << " --->"; cin >> newCols; cout << endl;
    
    cout << "This is your new matrix" << endl; cout << endl;
    TEST.growcols((row -1), (newCols-1));
    TEST._output();
 
}
/************************************************************************************/


/********************************** TEST CASE 8 *************************************/
/*We are going to use the grow() function to "grow" an existing matrix */
void TestCase8(mymatrix<int>&TEST){
    int rows = 0;
    int cols = 0;
    
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 8******"<< endl;
    cout <<"*******************************"<< endl;
    cout << "This function will allow the user (you) to grow the matrix" << endl;
    cout << "this is our existing matrix:" << endl; cout << endl;
    TEST._output(); //Showing the user the current matrix we have
    cout << endl; cout << "How many rows to you want to have? --->"; cin >> rows;
    cout << endl; cout << "How many columns do you want to have? --->"; cin >> cols;
    cout << endl; cout << "This is you new matrix: " << endl;
    
    TEST.grow(rows, cols);
    TEST._output();	//returns the 'grown' matrix
  
}
/************************************************************************************/


/********************************** TEST CASE 9 *************************************/
/* After grow, we are using the same matrix and getting its size, using the size() function
 * that war previously created in mymatrix.h*/
void TestCase9(mymatrix<int>TEST){
    cout <<"*******************************"<< endl;
    cout <<"******This is Test Case 9******"<< endl;
    cout <<"*******************************"<< endl;
    cout <<endl; cout<< "So, this is your current matrix: " << endl; cout << endl;
    TEST._output();
    cout << "We want to know the number of elements this matrix has."<< endl;
    cout << "Size of your current matrix is ---> " << TEST.size() << endl;
}
/************************************************************************************/


/********************************** TEST CASE 10 *************************************/
/*Returns a reference to the element at location (r, c). This allows you to access the 
 * element or change it*/
void TestCase10(mymatrix<int>TEST){
    int row = 0;
    int col = 0;
    
    cout <<"*******************************"<<endl;
    cout <<"******This is Test Case 10*****"<<endl;
    cout <<"*******************************"<<endl;
    cout << "We are going to use the following matrix: " << endl; cout << endl;
    TEST._output();
    cout << "Pick a row number ---> "; cin >> row; cout << endl;
    cout << "Pick a column number --->"; cin >> col; cout << endl;
    cout << "The element at row " << row << " column " << col << " is ---> " << TEST.at((row - 1), (col - 1));
    cout << endl;
}
/************************************************************************************/


/********************************** TEST CASE 11 *************************************/
 /*Multiplies every element of this matrix by the given scalar value,
  producing a new matrix that is returned.  "This" matrix is not
  changed */
void TestCase11(mymatrix<int>TEST){
    int scalar = 0;
    
    cout <<"*******************************"<<endl;
    cout <<"******This is Test Case 11*****"<<endl;
    cout <<"*******************************"<<endl;
    cout << "For this test, we are using the following matrix: " << endl; cout<< endl;
    TEST._output();
    cout << "Pick a number ---> "; cin >> scalar; cout << endl;
    cout << "We will muliply the current elements of the matrix with the number you have chosen" << endl;
    mymatrix<int>TEST2 = TEST*2;
    cout << "This is your new matrix: " << endl;
    TEST2._output();
}
/************************************************************************************/
                  
/********************************** TEST CASE 12 *************************************/
/* This is the last function of the program. I will be applying the use of Matrix 
 * Multiplication. In this function, I have created two new matrices, then I assigned
 * some new integers in those maricies.*/
void TestCase12(){
    mymatrix<int>TEST1(2,3);
    mymatrix<int>TEST2(3,5);
    
    TEST1(0,0) = 1;    TEST2(0,1) = 4;
    TEST1(0,2) = 2;    TEST2(2,2) = 1;
    TEST1(1,2) = 7;    TEST2(1,4) = 3;
                       TEST2(1,1) = 2;
    
    cout << endl;
    cout <<"*******************************"<<endl;
    cout <<"******This is Test Case 12*****"<<endl;
    cout <<"*******************************"<<endl;
    cout << "We will be multiplying two martices that have been already created" << endl; cout<< endl;
    cout << "there are the new matrices that have been created for this Test: " << endl;
    
    cout<< "Matrix 1: "<<endl;
    TEST1._output();
    cout<< "Matrix 2: "<< endl;
    TEST2._output();
    
    cout << "Now we will multiply both matrices"<< endl;
    cout<<"This is the result: "<< endl; cout<< endl;
    mymatrix<int>TEST3 = TEST1*TEST2;
    TEST3._output();   
}
/************************************************************************************/

int main(){
    mymatrix<int>M1;
    mymatrix<int>M2;
    mymatrix<int>M3(8,8);
    mymatrix<int>M4;
    
    TestCase1(M1); /* This displays the default 4x4 Matrix */ 
    TestCase2(M2); /* Parameterized Matrix */
    TestCase3(M3); /* Add values to Matrix */
    TestCase4(M3); /* Using Copy Constructor */
    TestCase5(M3, M2, M1); /* Returns Number of Rows */
    TestCase6(M3, M2, M1); /* Returns Number of Columns*/
    TestCase7(M3); /* Grow Column of Matrix*/
    TestCase8(M3); /* Grow Matrix */
    TestCase9(M3); /* Returns size of Matrix*/
    TestCase10(M3); /* Returns Value at a picked location */
    TestCase11(M3); /* Scalar Multiplication */
    TestCase12(); /* Matrix Multiplication */      
}
