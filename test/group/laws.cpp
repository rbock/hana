/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/group/minus_mcd.hpp>
#include <boost/hana/group/negate_mcd.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/group.hpp>
#include <boost/hana/group/laws.hpp>
#include <boost/hana/list/instance.hpp>
using namespace boost::hana;


template <template <typename ...> class mcd>
void test() {
    constexpr auto g = detail::minimal::group<mcd>;
    BOOST_HANA_CONSTEXPR_ASSERT(Group::laws::check(
        list(g(0), g(1), g(2), g(3))
    ));
}

int main() {
    test<Group::negate_mcd>();
    test<Group::minus_mcd>();
}
