/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/list.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_STATIC_ASSERT(head(list(1, '2', "3")) == 1);
    BOOST_HANA_STATIC_ASSERT(tail(list(1, '2', "3")) == list('2', "3"));
    BOOST_HANA_STATIC_ASSERT(!is_empty(list(1, '2', "3")));
    BOOST_HANA_STATIC_ASSERT(is_empty(list()));
    //! [main]
}