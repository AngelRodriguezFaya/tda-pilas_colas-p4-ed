/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Octubre 2024
 */

#define MAXSTACK__H

#include <iostream>
#include <list>

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

class MaxQueue{
    
    private:

        /**
         * @brief Lista para almacenar los elementos de la cola
         */
        list<elemento> cola;

    public:

        MaxQueue();

        MaxQueue(const MaxQueue& mq);

        void empty();

        int size();

        elemento front();

        elemento back();

        void push(int n);

        void pop();
};