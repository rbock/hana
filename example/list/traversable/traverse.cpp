/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/list/instance.hpp>
#include <boost/hana/maybe.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    BOOST_HANA_CONSTEXPR_LAMBDA auto half = [](auto x) {
        return if_(x % int_<2> == int_<0>,
            just(x / int_<2>),
            nothing
        );
    };

    BOOST_HANA_CONSTANT_ASSERT(
        traverse<Maybe>(half, list(int_<2>, int_<4>, int_<6>))
        ==
        just(list(int_<1>, int_<2>, int_<3>))
    );

    BOOST_HANA_CONSTANT_ASSERT(
        traverse<Maybe>(half, list(int_<2>, int_<3>, int_<6>))
        ==
        nothing
    );
    //! [main]
}
