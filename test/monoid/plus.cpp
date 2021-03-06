/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/monoid/mcd.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/monoid.hpp>
using namespace boost::hana;


template <typename mcd>
void test() {
    constexpr auto mono = detail::minimal::monoid<mcd>;
    BOOST_HANA_CONSTEXPR_ASSERT(plus(mono(2), mono(3)) == mono(5));
    BOOST_HANA_CONSTEXPR_ASSERT(mono(2) + mono(3) == mono(5));
}

int main() {
    test<Monoid::mcd>();
}
