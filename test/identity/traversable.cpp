/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/identity.hpp>

#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/minimal/applicative.hpp>
#include <boost/hana/functional.hpp>

#include "unique_comparable.hpp"
#include "unique_function.hpp"
using namespace boost::hana;


auto x = unique_comparable([]{});
auto a = detail::minimal::applicative<>;
auto f = compose(a, unique_function([]{}));
using A = detail::minimal::Applicative<>;

BOOST_HANA_CONSTANT_ASSERT(equal(
    traverse<A>(f, identity(x)),
    fmap(identity, f(x))
));

int main() { }
