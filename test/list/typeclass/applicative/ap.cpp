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


template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto ...xs) {
    return std::make_tuple(x<888>, xs...);
};

BOOST_HANA_CONSTEXPR_LAMBDA auto g = [](auto ...xs) {
    return std::make_tuple(x<999>, xs...);
};

template <typename mcd>
void test() {
    BOOST_HANA_CONSTEXPR_LAMBDA auto list = detail::minimal::list<mcd>;
    using L = detail::minimal::List<mcd>;

    BOOST_HANA_CONSTANT_ASSERT(ap(list(), list()) == list());
    BOOST_HANA_CONSTANT_ASSERT(ap(list(), list(x<0>)) == list());
    BOOST_HANA_CONSTANT_ASSERT(ap(list(), list(x<0>, x<1>)) == list());
    BOOST_HANA_CONSTANT_ASSERT(ap(list(), list(x<0>, x<1>, x<2>)) == list());

    BOOST_HANA_CONSTANT_ASSERT(ap(list(f), list()) == list());
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f), list(x<0>)) == list(f(x<0>)));
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f), list(x<0>, x<1>)) == list(f(x<0>), f(x<1>)));
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f), list(x<0>, x<1>, x<2>)) == list(f(x<0>), f(x<1>), f(x<2>)));

    BOOST_HANA_CONSTANT_ASSERT(ap(list(f, g), list()) == list());
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f, g), list(x<0>)) == list(f(x<0>), g(x<0>)));
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f, g), list(x<0>, x<1>)) == list(f(x<0>), f(x<1>), g(x<0>), g(x<1>)));
    BOOST_HANA_CONSTEXPR_ASSERT(ap(list(f, g), list(x<0>, x<1>, x<2>)) == list(f(x<0>), f(x<1>), f(x<2>), g(x<0>), g(x<1>), g(x<2>)));
}

int main() {
    test<List::mcd<void>>();
}
