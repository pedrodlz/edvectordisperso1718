#include <cassert>
#include <algorithm>

//TO-DO: Completar la implementacion de los metodos de vectorD.h

using namespace std;

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

template <typename T>
vectorD<T>::~vectorD()
{
    n_ele = 0;
}

template <class T>
typename vectorD<T>::size_type vectorD<T>::size() const{

	return n_ele;
}

template <class T>
T vectorD<T>::default_value() const{

	return v_nulo;
}

template <class T>
bool vectorD<T>::empty(){

	return n_ele == 0;
}

template <typename T>
void vectorD<T>::set(int p, const T & t){

	if(t != v_nulo){
		if(p < n_ele){

			int i = 0;
			bool sigo = true;

            typename list<pair<int,T> >::iterator it;

			for(it = vd.begin(); it != vd.end() && sigo; ++it){
				if((it)->first == p){
					(it)->first = t;
					sigo = false;
				}
				else if((*it).first > p){
                    cout << (*it).first ;
                    pair<int,T> par (p,t);
					vd.insert(it,par);
					sigo = false;
				}
				i++;
			}
		}
	}
}

template <class T>
void vectorD<T>::push_back(const T & t){
	if(t != v_nulo){
        pair<int,T> par (n_ele,t);
        vd.push_back(par);
    }

	n_ele++;
}

template <class T>
void vectorD<T>::pop_back(){
	if(vd.back().first == n_ele -1)
		vd.pop_back();

	n_ele--;
}

template <class T>
void vectorD<T>::clear(){
	if(!vd.empty())
		vd.clear();

	n_ele = 0;
}

template <class T>
void vectorD<T>::resize(int s){

	if (s < n_ele){
		while(vd.back().first >= s - 1)
			vd.pop_back();
	}

	n_ele = s;
}

template <class T>
vectorD<T> & vectorD<T>::operator=(const vectorD<T> & x)
{
    if (this != &x) {
    	*this.n_ele = x.n_ele;
    	*this.v_nulo = x.v_nulo;
    	*this.vd = x.vd;
    }
	return *this;
}

template <typename T>
const T & vectorD<T>::operator[](int c) const
{
	bool sigo = true;

    typename list<pair<int,T> >::const_iterator it;

	for(it = vd.begin(); it != vd.end() && sigo; ++it){ //Se busca si es no nulo
		if((*it).first == c){
			return ((*it).first);
			//sigo = false; <--no tiene sentido despues de un return
		}
	}

	if (sigo) return v_nulo;				//Si es nulo se devuelve una referencia a el atributo de la clase,
												//Por qué? no se
}

template <class T>
bool vectorD<T>::operator==(const vectorD<T> & x)
{
	bool iguales = false;

    if(n_ele == x.n_ele){
        if(v_nulo == x.v_nulo){
            if(vd.size() == x.vd.size()){

                iguales = *this == x;
            }
        }
    }

	return iguales;
}

template <class T>
bool vectorD<T>::operator!=(const vectorD<T> & x)
{
	return !(*this == x);
}

template <class T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin()
{
    stored_iterator i;
    i.ite = vd.begin();
    return i;
}

template <typename T>
typename vectorD<T>::stored_iterator vectorD<T>::send()
{
    stored_iterator i;
    i.ite = vd.end();
    return i;
}
/*
//FALTA BEGIN() Y END()
template <class T>
typename vectorD<T>::iterator vectorD<T>::begin()
{
    stored_iterator i;
    i.ite = vd.begin();
    return i;
}

template <typename T>
typename vectorD<T>::iterator vectorD<T>::end()
{
    iterator i;
    i.ite = vd.end();
    return i;
}
*/

//Implementacion iterator
template <typename T>
vectorD<T>::iterator::iterator(){ }

template <typename T>
vectorD<T>::iterator::iterator(const iterator & d)
{
    i_vect = d.i_vect;
    ite_rep = d.ite_rep;
    el_vect = d.el_vect;
}
/*
template <typename T>
const T & vectorD<T>::iterator::operator * ()
{
    stored_iterator ite;
    for(ite = el_vect.sbegin(); ite != el_vect.send(); ++ite){
        if((*ite).first == i_vect){
            return((*ite).second);
        }
    }
    return(el_vect->default_value());
}
/*
template <typename T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator++()
{
    i_vect++;
    iterator i = el_vect.begin();
    return(i);
}

template <typename T>
typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int)
{
    i_vect++;
    iterator i = el_vect.begin();
    return(i);
}*/
/*
template <typename T>
bool vectorD<T>::iterator::operator==(const iterator & d)
{
    return();
}*/
