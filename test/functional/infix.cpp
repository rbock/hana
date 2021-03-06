/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>
#include <boost/hana/functional.hpp>

#include <tuple>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto ...xs) {
    return std::make_tuple('f', xs...);
};

BOOST_HANA_CONSTEXPR_LAMBDA auto g = infix(f);

template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

int main() {
    // disregard associativity
    BOOST_HANA_CONSTEXPR_ASSERT((x<0> ^g^ x<1>) == f(x<0>, x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT(((x<0> ^g)^ x<1>) == f(x<0>, x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT((x<0> ^(g^ x<1>)) == f(x<0>, x<1>));

    // left partial application
    BOOST_HANA_CONSTEXPR_ASSERT((x<0>^g)(x<1>) == f(x<0>, x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT((x<0>^g)(x<1>, x<2>) == f(x<0>, x<1>, x<2>));
    BOOST_HANA_CONSTEXPR_ASSERT((x<0>^g)(x<1>, x<2>, x<3>) == f(x<0>, x<1>, x<2>, x<3>));

    // right partial application
    BOOST_HANA_CONSTEXPR_ASSERT((g^x<1>)(x<0>) == f(x<0>, x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT((g^x<2>)(x<0>, x<1>) == f(x<0>, x<1>, x<2>));
    BOOST_HANA_CONSTEXPR_ASSERT((g^x<3>)(x<0>, x<1>, x<2>) == f(x<0>, x<1>, x<2>, x<3>));

    // equivalence with the base function
    BOOST_HANA_CONSTEXPR_ASSERT(g(x<0>, x<1>) == f(x<0>, x<1>));
    BOOST_HANA_CONSTEXPR_ASSERT(g(x<0>, x<1>, x<2>) == f(x<0>, x<1>, x<2>));
    BOOST_HANA_CONSTEXPR_ASSERT(g(x<0>, x<1>, x<2>, x<3>) == f(x<0>, x<1>, x<2>, x<3>));
}
