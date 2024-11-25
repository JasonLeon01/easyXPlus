#pragma once

namespace easyXPlus {
	template <typename T1, typename T2>
	class ePair {
	public:
		T1 Key;
		T2 Value;

		ePair() : Key(), Value() {}
		ePair(T1 key, T2 value) : Key(key), Value(value) {}

		const bool operator==(const ePair& other) const {
			return Key == other.Key && Value == other.Value;
		}

		const bool operator!=(const ePair& other) const {
			return Key != other.Key || Value != other.Value;
		}
	};
}