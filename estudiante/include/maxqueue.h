/**
 * @file maxqueue.h
 * @brief  Archivo de especificación del TDA MaxQueue
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Noviembre 2024
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

    /*
    elemento(){}

    elemento(int v, int m){
        valor = v;
        maximo = m;
    }
     */

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

        /**
         * @brief Constructor por defecto de MaxQueue.
         * @post Crea una instancia de MaxQueue con cola vacia.
         */
        MaxQueue();

        /**
         * @brief Constructor de copia. Inicializa una nueva instancia de MaxQueue como copia de otra.
         * @param mq Referencia constante a otra instancia de MaxQueue.
         * @post Crea una instancia de MaxQueue con una cola igual a la de mq.
         */
        MaxQueue(const MaxQueue& mq);

        /**
         * @brief Comprueba si la cola está vacía.
         * @return true si la cola está vacía, false en caso contrario.
         */
        bool empty() const;

        /**
         * @brief Devuelve el tamaño de la cola.
         * @return Número de elementos en la cola.
         */
        int size() const;

        /**
         * @brief Accede al primer elemento de la cola.
         * Consulta o asigna un valor al frente de la cola.
         * @return Referencia al primer elemento de la cola.
         * @pre La cola no debe estar vacía.
         */
        elemento& front();

        /**
         * @brief Consulta el primer elemento de la cola.
         * @return Referencia constante al primer elemento de la cola.
         * @pre La cola no debe estar vacía.
         */
        const elemento& front() const;

        /**
         * @brief Accede al último elemento de la cola.
         * Consulta o asigna un valor al final de la cola.
         * @return Referencia al último elemento de la cola.
         * @pre La cola no debe estar vacía.
         */
        elemento& back();

        /**
         * @brief Consulta el último elemento de la cola.
         * @return Referencia constante al último elemento de la cola.
         * @pre La cola no debe estar vacía.
         */
        const elemento& back() const;

        /**
         * @brief Inserta un nuevo elemento al final de la cola y actualiza los maximos
         * si es necesario.
         * @param n Valor entero a insertar en la cola.
         * @post Aumenta en 1 el tamaño de la cola.
         * @post Actualiza los maximos de la cola de elementos.
         */
        void push(const int& n);

        //void push(const int&& n);

        //void emplace(int n);

        /**
         * @brief Elimina el primer elemento de la cola.
         * @pre La cola no debe estar vacía.
         * @post Disminuye en 1 el tamaño de la cola
         */
        void pop();

        /**
         * @brief Intercambia el contenido de dos instancias de MaxQueue,
         * intercambiando todos los elementos de la cola actual con los elementos de la cola c.
         * @param c Referencia a otra instancia de MaxQueue.
         */
        void swap(MaxQueue& c) noexcept;
};