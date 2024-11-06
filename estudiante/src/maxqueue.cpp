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

void MaxQueue::empty() {

    cola.clear();

}

int MaxQueue::size() {

    return cola.size();

}

elemento MaxQueue::front() {

    return cola.front();

}

elemento MaxQueue::back() {

    return cola.back();

}

void MaxQueue::push(int n) {

    elemento aux;
    aux.valor = n;
    aux.maximo = n;

    if(cola.size() == 0){

        cola.push_back(aux);

    }else{

        cola.push_back(aux);

        auto rit = cola.rbegin();
        while(aux.maximo > (*++rit).maximo){

            (*rit).maximo = aux.maximo;

        }
    }
}

void MaxQueue::pop() {

    cola.pop_front();

}