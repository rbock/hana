/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/ext/boost/fusion.hpp>

#include <boost/hana/detail/minimal/comparable.hpp>
#include <boost/hana/functor/laws.hpp>
#include <boost/hana/list/instance.hpp>

#include "../helper.hpp"
#include <cassert>
#include <tuple>
using namespace boost::hana;


template <int i>
constexpr auto x = detail::minimal::comparable<>(i);

template <int i, int j>
struct _f {
    template <typename X>
    constexpr auto operator()(X x) const
    { return std::make_tuple(i, j, x); }
};

template <int i, int j>
constexpr _f<i, j> f{};

int main() {
    with_nonassociative_forward_sequences([](auto container) {
        assert(Functor::laws::check(
            list(
                container(),
                container(x<0>),
                container(x<0>, x<1>),
                container(x<0>, x<1>, x<2>)
            ),
            list(
                f<1, 1>,
                f<1, 2>
            ),
            list(
                f<2, 1>,
                f<2, 2>
            )
        ));
    });
}
