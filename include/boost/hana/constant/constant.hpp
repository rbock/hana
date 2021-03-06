/*!
@file
Forward declares `boost::hana::Constant`.

@copyright Louis Dionne 2014
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_CONSTANT_CONSTANT_HPP
#define BOOST_HANA_CONSTANT_CONSTANT_HPP

#include <boost/hana/core/typeclass.hpp>


namespace boost { namespace hana {
    //! @ingroup group-typeclasses
    //! The `Constant` type class is used for data types representing
    //! compile-time constants.
    //!
    //!
    //! ### Laws
    //! For any `Constant` `c`, the following program must be well-formed:
    //! @code
    //!     template <typename X>
    //!     void f(X x) {
    //!         constexpr auto y = value(x);
    //!     }
    //!
    //!     int main() {
    //!         f(c);
    //!     }
    //! @endcode
    //!
    //! This is basically saying that all of `c`'s information used in the
    //! call to `value` must be stored in its type.
    //!
    //! @todo Consider renaming this to `UniversalConstant`.
    struct Constant {
        BOOST_HANA_TYPECLASS(Constant);

        //! Minimal complete definition: `value`
        struct mcd { };

        struct laws;
    };

    //! Return the compile-time value of a constant.
    //! @relates Constant
    //!
    //! This function returns a value which is always a constant expression,
    //! and this function can always be called inside a constant expression.
    //! This poses some rather heavy restrictions on the implementation;
    //! specifically, it means that the implementation is fully determined
    //! by the type of its argument, and that it does not use the value of
    //! its argument at all.
    //!
    //! ### Example
    //! @snippet example/constant/value.cpp main
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto value = [](auto const& c) {
        return Constant::instance<
            datatype_t<decltype(c)>
        >::value_impl(c);
    };
#else
    namespace constant_detail {
        struct value {
            template <typename C>
            constexpr auto operator()(C const& c) const {
                return Constant::instance<
                    datatype_t<C>
                >::value_impl(c);
            }
        };
    }

    constexpr constant_detail::value value{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_CONSTANT_CONSTANT_HPP
