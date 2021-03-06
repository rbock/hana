/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/map.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/product.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


template <int i>
constexpr auto key = int_<i>;

template <int i>
constexpr auto value = int_<i + 100>;

template <int i, int j>
constexpr auto p = detail::minimal::product<>(key<i>, value<j>);

int main() {
    BOOST_HANA_CONSTANT_ASSERT( equal(map(), map()));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>), map()));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(), map(p<1, 1>)));

    BOOST_HANA_CONSTANT_ASSERT( equal(map(p<1, 1>), map(p<1, 1>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>), map(p<1, 2>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>), map(p<2, 1>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>), map(p<1, 1>, p<2, 2>)));

    BOOST_HANA_CONSTANT_ASSERT( equal(map(p<1, 1>, p<2, 2>), map(p<1, 1>, p<2, 2>)));
    BOOST_HANA_CONSTANT_ASSERT( equal(map(p<1, 1>, p<2, 2>), map(p<2, 2>, p<1, 1>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>, p<2, 2>), map(p<9, 1>, p<2, 2>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>, p<2, 2>), map(p<1, 9>, p<2, 2>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>, p<2, 2>), map(p<1, 1>, p<9, 2>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>, p<2, 2>), map(p<1, 1>, p<2, 9>)));
    BOOST_HANA_CONSTANT_ASSERT(!equal(map(p<1, 1>, p<2, 2>), map(p<1, 1>, p<2, 2>, p<3, 3>)));
}
