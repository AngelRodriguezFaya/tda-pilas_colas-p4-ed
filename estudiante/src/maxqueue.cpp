/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Noviembre 2024
 */

#include <iostream>
#include <vector>
#include "maxqueue.h"

using namespace std;

MaxQueue::MaxQueue() {}

MaxQueue::MaxQueue(const MaxQueue& mq){


}

bool MaxQueue::empty() const{

    return cola.size()==0;

}

int MaxQueue::size() const{

    return cola.size();

}

elemento& MaxQueue::front() {

    return cola.front();

}

const elemento& MaxQueue::front() const{

    return cola.front();

}

elemento& MaxQueue::back() {

    return cola.back();

}

const elemento& MaxQueue::back() const{

    return cola.back();

}

void MaxQueue::push(const int& n) {

    elemento aux;
    aux.valor = n;
    aux.maximo = n;

    if(cola.empty()){

        cola.push_back(aux);

    }else{

        cola.push_back(aux);

        auto rit = cola.rbegin();
        while(aux.maximo > (*++rit).maximo){

            (*rit).maximo = aux.maximo;

        }
    }
}

/*
void MaxQueue::emplace(int n){

    if(cola.empty()){

        cola.emplace_back(n, n);

    }else{

        cola.emplace_back(n, n);

        auto rit = cola.rbegin();
        while(n > (*++rit).maximo){

            (*rit).maximo = n;

        }
    }

}
*/

void MaxQueue::pop() {

    cola.pop_front();

}

void MaxQueue::swap(MaxQueue& c) noexcept{

    cola.swap(c.cola);

}