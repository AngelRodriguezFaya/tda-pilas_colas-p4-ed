/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Octubre 2024
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

void MaxStack::poner(int x){
    queue<int> aux;

    // Vaciamos la cola de nuestra clase a una cola auxiliar
    while(!pila.empty()){
        aux.push(pila.front());
        pila.pop();
    }
    
    // Una vez que esté vacía, metemos el nuevo elemento en la cola de nuestra clase
    pila.push(x);

    // Inserto el nuevo elemento en la cola con prioridad
    maximos.push(x);

    // Volvemos a meter los elementos que hay en la cola auxiliar en la cola de nuestra clase.
    // De esta forma, el nuevo elemento quedará en la parte superior de la cola, simulando el comportamiento de una pila.
    while(!aux.empty()){
        pila.push(aux.front());
        aux.pop();
    }

}

// Eliminar el elemento implica eliminarlo de ambas colas.
void MaxStack::quitar(){

    int n = pila.front();
    pila.pop();

    vector<int> aux;
    while(maximos.top() != n){
        aux.push_back(maximos.top());
        maximos.pop();
    }

    //Una vez que hemos encontrado el elemento a eliminar de la cola con prioridad, lo eliminamos.
    maximos.pop();

    // Volvemos a meter los elementos que hay en la cola auxiliar en la cola con prioridad.
    while(!aux.empty()){
        maximos.push(aux.front());
        aux.erase(aux.begin());
    }   

}

// Corregido el error de segmetation fault. Ahora se devuelve un elemento por valor y no por referencia.
elemento MaxStack::tope(){

    elemento e;

    e.valor = pila.front();
    e.maximo = maximos.top();

    return e;
}



