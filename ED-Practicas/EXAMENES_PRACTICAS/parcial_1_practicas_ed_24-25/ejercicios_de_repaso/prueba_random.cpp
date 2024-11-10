/**
 * @file prueba_random.cpp
 * @brief Archivo de implementación de un ejemplo de primer parcial de prácticas 
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 10 noviembre 2024
 * 
 * Reordenar los elementos de una pila de tal forma que queden los elementos pares por encima 
 * de los impares.
 * 
 * Se tienen que utilizar pilas auxiliares.
 */

#include <iostream>
#include <stack>

using namespace std;

void flota_pares(stack<int> &pila){

    //Para que aparezca en el orden que indica el enunciado tengo que hacer algunos cambios.
    
    stack<int> aux1, aux2, pares, impares;
    int n=-1;

    while(!pila.empty()){
        n=pila.top();
        pila.pop();
        if((n%2)==0)
            pares.push(n);
        else 
            impares.push(n);
    }

    //Ordeno para que salga como el enunciado.

    pares.swap(aux1);
    while(!aux1.empty()){
        pares.push(aux1.top());
        aux1.pop();
    }

    impares.swap(aux2);
    while(!aux2.empty()){
        impares.push(aux2.top());
        aux2.pop();
    }

    // Paso a la pila.

    while(!impares.empty()){
        pila.push(impares.top());
        impares.pop();
    }

    while(!pares.empty()){
        pila.push(pares.top());
        pares.pop();
    }
}

int main(){
    stack<int> pila;

    //Input: 4 9 7 2 0 17
    pila.push(17);
    pila.push(0);
    pila.push(2);
    pila.push(7);
    pila.push(9);
    pila.push(4);
    cout << "Elementos insertados en la pila" << endl;

    flota_pares(pila);
    
    cout << "Los elementos de la pila transformada son: ";
    while (!pila.empty()){
        cout << pila.top() << " ";
        pila.pop();
    }   

    cout << endl;

    return 0;
}

