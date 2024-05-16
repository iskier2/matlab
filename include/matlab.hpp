#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include <vector>
#include <cmath>
#include <string>
#include <numeric>
#include "matlab.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace Matlab {
    template<typename T>
    class Vector {
    private:
        std::vector<int> v_;
    public:
        Vector(size_t size = 3) : v_(size, 0) {}

        Vector(const std::vector<int> &vec) : v_(vec) {}

        Vector(const Vector &) = default;

        std::vector<int>::iterator begin() { return v_.begin(); }

        std::vector<int>::iterator end() { return v_.end(); }

        [[nodiscard]] double sum() const { return std::accumulate(begin(), end(), 0); };

        void print_vector() const;

        [[nodiscard]] double norm() const;

        [[nodiscard]] size_t size() const { return v_.size(); }

        [[nodiscard]] std::vector<int>::const_iterator begin() const { return v_.cbegin(); }

        [[nodiscard]] std::vector<int>::const_iterator end() const { return v_.cend(); }

        [[nodiscard]] std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }

        [[nodiscard]] std::vector<int>::const_iterator cend() const { return v_.cend(); }

        const int &operator[](std::size_t pos) const { return v_[pos]; }  // inspector
        int &operator[](std::size_t pos) { return v_[pos]; }  // mutator
    };

    template<typename T>
    class Matrix {
    private:
        std::vector<Vector<T>> matrix_;
    public:
        Matrix(std::size_t n_rows, std::size_t n_cols) : matrix_(n_rows, Vector<T>(n_cols)) {};

        Matrix(const Matrix &) = default;

        explicit Matrix(const std::vector<std::vector<int>> &m) {
            std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
        };

        [[nodiscard]] double sum() const;

        Vector<T> &operator[](const size_t &index) { return matrix_[index]; };

        const Vector<T> &operator[](const size_t &index) const { return matrix_[index]; };

        typename std::vector<Vector<T>>::iterator begin() { return matrix_.begin(); };

        typename std::vector<Vector<T>>::iterator end() { return matrix_.end(); };

        [[nodiscard]] std::size_t size() const { return matrix_.size(); };

        [[nodiscard]] typename std::vector<Vector<T>>::const_iterator begin() const { return matrix_.cbegin(); };

        [[nodiscard]] typename std::vector<Vector<T>>::const_iterator end() const { return matrix_.cend(); };

        [[nodiscard]] typename std::vector<Vector<T>>::const_iterator cbegin() const { return matrix_.cbegin(); };

        [[nodiscard]] typename std::vector<Vector<T>>::const_iterator cend() const { return matrix_.cend(); };

    };

    template<typename T>
    Vector<T> add_vectors(const Vector<T> &v1, const Vector<T> &v2);

    template<typename T>
    Matrix<T> add_matrices(const Matrix<T> &m1, const Matrix<T> &m2);

    template<typename T>
    std::string to_string(const Vector<T> &vec);

    template<typename T>
    std::string to_string(const Matrix<T> &m);

    template<typename T>
    std::string was_exception_raised_when_adding_vectors(const Vector<T>& v1, const Vector<T>& v2);
}

///////////////////////////////////////


template<typename T>
Matlab::Vector<T> Matlab::add_vectors(const Matlab::Vector<T>&v1, const Matlab::Vector<T>&v2) {
    if(v1.size() != v2.size())
        throw std::invalid_argument("Vectors have unequal size (" + std::to_string(v1.size()) + " and " + std::to_string(v2.size()) + ").");
    Matlab::Vector<T> s(v1.size());
    std::transform(v1.cbegin(), v1.cend(), v2.cbegin(), s.begin(), std::plus<>());
    return s;
}

template<typename T>
Matlab::Matrix<T> Matlab::add_matrices(const Matlab::Matrix<T>&m1, const Matlab::Matrix<T>&m2) {
    Matlab::Matrix resp(m1);
    std::transform(m1.begin(), m1.end(), m2.begin(), resp.begin(), add_vectors<T>);
    return resp;
}

template<typename T>
void Matlab::Vector<T>::print_vector() const{
    for (const int& i : v_)std::cout<<i<<", ";
    std::cout<<std::endl;
}

template<typename T>
double Matlab::Vector<T>::norm() const {
    return std::sqrt(std::accumulate(begin(), end(), 0, [](double acc, const double& val){return acc + val * val;}));
}

template<typename T>
std::string Matlab::to_string(const Matlab::Vector<T>&vec){
    std::ostringstream stream;
    stream << "[ ";
    for(auto i = vec.cbegin(); i != vec.cend(); i++)
        stream << *i << (i == vec.cend() - 1 ? "" : ", ");
    stream << " ]";
    return stream.str();
}

template<typename T>
std::string Matlab::to_string(const Matlab::Matrix<T>&m){
    std::ostringstream stream;
    stream << "[" << std::endl;
    for(const Matlab::Vector<T>&i : m) stream << "\t" << Matlab::to_string(i) << std::endl;
    stream << "]" << std::endl;
    return stream.str();
}

template<typename T>
double Matlab::Matrix<T>::sum() const {
    return std::accumulate(matrix_.begin(), matrix_.end(), 0,
                           [](int accumulator, const Matlab::Vector<T>&vector) {
                               return accumulator + vector.sum();
                           });
}

template<typename T>
std::string Matlab::was_exception_raised_when_adding_vectors(const Matlab::Vector<T>&v1, const Matlab::Vector<T>&v2){
    try {
        Matlab::add_vectors(v1, v2);
        return"";
    }catch (const std::invalid_argument& err){
        return err.what();
    }
}
#endif /* INCLUDE_MATLAB_HPP_ */
