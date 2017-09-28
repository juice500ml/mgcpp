
//          Copyright RedPortal 2017 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <gtest/gtest.h>

#include <mgcpp/cuda/memory_management.hpp>
#define private public
#include <mgcpp/gpu_matrix.hpp>

TEST(gpu_matrix, default_constructor)
{
    mgcpp::gpu::matrix<float, 0> mat;

    EXPECT_EQ(mat.rows(), 0u);
    EXPECT_EQ(mat.columns(), 0u);
    EXPECT_EQ(mat._data, nullptr);
    EXPECT_EQ(mat._context, nullptr);
    EXPECT_TRUE(mat._released);
}

TEST(gpu_matrix, contextless_dimention_constructor)
{
    auto before = mgcpp::cuda_mem_get_info();
    EXPECT_TRUE(before);
    auto before_memory = before.value().first;
    
    {
        size_t row_dim = 10;
        size_t col_dim = 10;
        mgcpp::gpu::matrix<float, 0> mat(row_dim, col_dim);

        auto after = mgcpp::cuda_mem_get_info();
        EXPECT_TRUE(after);
        auto after_memory = after.value().first;

        EXPECT_GT(before_memory, after_memory);

        EXPECT_EQ(mat.rows(), row_dim);
        EXPECT_EQ(mat.columns(), col_dim);
        EXPECT_NE(mat._data, nullptr);
        EXPECT_EQ(mat._context, nullptr);
        EXPECT_FALSE(mat._released);
    }

    auto last = mgcpp::cuda_mem_get_info();
    EXPECT_TRUE(last);
    auto last_memory = last.value().first;

    EXPECT_EQ(before_memory, last_memory);
}