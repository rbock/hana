/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/ext/boost/fusion.hpp>

#include "../helper.hpp"
#include <cassert>
using namespace boost::hana;


auto test = [](auto container) {
    assert(equal(tail(container(1)), container()));
    assert(equal(tail(container(1, '2')), container('2')));
    assert(equal(tail(container(1, '2', 3.3)), container('2', 3.3)));
};

int main() {
    with_nonassociative_forward_sequences(test);
}
