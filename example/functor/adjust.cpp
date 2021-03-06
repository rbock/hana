/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/list/instance.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_LAMBDA auto negative = [](auto x) {
        return x < 0;
    };

    BOOST_HANA_CONSTEXPR_LAMBDA auto negate = [](auto x) {
        return -x;
    };

    BOOST_HANA_CONSTEXPR_ASSERT(
        adjust(negative, negate, list(-3, -2, -1, 0, 1, 2, 3))
        ==
        list(3, 2, 1, 0, 1, 2, 3)
    );
    //! [main]
}
