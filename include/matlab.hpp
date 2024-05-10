#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_

// Biblioteka <cstddef> zawiera definicję typu `std::size_t`.
#include <cstddef>
#include <vector>
#include <cmath>
#include <vector>
class MatVect{
private:
    std::vector<int> v_ = {};
public:
    explicit MatVect(size_t size){for (size_t i = 0; i < size; ++i) v_.push_back(0);}
    auto get_elem(size_t pos){return v_[pos];}
    void set_elem(size_t pos, int val){v_[pos] = val;}
    size_t size(){return v_.size();}
    double norm();
    void print_vector();
};

MatVect add_vectors(MatVect v1, MatVect v2);


#endif /* INCLUDE_MATLAB_HPP_ */
