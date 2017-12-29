
//          Copyright RedPortal 2017 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef _MGCPP_SYSTEM_TYPE_CAST_HPP_
#define _MGCPP_SYSTEM_TYPE_CAST_HPP_

namespace mgcpp
{
    template<typename OutputType, typename InputType>
    inline OutputType
    mgcpp_cast(InputType data);
}

#include <mgcpp/system/type_cast.tpp>
#endif
