/**
 * @file maxstack.h
 * @brief  Archivo de especificación del TDA MaxStack
 * 
 * @authors Gabriel Josué Marcano Grimán
 *          Ángel Rodíguez Faya
 *
 * @date Octubre 2024
 */

#ifndef MAXSTACK__H
#define MAXSTACK__H

#include <iostream>
#include <queue>

using namespace std;

struct elemento{
    int valor;
    int maximo;

    friend ostream& operator<<(ostream& os, const elemento& e){
        os << e.valor << ", " << e.maximo;
        return os;
    }
};

class MaxStack{
    
    private:

        queue<int> pila;
        priority_queue<int> maximos;

    public:

        /**
         * @brief Constructor por defecto de 
         */
        MaxStack();

        bool vacia() const;

        int tamanio() const;

        void poner(int x);

        void quitar();

        elemento tope();
};

#endif // MAXSTACK__H

