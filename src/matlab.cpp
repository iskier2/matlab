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
Matrix add_matrices(const Matrix& m1, const Matrix& m2) {
    Matrix resp(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), resp.begin(), add_vectors);
    return resp;
}

void MatVect::print_vector() const{
    for (const int& i : v_)std::cout<<i<<", ";
    std::cout<<std::endl;
}

double MatVect::norm() const {
    return std::sqrt(std::accumulate(begin(), end(), 0, [](double acc, const double& val){return acc + val * val;}));
}

std::string to_string(const MatVect& vec){
    std::ostringstream stream;
    stream << "[ ";
    for(auto i = vec.cbegin(); i != vec.cend(); i++)
        stream << *i << (i == vec.cend() - 1 ? "" : ", ");
    stream << " ]";
    return stream.str();
}
std::string to_string(const Matrix& m){
    std::ostringstream stream;
    stream << "[" << std::endl;
    for(const MatVect& i : m) stream << "\t" << to_string(i) << std::endl;
    stream << "]" << std::endl;
    return stream.str();
}

double Matrix::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0,
                           [](int accumulator, const MatVect& vector) {
        return accumulator + vector.sum();
    });
}
