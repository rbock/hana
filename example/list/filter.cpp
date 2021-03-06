/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/list/instance.hpp>
#include <boost/hana/type.hpp>

#include <type_traits>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_ASSERT(filter(list(1, 2.0, 3, 4.0), trait_<std::is_integral>) == list(1, 3));
    //! [main]
}
