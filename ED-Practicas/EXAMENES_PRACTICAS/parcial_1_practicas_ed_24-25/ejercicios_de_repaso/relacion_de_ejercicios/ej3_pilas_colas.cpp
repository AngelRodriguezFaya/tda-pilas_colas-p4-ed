/**
 * @file ej3.cpp
 * @brief Archivo de implementación del ejercicio 3
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 09 noviembre 2024
 * 
 * Ejercicio 3: Dada una pila y una cola, generar una cola que devolveremos. Dicha cola tendrá en las
 * posiciones pares las posiciones pares de la pila y en las posiciones impares las posiciones impares 
 * de la cola. La pila y la cola de entrada no tienen por qué tener el mismo tamaño, hay que ajustarse 
 * al tamaño de la estructura más pequeña.
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/**
 * @brief Función que genera una cola a partir de una pila y una cola.
 * @param p Pila de la que se tomarán los elementos.
 * @param c Cola de la que se tomarán los elementos.
 * @return Cola generada.
 * @post En las posiciones pares de la cola devuelta estarán los elementos que estén en las posiciones pares de la pila  
 * y en las posiciones impares de la cola devuelta estarán los elementos que estén en las posiciones impares de la cola.
 * @post La cola devuelta tendrá el tamaño de la estructura más pequeña. * 
 */
template<typename T>
queue<T> alterna_pila_cola(stack<T> p, queue<T> c){
    queue<T> cola;
    int tamanio = 0;

    // Veo cuál tiene menor tamaño
    if(p.size() <= c.size())
        tamanio = p.size();
    else
        tamanio = c.size();

    for(int i = 0; i < tamanio; i++){
        if((i%2)==0)    // posicion par
            cola.push(p.top());
        else            // posicion impar
            cola.push(c.front());
        p.pop();
        c.pop();
    }

    return cola;
}

int main(){

    queue<int> cola, cola_alternada;
    stack<int> pila;

    // Pila -> Input: 8 7 6 3 4
    pila.push(8);
    pila.push(7);
    pila.push(6);
    pila.push(3);
    pila.push(4);
    cout << "El contenido de la PILA es: \n4\n \n3\n \n6\n \n7\n \n8\n \ndonde 4 es el elemento que está en el tope." << endl;

    // Cola -> Input: 5 1 2 9
    cola.push(5);
    cola.push(1);
    cola.push(2);
    cola.push(9);
    cout << "\nEl contenido de la COLA es: \n\t5 1 2 9\ndonde 5 es el elemento que está en el frente." << endl;

    cola_alternada = alterna_pila_cola(pila, cola);

    cout << "\nEl contenido de la COLA ALTERNADA es: ";
    while(!cola_alternada.empty()){
        cout << cola_alternada.front() << " ";
        cola_alternada.pop();
    }

    cout << endl << endl;   

    return 0;
}