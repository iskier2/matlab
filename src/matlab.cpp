#include "matlab.hpp"

// Wersje standardowych bibliotek znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c". Dołączając je, nie podajemy rozszerzenia ".h".
// Przykładowo: stdlib.h -> cstdlib
#include <cstdlib>

// Biblioteka <iostream> służy do obsługi strumieni wejścia/wyjścia (odpowiednik
// <stdio.h> w języku C).
#include <iostream>

int* add_vectors(int* v1, int* v2, std::size_t n) {
    int* resp = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < (int)n; i++) {
        resp[i] = v1[i] + v2[i];
    }
    return resp;
}

void print_vector(int* v, std::size_t n) {
    for (int i = 0; i < (int)n; i++) {
        std::cout << (v[i]) << std::endl;
    }
}
