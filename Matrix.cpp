#include <iostream>
#include <memory>

class Matrix {
public:
    Matrix(int n, int m) : rows(n), cols(m), data(std::make_unique<int[]>(n * m)) {}

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(std::make_unique<int[]>(rows * cols)) {
        std::copy(other.data.get(), other.data.get() + rows * cols, data.get());
    }

    Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data)) {
        other.rows = 0;
        other.cols = 0;
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }
        rows = other.rows;
        cols = other.cols;
        data = std::make_unique<int[]>(rows * cols);
        std::copy(other.data.get(), other.data.get() + rows * cols, data.get());
        return *this;
    }

    Matrix& operator=(Matrix&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0;
        other.cols = 0;
        return *this;
    }

    int& operator()(int i, int j) {
        return data[i * cols + j];
    }

    const int& operator()(int i, int j) const {
        return data[i * cols + j];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Размеры матриц обязаны совпадать");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = (*this)(i, j) + other(i, j);
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw std::invalid_argument("Количество столбцов в первой матрице обязано быть равным количеству строк во второй матрице");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result(i, j) += (*this)(i, k) * other(k, j);
                }
            }
        }
        return result;
    }

private:
    int rows;
    int cols;
    std::unique_ptr<int[]> data;
};

