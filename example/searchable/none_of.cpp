/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/bool.hpp>
#include <boost/hana/detail/assert.hpp>
#include <boost/hana/list/instance.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_ASSERT(none_of(list(false, false_, false_)));
    BOOST_HANA_CONSTEXPR_ASSERT(!none_of(list(false, false_, true)));
    BOOST_HANA_CONSTANT_ASSERT(!none_of(list(false, false_, true_)));
    //! [main]
}
