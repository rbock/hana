/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/type.hpp>

#include <boost/hana/detail/assert.hpp>
using namespace boost::hana;


struct T; struct U;

BOOST_HANA_CONSTANT_ASSERT( equal(type<T>, type<T>));
BOOST_HANA_CONSTANT_ASSERT(!equal(type<T>, type<U>));
BOOST_HANA_CONSTANT_ASSERT(!equal(type<void>, type<U>));
BOOST_HANA_CONSTANT_ASSERT(!equal(type<T>, type<void>));
BOOST_HANA_CONSTANT_ASSERT( equal(type<void>, type<void>));

BOOST_HANA_CONSTANT_ASSERT( equal(type<T&>, type<T&>));
BOOST_HANA_CONSTANT_ASSERT(!equal(type<T&>, type<T&&>));
BOOST_HANA_CONSTANT_ASSERT(!equal(type<T const>, type<T>));
BOOST_HANA_CONSTANT_ASSERT( equal(type<T const>, type<T const>));

int main() { }
