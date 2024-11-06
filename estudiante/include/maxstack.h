/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Noviembre 2024
 */

#ifndef MAXSTACK__H
#define MAXSTACK__H

#include <iostream>
#include <queue>

using namespace std;

/**
 * @brief Estructura elemento.
 * 
 * Esta estructura representa un elemento de la pila, que contiene el valor del elemento y el 
 * maximo valor insertado en la pila hasta el momento.
 */
struct elemento{
    int valor;
    int maximo;

    /**
     * @brief Sobrecarga del operador de salida.
     * @param os Referencia al flujo de salida.
     * @param e Referencia constante al elemento a imprimir.
     * @pre El elemento e debe tener un valor y un maximo, es decir, no debe ser nulo.
     * @return Referencia al flujo de salida.
     * @post Se imprime el valor y el maximo del elemento e en el flujo de salida.
     */
    friend ostream& operator<<(ostream& os, const elemento& e){
        os << e.valor << ", " << e.maximo;
        return os;
    }
};

/**
 * @brief TDA MaxStack
 * 
 * Una instancia del tipo de dato abstracto MaxStack es una pila de enteros que almacena el número 
 * insertado y el número máximo en la pila en cada momento.
 * 
 * El TDA MaxStack proporciona distintas operaciones para trabajar con la pila, como inserciones y borrados 
 * de elementos, así como la obtención del elemento en el tope.
 * 
 * La pila se implementa mediante dos colas, una de tipo queue para almacenar los elemntos que vamos insertando, 
 * y otra de tipo priority_queue para almacenar los maximos. Solamente se puede acceder por el frente de las colas,
 * simulando así el comportamiento de una pila.
 * 
 * Para poder utilizar el TDA MaxStack se debe incluir el fichero
 * 
 * \include "maxstack.h"
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Octubre 2024
 * 
 */
class MaxStack{
    
    private:

        /**
         * @brief Cola de enteros para almacenar los elementos de la pila.
         */
        queue<int> pila;

        /**
         * @brief Cola de prioridad de enteros para almacenar los maximos de la pila.
         */
        priority_queue<int> maximos;

    public:

        /**
         * @brief Constructor por defecto.
         * @post Crea una pila vacía.
         * @return MaxStack, el objeto creado.
         */
        MaxStack();

        /**
         * @brief Comprueba si la pila esta vacía.
         * @pre La pila debe estar creada.
         * @return true si la pila esta vacía, false en caso contrario.
         */
        bool vacia() const;
        
        /**
         * @brief Devuelve el tamaño de la pila.
         * @pre La pila debe estar creada.
         * @return El tamaño de la pila, es decir, el número de elementos que contiene.
         */
        int tamanio() const;

        /**
         * @brief Inserta un elemento en la pila.
         * @param x Entero a insertar en la pila.
         * @pre La pila debe estar creada.
         * @return void
         * @post La pila contiene un elemento más, que es el entero x.
         */
        void poner(const int &x);

        /**
         * @brief Elimina el elemento que hay en el tope de la pila.
         * @pre La pila debe estar creada y no debe estar vacía.
         * @return void
         * @post La pila contiene un elemento menos, que es el que estaba en el tope.
         */
        void quitar();

        /**
         * @brief Devuelve el elemento que hay en el tope de la pila.
         * @pre Tanto la pila como los maximos no pueden estar vacios.
         * @return elemento, objeto de tipo elemento que contiene el valor y el maximo del elemento que hay en el tope de la pila. 
         */
        elemento tope();
};

#endif // MAXSTACK__H

