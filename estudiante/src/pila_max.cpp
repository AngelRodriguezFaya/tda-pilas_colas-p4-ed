#include <iostream>
#include "maxstack.h"

using namespace std;

int main(int argc, char *argv[]){

    // Run the current exercise
    MaxStack stack;

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
            cout << stack.tope() << endl;   // Cambiado top() por tope()
            stack.quitar();                 // Cambiado pop() por quitar()
        } else {
            stack.poner(atoi(argv[i]));     // Cambiado push() por poner()
        }
    }
    return 0;
}
