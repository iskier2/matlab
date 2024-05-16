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

Matlab::Vector Matlab::add_vectors(const Matlab::Vector& v1, const Matlab::Vector& v2) {
    if(v1.size() != v2.size())
        throw std::invalid_argument("Vectors have unequal size (" + std::to_string(v1.size()) + " and " + std::to_string(v2.size()) + ").");
    Matlab::Vector s(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), s.begin(), std::plus<>());
    return s;
}
Matlab::Matrix Matlab::add_matrices(const Matlab::Matrix& m1, const Matlab::Matrix& m2) {
    Matlab::Matrix resp(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), resp.begin(), add_vectors);
    return resp;
}

void Matlab::Vector::print_vector() const{
    for (const int& i : v_)std::cout<<i<<", ";
    std::cout<<std::endl;
}

double Matlab::Vector::norm() const {
    return std::sqrt(std::accumulate(begin(), end(), 0, [](double acc, const double& val){return acc + val * val;}));
}

std::string Matlab::to_string(const Matlab::Vector& vec){
    std::ostringstream stream;
    stream << "[ ";
    for(auto i = vec.cbegin(); i != vec.cend(); i++)
        stream << *i << (i == vec.cend() - 1 ? "" : ", ");
    stream << " ]";
    return stream.str();
}
std::string Matlab::to_string(const Matlab::Matrix& m){
    std::ostringstream stream;
    stream << "[" << std::endl;
    for(const Matlab::Vector& i : m) stream << "\t" << Matlab::to_string(i) << std::endl;
    stream << "]" << std::endl;
    return stream.str();
}

double Matlab::Matrix::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0,
                           [](int accumulator, const Matlab::Vector& vector) {
        return accumulator + vector.sum();
    });
}

std::string Matlab::was_exception_raised_when_adding_vectors(const Matlab::Vector& v1, const Matlab::Vector& v2){
    try {
        Matlab::add_vectors(v1, v2);
        return"";
    }catch (const std::invalid_argument& err){
        return err.what();
    }
}