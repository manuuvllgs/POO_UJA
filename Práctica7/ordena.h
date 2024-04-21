//
// Created by Manuel Villegas Aceituno on 17/4/24.
//

#ifndef PROJECT_PR7_ORDENA_H
#define PROJECT_PR7_ORDENA_H

template<typename T>

class ordena {


};

template<typename T>
void intercambia(T &a, T &b)
{ T c=a;
    a=b;
    b=c;
}

template<typename T>
void ordenar( T* valores[], int numValores) {
    int posMenor;
    for (int i = 0; i < numValores - 1; i++) {
        posMenor = i;
        for (int j = i + 1; j < numValores; j++) {
            if ((*valores[j]) < (*valores[posMenor]))
                posMenor = j;
        }
        intercambia((*valores[i]), (*valores[posMenor]));
    }
}

#endif //PROJECT_PR7_ORDENA_H
