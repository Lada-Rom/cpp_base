#include "matrixa.h"

namespace {

std::unique_ptr<float[]> allocate(
    const std::ptrdiff_t col, const std::ptrdiff_t row) {

    //MatrixA(0, 0) is allowed
    if (col < 0 || row < 0 || ((col == 0) != (row == 0)))
        throw std::invalid_argument("Wrong size");

    return std::unique_ptr<float[]>(new float[col * row]);
}

} // namespace

MatrixA& MatrixA::operator=(const MatrixA& rhs) {
    return *this = MatrixA(rhs);
}

MatrixA::MatrixA(const MatrixA& rhs)
    : n_col_(rhs.col_count())
    , n_row_(rhs.row_count())
    , data_(allocate(rhs.col_count(), rhs.row_count())) {

    const auto begin = rhs.data_.get();
    const auto end = begin + n_row_ * n_col_;
    std::copy(begin, end, data_.get());
}

MatrixA::MatrixA(const std::ptrdiff_t col, const std::ptrdiff_t row)
    : n_col_(col)
    , n_row_(row)
    , data_(allocate(col, row)) {

    for(std::ptrdiff_t i(0); i < (n_col_ * n_row_); i += 1)
        data_[i] = 0;
}

float& MatrixA::at(const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) {
    if(row_i < 0 || col_i < 0 || row_i == row_count() || col_i == col_count())
        throw std::out_of_range("Index is out of range");
    else
        return data_[n_col_ * row_i + col_i];
}

const float& MatrixA::at(
    const std::ptrdiff_t row_i, const std::ptrdiff_t col_i) const {

    if (row_i < 0 || col_i < 0 || row_i == row_count() || col_i == col_count())
        throw std::out_of_range("Index is out of range");
    else
        return data_[n_col_ * row_i + col_i];
}
