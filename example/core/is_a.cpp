/*
@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/bool.hpp>
#include <boost/hana/comparable/comparable.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/detail/assert.hpp>
#include <boost/hana/detail/constexpr.hpp>
#include <boost/hana/ext/std/tuple.hpp>
#include <boost/hana/integral.hpp>
#include <boost/hana/iterable/iterable.hpp>
#include <boost/hana/list/instance.hpp>
#include <boost/hana/logical/logical.hpp>
#include <boost/hana/maybe.hpp>
#include <boost/hana/monad/monad.hpp>
#include <boost/hana/range.hpp>

#include <tuple>
using namespace boost::hana;


int main() {
    //! [standard]
    BOOST_HANA_CONSTANT_ASSERT( is_a<Foldable, Maybe>);
    BOOST_HANA_CONSTANT_ASSERT(!is_a<Logical, Maybe>);
    BOOST_HANA_CONSTANT_ASSERT(!is_a<Foldable, int>);
    BOOST_HANA_CONSTANT_ASSERT( are<Comparable, int, long>);
    //! [standard]

    //! [alternate]
    BOOST_HANA_CONSTEXPR_LAMBDA auto row = list;
    BOOST_HANA_CONSTEXPR_LAMBDA auto check_table = [](auto ...headers) {
        return [=](auto ...rows) {
            auto row_is_correct = [=](auto row) {
                return list(headers(head(row))...) == tail(row);
            };
            BOOST_HANA_CONSTANT_ASSERT(all(list(rows...), row_is_correct));
        };
    };

    check_table(                      is_a<Logical>, is_an<Iterable>, is_a<Monad>   )(
    row(just(1),                         false_,         false_,         true_      ),
    row(list(1, '2', 3.3),               false_,         true_,          true_      ),
    row(std::make_tuple("abc", 'd'),     false_,         true_,          true_      ),
    row(long_<12>,                       true_,          false_,         false_     ),
    row(range(int_<-4>, int_<15>),       false_,         true_,          false_     )
    );
    //! [alternate]
}
