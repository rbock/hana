/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/list/instance.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_ASSERT(at(int_<0>, list(0, '1', 2.0)) == 0);
    BOOST_HANA_CONSTEXPR_ASSERT(at(int_<1>, list(0, '1', 2.0)) == '1');
    BOOST_HANA_CONSTEXPR_ASSERT(at(int_<2>, list(0, '1', 2.0)) == 2.0);
    //! [main]
}
