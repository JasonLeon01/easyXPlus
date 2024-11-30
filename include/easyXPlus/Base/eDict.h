#pragma once
#include <easyXPlus/Base/ePair.h>
#include <easyXPlus/Base/eList.h>

namespace easyXPlus {
	template <typename TKey, typename TValue>
	class eNode {
	public:
		ePair <TKey, TValue> Data;
		eNode* Next;

		eNode() : Data(), Next(nullptr) {}
		eNode(ePair <TKey, TValue> data) : Data(data), Next(nullptr) {}
	};

	template <typename TKey, typename TValue>
	class eDict {
	public:
		eDict() : _head(nullptr), _count(0) {}
		~eDict() {
			Clear();
		}

		void Add(TKey key, TValue value) {
			eNode <TKey, TValue>* newNode = new eNode <TKey, TValue>(ePair <TKey, TValue>(key, value));

			if (_head == nullptr) {
				_head = newNode;
			}
			else {
				eNode <TKey, TValue>* current = _head;
				while (current->Next != nullptr) {
					current = current->Next;
				}
				current->Next = newNode;
			}
			++_count;
		}

		size_t Size() {
			return _count;
		}

		void Clear() {
			eNode <TKey, TValue>* current = _head;
			while (current != nullptr) {
				eNode <TKey, TValue>* toDelete = current;
				current = current->Next;
				delete current;
			}
			_head = nullptr;
			_count = 0;
		}

		TValue& operator[](TKey key) {
			eNode <TKey, TValue>* current = _head;
			while (current != nullptr) {
				if (current->Data.Key == key) {
					return current->Data.Value;
				}
				current = current->Next;
			}
			Add(key, TValue());
			return operator[](key);
		}

		TKey KeyAt(size_t index) const {
			if (index >= _count) {
				throw std::out_of_range("Index out of range");
			}
			eNode <TKey, TValue>* current = _head;
			for (size_t i = 0; i < index; ++i) {
				current = current->Next;
			}
			return current->Data.Key;
		}

		TValue ValueAt(size_t index) const {
			if (index >= _count) {
				throw std::out_of_range("Index out of range");
			}
			eNode <TKey, TValue>* current = _head;
			for (size_t i = 0; i < index; ++i) {
				current = current->Next;
			}
			return current->Data.Value;
		}

		bool ContainsKey(TKey key) const {
			eNode <TKey, TValue>* current = _head;
			while (current != nullptr) {
				if (current->Data.Key == key) {
					return true;
				}
				current = current->Next;
			}
			return false;
		}

		void Remove(TKey key) {
			if (_head == nullptr) {
				return;
			}
			if (_head->Data.Key == key) {
				eNode <TKey, TValue>* toDelete = _head;
				_head = _head->Next;
				delete toDelete;
				--_count;
				return;
			}
			eNode <TKey, TValue>* current = _head;
			while (current->Next != nullptr) {
				if (current->Next->Data.Key == key) {
					eNode <TKey, TValue>* toDelete = current->Next;
					current->Next = current->Next->Next;
					delete toDelete;
					--_count;
					return;
				}
				current = current->Next;
			}
		}

		void RemoveAt(size_t index) {
			if (index >= _count) {
				throw std::out_of_range("Index out of range");
			}
			if (index == 0) {
				eNode <TKey, TValue>* toDelete = _head;
				_head = _head->Next;
				delete toDelete;
				--_count;
				return;
			}
			eNode <TKey, TValue>* current = _head;
			for (size_t i = 0; i < index - 1; ++i) {
				current = current->Next;
			}
			eNode <TKey, TValue>* toDelete = current->Next;
			current->Next = current->Next->Next;
			delete toDelete;
			--_count;
		}

		eList <TKey> GetKeys() {
			eList <TKey> keys;
			eNode <TKey, TValue>* current = _head;
			while (current != nullptr) {
				keys.Append(current->Data.Key);
				current = current->Next;
			}
			return keys;
		}

		class Iterator {
		private:
			eNode<TKey, TValue>* Current;

		public:
			Iterator(eNode<TKey, TValue>* start) : Current(start) {}

			bool isValid() const {
				return Current != nullptr;
			}

			void next() {
				if (Current) {
					Current = Current->Next;
				}
			}

			ePair<TKey, TValue>& current() {
				if (Current) {
					return Current->Data;
				}
				throw std::out_of_range("Iterator out of range");
			}

			operator bool() const {
				return isValid();
			}

			ePair<TKey, TValue>& operator*() {
				return current();
			}

			Iterator& operator++() {
				next();
				return *this;
			}
		};

		Iterator begin() {
			return Iterator(_head);
		}

		Iterator end() {
			return Iterator(nullptr);
		}

	private:
		eNode <TKey, TValue>* _head;
		size_t _count;
	};
}