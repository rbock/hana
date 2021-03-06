/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include "../udt.hpp"
#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
using namespace boost::hana;


BOOST_HANA_CONSTEXPR_LAMBDA auto is = [](auto k) {
    return [=](auto key) { return equal(k, key); };
};

BOOST_HANA_CONSTANT_ASSERT(any(udt{0, '0'}, is(member1)));
BOOST_HANA_CONSTANT_ASSERT(any(udt{0, '0'}, is(member2)));

int main() { (void)is; }
