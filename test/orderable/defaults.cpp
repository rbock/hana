/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/orderable/orderable.hpp>

#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/is_a.hpp>

#include <boost/hana/detail/assert.hpp>
using namespace boost::hana;


struct integer {
    int value;
    friend constexpr bool operator<(integer a, integer b)
    { return a.value < b.value; }
};

struct integer2 {
    int value;
    struct hana_datatype;
    friend constexpr bool operator<(integer2 a, integer2 b)
    { return a.value < b.value; }
};

using Integer = datatype_t<integer>;
using Integer2 = datatype_t<integer2>;

int main() {
    BOOST_HANA_CONSTEXPR_ASSERT(less(integer{0}, integer{1}));
    BOOST_HANA_CONSTEXPR_ASSERT(!less(integer{0}, integer{0}));
    BOOST_HANA_CONSTEXPR_ASSERT(!less(integer{1}, integer{0}));
    BOOST_HANA_CONSTANT_ASSERT(are<Orderable, Integer, Integer>);

    // No instance is provided when the data type differs from the C++ type.
    BOOST_HANA_CONSTANT_ASSERT(!are<Orderable, Integer2, Integer2>);
    BOOST_HANA_CONSTANT_ASSERT(!are<Orderable, Integer2, Integer>);
    BOOST_HANA_CONSTANT_ASSERT(!are<Orderable, Integer, Integer2>);
}
