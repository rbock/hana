/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/range.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
using namespace boost::hana;


void test_drop() {
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<0>, range(int_<0>, int_<0>)) == range(int_<0>, int_<0>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<1>, range(int_<0>, int_<0>)) == range(int_<0>, int_<0>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<2>, range(int_<0>, int_<0>)) == range(int_<0>, int_<0>));

    BOOST_HANA_CONSTANT_ASSERT(drop(int_<0>, range(int_<0>, int_<1>)) == range(int_<0>, int_<1>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<1>, range(int_<0>, int_<1>)) == range(int_<1>, int_<1>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<2>, range(int_<0>, int_<1>)) == range(int_<1>, int_<1>));

    BOOST_HANA_CONSTANT_ASSERT(drop(int_<0>, range(int_<0>, int_<2>)) == range(int_<0>, int_<2>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<1>, range(int_<0>, int_<2>)) == range(int_<1>, int_<2>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<2>, range(int_<0>, int_<2>)) == range(int_<2>, int_<2>));

    BOOST_HANA_CONSTANT_ASSERT(drop(int_<0>, range(int_<0>, int_<3>)) == range(int_<0>, int_<3>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<1>, range(int_<0>, int_<3>)) == range(int_<1>, int_<3>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<2>, range(int_<0>, int_<3>)) == range(int_<2>, int_<3>));
    BOOST_HANA_CONSTANT_ASSERT(drop(int_<3>, range(int_<0>, int_<3>)) == range(int_<3>, int_<3>));

    BOOST_HANA_CONSTANT_ASSERT(drop(int_<10>, range(int_<20>, int_<50>)) == range(int_<30>, int_<50>));
}

int main() {
    BOOST_HANA_CONSTANT_ASSERT(is_empty(range(int_<0>, int_<0>)));
    BOOST_HANA_CONSTANT_ASSERT(!is_empty(range(int_<0>, int_<1>)));
    BOOST_HANA_CONSTANT_ASSERT(!is_empty(range(int_<0>, int_<2>)));

    BOOST_HANA_CONSTANT_ASSERT(head(range(int_<0>, int_<1>)) == int_<0>);
    BOOST_HANA_CONSTANT_ASSERT(head(range(int_<0>, int_<2>)) == int_<0>);
    BOOST_HANA_CONSTANT_ASSERT(head(range(int_<2>, int_<5>)) == int_<2>);
    BOOST_HANA_CONSTANT_ASSERT(head(range(int_<5>, int_<6>)) == int_<5>);

    BOOST_HANA_CONSTANT_ASSERT(tail(range(int_<0>, int_<1>)) == range(int_<1>, int_<1>));
    BOOST_HANA_CONSTANT_ASSERT(tail(range(int_<0>, int_<2>)) == range(int_<1>, int_<2>));
    BOOST_HANA_CONSTANT_ASSERT(tail(range(int_<0>, int_<3>)) == range(int_<1>, int_<3>));
    BOOST_HANA_CONSTANT_ASSERT(tail(range(int_<4>, int_<7>)) == range(int_<5>, int_<7>));

    BOOST_HANA_CONSTANT_ASSERT(at(int_<0>, range(int_<0>, int_<1>)) == int_<0>);
    BOOST_HANA_CONSTANT_ASSERT(at(int_<0>, range(int_<0>, int_<2>)) == int_<0>);
    BOOST_HANA_CONSTANT_ASSERT(at(int_<1>, range(int_<0>, int_<2>)) == int_<1>);
    BOOST_HANA_CONSTANT_ASSERT(at(int_<46>, range(int_<4>, int_<90>)) == int_<50>);

    BOOST_HANA_CONSTANT_ASSERT(last(range(int_<0>, int_<1>)) == int_<0>);
    BOOST_HANA_CONSTANT_ASSERT(last(range(int_<0>, int_<2>)) == int_<1>);
    BOOST_HANA_CONSTANT_ASSERT(last(range(int_<0>, int_<3>)) == int_<2>);
    BOOST_HANA_CONSTANT_ASSERT(last(range(int_<3>, int_<6>)) == int_<5>);

    test_drop();
}
