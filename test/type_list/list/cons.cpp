/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/type_list.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/type.hpp>
using namespace boost::hana;


struct x0; struct x1; struct x2;

int main() {
    BOOST_HANA_CONSTANT_ASSERT(cons(type<x0>, type_list<>) == type_list<x0>);
    BOOST_HANA_CONSTANT_ASSERT(cons(type<x0>, type_list<x1>) == type_list<x0, x1>);
    BOOST_HANA_CONSTANT_ASSERT(cons(type<x0>, type_list<x1, x2>) == type_list<x0, x1, x2>);
}
