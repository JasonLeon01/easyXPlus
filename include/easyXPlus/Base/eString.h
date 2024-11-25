#pragma once
#include <easyXPlus/Base/eList.h>
#include <tchar.h>

namespace easyXPlus {
	class eString {
	public:
		eString();
#ifdef UNICODE
		eString(const _TCHAR* str);
#else
		eString(const char* str);
#endif
		eString(const eString& other);
		eString(eString&& other) noexcept;
		~eString();

		eString& operator=(const eString& other);
		eString& operator=(eString&& other) noexcept;
		char operator[](size_t index) const;
		const bool operator==(const eString& other) const;
		const bool operator!=(const eString& other) const;
		const bool operator<(const eString& other) const;
		const bool operator>(const eString& other) const;
		const bool operator<=(const eString& other) const;
		const bool operator>=(const eString& other) const;
		eString operator+(const eString& other) const;
		eString& operator+=(const eString& other);

		_TCHAR* CString() const;
		eList <char> CharArray() const;
		bool Empty() const;
		size_t Length() const;
		void Clear();
		eString Erase(eString& str);
		eString EraseAt(size_t index);
		eString EraseAll(eString& str);
		
		bool EndsWith(const eString& other) const;
		bool StartsWith(const eString& other) const;
		bool Contains(const eString& other) const;
		size_t Find(const eString& other) const;
		size_t FindLast(const eString& other) const;
		eString SubString(size_t start, size_t length) const;
		eString Replace(const eString& oldStr, const eString& newStr) const;
		eString ReplaceAll(const eString& oldStr, const eString& newStr) const;
		eList<eString> Split(const char separator) const;

		eString ToLower() const;
		eString ToUpper() const;
		eString Trim() const;
		bool IsNumeric() const;
		bool IsAlpha() const;

		int ToInt() const;
		float ToFloat() const;

#ifdef UNICODE
		static eString Format(const wchar_t* format, ...);
#else
		static eString Format(const char* format, ...);
#endif

		static eString Join(const eList<eString>& list, const eString& separator);
		static eString FromInt(int value);
		static eString FromFloat(float value);

		class Iterator {
		public:
#ifdef UNICODE
			Iterator(wchar_t* ptr) : _ptr(ptr) {}
			wchar_t& operator*() { return *_ptr; }
#else
			Iterator(char* ptr) : _ptr(ptr) {}
			char& operator*() { return *_ptr; }
#endif
			Iterator& operator++() { _ptr++; return *this; }
			bool operator==(const Iterator& other) const { return _ptr == other._ptr; }
			bool operator!=(const Iterator& other) const { return _ptr != other._ptr; }
		private:
#ifdef UNICODE
			wchar_t* _ptr;
#else
			char* _ptr;
#endif
		};

		Iterator begin() { return Iterator(_data); }
		Iterator end() { return Iterator(_data + _length); }

	private:
#ifdef UNICODE
		wchar_t* _data;
#else
		char* _data;
#endif
		size_t _length;
	};
}