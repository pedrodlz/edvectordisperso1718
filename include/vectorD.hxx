#include <cassert>
#include <algorithm>

//TO-DO: Completar la implementacion de los metodos de vectorD.h

template <class T>
vectorD<T>::vectorD(const  T  & t){
  n_ele = 0;                  
  v_nulo = t;
}

template <class T>
vectorD<T>::vectorD(const vectorD<T> & b){
  //...
}


template <class T>
vectorD<T>::vectorD(int numcomp, const  T  & t){
  //...
}


template <class T>
typename vectorD<T>::size_type vectorD<T>::size() const{
  //...
}

//...
