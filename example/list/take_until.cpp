/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/functional.hpp>
#include <boost/hana/integer_list.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;
using namespace literals;


int main() {
    //! [main]
    BOOST_HANA_CONSTANT_ASSERT(
        take_until(_ < 2_c, integer_list<int, 3, 2, 1, 0>) == integer_list<int, 3, 2>
    );
    //! [main]
}
