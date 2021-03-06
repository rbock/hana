/*!
@file
Defines `boost::hana::detail::minimal::Searchable`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_DETAIL_MINIMAL_SEARCHABLE_HPP
#define BOOST_HANA_DETAIL_MINIMAL_SEARCHABLE_HPP

#include <boost/hana/comparable/equal_mcd.hpp>
#include <boost/hana/core/datatype.hpp>
#include <boost/hana/logical/logical.hpp>
#include <boost/hana/maybe.hpp>
#include <boost/hana/searchable/mcd.hpp>


namespace boost { namespace hana {
namespace detail { namespace minimal {
    template <typename mcd = hana::Searchable::mcd>
    struct Searchable { };

    template <typename X, typename mcd, typename = operators<hana::Comparable>>
    struct searchable_type {
        X value;
        using hana_datatype = Searchable<mcd>;
    };

    template <typename mcd>
    struct make_searchable_impl {
        template <typename X>
        constexpr auto operator()(X x) const
        { return searchable_type<X, mcd>{x}; }
    };

    template <typename mcd = hana::Searchable::mcd>
    constexpr make_searchable_impl<mcd> searchable{};
}} // end namespace detail::minimal

// Provided for convenience.
template <typename mcd>
struct Comparable::instance<
    detail::minimal::Searchable<mcd>, detail::minimal::Searchable<mcd>
> : Comparable::equal_mcd {
    template <typename X, typename Y>
    static constexpr auto equal_impl(X x, Y y)
    { return equal(x.value, y.value); }
};

template <>
struct Searchable::instance<detail::minimal::Searchable<Searchable::mcd>>
    : Searchable::mcd
{
    template <typename X, typename Pred>
    static constexpr auto find_impl(X x, Pred p)
    { return if_(p(x.value), just(x.value), nothing); }

    template <typename X, typename Pred>
    static constexpr auto any_impl(X x, Pred p)
    { return p(x.value); }
};
}} // end namespace boost::hana

#endif // !BOOST_HANA_DETAIL_MINIMAL_SEARCHABLE_HPP
