
//          Copyright RedPortal, mujjingun 2017 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

namespace mgcpp
{
    template<typename GpuMat>
    trans_expr<GpuMat>::
    trans_expr(GpuMat&& mat) noexcept
        : _mat(std::forward<GpuMat>(mat)) {}

    template<typename GpuMat>
    typename trans_expr<GpuMat>::result_type
    trans_expr<GpuMat>::
    eval()
    {
        
    }

    template<typename GpuMat,
             MGCPP_CONCEPT(assert_gpu_matrix<GpuMat>)>
    inline mat_trans_expr<GpuMat>
    trans(GpuMat&& mat) noexcept
    {
        return trans_expr<GpuMat>(std::forward<GpuMat>(mat));
    }
}
