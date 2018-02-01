
//          Copyright RedPortal 2017 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <mgcpp/cuda_libs/cublas.hpp>
#include <mgcpp/system/error_code.hpp>

#include <cublas_v2.h>

namespace mgcpp
{
    // lv1
    inline outcome::result<void>
    cublas_dot(cublasHandle_t handle, size_t n,
               float const* x, size_t incx,
               float const* y, size_t incy,
               float* result) noexcept
    {
        std::error_code status =
            cublasSdot(handle, n, x, incx, y, incy, result); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_dot(cublasHandle_t handle, size_t n,
               double const* x, size_t incx,
               double const* y, size_t incy,
               double* result) noexcept
    {
        
        std::error_code status =
            cublasDdot(handle, n, x, incx, y, incy, result); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }


    inline outcome::result<void>
    cublas_axpy(cublasHandle_t handle, size_t n,
                float const* alpha,
                float const* x, size_t incx,
                float* y, size_t incy) noexcept
    {
        std::error_code status = cublasSaxpy(handle, n,
                                             alpha,
                                             x, incx,
                                             y, incy); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_axpy(cublasHandle_t handle, size_t n,
                double const* alpha,
                double const* x, size_t incx,
                double* y, size_t incy) noexcept
    {
        
        std::error_code status = cublasDaxpy(handle, n,
                                             alpha,
                                             x, incx,
                                             y, incy); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                float const* alpha,
                float* vec, size_t incvec) noexcept
    {
        std::error_code status = cublasSscal(handle, n,
                                             alpha,
                                             vec, incvec); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                double const* alpha,
                double* vec, size_t incvec) noexcept
    {
        std::error_code status = cublasDscal(handle, n,
                                             alpha,
                                             vec, incvec); 

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                cuComplex const* alpha,
                cuComplex* vec, size_t incvec) noexcept
    {
        // Technically undefined behavior, but no way around it
        std::error_code status = cublasCscal(handle, n,
                                             alpha,
                                             vec, incvec);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                float const* alpha,
                cuComplex* vec, size_t incvec) noexcept
    {
        std::error_code status = cublasCsscal(handle, n,
                                              alpha,
                                              vec, incvec);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                cuDoubleComplex const* alpha,
                cuDoubleComplex* vec, size_t incvec) noexcept
    {
        std::error_code status = cublasZscal(handle, n,
                                             alpha,
                                             vec, incvec);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_scal(cublasHandle_t handle, size_t n,
                double const* alpha,
                cuDoubleComplex* vec, size_t incvec) noexcept
    {
        std::error_code status = cublasZdscal(handle, n,
                                              alpha,
                                              vec, incvec);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }


    // lv3
    inline outcome::result<void>
    cublas_gemm(cublasHandle_t handle,
                cublasOperation_t transa, cublasOperation_t transb,
                size_t m, size_t n, size_t k,
                float const* alpha,
                float const* A, size_t lda,
                float const* B, size_t ldb,
                float const* beta,
                float* C, size_t ldc) noexcept
    {
        std::error_code status =
            cublasSgemm(handle, transa, transb,
                        m, n, k, alpha, A, lda,
                        B, ldb, beta, C, ldc);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_gemm(cublasHandle_t handle,
                cublasOperation_t transa, cublasOperation_t transb,
                size_t m, size_t n, size_t k,
                double const* alpha,
                double const* A, size_t lda,
                double const* B, size_t ldb,
                double const* beta,
                double* C, size_t ldc) noexcept
    {
        std::error_code status =
            cublasDgemm(handle, transa, transb,
                        m, n, k, alpha, A, lda,
                        B, ldb, beta, C, ldc);

        if(status != status_t::success)
            return status;
        else
            return outcome::success();
    }

    // blas-like cublas extensions
    template<>
    inline outcome::result<void>
    cublas_geam(cublasHandle_t handle,
                cublasOperation_t transa,
                cublasOperation_t transb,
                size_t m, size_t n,
                float const* alpha,
                float const* A, size_t lda,
                float const* beta,
                float const* B, size_t ldb,
                float *C, size_t ldc) noexcept
    {
        std::error_code err = cublasSgeam(handle,
                                          transa, transb,
                                          m, n,
                                          alpha,
                                          A, lda,
                                          beta,
                                          B, ldb,
                                          C, ldc);

        if(err)
            return err;
        else
            return outcome::success();
    }

    inline outcome::result<void>
    cublas_geam(cublasHandle_t handle,
                cublasOperation_t transa,
                cublasOperation_t transb,
                size_t m, size_t n,
                double const* alpha,
                double const* A, size_t lda,
                double const* beta,
                double const* B, size_t ldb,
                double* C, size_t ldc) noexcept
    {
        std::error_code err = cublasDgeam(handle,
                                          transa, transb,
                                          m, n,
                                          alpha,
                                          A, lda,
                                          beta,
                                          B, ldb,
                                          C, ldc);

        if(err)
            return err;
        else
            return outcome::success();
    }
}
