#ifndef BONIFACE_CACHEKEY_H
#define BONIFACE_CACHEKEY_H


#include <string>

class CacheKey {
private:
    const std::string &path;
    const uint8_t method;

public:
    CacheKey(const std::string &path, uint8_t method);

    friend bool operator==(const CacheKey &x, const CacheKey &y);
    friend bool operator!=(const CacheKey &x, const CacheKey &y);
    friend bool operator<(const CacheKey &x, const CacheKey &y);
    friend bool operator>(const CacheKey &x, const CacheKey &y);
    friend bool operator<=(const CacheKey &x, const CacheKey &y);
    friend bool operator>=(const CacheKey &x, const CacheKey &y);
};


#endif //BONIFACE_CACHEKEY_H
