/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/maybe.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>

#include <tuple>
using namespace boost::hana;


template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto x, auto s) {
    return std::make_tuple(x, s);
};

int main() {
    constexpr auto s = x<999>;
    BOOST_HANA_CONSTEXPR_ASSERT(foldr(just(x<0>), s, f) == f(x<0>, s));
    BOOST_HANA_CONSTEXPR_ASSERT(foldr(nothing, s, f) == s);
}
