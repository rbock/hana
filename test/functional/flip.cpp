/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/functional.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>

#include <tuple>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto ...xs) {
    return std::make_tuple(xs...);
};

int main() {
    BOOST_HANA_CONSTEXPR_ASSERT(flip(f)(1, '2') == f('2', 1));
    BOOST_HANA_CONSTEXPR_ASSERT(flip(f)(1, '2', 3.3) == f('2', 1, 3.3));
    BOOST_HANA_CONSTEXPR_ASSERT(flip(f)(1, '2', 3.3, 4.4f) == f('2', 1, 3.3, 4.4f));
    BOOST_HANA_CONSTEXPR_ASSERT(flip(f)(1, '2', 3.3, 4.4f, nullptr) == f('2', 1, 3.3, 4.4f, nullptr));
}
