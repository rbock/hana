/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/maybe.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_LAMBDA auto plus = [](auto x, auto y) {
        return x + y;
    };

    BOOST_HANA_CONSTEXPR_ASSERT(foldr(nothing, 1, plus) == 1);
    BOOST_HANA_CONSTEXPR_ASSERT(foldr(just(4), 1, plus) == 5);
    //! [main]
}
