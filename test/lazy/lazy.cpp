/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/lazy.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>

#include "comparable.hpp"
#include <tuple>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto ...xs) {
    return std::make_tuple(xs...);
};

BOOST_HANA_CONSTEXPR_LAMBDA auto invalid = [](auto x) {
    return x.this_function_must_not_be_instantiated;
};

template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

int main() {
    BOOST_HANA_CONSTEXPR_ASSERT(equal(lazy(f)(), lazy(f())));
    BOOST_HANA_CONSTEXPR_ASSERT(equal(lazy(f)(x<0>), lazy(f(x<0>))));
    BOOST_HANA_CONSTEXPR_ASSERT(equal(lazy(f)(x<0>, x<1>), lazy(f(x<0>, x<1>))));
    BOOST_HANA_CONSTEXPR_ASSERT(equal(lazy(f)(x<0>, x<1>, x<2>), lazy(f(x<0>, x<1>, x<2>))));

    // The function is not applied.
    lazy(invalid)();
    lazy(invalid)(x<0>);
    lazy(invalid)(x<0>, x<1>);
    lazy(invalid)(x<0>, x<1>, x<2>);
}
