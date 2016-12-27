#ifndef __AMY_PLACEHOLDERS_HPP__
#define __AMY_PLACEHOLDERS_HPP__

#include <asio/placeholders.hpp>

namespace amy {
namespace placeholders {

inline boost::arg<1> error() {
    return boost::arg<1>();
}

inline boost::arg<2> result_set() {
    return boost::arg<2>();
}

inline boost::arg<2> affected_rows() {
    return boost::arg<2>();
}

} // namespace placeholders
} // namespace amy

#endif // __AMY_PLACEHOLDERS_HPP__

// vim:ft=cpp sw=4 ts=4 tw=80 et
