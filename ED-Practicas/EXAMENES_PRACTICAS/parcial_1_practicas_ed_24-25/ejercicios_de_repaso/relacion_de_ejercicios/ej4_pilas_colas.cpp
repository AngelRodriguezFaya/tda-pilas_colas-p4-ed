/**
 * @file ej4.cpp
 * @brief Archivo de implementación del ejercicio 4
 * 
 * @author Ángel Rodíguez Faya
 *
 * @date 09 noviembre 2024
 * 
 * Ejercicio 4: Eliminar los elementos de una cola que sean menores que 10.
 */

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Función que elimina los elementos de una cola que sean menores que 10.
 * @pre La cola no puede estar vacía.
 * @param cola Cola de la que se eliminarán los elementos.
 * @post La cola queda modificada.
 */
void elimina_menores_que_10(queue<int> &cola){
    queue<int> aux;
    int num = 0;

    // cola -> aux
    while(!cola.empty()){
        num = cola.front();
        if(num >= 10)
            aux.push(num);
        cola.pop();
    }
    
    // cola <-> aux
    cola.swap(aux);
}

int main(){
    queue<int> cola;

    // Input: 1 16 24 9 30 3
    cola.push(1);
    cola.push(16);
    cola.push(24);
    cola.push(9);
    cola.push(30);
    cola.push(3);
    cout << "\nEl contenido de la COLA es: \n\t1 16 24 9 30 3\ndonde 1 es el elemento que está en el frente." << endl;

    elimina_menores_que_10(cola);
    cout << "\nEliminando menores que 10..." << endl;

    cout << "\nEl contenido de la COLA es: ";
    while (!cola.empty()){
        cout << cola.front() << " ";
        cola.pop();
    }

    cout << endl;
    
    return 0;
}