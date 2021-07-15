//
// Created by sajith on 7/15/21.
//

#ifndef ADVANCED_TOPICS_CTSTRING_H
#define ADVANCED_TOPICS_CTSTRING_H


#ifdef _MSC_VER

// disable MSVC _s warnings

#ifndef _CRT_SECURE_NO_WARNINGS
#   define _CRT_SECURE_NO_WARNINGS
#endif

// uncomment to disable pragma warnings
// #pragma warning (disable: 4068 )
// standard-ish function missing from MS library


#include <cstdarg>
int vasprintf(char **ret, const char *format, va_list ap);
#endif // _MSC_VER

#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <cctype>
#include <memory>

constexpr const char *_ctstring_vertion = "1.0.0";
constexpr size_t _ctstring_max_len = 65535;
constexpr size_t _ctstring_max_split = 65535;

// simple smart C-string
class CTString
{
    char *_str = nullptr;
    size_t _str_len = 0;

    // this is a poor man's vector
    // unique ptr to array of shared pointer CTString objects

    typedef std::shared_ptr<CTString> _ctsp;
    typedef std::unique_ptr<_ctsp[]> _split_ptr;

    mutable _split_ptr _split_array;
    mutable size_t _split_count = 0;

    // private methods
    void _reset_split_arary() const;

    void _append_split_array(const CTString &s) const;

public:

    typedef _split_ptr split_ptr;

    // constructor
    CTString(); // default constructor
    CTString(const char *s); // c-string
    CTString(const CTString &);  // copy constructor
    CTString(CTString &&) noexcept; // move constructor
    ~CTString();


    // data management
    const char *allo_str(size_t sz); // smart alloc string
    void reset(); // reset data
    void swap(CTString &b); // member function swap
    const char *c_str() const;  // getter
    const char *copy_str() const;  // alloc and copy


    // Operators
    CTString &operator=(CTString); // copy and swap assigment
    CTString &operator+=(const char *); // concatenation operator
    CTString &operator+=(const CTString &); // concatenation operator
    const char operator[](const int) const; // subscript operator

    // comparison operators
    bool operator==(const CTString &) const;

    bool operator!=(const CTString &) const;

    bool operator>(const CTString &) const;

    bool operator<(const CTString &) const;

    bool operator>=(const CTString &) const;

    bool operator<=(const CTString &) const;

    // conversion operators
    operator const char *() const; // c-string type

    // utility methods
    static const char *version() { return _ctstring_vertion; }

    bool have_value() const;

    size_t length() const { return _str_len; }

    size_t size() const { return _str_len; }

    CTString &format(const char *format, ...);

    CTString &trim();

    CTString lower() const;

    CTString upper() const;

    const char &back() const;

    const char &front() const;

    // find  and replace methods
    long int char_find(const char &match) const;

    const CTString &char_repl(const char &match, const char &repl);

    CTString substr(size_t start, size_t length);

    long find(const CTString &match) const;

    const CTString replace(const CTString &match, const CTString &repl);

    // split methods
    const split_ptr &split(const char *match) const;

    const split_ptr &split(const char match) const;

    const split_ptr &split(const char *match, int max_split) const;

    const CTString &split_item(size_t index) const;

    size_t split_count() const { return _split_count; }

};

// non-member operator overloads
CTString operator+(const CTString &lhs, const CTString &rhs);

#endif //ADVANCED_TOPICS_CTSTRING_H
