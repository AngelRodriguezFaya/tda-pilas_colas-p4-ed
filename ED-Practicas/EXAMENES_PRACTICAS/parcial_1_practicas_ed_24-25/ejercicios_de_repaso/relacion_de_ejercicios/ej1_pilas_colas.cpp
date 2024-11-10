/**
 * @file ej1.cpp
 * @brief Archivo de implementación del ejercicio 1
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 09 noviembre 2024
 * 
 * Ejercicio 1: Invertir el orden de los elementos de una pila.
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * @brief Función que invierte el orden de los elementos de una pila.
 * @param pila Pila a invertir.
 * @post La pila queda invertida.
 */
template <typename T>
void invierte_pila(stack<T> &pila){
    stack<T> aux;

    while(!pila.empty()){
        aux.push(pila.top());
        pila.pop();
    }

    pila.swap(aux);
}


int main(){

    stack<int> pila;

    // Input: 2 8 40 28 7 82
    pila.push(2);
    pila.push(8);
    pila.push(40);
    pila.push(28);
    pila.push(7);
    pila.push(82);
    cout << "El contenido de la pila es: 82 7 28 40 8 2" << endl;

    invierte_pila(pila);
    cout << "Pila invertida" << endl;

    cout << "El contenido de la pila después de invertirla es: ";
    while(!pila.empty()){
        cout << pila.top() << " ";
        pila.pop();
    }    

    cout << endl;

    return 0;
}