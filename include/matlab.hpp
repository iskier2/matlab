#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include <vector>
#include <cmath>
#include <vector>
#include <string>


class MatVect{
private:
    std::vector<int> v_;
public:
    explicit MatVect(size_t size) : v_(size, 0){}
    explicit MatVect(const std::vector<int>& vec) : v_(vec){}

    std::vector<int>::iterator  begin() {return v_.begin();}
    std::vector<int>::iterator  end() {return v_.end();}

    void print_vector() const;

    [[nodiscard]] double norm() const;

    [[nodiscard]] size_t size() const {return v_.size();}

    [[nodiscard]] std::vector<int>::const_iterator  begin() const {return v_.cbegin();}
    [[nodiscard]] std::vector<int>::const_iterator  end() const {return v_.cend();}

    [[nodiscard]] std::vector<int>::const_iterator  cbegin()const {return v_.cbegin();}
    [[nodiscard]] std::vector<int>::const_iterator  cend()const {return v_.cend();}

    const int& operator[](std::size_t pos) const { return v_[pos]; }  // inspector
    int& operator[](std::size_t pos) { return v_[pos]; }  // mutator
};

MatVect add_vectors(const MatVect& v1, const MatVect& v2);

std::string to_string(const MatVect& vec);
#endif /* INCLUDE_MATLAB_HPP_ */
