/*mymatrix.h*/

// 
// << Daniela Chavez>>
// U. of Illinois, Chicago
// CS 251: Spring 2020
// Project #02
//

//
// mymatrix
//
// The mymatrix class provides a matrix (2D array) abstraction.
// The size can grow dynamically in both directions (rows and 
// cols).  Also, rows can be "jagged" --- i.e. rows can have 
// different column sizes, and thus the matrix is not necessarily 
// rectangular.  All elements are initialized to the default value
// for the given type T.  Example:
//
//   mymatrix<int>  M;  // 4x4 matrix, initialized to 0
//   
//   M(0, 0) = 123;
//   M(1, 1) = 456;
//   M(2, 2) = 789;
//   M(3, 3) = -99;
//
//   M.growcols(1, 8);  // increase # of cols in row 1 to 8
//
//   for (int r = 0; r < M.numrows(); ++r)
//   {
//      for (int c = 0; c < M.numcols(r); ++c)
//         cout << M(r, c) << " ";
//      cout << endl;
//   }
//
// Output:
//   123 0 0 0
//   0 456 0 0 0 0 0 0
//   0 0 789 0
//   0 0 0 -99
//

#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>

using namespace std;

template<typename T>
class mymatrix
{
private:
  struct ROW
  {
    T*  Cols;     // dynamic array of column elements
    int NumCols;  // total # of columns (0..NumCols-1)
  };

  ROW* Rows;     // dynamic array of ROWs
  int  NumRows;  // total # of rows (0..NumRows-1)

public:
  //
  // default constructor:
  //
  // Called automatically by C++ to construct a 4x4 matrix.  All 
  // elements are initialized to the default value of T.
  //
  mymatrix()
  {
    Rows = new ROW[4];  // an array with 4 ROW structs:
    NumRows = 4;

    // initialize each row to have 4 columns:
    for (int r = 0; r < NumRows; ++r)
    {
      Rows[r].Cols = new T[4];  // an array with 4 elements of type T:
      Rows[r].NumCols = 4;

      // initialize the elements to their default value:
      for (int c = 0; c < Rows[r].NumCols; ++c)
      {
        Rows[r].Cols[c] = T{};  // default value for type T:
      }
    }
  }

/**********************PARAMETERIZED CONSTRUCTOR**************************************/

  // Called automatically by C++ to construct a matrix with R rows, 
  // where each row has C columns. All elements are initialized to 
  // the default value of T.
  //
  mymatrix(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::constructor: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::constructor: # of cols");

    Rows = new ROW [R]; //New row of size R
    NumRows = R;
        //Initializing each row with R
    for (int i = 0; i < NumRows; ++i){
        Rows[i].Cols = new T[C]; //array with R elements of type T
        Rows[i].NumCols = C;
        
        for (int y = 0; y < Rows[i].NumCols; ++y){
            Rows[i].Cols[y] = T{};
        }
        
    }// closing for(int i = 0; ...)
  } //close mymatrix(int R, int C)...
/************************************************************************************/


/******************************COPY CONSTRUCTOR**************************************/

  // Called automatically by C++ to construct a matrix that contains a 
  // copy of an existing matrix.  Example: this occurs when passing 
  // mymatrix as a parameter by value
  //
  //   void somefunction(mymatrix<int> M2)  <--- M2 is a copy:
  //   { ... }
  //
  mymatrix(const mymatrix<T>& other)
  {
    //
    // TODO
    NumRows = other.NumRows;
    Rows = new ROW[other.NumRows];
    
    for (int i = 0; i < NumRows; i++){
        Rows[i].Cols = new T [other.Rows[i].NumCols];
        Rows[i].NumCols = other.Rows[i].NumCols;
        
        for (int y = 0; y < Rows[i].NumCols; y++){
            Rows[i].Cols[y] = other.Rows[i].Cols[y];
        }
    }  
  }
/************************************************************************************/


/**********************************NUMROWS*******************************************/

  // Returns the # of rows in the matrix.  The indices for these rows
  // are 0..numrows-1.
  //
  int numrows() const
  {
    return NumRows;
  }
/************************************************************************************/


/*************************************NUMCOLS***************************************/

  // Returns the # of columns in row r.  The indices for these columns
  // are 0..numcols-1.  Note that the # of columns can be different 
  // row-by-row since "jagged" rows are supported --- matrices are not
  // necessarily rectangular.
  //
  int numcols(int r) const
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::numcols: row");

