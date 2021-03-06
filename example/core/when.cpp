/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/core/typeclass.hpp>

#include <iostream>
#include <type_traits>
using namespace boost::hana;


struct Printable {
    BOOST_HANA_TYPECLASS(Printable);
};

auto print = [](std::ostream& os, auto x) {
  return Printable::instance<datatype_t<decltype(x)>>::print_impl(os, x);
};

template <typename T>
struct Printable::instance<T, when<std::is_arithmetic<T>::value>> {
    static void print_impl(std::ostream& os, T x) {
        os << x;
    }
};

int main() {
    print(std::cout, 2);
}
