/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/core/typeclass.hpp>

#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
using namespace boost::hana;


struct Printable {
    BOOST_HANA_TYPECLASS(Printable);
};

auto print = [](std::ostream& os, auto x) {
    return Printable::instance<
        datatype_t<decltype(x)>
    >::print_impl(os, x);
};

auto to_string = [](auto x) {
    return Printable::instance<
        datatype_t<decltype(x)>
    >::to_string_impl(x);
};

//! [streamable_instance]
template <typename T>
struct Printable::instance<T, when<is_valid<
    decltype(std::declval<std::ostream&>() << std::declval<T>())
>>> {
    static void print_impl(std::ostream& os, T x) {
        os << x;
    }

    static std::string to_string_impl(T x) {
        return (std::ostringstream{} << x).str();
    }
};
//! [streamable_instance]


int main() {
    //! [print_string]
print(std::cout, std::string{"foo"});
assert(to_string(std::string{"foo"}) == "foo");
    //! [print_string]
}