    return Rows[r].NumCols;
  }
/************************************************************************************/


/********************************GROWCOLS********************************************/

  // Grows the # of columns in row r to at least C.  If row r contains 
  // fewer than C columns, then columns are added; the existing elements
  // are retained and new locations are initialized to the default value 
  // for T.  If row r has C or more columns, then all existing columns
  // are retained -- we never reduce the # of columns.
  //
  // Jagged rows are supported, i.e. different rows may have different
  // column capacities -- matrices are not necessarily rectangular.
  //
  void growcols(int r, int C)
  {
    if (r < 0 || r >= NumRows)                           //if r is less than zero or r is greater than or equal to Number of rows
      throw invalid_argument("mymatrix::growcols: row"); // then print out an invalid argument
    if (C < 1)
      throw invalid_argument("mymatrix::growcols: columns"); //if C (colums we want to add) is less than one, 
                                                            //then print out error
    // are we growing or shrinking? 
    if (C <= Rows[r].NumCols){     //If the columns we want to add are less then the current number of columns in that row (r)
        return;                    // THen, return.
    }
     
    //Grow row r to have C columns
    T* newRow = new T[C]; 
    
    //copy over elements of the previous row
    for (int i = 0; i < Rows[r].NumCols; i++){
        newRow[i] = Rows[r].Cols[i];
    }
    //
    for (int i = Rows[r].NumCols; i < C; i++){
        newRow[i] = T{};
    }
   
    //Now we delete the old row and instal the new row;
    delete[] Rows[r].Cols; 
    Rows[r].Cols = newRow; //we add the new row into the now empty row
    Rows[r].NumCols = C;  // The row at position r now has C number of columns
    
  }
/************************************************************************************/


/*******************************GROW*************************************************/
  // Grows the size of the matrix so that it contains at least R rows,
  // and every row contains at least C columns.
  // 
  // If the matrix contains fewer than R rows, then rows are added
  // to the matrix; each new row will have C columns initialized to 
  // the default value of T.  If R <= numrows(), then all existing
  // rows are retained -- we never reduce the # of rows.
  //
  // If any row contains fewer than C columns, then columns are added
  // to increase the # of columns to C; existing values are retained
  // and additional columns are initialized to the default value of T.
  // If C <= numcols(r) for any row r, then all existing columns are
  // retained -- we never reduce the # of columns.
  // 
  void grow(int R, int C)
  {
    if (R < 1)
      throw invalid_argument("mymatrix::grow: # of rows");
    if (C < 1)
      throw invalid_argument("mymatrix::grow: # of cols");
      if(R < NumRows){
          return;
      }
   
    mymatrix<T>TEMP(R,C); //Creating a temporary matrix to store new data
    
    
    if (NumRows < R){   //If the current cumber of rows are less than the number of rows we want
        for (int i = 0; i < NumRows; i ++){ //we loop through each row
             if (Rows[i].NumCols <= C){  // at Row i, if the number of columns is less than C,
                 growcols(i, C);         // then, increment the size of columns to C.
                }  
            for (int y = 0; y < Rows[i].NumCols; y++){  //Once all the columns are updated to the size we want,
                TEMP.Rows[i].Cols[y] = Rows[i].Cols[y]; // copy all the data of the old matrix into the TEMP
             }   
         }
     }
     
     else if (NumRows >= R){                   //If the current number of rows we have is greater than R,
         for (int i = 0; i < NumRows; i++){    // no changes are applied to Rows, but columns may modify.
             if (Rows[i].NumCols <= C){ 
                 growcols(i, C);  // Grow columns if necessary
                 } 
             for (int y = 0; y < Rows[i].NumCols; y++){
                TEMP.Rows[i].Cols[y] = Rows[i].Cols[y];  //Copy new inormation into TEMP matrix
                }
         }
     }
    *this = TEMP;    
       
  } // closes void grow(int R, int C)..
/************************************************************************************/


/*********************************** SIZE *******************************************/
  // Loops though the matrix and returns the total number of elements
  int size() const
  {
    int counter = 0;
    for (int i = 0; i < NumRows; i++){
        for (int y = 0; y < Rows[i].NumCols; y++ ){
            counter++;
        } // closes for (int y = 0; y < Rows[i].NumCols; y++ )
    } // closes  for (int i = 0; i < NumRows; i++)

    return counter;   //returns total number of elements inside of any matrix
  }
