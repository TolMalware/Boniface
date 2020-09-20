#include "CacheKey.h"

CacheKey::CacheKey(const std::string &path, uint8_t method) :
    path(path),
    method(method) {}

bool operator==(const CacheKey &x, const CacheKey &y) {
    return x.path == y.path && x.method == y.method;
}

bool operator!=(const CacheKey &x, const CacheKey &y) {
    return !(x == y);
}

bool operator<(const CacheKey &x, const CacheKey &y) {
    return x.path < y.path || (!(y.path < x.path) && x.method < y.method);
}

bool operator>(const CacheKey &x, const CacheKey &y) {
    return y < x;
}

bool operator<=(const CacheKey &x, const CacheKey &y) {
    return !(y < x);
}

bool operator>=(const CacheKey &x, const CacheKey &y) {
    return !(x < y);
}
