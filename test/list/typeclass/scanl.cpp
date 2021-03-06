/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/list/mcd.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>
#include <boost/hana/detail/minimal/list.hpp>

#include <tuple>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto s, auto x) {
    return std::make_tuple(s, x);
};

template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

template <typename mcd>
void test() {
    BOOST_HANA_CONSTEXPR_LAMBDA auto list = detail::minimal::list<mcd>;
    constexpr auto s = x<999>;

    BOOST_HANA_CONSTEXPR_ASSERT(scanl(list(), s, f)                 == list(s));
    BOOST_HANA_CONSTEXPR_ASSERT(scanl(list(x<0>), s, f)             == list(s, f(s, x<0>)));
    BOOST_HANA_CONSTEXPR_ASSERT(scanl(list(x<0>, x<1>), s, f)       == list(s, f(s, x<0>), f(f(s, x<0>), x<1>)));
    BOOST_HANA_CONSTEXPR_ASSERT(scanl(list(x<0>, x<1>, x<2>), s, f) == list(s, f(s, x<0>), f(f(s, x<0>), x<1>), f(f(f(s, x<0>), x<1>), x<2>)));
}

int main() {
    test<List::mcd<void>>();
}
