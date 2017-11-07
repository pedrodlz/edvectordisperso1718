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

			for(std::list<int>::iterator it = vd.begin(); it != vd.end() && sigo; ++it){
				if(get<0>(it) == p){
					get<0>(it) = t;
					sigo = false;
				}			
				else if(get<0>(it) > p){
					it.insert(i,pair<p,t>);
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
	if(get<0>(vd.back()) == n_ele -1)
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
		while(get<0>(vd.back()) >= s - 1)
			vd.pop_back();
	}

	n_ele = s;
}
