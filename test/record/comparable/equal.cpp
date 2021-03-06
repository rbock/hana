/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include "../udt.hpp"
#include <boost/hana/detail/assert.hpp>
using namespace boost::hana;


int main() {
    BOOST_HANA_CONSTEXPR_ASSERT( equal(udt{0, '0'}, udt{0, '0'}));
    BOOST_HANA_CONSTEXPR_ASSERT(!equal(udt{0, '0'}, udt{1, '0'}));
    BOOST_HANA_CONSTEXPR_ASSERT(!equal(udt{0, '0'}, udt{0, '1'}));
}
