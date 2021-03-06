/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/integral.hpp>
using namespace boost::hana;


int main() {
    //! [main]
    auto i = integral<int, 3>; // notice no constexpr
    static_assert(value(i) == 3, "value(i) is always a constant expression!");
    //! [main]
}
