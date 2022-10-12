#include <cstring>
#include <iomanip>
#include "number.h"

uint32_t base = 1000000000;

uint2022_t from_uint(uint32_t i) {
    uint2022_t number;
    number.digits.reserve(70);
    while (true) {
        number.digits.push_back(i % base);
        i /= base;
        if (i == 0) {
            break;
        }
    }
    return number;
}

uint2022_t from_string(const char* buff) {
    uint2022_t number;
    number.digits.reserve(70);
    char buf[2022];
    strcpy(buf, buff);
    for (int i = (int) strlen(buf); i > 0; i -= 9) {
        buf[i] = 0;
        number.digits.push_back(atoi(i >= 9 ? buf + i - 9 : buf));
    }
    return number;
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    if (lhs.digits.size() != rhs.digits.size()) {
        return false;
    }
    for (long long i = 0; i < lhs.digits.size(); i++) {
        if (lhs.digits[i] != rhs.digits[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return !(lhs == rhs);
}

bool operator<(const uint2022_t& lhs, const uint2022_t& rhs) {
    if (lhs == rhs) return false;
    else {
        if (lhs.digits.size() != rhs.digits.size()) {
            return lhs.digits.size() < rhs.digits.size();
        } else {
            for (long long i = lhs.digits.size() - 1; i >= 0; --i) {
                if (lhs.digits[i] != rhs.digits[i]) {
                    return lhs.digits[i] < rhs.digits[i];
                }
            }
        }
        return false;
    }
}

bool operator>(const uint2022_t& lhs, const uint2022_t& rhs) {
    return (rhs < lhs);
}

bool operator<=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return (lhs < rhs || lhs == rhs);
}

bool operator>=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return (lhs > rhs || lhs == rhs);
}

uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t number;
    number.digits.reserve(70);
    uint32_t carry = 0;
    for (long long i = 0; i < lhs.digits.size() || i < rhs.digits.size() || carry; i++) {
        uint32_t left_value = (i < lhs.digits.size() ? lhs.digits[i] : 0);
        uint32_t right_value = (i < rhs.digits.size() ? rhs.digits[i] : 0);
        int sum = (left_value + right_value + carry) % base;
        carry = (left_value + right_value + carry) / base;
        number.digits.push_back(sum);
    }
    return number;
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t number;
    number.digits.reserve(70);
    number.digits = lhs.digits;
    uint32_t carry = 0;
    for (long long i = 0; i < rhs.digits.size() || carry; i++) {
        int64_t value = (int64_t) number.digits[i] - (carry + ((i < rhs.digits.size()) ? (int64_t) rhs.digits[i] : 0));
        carry = value < 0;
        if (carry) {
            value += base;
        }
        number.digits[i] = value;
    }
    while (number.digits.size() > 1 && number.digits.back() == 0) {
        number.digits.pop_back();
    }
    return number;
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    stream << "Implement me";

    return stream;
}
