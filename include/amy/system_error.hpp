#ifndef __AMY_SYSTEM_ERROR_HPP__
#define __AMY_SYSTEM_ERROR_HPP__

#include <system_error>

namespace amy {

class system_error : public std::system_error {
public:
    explicit system_error(std::error_code const& ec) :
        std::system_error(ec)
    {}

    explicit system_error(std::error_code const& ec,
                          std::string const& message)
      : std::system_error(ec),
        message_(message)
    {}

    virtual ~system_error() throw() {
    }

    virtual char const* what() const throw() {
        return message_.c_str();
    }

private:
    std::string message_;

}; // class system_error

} // namespace amy

#endif // __AMY_SYSTEM_ERROR_HPP__

// vim:ft=cpp sw=4 ts=4 tw=80 et
