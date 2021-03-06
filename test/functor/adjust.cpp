/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/functor/adjust_mcd.hpp>
#include <boost/hana/functor/fmap_mcd.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/detail/minimal/functor.hpp>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto x) {
    return x + 1;
};

template <typename mcd>
void test() {
    constexpr auto functor = detail::minimal::functor<mcd>;
    constexpr auto x = 1;
    BOOST_HANA_CONSTEXPR_ASSERT(adjust([](auto) { return true; }, f, functor(x)) == functor(f(x)));
    BOOST_HANA_CONSTEXPR_ASSERT(adjust([](auto) { return false; }, f, functor(x)) == functor(x));
}

int main() {
    test<Functor::fmap_mcd>();
    test<Functor::adjust_mcd>();
}
