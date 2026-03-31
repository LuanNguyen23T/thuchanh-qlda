#pragma once
#include <cstddef>

class FloatVector {
public:
       
        FloatVector();  
        void push(float n); 
        float pop();    
                       

       
        float &operator[](size_t idx);
        float operator[](size_t idx) const;

        FloatVector &operator=(const FloatVector); 
                                                  
        bool operator==(const FloatVector&) const; // So sanh 2 vector.
        FloatVector operator*(float n) const;   // Nhan moi phan tu voi n.
        FloatVector operator+(float n) const;   // Cong moi phan tu voi n.

        // Thanh vien 4 (neu co)
        ~FloatVector(); // Don dep bo nho. Dung delete hoac free() tuy vao
                        // quyet dinh cua thanh vien 1 trong FloatVector().
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
        // Thanh vien 1.
        // Cap lai bo nho moi cho pointer _data. Co the cap truoc
        // bo nho cho nhieu phan tu de tang toc do xu li.
        void _realloc(size_t new_size);

        float *_data;
        size_t _size, _capacity;
};

