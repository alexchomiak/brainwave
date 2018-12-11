#ifndef matrix_h
#define matrix_h
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>

template <class type>
class Matrix {
    public:
        Matrix(int r, int c) {init(r,c);}
        Matrix(){init(0,0);}
        ~Matrix();
        
        void clear();
        void init(int r, int c);
        
        type & at(int r, int c);        
        Matrix(Matrix<type> &src);
        
        int numRows() {return nRow;}
        int numCols() {return nCol;}
        
        void printMatrix(int s = 5);
        Matrix<type> operator * (Matrix<type> & arg);
    private:
        int nRow = 0;
        int nCol = 0;
        std::vector< std::vector< type* > > data;
};



template <class type>
type & Matrix<type>:: at(int r, int c) 
 {
    if(nRow == 0 || nCol == 0) throw std::runtime_error("matrix empty!");
    if(r >= nRow || r < 0) throw std::runtime_error("out of index!");
    if(c >= nCol || c < 0) throw std::runtime_error("out of index!");
    return *(data.at(r).at(c));
 }


template <class type>
void Matrix<type>::init(int r, int c) {
    for(int i = 0; i < r; i++) {
        std::vector< type* > row;
        for(int j = 0; j < c; j++) {
            row.push_back( new type() );
        }
        data.push_back(row);
    }
    nRow = r;
    nCol = c;
}

template <class type>
Matrix<type>::Matrix(Matrix<type> &src) {
    init(src.numRows(),src.numCols());
   
    for(int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
            at(i,j) = src.at(i,j);
        }
    }
}


template <class type>
void Matrix<type>::clear() {
    for(int i = 0; i < nRow; i++) {
        for(int j = 0; j < nCol; j++) {
            delete data.at(i).at(j);
        }
        data.at(i).clear();
    }
    data.clear();

    nRow = 0;
    nCol = 0;

}

template <class type>
Matrix<type>::~Matrix() { 
    clear();
}

template <class type>
Matrix<type> Matrix<type>::operator * (Matrix<type> & arg) {
    if(nCol !=  arg.numRows()) throw std::runtime_error("Invalid Matrix Multiplication Operative");
    Matrix<type> result(nRow, arg.numCols());

    //matrix multiplication algorithm
    for(int i = 0; i < nRow; i++) {
        for(int j = 0; j < arg.numCols(); j++) {
            type sum = 0;
            for(int k = 0; k < nCol; k++) {
                sum += at(i,k) * arg.at(k,j);
            }
            result.at(i,j) = sum;
        }
    }
    
    return result;
}


void printRow(int s, int cols) {
    std::cout << "|";
    for(int i = 0; i < cols; i++) {
        for(int j = 0; j < s+1; j++) {
            std::cout << "-";
                  
        }
        std::cout << "|";
    }
   
    std::cout << std::endl;
}

template <class type>
void Matrix<type>::printMatrix(int s) {
    for(int i = 0; i < nRow; i++) {
        if(i == 0) printRow(s,nCol);
        for(int j = 0; j < nCol; j++) {
             std::string p = std::to_string(at(i,j));
            std::string x = p;
            if(p.length() > s ) {
                x = p.substr(0,s-1);
                x += ",";
            }

            if(j == 0) std::cout << "| ";
            std::cout << std::setw(s) << x;
            std::cout << "| ";
        }
        std::cout << std::endl;
        printRow(s, nCol);

    }
}


#endif
