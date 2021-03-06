/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTANT_ASSERT(equal(int_<1>, int_<1>));
    BOOST_HANA_CONSTANT_ASSERT(not_equal(int_<1>, int_<2>));

    BOOST_HANA_CONSTANT_ASSERT(equal(int_<1>, long_<1>));
    BOOST_HANA_CONSTANT_ASSERT(not_equal(int_<1>, long_<2>));
    //! [main]
}
