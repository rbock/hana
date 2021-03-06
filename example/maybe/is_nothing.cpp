/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/maybe.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTANT_ASSERT( is_nothing(nothing));
    BOOST_HANA_CONSTANT_ASSERT(!is_nothing(just('x')));
    BOOST_HANA_CONSTANT_ASSERT(!is_nothing(just(nothing)));
    //! [main]
}
