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

	*this = b;
}


template <class T>
vectorD<T>::vectorD(int numcomp, const  T  & t){
	n_ele = numcomp;
	v_nulo = t;
}


template <class T>
typename vectorD<T>::size_type vectorD<T>::size() const{

	return n_ele;
}

template <class T>
typename vectorD<T>::T vectorD<T>::default_value() const{

	return v_nulo;
}

template <class T>
typename vectorD<T>::bool vectorD<T>::empty(){

	return n_ele == 0;
}

template <class T>
typename vectorD<T>::void vectorD<T>::set(int p, const T & t){

	if(t != v_nulo){
		if(p < n_ele){
		
			int i = 0;
			bool sigo = true;

			for(std::list<T>::iterator it = vd.begin(); it != vd.end() && sigo; ++it){
				if(*it.first == p){
					*it.first = t;
					sigo = false;
				}			
				else if(*it.first > p){
					*it.insert(i,pair<p,t>);
					sigo = false;
				}
				i++;
			}
		}
	}
}

template <class T>
typename vectorD<T>::void vectorD<T>::push_back(const T & t){
	if(t != v_nulo)
		vd.push_back(pair<n_ele,t>);

	n_ele++;
}

template <class T>
typename vectorD<T>::void vectorD<T>::pop_back(){
	if(vd.back().first == n_ele -1)
		vd.pop_back();

	n_ele--;
}

template <class T>
typename vectorD<T>::void vectorD<T>::clear(){
	if(!vd.empty())
		vd.clear();

	n_ele = 0;
}

template <class T>
typename vectorD<T>::void vectorD<T>::resize(int s){

	if (s < n_ele){
		while(vd.back().first >= s - 1)
			vd.pop_back();
	}

	n_ele = s;
}

template <class T>
typename vectorD<T>::vectorD<T> & vectorD<T>::operator=(const vectorD<T> & x)
{
	*this.n_ele = x.n_ele;
	*this.v_nulo = x.v_nulo;
	*this.vd = x.vd;
	
	return this;
}

template <class T>
typename vectorD<T>::const T & vectorD<T>::operator[](int c) const
{
	bool sigo = true;
	T* referencia;
		
	for(std::list<T>::iterator it = vd.begin(); it != vd.end() && sigo; ++it){ //Se busca si es no nulo
		if(*it.first == c){
			referencia = it;
			sigo = false;
		}
	}
	
	if (sigo) referencia = &v_nulo;				//Si es nulo se devuelve una referencia a el atributo de la clase,
												//Por qué? no se
	
	return referencia;
}
