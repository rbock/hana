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


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto x, auto s) {
    return std::make_tuple(x, s);
};

template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

template <typename mcd>
void test() {
    BOOST_HANA_CONSTEXPR_LAMBDA auto list = detail::minimal::list<mcd>;
    BOOST_HANA_CONSTANT_ASSERT( scanr1(list(), f)                 == list(                                           ));
    BOOST_HANA_CONSTEXPR_ASSERT(scanr1(list(x<0>), f)             == list(                                       x<0>));
    BOOST_HANA_CONSTEXPR_ASSERT(scanr1(list(x<0>, x<1>), f)       == list(                        f(x<0>, x<1>), x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT(scanr1(list(x<0>, x<1>, x<2>), f) == list(f(x<0>, f(x<1>, x<2>)), f(x<1>, x<2>), x<2>));
}

int main() {
    test<List::mcd<void>>();
}
