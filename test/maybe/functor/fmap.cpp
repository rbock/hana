/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/maybe.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto f = [](auto x) { return x + int_<1>; };

int main() {
    BOOST_HANA_CONSTANT_ASSERT(fmap(f, nothing) == nothing);
    BOOST_HANA_CONSTEXPR_ASSERT(fmap(f, just(1)) == just(2));
    BOOST_HANA_CONSTANT_ASSERT(fmap(f, just(int_<1>)) == just(int_<2>));
}
