#pragma once
#include <cstddef>

// Moi thanh vien trong nhom tao feature branch, roi lam task duoc
// giao o comment trong cac function. Thanh vien nhom co the tao
// file source code moi, edit file FloatVector.cxx, viet thang vao
// header tuy so thich.
//
// Sau khi cac thanh vien da hoan thanh, nhom truong merge cac
// branch thanh vien vao main, hoac tao 1 dev branch de merge vao,
// sau do tao pull request len upstream (repo goc ma minh fork ve).
//
// Khi merge feature branch vao dev hoac main, neu xay ra conflict
// thi gio tay de co nguoi cuu.

class FloatVector {
public:
        // Thanh vien 1
        void push(float n);
        float pop();

        // Thanh vien 2
        float &operator[](size_t idx);
        float operator[](size_t idx) const;
        FloatVector operator=(const FloatVector&) const;

        // Thanh vien 3
        bool operator==(const FloatVector&) const;
        FloatVector operator*(float n) const;
        FloatVector operator+(float n) const;

        // Thanh vien 4 (neu co)
        ~FloatVector();
        size_t get_size() const;
        size_t get_capacity() const;

        bool operator!=(const FloatVector &n) const
        {
                return !(*this == n);
        }

        FloatVector operator-(float n) const
        {
                return *this + (-n);
        }

        FloatVector operator/(float n) const
        {
                return *this * (1.0f/n);
        }
private:
        // Thanh vien 1
        void _realloc(size_t new_size);

        float *_data;
        size_t _size, _capacity;
};

