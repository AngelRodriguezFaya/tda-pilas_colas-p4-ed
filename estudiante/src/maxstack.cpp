/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Noviembre 2024
 */

#include <iostream>
#include <vector>
#include "maxstack.h"

using namespace std;

MaxStack::MaxStack(){}

bool MaxStack::vacia() const{
    return pila.empty();
}

int MaxStack::tamanio() const{
    return pila.size();
}

void MaxStack::poner(const int &x){

    queue<int> aux;

    // Vaciamos la cola de nuestra clase a una cola auxiliar
    while(!pila.empty()){
        aux.push(pila.front());
        pila.pop();
    }
    
    // Una vez que esté vacía, metemos el nuevo elemento en la cola de nuestra clase
    pila.push(x);

    // Volvemos a meter los elementos que hay en la cola auxiliar en la cola de nuestra clase.
    // De esta forma, el nuevo elemento quedará en la parte superior de la cola, simulando el comportamiento de una pila.
    while(!aux.empty()){
        pila.push(aux.front());
        aux.pop();
    }

    // Inserto el nuevo elemento en la cola con prioridad SI ES CANDIDATO A SER EL NUEVO MÁXIMO, SI NO, NO LO METO.
    if (!maximos.empty()){
        if(maximos.top() <= x)
            maximos.push(x);
    } else 
        maximos.push(x);
}

void MaxStack::quitar(){

    if(pila.front() == maximos.top()){
        maximos.pop();
    }

    pila.pop();
}

elemento MaxStack::tope(){

    elemento e;

    e.valor = pila.front();
    e.maximo = maximos.top();

    return e;
}



