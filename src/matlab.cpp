#include "matlab.hpp"

// Wersje standardowych bibliotek znanych z języka C, ale zaimplementowanych
// dla C++, mają przedrostek "c". Dołączając je, nie podajemy rozszerzenia ".h".
// Przykładowo: stdlib.h -> cstdlib
#include <cstdlib>

// Biblioteka <iostream> służy do obsługi strumieni wejścia/wyjścia (odpowiednik
// <stdio.h> w języku C).
#include <iostream>
#include <sstream>
#include <algorithm>

MatVect add_vectors(const MatVect& v1, const MatVect& v2) {
    MatVect s(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), s.begin(), std::plus<>());
    return s;
}

void MatVect::print_vector() const{
    for (const int& i : v_)std::cout<<i<<", ";
    std::cout<<std::endl;
}

double MatVect::norm() const {
    int s = 0;
    for(int i : v_) s += i*i;
    return sqrt(s);
}

std::string to_string(const MatVect& vec){
    std::ostringstream stream;
    for(const int& i : vec) stream << i << " ";
    return stream.str();
}
