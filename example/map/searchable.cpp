/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/maybe.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/type.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    auto m = map(
        pair(type<int>, 'i'),
        pair(type<float>, 'f')
    );
    BOOST_HANA_CONSTEXPR_ASSERT(lookup(m, type<int>) == just('i'));
    BOOST_HANA_CONSTEXPR_ASSERT(lookup(m, type<float>) == just('f'));
    BOOST_HANA_CONSTANT_ASSERT(lookup(m, type<void>) == nothing);
    BOOST_HANA_CONSTANT_ASSERT(lookup(m, int_<3>) == nothing);
    //! [main]
}
