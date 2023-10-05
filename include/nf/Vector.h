// Copyright 2021 Jan Hermes. All rights reserved.
// SPDX-License-Identifier: BSD-3-Clause

#pragma once

#include <stddef.h>
#include <algorithm>

namespace nf {
    /**
     * @brief A fixed-size circular buffer implementation for storing elements of type T.
     * 
     * @tparam T The type of elements to be stored in the buffer.
     * @tparam S The maximum size of the buffer. Once the buffer is full, new elements will overwrite the oldest elements.
     */
    template<typename T, size_t S>
    class Vector {
    public:
        /**
         * @brief Default constructor for the Vector class.
         * 
         * Initializes the internal array and other member variables.
         */
        Vector() {}

        /**
         * @brief Adds an element to the buffer.
         * 
         * If the buffer is not full, the new element will be added at the current cursor position.
         * If the buffer is full, the new element will overwrite the oldest element, and the cursor will wrap around to the beginning.
         * 
         * @param element The element of type T to be added to the buffer.
         */
        void add(T element) {
            this->_elements[_cursor] = element;
            _size = std::min(S, _size + 1);
            _cursor = (_cursor + 1) % S;
        }

        /**
         * @brief Clears the buffer.
         * 
         * This operation resets the buffer size and the cursor position, effectively clearing all elements.
         */
        void clear() {
            this->_size = 0;
            this->_cursor = 0;
        }

        /**
         * @brief Get the current size of the buffer.
         * 
         * @return size_t The number of elements currently stored in the buffer.
         */
        size_t getSize() {
            return _size;
        }

        /**
         * @brief Accesses an element in the buffer by index.
         * 
         * @param idx The index of the element to access.
         * @return T& A reference to the element at the specified index.
         */
        T& operator[](int idx) {
            return _elements[(size_t) idx];
        }

        /**
         * @brief Iterator for the Vector class.
         * 
         * An iterator that allows iterating over the elements in the buffer from the beginning to the end.
         * The iterator can be used in range-based for loops.
         */
        typedef T* iterator;

        /**
         * @brief Const iterator for the Vector class.
         * 
         * A const iterator that allows iterating over the elements in the buffer from the beginning to the end.
         * The const iterator is used when the Vector object is constant.
         */
        typedef const T* const_iterator;

        /**
         * @brief Get the iterator pointing to the first element of the buffer.
         * 
         * @return iterator An iterator pointing to the first element of the buffer.
         */
        iterator begin() { return &_elements[0]; }

        /**
         * @brief Get the const iterator pointing to the first element of the buffer.
         * 
         * @return const_iterator A const iterator pointing to the first element of the buffer.
         */
        const_iterator begin() const { return &_elements[0]; }

        /**
         * @brief Get the iterator pointing to the position after the last element of the buffer.
         * 
         * @return iterator An iterator pointing to the position after the last element of the buffer.
         */
        iterator end() { return &_elements[_size]; }

        /**
         * @brief Get the const iterator pointing to the position after the last element of the buffer.
         * 
         * @return const_iterator A const iterator pointing to the position after the last element of the buffer.
         */
        const_iterator end() const { return &_elements[_size]; }

    private:
        /**
         * @brief Internal array to store the elements.
         */
        T _elements[S] = {};

        /**
         * @brief Current size of the buffer (number of elements).
         */
        size_t _size = 0;

        /**
         * @brief Cursor to keep track of the position to add the next element.
         */
        size_t _cursor = 0;
    };
}
