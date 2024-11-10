/**
 * @file ej2.cpp
 * @brief Archivo de implementación del ejercicio 2
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 09 noviembre 2024
 * 
 * Ejercicio 2: Invertir el orden de los elementos de una cola
 */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/**
 * @brief Función que invierte el orden de los elementos de una cola.
 * @param cola Cola a invertir.
 * @post La cola queda invertida.
 */
template <typename T>
void invierte_cola(queue<T> &cola){
    stack<T> pila;

    // cola -> pila
    while(!cola.empty()){
        pila.push(cola.front());
        cola.pop();
    }

    // pila -> cola
    while(!pila.empty()){
        cola.push(pila.top());
        pila.pop();
    }
}

int main(){
    queue<int> c;

    cout << "El contenido de la cola es: 4 99 74 53" << endl;
    c.push(4);
    c.push(99);
    c.push(74);
    c.push(53);

    invierte_cola(c);
    cout << "Cola invertida." << endl; 

    cout << "El contenido de la cola invertida es: ";
    while(!c.empty()){
        cout << c.front() << " ";
        c.pop();
    }

    cout << endl;

    return 0;
}