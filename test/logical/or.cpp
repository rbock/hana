/*
 * Copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/logical.hpp>

#include <boost/hana/detail/static_assert.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


int main() {
    BOOST_HANA_STATIC_ASSERT(!or_());
    BOOST_HANA_STATIC_ASSERT(!or_(false_));
    BOOST_HANA_STATIC_ASSERT(!or_(false_, false_));

    BOOST_HANA_STATIC_ASSERT(or_(true_));
    BOOST_HANA_STATIC_ASSERT(or_(false_, true_));
    BOOST_HANA_STATIC_ASSERT(or_(false_, false_, true_));
    BOOST_HANA_STATIC_ASSERT(or_(true_, false_, false_));
}