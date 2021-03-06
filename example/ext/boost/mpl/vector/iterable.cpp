/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/ext/boost/mpl/vector.hpp>
#include <boost/hana/ext/std/integral_constant.hpp>
#include <boost/hana/type.hpp>

#include <boost/mpl/vector.hpp>
#include <type_traits>
using namespace boost::hana;
namespace mpl = boost::mpl;


BOOST_HANA_CONSTANT_ASSERT(head(mpl::vector<int, char, void>{}) == type<int>);

BOOST_HANA_CONSTANT_ASSERT(equal(
    tail(mpl::vector<int, char, void>{}),
    mpl::vector<char, void>{}
));

BOOST_HANA_CONSTANT_ASSERT(equal(
    drop_while(trait<std::is_floating_point>, mpl::vector<float, double const, int, float&>{}),
    mpl::vector<int, float&>{}
));

int main() { }
