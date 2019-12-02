#pragma once
#include"tableau2D.hh"
#include<iostream>
template <typename T>
class Matrix : public Tableau2D<T>
{
protected:
public:
  //Constructor
  Matrix(std::size_t nbC, std::size_t nbL, T value);
  Matrix(const Tableau2D<T>& t);

  //Operator Matrix/Matrix
  friend Matrix operator+(const Matrix<T>& M,const Matrix<T>& N)
  {
    Matrix res(M);
    for(size_t i=0 ; i < res.nbLine ; ++i)
    {
      for(size_t j=0 ; j< res.nbColumn ; ++j)
      {
        res.table[i][j]+=N.table[i][j];
      }
    }
    return res;
  };

  friend Matrix operator-(const Matrix<T>& M, const Matrix<T>& N)
  {
    Matrix res(M);
    for(size_t i=0 ; i < res.nbLine ; ++i)
    {
      for(size_t j=0 ; j< res.nbColumn ; ++j)
      {
        res.table[i][j]-=N.table[i][j];
      }
    }
    return res;
  };

  friend Matrix operator*(const Matrix<T>& M, const Matrix<T>& N)
  {
    Matrix res(M.nbColumn, M.nbLine,0);
    for(size_t i=0 ; i < res.nbLine ; ++i)
    {
      for(size_t j=0 ; j < N.nbColumn ; ++j)
      {
        for(size_t k=0 ; k < res.nbLine ; ++k)
        {
          res.table[i][j]+=M.table[i][k]*N.table[k][j];
        }
      }
    }
    return res;
  };

  //Operator Scalar/Matrix
  template<typename U> //function used to multiply with scalar on two sides
  friend Matrix multiply(const U&coeff,const Matrix<T>& M)
  {
    Matrix res(M);
    for(size_t i=0 ; i< res.nbLine ; ++i)
    {
      for(size_t j=0 ; j< res.nbColumn ; ++j)
      {
        res.table[i][j]*=coeff;
      }
    }
    return res;
  }
  //Multiplication
  template<typename U>
  friend Matrix operator*(const U&coeff,const Matrix<T>& M)
  {
    return multiply(coeff,M);
  }
  template<typename U>
  friend Matrix operator*(const Matrix<T>&M, const U& coeff)
  {
    return multiply(coeff,M);
  }
  //Division
  friend Matrix operator/(const Matrix<T>&M, const float& coeff)
  {
    return multiply(1/coeff,M);
  }
  //Addition
  template<typename U> //function used to add a scalar on two sides
  friend Matrix add(const U&coeff,const Matrix<T>& M)
  {
    Matrix res(M);
    for(size_t i=0 ; i< res.nbLine ; ++i)
    {
      for(size_t j=0 ; j< res.nbColumn ; ++j)
      {
        res.table[i][j]+=coeff;
      }
    }
    return res;
  }
  //Addition
  template<typename U>
  friend Matrix operator+(const U&coeff,const Matrix<T>& M)
  {
    return add(coeff,M);
  }
  template<typename U>
  friend Matrix operator+(const Matrix<T>&M, const U& coeff)
  {
    return add(coeff,M);
  }
  //Substract
  template<typename U>
  friend Matrix operator-(const Matrix<T>&M, const U& coeff)
  {
    return add(-coeff,M);
  }

  //Transpose
  friend Matrix transpose(const Matrix<T>& M)
  {
    Matrix res(M.nbLine,M.nbColumn,0);
    for(size_t i=0 ; i < res.nbLine ;++i)
    {
      for(size_t j=0 ; j < res.nbColumn ; ++j)
      {
        res.table[i][j]=M.table[j][i];
      }
    }
    return res;
  }

};

//Constructor
template<typename T>
Matrix<T>::Matrix(std::size_t nbC, std::size_t nbL,T value):Tableau2D<T>(nbC,nbL)
{
  for(size_t i=0 ; i<this->nbLine ; ++i)
  {
    for(size_t j=0 ; j<this->nbColumn ; ++j)
    {
      this->table[i][j]=value;
    }
  }
}
template<typename T>
Matrix<T>::Matrix(const Tableau2D<T>& t):Tableau2D<T>(t){};
