/**
 * @file prueba_D3.cpp
 * @brief Archivo de implementación del primer parcial de prácticas del grupo D3
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 10 noviembre 2024
 * 
 * Crear una función a la que se le pasa una pila con elementso repetidos y ordenados de menor a mayor
 * y se tiene que devolver una pila ordenada de la misma forma y como contenido tiene pares donde la 
 * primera posición es el número y la segunda es el número de veces que aparece en la pila.
 */

#include <iostream>
#include <stack>
#include <utility> // Para usar pair

using namespace std;

void cuentasecuencias(stack<int> &p, stack<pair<int,int>> &pout){
    stack<pair<int,int>> aux;
    
    //Preparo la primera iteración... 
    int num = p.top();
    p.pop();
    pair<int,int> par(num, 1);
    
    //y empiezo desde la segunda.
    while(!p.empty()){
        num = p.top();
        p.pop();
        if(num == par.first)
            par.second++;
        else{  // Si es un número distinto 
            par.first = num;
            par.second = 1;
        }
        cout << "Vamos por: ";
        cout << par.first << " " << par.second << endl;

        //Compruebo si es la última iteración o si el siguiente número es igual o no
        //para saber si tengo que guardar el pair en la pila.
        if(p.empty() || (!p.empty() && num != p.top())){
            cout << "Vamos a guardar: " << par.first << " " << par.second << endl; 
            aux.push(par);
        }
    }

    while(!aux.empty()){
        pout.push(aux.top());
        aux.pop();
    }
}

int main(){
    stack<int> pila;
    stack<pair<int, int>> pila_secuencias;

    //Input: 1 1 1 2 3 3 7 7 7
    pila.push(7);
    pila.push(7);
    pila.push(7);
    pila.push(3);
    pila.push(3);
    pila.push(2);
    pila.push(1);
    pila.push(1);
    pila.push(1);
    cout << "Elementos insertados en la pila" << endl;

    cuentasecuencias(pila, pila_secuencias);
    
    cout << "Los elementos de la pila con secuencias son: ";
    while (!pila_secuencias.empty()){
        cout << "(" << pila_secuencias.top().first << ", " << pila_secuencias.top().second << ") ";
        pila_secuencias.pop();
    }   

    cout << endl;

    return 0;
}

