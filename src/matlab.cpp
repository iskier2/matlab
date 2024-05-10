#include "matlab.hpp"

// Wersje standardowych bibliotek znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c". Dołączając je, nie podajemy rozszerzenia ".h".
// Przykładowo: stdlib.h -> cstdlib
#include <cstdlib>

// Biblioteka <iostream> służy do obsługi strumieni wejścia/wyjścia (odpowiednik
// <stdio.h> w języku C).
#include <iostream>

MatVect add_vectors(MatVect l, MatVect s) {
    if(l.size() < s.size())return add_vectors(s,l);
    MatVect resp(l.size());
    for(size_t i = 0; i < s.size(); i++)
        resp.set_elem(i, l.get_elem(i) + s.get_elem(i));
    for(size_t i = s.size(); i < l.size(); i++)
        resp.set_elem(i, l.get_elem(i));
    return resp;
}

void MatVect::print_vector() {
    for (int i : v_)std::cout<<i<<", ";
    std::cout<<std::endl;
}


double MatVect::norm() {
    int s = 0;
    for(int i : v_) s += i*i;
    return sqrt(s);
}
