/**
 * @file prueba_B1.cpp
 * @brief Archivo de implementación del primer parcial de prácticas del grupo B1
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 10 noviembre 2024
 * 
 * Crear una función a la que se le pasa la pila y elimina los elementos impares 
 * que aparaezcan repetidos y consecutivos.
 */

#include <iostream>
#include <stack>

using namespace std;

void transformarpila(stack<int> &p){
    int actual = 0, 
        anterior = 0;
    stack<int> aux;

    while(!p.empty()){
        actual = p.top();
        p.pop();
        if((actual%2) == 0)     // Si es par lo añade
            aux.push(actual);
        else{                   // Si es impar ....
            if(actual != anterior)   // ... y el actual es distinto del anterior, lo añade
                aux.push(actual);
        }
        anterior = actual;
    }

    while(!aux.empty()){
        p.push(aux.top());
        aux.pop();
    }
}

int main(){
    stack<int> pila;

    //Input: 1 1 2 3 3 4 5 5 1 1 9 8 7 7 3
    pila.push(3);
    pila.push(7);
    pila.push(7);
    pila.push(8);
    pila.push(9);
    pila.push(1);
    pila.push(1);
    pila.push(5);
    pila.push(5);
    pila.push(4);
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(1);
    pila.push(1);
    cout << "Elementos insertados en la pila" << endl;

    transformarpila(pila);
    cout << "Transformando la pila....." << endl;

    cout << "Los elementos de la pila transformada son: ";
    while (!pila.empty()){
        cout << pila.top() << " ";
        pila.pop();
    }   

    cout << endl;

    return 0;
}
