#pragma once
#include <iostream>

template<typename T>
class Tableau2D
{
protected:
  T** table;
  std::size_t nbLine;
  std::size_t nbColumn;

public:
  Tableau2D(std::size_t nbC, std::size_t nbL);
  Tableau2D(const Tableau2D&);
  T operator()(std::size_t C, std::size_t L)const;
  T& operator()(std::size_t C, std::size_t L);
  template<typename U>
  friend std::ostream& operator<<(std::ostream& , const Tableau2D<U> &);
  bool operator== (const Tableau2D<T>& lhs) const;
  Tableau2D<T>& operator=(const Tableau2D<T>& m);
  virtual ~Tableau2D();
};
//Constructor
template<typename T>
Tableau2D<T>::Tableau2D(std::size_t nbC, std::size_t nbL)
{
  nbLine=nbL;
  nbColumn=nbC;
  table=new T* [nbLine];
  for(size_t i=0 ; i<nbLine ;++i)
  {
    table[i]=new T [nbColumn];
  }
}

template<typename T>
Tableau2D<T>::Tableau2D(const Tableau2D<T>& t):Tableau2D(t.nbColumn,t.nbLine)
{
  for(size_t i=0 ; i < nbLine ; i++)
  {
    for(size_t j=0 ; j < nbColumn ; j++)
     {
       table[i][j]=t.table[i][j];
     }
  }
}

//Destructor
template<typename T>
Tableau2D<T>::~Tableau2D()
{
  for(size_t i=0 ; i<nbLine ; ++i)
  {
    delete[] table[i];
  }
  delete[] table;
}

//Operators
template<typename T>
T Tableau2D<T>::operator()(std::size_t C, std::size_t L)const
{
  return table[L][C];
}
template<typename T>
T& Tableau2D<T>::operator()(std::size_t C, std::size_t L)
{
  return table[L][C];
}

template<typename T>
std::ostream& operator<<(std::ostream& os , const Tableau2D<T> & t)
{
  for(size_t i=0 ; i < t.nbLine ; i++)
  {
    for(size_t j=0 ; j < t.nbColumn ; j++)
     {
       os<< t.table[i][j]<<"\t";
     }
     os<<std::endl;
  }
  return os;
}

template<typename T>
bool Tableau2D<T>::operator==(const Tableau2D<T>& rhs) const
{
  bool egalite=true;
  for(size_t i=0 ; i < nbLine ; i++)
  {
    for(size_t j=0 ; j < nbColumn ; j++)
     {
       if(table[i][j] != rhs.table[i][j])
         {
           egalite=false;
           return egalite;
         }
     }
  }
  return egalite;
}

template<typename T>
Tableau2D<T>& Tableau2D<T>::operator=(const Tableau2D<T>& m)
{
  if((nbLine!=m.nbLine) || (nbColumn!=m.nbColumn))
  {
    //Deallocate table
    for(size_t i=0 ; i < nbLine ; i++)
    {
       delete[] table[i];
    }
    delete[] table;

    //Reallocate tableau
    nbLine=m.nbLine;
    nbColumn=m.nbColumn;
    table=new T* [m.nbLine];
    for(size_t i=0 ; i < m.nbLine ; i++)
    {
       table[i]=new T [m.nbColumn];
       for(size_t j=0 ; j < nbColumn ; j++)
        {
          table[i][j]=m.table[i][j];
        }
    }
  }
  else
  {
    for(size_t i=0 ; i < m.nbLine ; i++)
    {
       for(size_t j=0 ; j < nbColumn ; j++)
        {
          table[i][j]=m.table[i][j];
        }
    }
  }
  return *this;
}
