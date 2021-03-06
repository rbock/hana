/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/functional.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto ...xs) {
    return sizeof...(xs);
};

struct nonpod { virtual ~nonpod() { } };

int main() {
    BOOST_HANA_CONSTEXPR_ASSERT(apply(f) == 0);
    BOOST_HANA_CONSTEXPR_ASSERT(apply(f, 1) == 1);
    BOOST_HANA_CONSTEXPR_ASSERT(apply(f, 1, '2') == 2);
    BOOST_HANA_CONSTEXPR_ASSERT(apply(f, 1, '2', "3") == 3);
    BOOST_HANA_CONSTEXPR_ASSERT(apply(f, 1, '2', "3", 4.4) == 4);
    BOOST_HANA_RUNTIME_ASSERT(apply(f, 1, '2', "3", 4.4, nonpod{}) == 5);
}
