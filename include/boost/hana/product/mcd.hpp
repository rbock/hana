/*!
@file
Defines `boost::hana::Product::mcd`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_PRODUCT_MCD_HPP
#define BOOST_HANA_PRODUCT_MCD_HPP

#include <boost/hana/product/product.hpp>

#include <boost/hana/comparable/equal_mcd.hpp>
#include <boost/hana/core/is_a.hpp>
#include <boost/hana/logical/logical.hpp>


namespace boost { namespace hana {
    //! Minimal complete definition: `first` and `second`
    struct Product::mcd { };

    //! Instance of `Comparable` for `Product`s.
    //!
    //! Two products `x` and `y` are equal iff they are equal element-wise,
    //! i.e. iff
    //! @code
    //!     first(x) == first(y) && second(x) == second(y)
    //! @endcode
    //!
    //! ### Example
    //! @snippet example/product/comparable.cpp main
    template <typename T, typename U>
    struct Comparable::instance<T, U, when<
        is_a<Product, T>() && is_a<Product, U>()
    >> : Comparable::equal_mcd {
        template <typename X, typename Y>
        static constexpr auto equal_impl(X x, Y y) {
            return and_(
                equal(first(x), first(y)),
                equal(second(x), second(y))
            );
        }
    };

#if 0
    template <typename T>
    struct Functor::instance<T, when<is_a<Pair, T>()>>
        : Functor::fmap_mcd
    {
        template <typename F, typename P>
        static constexpr auto fmap_impl(F f, P p)
        { return pair(f(first(p)), f(second(p))); }
    };

    template <typename T>
    struct Applicative::instance<T, when<is_a<Pair, T>()>>
        : Applicative::mcd
    {
        template <typename X>
        static constexpr auto lift_impl(X x)
        { return pair(x, x); }

        template <typename F, typename P>
        static constexpr auto ap_impl(F f, P p)
        { return pair(first(f)(first(p), second(f)(second(p)))); }
    };

    template <typename T>
    struct Monad::instance<T, when<is_a<Pair, T>()>>
        : Monad::bind_mcd<T>
    {
        template <typename P, typename F>
        static constexpr auto bind_impl(P p, F f) {
            return pair(
                bind(first(p), compose(first, f)),
                bind(second(p), compose(second, f))
            );
        }
    };

    template <typename T>
    struct Foldable::instance<T, when<is_a<Pair, T>()>>
        : Foldable::mcd
    {
        template <typename P, typename S, typename F>
        static constexpr auto foldr_impl(P p, S s, F f) {
            return f(first(p), f(second(p), s));
        }

        template <typename P, typename S, typename F>
        static constexpr auto foldl_impl(P p, S s, F f) {
            return f(f(s, first(p)), second(p));
        }
    };
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_PRODUCT_MCD_HPP
