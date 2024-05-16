#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include <vector>
#include <cmath>
#include <vector>
#include <string>
#include <numeric>

namespace Matlab {
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

    class Matrix {
    private:
        std::vector<Vector> matrix_;
    public:
        Matrix(std::size_t n_rows, std::size_t n_cols) : matrix_(n_rows, Vector(n_cols)) {};

        Matrix(const Matrix &) = default;

        explicit Matrix(const std::vector<std::vector<int>> &m) {
            std::copy(m.begin(), m.end(), std::back_inserter(matrix_));
        };

        [[nodiscard]] double sum() const;

        Vector &operator[](const size_t &index) { return matrix_[index]; };

        const Vector &operator[](const size_t &index) const { return matrix_[index]; };

        std::vector<Vector>::iterator begin() { return matrix_.begin(); };

        std::vector<Vector>::iterator end() { return matrix_.end(); };

        [[nodiscard]] std::size_t size() const { return matrix_.size(); };

        [[nodiscard]] std::vector<Vector>::const_iterator begin() const { return matrix_.cbegin(); };

        [[nodiscard]] std::vector<Vector>::const_iterator end() const { return matrix_.cend(); };

        [[nodiscard]] std::vector<Vector>::const_iterator cbegin() const { return matrix_.cbegin(); };

        [[nodiscard]] std::vector<Vector>::const_iterator cend() const { return matrix_.cend(); };

    };

    Vector add_vectors(const Vector &v1, const Vector &v2);

    Matrix add_matrices(const Matrix &m1, const Matrix &m2);

    std::string to_string(const Vector &vec);

    std::string to_string(const Matrix &m);
}
#endif /* INCLUDE_MATLAB_HPP_ */
