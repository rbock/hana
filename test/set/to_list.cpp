/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/set.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/comparable.hpp>
#include <boost/hana/detail/minimal/list.hpp>
using namespace boost::hana;


template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

int main() {
    using L = detail::minimal::List<>;
    constexpr auto list = detail::minimal::list<>;
    BOOST_HANA_CONSTANT_ASSERT(to<L>(set()) == list());
    BOOST_HANA_CONSTEXPR_ASSERT(to<L>(set(x<1>)) == list(x<1>));

    BOOST_HANA_CONSTEXPR_ASSERT(elem(permutations(list(x<1>, x<2>)), to<L>(set(x<1>, x<2>))));
    BOOST_HANA_CONSTEXPR_ASSERT(elem(permutations(list(x<1>, x<2>, x<3>)), to<L>(set(x<1>, x<2>, x<3>))));
}
