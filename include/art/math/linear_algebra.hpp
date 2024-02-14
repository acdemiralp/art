#pragma once

#define EIGEN_INITIALIZE_MATRICES_BY_ZERO

#include <cstdint>

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <unsupported/Eigen/CXX11/Tensor>

namespace art
{
template <typename scalar_type>
struct linear_algebra
{
using scalar     = scalar_type;

template <std::int32_t size> // Bad practice: Eigen uses 32 bit integers for size.
using vector     = Eigen::Vector<scalar, size>;
using vector2    = vector<2>;
using vector3    = vector<3>;
using vector4    = vector<4>;

template <std::int32_t rows, std::int32_t columns> // Bad practice: Eigen uses 32 bit integers for size.
using matrix     = Eigen::Matrix<scalar, rows, columns>;
using matrix22   = matrix<2, 2>;
using matrix33   = matrix<3, 3>;
using matrix44   = matrix<4, 4>;

template <typename dimensions>
using tensor     = Eigen::TensorFixedSize<scalar, dimensions>;
using tensor222  = tensor<Eigen::Sizes<2, 2, 2>>;
using tensor333  = tensor<Eigen::Sizes<3, 3, 3>>;
using tensor444  = tensor<Eigen::Sizes<4, 4, 4>>;

template <std::int32_t size>
using aabb       = Eigen::AlignedBox<scalar, size>;
using aabb2      = aabb<2>;
using aabb3      = aabb<3>;
using aabb4      = aabb<4>;

using quaternion = Eigen::Quaternion<scalar>;
using angle_axis = Eigen::AngleAxis <scalar>;

template <typename type>
using mapped     = Eigen::Map<type>;
};
}