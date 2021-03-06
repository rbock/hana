/*!
@file
Defines `boost::hana::Record::mcd`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_RECORD_MCD_HPP
#define BOOST_HANA_RECORD_MCD_HPP

#include <boost/hana/record/record.hpp>

#include <boost/hana/comparable/equal_mcd.hpp>
#include <boost/hana/core/datatype.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/detail/std/type_traits.hpp>
#include <boost/hana/foldable/mcd.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/product/product.hpp>
#include <boost/hana/searchable/mcd.hpp>


namespace boost { namespace hana {
    //! Minimal complete definition: `members`
    struct Record::mcd { };

    //! Two `Records` of the same data type `R` are equal if and only if
    //! all their members are equal. The members are compared in the
    //! same order as they appear in `members<R>`.
    template <typename R>
    struct Comparable::instance<R, R, when<is_a<Record, R>()>>
        : Comparable::equal_mcd
    {
        template <typename X, typename Y>
        static constexpr auto equal_impl(X x, Y y) {
            return all(members<R>, [=](auto k_f) {
                return equal(second(k_f)(x), second(k_f)(y));
            });
        }
    };

    //! Folding a `Record` `R` is equivalent to folding a list of its members,
    //! in the same order as they appear in `members<R>`.
    template <typename R>
    struct Foldable::instance<R, when<is_a<Record, R>()>>
        : Foldable::mcd
    {
        template <typename X, typename S, typename F>
        static constexpr auto foldl_impl(X x, S s, F f) {
            return foldl(members<R>, s, [=](auto s, auto k_f) {
                return f(s, second(k_f)(x));
            });
        }

        template <typename X, typename S, typename F>
        static constexpr auto foldr_impl(X x, S s, F f) {
            return foldr(members<R>, s, [=](auto k_f, auto s) {
                return f(second(k_f)(x), s);
            });
        }
    };

    //! Searching a `Record` `r` is equivalent to searching `to<Map>(r)`.
    template <typename R>
    struct Searchable::instance<R, when<is_a<Record, R>()>>
        : Searchable::mcd
    {
        template <typename X, typename Pred>
        static constexpr auto find_impl(X x, Pred pred) {
            return fmap(
                [=](auto k_f) { return second(k_f)(x); },
                find(members<R>, [=](auto k_f) { return pred(first(k_f)); })
            );
        }

        template <typename X, typename Pred>
        static constexpr auto any_impl(X x, Pred pred) {
            return any(members<R>, [=](auto k_f) { return pred(first(k_f)); });
        }
    };

    //! Converting a `Record` `R` to a `Map` is equivalent to converting its
    //! `members<R>` to a `Map`, except the values are replaced by the actual
    //! members of the object instead of accessors.
    template <typename R>
    struct convert<Map, R, detail::std::enable_if_t<is_a<Record, R>()>> {
        template <typename X>
        static constexpr auto apply(X x) {
            return to<Map>(fmap(
                [=](auto k_f) {
                    using P = datatype_t<decltype(k_f)>;
                    return make_product<P>(first(k_f), second(k_f)(x));
                },
                members<R>
            ));
        }
    };
}} // end namespace boost::hana

#endif // !BOOST_HANA_RECORD_MCD_HPP
