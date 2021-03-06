/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/map.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>
#include <boost/hana/detail/minimal/product.hpp>
#include <boost/hana/list/instance.hpp>
using namespace boost::hana;


template <int i>
constexpr auto key = detail::minimal::comparable<>(i);

template <int i>
constexpr auto value = detail::minimal::comparable<>(i + 100);

template <int i, int j>
constexpr auto p = detail::minimal::product<>(key<i>, value<j>);

int main() {
    BOOST_HANA_CONSTANT_ASSERT(values(map()) == list());
    BOOST_HANA_CONSTEXPR_ASSERT(values(map(p<1, 1>)) == list(value<1>));
    BOOST_HANA_CONSTEXPR_ASSERT(values(map(p<1, 1>, p<2, 2>)) == list(value<1>, value<2>));
    BOOST_HANA_CONSTEXPR_ASSERT(values(map(p<1, 1>, p<2, 2>, p<3, 3>)) == list(value<1>, value<2>, value<3>));
}
