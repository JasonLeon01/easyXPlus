#include <easyXPlus/Base/eString.h>
#include <stdexcept>
#include <ctype.h>
#include <cstdarg>

#ifdef UNICODE
#include <cwchar>
#else
#include <cstring>
#endif

namespace easyXPlus {
	eString::eString() : _data(nullptr), _length(0) {}
#ifdef UNICODE
    eString::eString(const _TCHAR* str) {
        if (str) {
            _length = wcslen(str);
            _data = _wcsdup(str);
        }
    }
#else
    eString::eString(const char* str) {
		if (str) {
			_length = strlen(str);
			_data = strdup(str);
		}
	}
#endif

    eString::eString(const eString& other) : _data(nullptr), _length(other._length) {
#ifdef UNICODE
        if (other._data) {
            _data = _wcsdup(other._data);
        }
#else
        if (other._data) {
            _data = strdup(other._data);
        }
#endif
    }

    eString::eString(eString&& other) noexcept : _data(other._data), _length(other._length) {
        other._data = nullptr;
        other._length = 0;
    }

    eString::~eString() {
        delete[] _data;
    }

    eString& eString::operator=(const eString& other) {
        if (this != &other) {
            delete[] _data;

            _length = other._length;
#ifdef UNICODE
            _data = other._data ? _wcsdup(other._data) : nullptr;
#else
            _data = other._data ? strdup(other._data) : nullptr;
#endif
        }
        return *this;
    }