/************************************************************************************/


 /*********************************** AT ********************************************/
  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //
  //    M.at(r, c) = ...
  //    cout << M.at(r, c) << endl;
  //
  T& at(int r, int c)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::at: row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::at: col");
      
      return Rows[r].Cols[c];
  }
/************************************************************************************/


/******************************* T& operator() **************************************/

  // Returns a reference to the element at location (r, c); this
  // allows you to access the element or change it:
  //    M(r, c) = ...
  //    cout << M(r, c) << endl;
  T& operator()(int r, int c)
  {
    if (r < 0 || r >= NumRows)
      throw invalid_argument("mymatrix::(): row");
    if (c < 0 || c >= Rows[r].NumCols)
      throw invalid_argument("mymatrix::(): col");

    return Rows[r].Cols[c]; //access to the rth row, then the cth column
  }
/************************************************************************************/


/****************************** SACLAR MULTIPLICATION********************************/
  // Multiplies every element of this matrix by the given scalar value,
  // producing a new matrix that is returned.  "This" matrix is not
  // changed.
  // Example:  M2 = M1 * 2;
  mymatrix<T> operator* (T scalar)
  {
    mymatrix<T> result = *this;
 
    for (int i = 0; i < NumRows; i++){
        for (int y = 0; y < Rows[i].NumCols; y++){
               result.Rows[i].Cols[y] = Rows[i].Cols[y] * scalar;      
            } // closes for (int y = 0; y < Rows[i].NumCols; y++){
        } //closes for (int i = 0; i < NumRows; i++){
    return result;
  }
/************************************************************************************/

/*************************** MATRIX MULTIPLICATION **********************************/
  // Performs matrix multiplication M1 * M2, where M1 is "this" matrix and
  // M2 is the "other" matrix.  This produces a new matrix, which is returned.
  // "This" matrix is not changed, and neither is the "other" matrix.
  //
  // Example:  M3 = M1 * M2;
  //
  // NOTE: M1 and M2 must be rectangular, if not an exception is thrown.  In
  // addition, the sizes of M1 and M2 must be compatible in the following sense:
  // M1 must be of size RxN and M2 must be of size NxC.  In this case, matrix
  // multiplication can be performed, and the resulting matrix is of size RxC.
  //
  mymatrix<T> operator*(const mymatrix<T>& other)
  {
    int M1Rows=this->NumRows;
    int M1Cols=this->Rows[0].NumCols;
    int M2Rows=other.NumRows;
    int M2Cols=other.Rows[0].NumCols;
    
    // both matrices must be rectangular for this to work:
    for (int i = 1; i < M1Rows; i++) //checking if each row of M1 has the same number of columns
    {
        if (this-> Rows[i].NumCols != M1Cols)
        {
            throw runtime_error("mymatrix::*: this not rectangular");
        }
    }
  
    for (int j = 1; j < M2Rows; j++) //checking each row of M2 has the same number of columns
    {
        if (other.Rows[j].NumCols != M2Cols)
        {
            throw runtime_error("mymatrix::*: other not rectangular");
        }
    
    }
    
    mymatrix<T> result(*this); //Returns result value
    
    // Okay, both matrices are rectangular.  Can we multiply?  Only
    // if M1 is R1xN and M2 is NxC2.  This yields a result that is
    // R1xC2.
    // 
    // Example: 3x4 * 4x2 => 3x2
   
     if (M1Cols != M2Rows){
        throw runtime_error("mymatrix::*: size mismatch");
     }
     
     /*Now that we know that the number of columns of M1 is equal
      * to the number of rows of M2, we multiply   */
     for (int i = 0; i < this->NumRows; i++ ){
         for (int j = 0; j < Rows[0].NumCols; j++){
             result.Rows[i].Cols[j] = 0;
             for (int k =  0; k < M2Rows; k++){
              result.Rows[i].Cols[j] += this->Rows[i].Cols[k] * other.Rows[k].Cols[j];
                 } // for (int k =  0; k < M2Rows; k++){
             } // closes for (int j = 0; j < Rows[0].NumCols; j++){
         } // closes for (int i = 0; i < this->NumRows; i++ ){
    
    return result;
  }
/************************************************************************************/


/******************************* _output() ******************************************/
  // Outputs the contents of the matrix; for debugging purposes.
  //
  void _output()
  {
    for (int r = 0; r < this->NumRows; ++r)
    {
      for (int c = 0; c < this->Rows[r].NumCols; ++c)
      {
        cout << this->Rows[r].Cols[c] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
/************************************************************************************/

};
