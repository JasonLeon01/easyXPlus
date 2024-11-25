#pragma once
#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace easyXPlus {
	template <typename T>
	class eList {
	public:
		eList() : _data(nullptr), _size(0), _capacity(0) {}

		eList(std::initializer_list<T> init) : _data(nullptr), _size(0), _capacity(0) {
			for (const auto& elem : init) {
				Append(elem);
			}
		}

		eList(const eList<T>& other) : _data(nullptr), _size(0), _capacity(0) {
			Resize(other._capacity);
			for (size_t i = 0; i < other._size; i++) {
				Append(other._data[i]);
			}
		}

		eList(eList<T>&& other) noexcept : _data(other._data), _size(other._size), _capacity(other._capacity) {
			other._data = nullptr;
			other._size = 0;
			other._capacity = 0;
		}
		~eList() { delete[] _data; }

		eList<T>& operator=(const eList<T>& other) {
			if (this != &other) {
				Clear();
				Resize(other._capacity);
				for (size_t i = 0; i < other._size; i++) {
					Append(other._data[i]);
				}
			}
			return *this;
		}

		eList<T>& operator=(eList<T>&& other) noexcept {
			if (this != &other) {
				delete[] _data;
				_data = other._data;
				_size = other._size;
				_capacity = other._capacity;
				other._data = nullptr;
				other._size = 0;
				other._capacity = 0;
			}
			return *this;
		}

		T& operator[](size_t index) {
			if (index >= _size) throw std::out_of_range("Index out of range");
			return _data[index];
		}

		const T& operator[](size_t index) const {
			if (index >= _size) throw std::out_of_range("Index out of range");
			return _data[index];
		}

		size_t Size() const {
			return _size;
		}

		bool Empty() const {
			return _size == 0;
		}

		void Clear() {
			delete[] _data;
			_data = nullptr;
			_size = 0;
			_capacity = 0;
		}

		void Append(const T& value) {
			if (_size == _capacity) {
				Resize(_capacity * 2 + 1);
			}
			_data[_size++] = value;
		}

		void Append(T&& value) {
			if (_size == _capacity) {
				Resize(_capacity * 2 + 1);
			}
			_data[_size++] = std::move(value);
		}

		void Insert(size_t index, const T& value) {
			if (_size == _capacity) {
				Resize(_capacity * 2 + 1);
			}
			for (int i = _size; i > index; i--) {
				_data[i] = _data[i - 1];
			}
			_data[index] = value;
			_size++;
		}

		void Insert(size_t index, T&& value) {
			if (_size == _capacity) {
				Resize(_capacity * 2 + 1);
			}
			for (int i = _size; i > index; i--) {
				_data[i] = _data[i - 1];
			}
			_data[index] = std::move(value);
			_size++;
		}

		void RemoveAt(size_t index) {
			if (index < 0 || index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			for (int i = index; i < _size - 1; i++) {
				_data[i] = _data[i + 1];
			}
			_size--;
		}

		void Remove(const T& value) {
			for (int i = 0; i < _size; i++) {
				if (_data[i] == value) {
					RemoveAt(i);
					break;
				}
			}
		}

		void RemoveAll(const T& value) {
			for (int i = 0; i < _size; i++) {
				if (_data[i] == value) {
					RemoveAt(i);
					i--;
				}
			}
		}

		int Find(const T& value) const {
			for (int i = 0; i < _size; i++) {
				if (_data[i] == value) {
					return i;
				}
			}
			return -1;
		}

		int FindLast(const T& value) const {
			for (int i = _size - 1; i >= 0; i--) {
				if (_data[i] == value) {
					return i;
				}
			}
			return -1;
		}

		T Pop() {
			T result = _data[_size - 1];
			_size--;
			return result;
		}

		class Iterator {
		public:
			Iterator(T* ptr) : _ptr(ptr) {}

			Iterator& operator++() { 
				_ptr++; 
				return *this;
			}

			Iterator operator++(int) { 
				Iterator temp = *this; 
				_ptr++; 
				return temp;
			}

			Iterator& operator--() { 
				_ptr--; 
				return *this; 
			}

			Iterator operator--(int) { 
				Iterator temp = *this; 
				_ptr--; 
				return temp; 
			}

			T& operator*() {
				return *_ptr; 
			}

			T* operator->() {
				return _ptr; 
			}

			bool operator==(const Iterator& other) const { 
				return _ptr == other._ptr; 
			}

			bool operator!=(const Iterator& other) const {
				return _ptr != other._ptr; 
			}	

		private:
			T* _ptr;
		};

		Iterator begin() { 
			return Iterator(_data); 
		}
		Iterator end() { 
			return Iterator(_data + _size);
		}

	private:
		T* _data;
		size_t _size;
		size_t _capacity;

		void Resize(size_t newCapacity) {
			T* newData = new T[newCapacity];
			for (int i = 0; i < _size; i++) {
				newData[i] = _data[i];
			}
			delete[] _data;
			_data = newData;
			_capacity = newCapacity;
		}
	};
}