    eString& eString::operator=(eString&& other) noexcept {
        if (this != &other) {
            delete[] _data;
            _data = other._data;
            _length = other._length;
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }

    char eString::operator[](size_t index) const {
        if (index >= _length) {
            throw std::out_of_range("Index out of range");
        }
#ifdef UNICODE
        return static_cast<char>(_data[index]);
#else
        return _data[index];
#endif
    }

    const bool eString::operator==(const eString& other) const {
#ifdef UNICODE
        return wcscmp(_data, other._data) == 0;
#else
        return strcmp(_data, other._data) == 0;
#endif
    }

    const bool eString::operator!=(const eString& other) const {
        return !(*this == other);
    }

    const bool eString::operator<(const eString& other) const {
#ifdef UNICODE
        return wcscmp(_data, other._data) < 0;
#else
        return strcmp(_data, other._data) < 0;
#endif
    }

    const bool eString::operator>(const eString& other) const {
        return !(*this < other) && *this != other;
    }

    const bool eString::operator<=(const eString& other) const {
        return !(*this > other);
    }

    const bool eString::operator>=(const eString& other) const {
        return !(*this < other);
    }

    eString eString::operator+(const eString& other) const {
#ifdef UNICODE
        size_t newSize = _length + other._length + 1;
        wchar_t* result = new wchar_t[newSize];
        wcscpy(result, _data);
        wcscat(result, other._data);
#else
        size_t newSize = _length + other._length + 1;
        char* result = new char[newSize];
        strcpy(result, _data);
        strcat(result, other._data);
#endif
        return eString(result);
    }

    eString& eString::operator+=(const eString& other) {
#ifdef UNICODE
        size_t newSize = _length + other._length + 1;
        wchar_t* result = new wchar_t[newSize];
        wcscpy(result, _data);
        wcscat(result, other._data);
        delete[] _data;
        _data = result;
#else
        size_t newSize = _length + other._length + 1;
        char* result = new char[newSize];
        strcpy(result, _data);
        strcat(result, other._data);
        delete[] _data;
        _data = result;
#endif
        _length = newSize - 1;
        return *this;
    }

    _TCHAR* eString::CString() const {
        return _data;
    }

    eList<char> eString::CharArray() const {
		eList<char> result;
#ifdef UNICODE
        for (size_t i = 0; i < _length; ++i) {
            result.Append(static_cast<char>(_data[i]));
        }
#else
        for (size_t i = 0; i < _length; ++i) {
            result.Append(_data[i]);
        }
#endif
		return result;
	}

    bool eString::Empty() const {
        return _length == 0;
    }

    size_t eString::Length() const {
        return _length;
    }

    void eString::Clear() {
        delete[] _data;
        _data = nullptr;
        _length = 0;
    }

    eString eString::Erase(eString& str) {
        size_t newLength = _length;
#ifdef UNICODE
		wchar_t* newData = new wchar_t[_length + 1];
#else
		char* newData = new char[_length + 1];
#endif
		size_t newIndex = 0;
		for (size_t i = 0; i < _length; ++i) {
			bool found = true;
			for (size_t j = 0; j < str._length; ++j) {
				if (_data[i + j] != str._data[j]) {
					found = false;
					break;
				}
			}
			if (!found) {
				newData[newIndex++] = _data[i];
			}
			else {
				i += str._length - 1;
			}
		}
		newData[newIndex] = '\0';
		eString result(newData);
		delete[] newData;
		return result;
    }

    eString eString::EraseAt(size_t index) {
        if (index >= _length) {
            throw std::out_of_range("Index out of range");
        }
#ifdef UNICODE
        wchar_t* newData = new wchar_t[_length + 1];
#else
        char* newData = new char[_length + 1];
#endif
        for (size_t i = 0; i < index; ++i) {
            newData[i] = _data[i];
        }
        for (size_t i = index + 1; i < _length; ++i) {
            newData[i - 1] = _data[i];
        }
        newData[_length - 1] = '\0';
        eString result(newData);
        delete[] newData;
        return result;
    }

    eString eString::EraseAll(eString& str) {
        size_t newLength = _length;
#ifdef UNICODE
        wchar_t* newData = new wchar_t[_length + 1];
#else
        char* newData = new char[_length + 1];
#endif
        size_t newIndex = 0;
        for (size_t i = 0; i < _length; ++i) {
            bool found = true;
            for (size_t j = 0; j < str._length; ++j) {
                if (_data[i + j] != str._data[j]) {
                    found = false;
                    break;
                }
            }
            if (!found) {
                newData[newIndex++] = _data[i];
            }
        }
        newData[newIndex] = '\0';
        eString result(newData);
        delete[] newData;
        return result;
    }

    bool eString::EndsWith(const eString& other) const {
#ifdef UNICODE
        return _length >= other._length && wcscmp(_data + (_length - other._length), other._data) == 0;
#else
        return _length >= other._length && strcmp(_data + (_length - other._length), other._data) == 0;
#endif
    }

    bool eString::StartsWith(const eString& other) const {
#ifdef UNICODE
        return wcsncmp(_data, other._data, other._length) == 0;
#else
        return strncmp(_data, other._data, other._length) == 0;
#endif
    }

    bool eString::Contains(const eString& other) const {
#ifdef UNICODE
        return wcsstr(_data, other._data) != nullptr;
#else
        return strstr(_data, other._data) != nullptr;
#endif
    }

    size_t eString::Find(const eString& other) const {
        if (other.Empty()) {
            return std::string::npos;
        }

#ifdef UNICODE
        wchar_t* found = wcsstr(_data, other._data);
        if (found) {
            return found - _data;
        }
#else
        char* found = strstr(_data, other._data);
        if (found) {
            return found - _data;
        }
#endif
        return std::string::npos;
    }

    size_t eString::FindLast(const eString& other) const {
        if (other.Empty()) {
            return std::string::npos;
        }

#ifdef UNICODE
        wchar_t* found = nullptr;
        wchar_t* current_pos = _data;
        while ((current_pos = wcsstr(current_pos, other._data)) != nullptr) {
            found = current_pos;
            current_pos++;
        }
        if (found) {
            return found - _data;
#else
        char* found = nullptr;
        char* current_pos = _data;
        while ((current_pos = strstr(current_pos, other._data)) != nullptr) {
            found = current_pos;
            current_pos++;
        }
        if (found) {
            return found - _data;
#endif
        }
        return std::string::npos;
    }

    eString eString::SubString(size_t start, size_t length) const {
        if (start >= _length) {
            return eString();
        }

        length = std::min(length, _length - start);

#ifdef UNICODE
        wchar_t* subStr = new wchar_t[length + 1];
        wcsncpy(subStr, _data + start, length);
        subStr[length] = L'\0';
        eString result(subStr);
        delete[] subStr;
        return result;
#else
        char* subStr = new char[length + 1];
        strncpy(subStr, _data + start, length);
        subStr[length] = '\0';
        eString result(subStr);
        delete[] subStr;
        return result;
#endif
    }

    eString eString::Replace(const eString& oldStr, const eString& newStr) const {
        eString result(*this);
        size_t pos = result.Find(oldStr);
        if (pos != std::string::npos) {
            result._data[pos] = '\0';
            result += newStr;
            result += eString(result._data + pos + oldStr._length);
        }
        return result;
    }

    eString eString::ReplaceAll(const eString& oldStr, const eString& newStr) const {
        eString result(*this);
        size_t pos = result.Find(oldStr);
        while (pos != std::string::npos) {
            result._data[pos] = '\0'; 
            result += newStr;
            result += eString(result._data + pos + oldStr._length);
            pos = result.Find(oldStr);
        }
        return result;
    }

    eList<eString> eString::Split(const char separator) const {
        eList<eString> result;
        size_t start = 0;
        for (size_t i = 0; i < _length; ++i) {
            if (_data[i] == separator) {
                result.Append(SubString(start, i - start));
                start = i + 1;
            }
        }
        if (start < _length) {
            result.Append(SubString(start, _length - start));
        }
        return result;
    }

    eString eString::ToLower() const {
        eString result(*this);
        for (size_t i = 0; i < result._length; ++i) {
            result._data[i] = static_cast<char>(tolower(result._data[i]));
        }
        return result;
    }

    eString eString::ToUpper() const {
        eString result(*this);
        for (size_t i = 0; i < result._length; ++i) {
            result._data[i] = static_cast<char>(toupper(result._data[i]));
        }
        return result;
    }

    eString eString::Trim() const {
        size_t start = 0;
        size_t end = _length;
        while (start < end && isspace(_data[start])) ++start;
        while (end > start && isspace(_data[end - 1])) --end;
        return SubString(start, end - start);
    }

    bool eString::IsNumeric() const {
        for (size_t i = 0; i < _length; ++i) {
            if (!isdigit(_data[i])) return false;
        }
        return true;
    }

    bool eString::IsAlpha() const {
        for (size_t i = 0; i < _length; ++i) {
            if (!isalpha(_data[i])) return false;
        }
        return true;
    }

    int eString::ToInt() const {
        if (!IsNumeric()) {
			throw std::invalid_argument("String is not numeric");
		}
        int result = 0;
        for (size_t i = 0; i < _length; ++i) {
			result = result * 10 + (_data[i] - '0');
		}
    }

    float eString::ToFloat() const {
        if (!IsNumeric()) {
            throw std::invalid_argument("String is not numeric");
        }
        float result = 0.0f;
        float decimal = 0.1f;
        bool decimalPoint = false;
        for (size_t i = 0; i < _length; ++i) {
            if (_data[i] == '.') {
				decimalPoint = true;
				continue;
			}
            if (decimalPoint) {
				result += (_data[i] - '0') * decimal;
				decimal *= 0.1f;
            }
            else {
				result = result * 10 + (_data[i] - '0');
			}
		}
        return result;
    }
#ifdef UNICODE
    eString eString::Format(const wchar_t* format, ...) {
		va_list args;
		va_start(args, format);
		size_t size = std::vswprintf(nullptr, 0, format, args) + 1;
		va_end(args);

		wchar_t* buffer = new wchar_t[size];
		va_start(args, format);
		std::vswprintf(buffer, size, format, args);
		va_end(args);

		eString result(buffer);
		delete[] buffer;
		return result;
    }
#else
    eString eString::Format(const char* format, ...) {
        va_list args;
        va_start(args, format);
        size_t size = std::vsnprintf(nullptr, 0, format, args) + 1;
        va_end(args);

        char* buffer = new char[size];
        va_start(args, format);
        std::vsnprintf(buffer, size, format, args);
        va_end(args);

        eString result(buffer);
        delete[] buffer;
        return result;
    }
#endif

    eString eString::Join(const eList<eString>& list, const eString& separator) {
        eString result;
        for (size_t i = 0; i < list.Size(); ++i) {
            if (i > 0) result += separator;
            result += list[i];
        }
        return result;
    }

    eString eString::FromInt(int value) {
#ifdef UNICODE
		return Format(L"%d", value);
#else
        return Format("%d", value);
#endif
	}

    eString eString::FromFloat(float value) {
#ifdef UNICODE
        return Format(L"%f", value);
#else
        return Format("%f", value);
#endif
	}
}