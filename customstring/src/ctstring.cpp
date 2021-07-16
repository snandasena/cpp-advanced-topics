//
// Created by sajith on 7/15/21.
//

#include "ctstring.h"

// MARK: constructors/destructors
CTString::CTString()
{
    reset();
}

CTString::CTString(const char *s)
{
    copy_str(s);
}

CTString::~CTString()
{
    reset();
}

// move constructor

CTString::CTString(CTString &&other) noexcept
{
    reset();

    _str = other._str;
    _str_len = other._str_len;

    other._str = nullptr;
    other._str_len = 0;
    other.reset();
}

// MARK: - private methods

void CTString::_reset_split_array() const
{
    if (_split_count)
    {
        while (_split_count)
        {
            _split_array[--_split_count]->reset();
        }

        _split_array.reset();
        _split_count = 0;
    }
}

void CTString::_append_split_array(const CTString &s) const
{
    if (_split_count >= _ctstring_max_split)
    {
        return;
    }

    if (!_split_count)
    {
        _split_array.reset(new _ctsp[_ctstring_max_split + 1]);
    }

    _split_array[_split_count] = std::make_shared<CTString>(s);
    ++_split_count;
}

// public methods

const char *CTString::alloc_str(size_t sz)
{
    if (_str)
    {
        reset();
    }

    _str_len = (sz > _ctstring_max_len) ? _ctstring_max_len : sz;
    _str = new char[_str_len + 1](); // new char[]() fills with 0

    return _str;
}

void CTString::reset()
{
    _reset_split_array();

    if (_str)
    {
        delete[] _str;
        _str = nullptr;
        _str_len = 0;
    }
}

void CTString::swap(CTString &b)
{
    std::swap(_str, b._str);
    std::swap(_str_len, b._str_len);
}


const char *CTString::c_str() const
{
    return _str;
}

const char *CTString::copy_str(const char *s)
{
    if (s)
    {
        size_t len = strnlen(s, _ctstring_max_len);
        alloc_str(len);
        strncpy((char *) _str, s, len);
        _str_len = len;
    }
    return _str;
}

// MARK: - operators

// copy-and-swap assigment
CTString &CTString::operator=(CTString other)
{
    swap(other);
    return *this;
}

CTString &CTString::operator+=(const char *rhs)
{
    if (rhs)
    {
        size_t newlen = _str_len + strnlen(rhs, _ctstring_max_len);

        if (newlen > _ctstring_max_len)
        {
            newlen = _ctstring_max_len;
        }

        size_t rhslen = newlen - _str_len;
        if (rhslen < 1)
        {
            return *this;
        }
        char *buf = new char[newlen + 1]();

        if (_str && _str_len)
        {
            memcpy(buf + _str_len, rhs, rhslen);
        }

        copy_str(buf);
        delete[] buf;
    }

    return *this;
}


const char CTString::operator[](const int index) const
{
    if (index < 0)
    {
        return 0;
    }

    if (index >= (int) _str_len)
    {
        return 0;
    } else return _str[index];
}

// MARK: - comparison operator

bool CTString::operator==(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) != 0)
    {
        return true;
    }
    return false;
}


bool CTString::operator!=(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) != 0) return true;
    else return false;
}

bool CTString::operator>(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) > 0) return true;
    else return false;
}

bool CTString::operator<(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) < 0) return true;
    else return false;
}

bool CTString::operator>=(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) >= 0) return true;
    else return false;
}

bool CTString::operator<=(const CTString &rhs) const
{
    if (std::strncmp(this->c_str(), rhs.c_str(), _ctstring_max_len) <= 0) return true;
    else return false;
}


// MARK: - conversion operators

CTString::operator const char *() const
{
    return c_str();
}

// MARK: - Utility methods
bool CTString::have_value() const
{
    if (_str)
    {
        return true;
    }
    return false;
}

// string format
CTString &CTString::format(const char *format, ...)
{
    char *buffer;

    va_list args;
    va_start(args, format);

    vasprintf(&buffer, format, args);
    copy_str(buffer);
    free(buffer);

    return *this;
}

CTString &CTString::trim()
{
    const static char *whitespace = "\x20\x1b\t\r\n\v\b\f\a";

    if (!have_value())
    {
        return *this;
    }

    size_t begin = 0;
    size_t end = length() - 1;

    for (begin = 0; begin <= end; ++begin)
    {
        if (strchr(whitespace, _str[begin]) == nullptr)
        {
            break;
        }
    }

    for (; end > begin; --end)
    {
        if (strchr(whitespace, _str[end]) == nullptr)
        {
            break;
        } else
        {
            _str[end] = '\0';
        }
    }

    if (begin)
    {
        for (size_t i = 0; _str[begin]; ++i)
        {
            _str[i] = _str[begin++];
        }
    }

    _str_len = strlen(_str);
    return *this;
}

CTString CTString::lower() const
{
    CTString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i)
    {
        rs._str[i] = std::tolower(rs._str[i]);
    }
    return rs;
}

CTString CTString::upper() const
{
    CTString rs = *this;
    for (size_t i = 0; rs._str[i]; ++i)
    {
        rs._str[i] = std::toupper(rs._str[i]);
    }
    return rs;
}

const char &CTString::back() const
{
    return _str[length() - 1];
}

const char &CTString::front() const
{
    return _str[0];
}

// MARK: - find and replace methods

long int CTString::char_find(const char &match) const
{
    for (size_t i = 0; _str[i]; ++i)
    {
        if (_str[i] == match)
        {
            return i;
        }
    }

    return -1;
}

const CTString &CTString::char_repl(const char &match, const char &repl)
{
    for (size_t i = 0; _str[i]; ++i)
    {
        if (_str[i] == match)
        {
            _str[i] = repl;
        }
    }

    return *this;
}


CTString CTString::substr(size_t start, size_t length)
{
    CTString re;
    char  *buf;

    if()
}




















