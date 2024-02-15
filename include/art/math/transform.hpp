#pragma once

#include <art/math/linear_algebra.hpp>

namespace art
{
template <typename scalar_type>
struct transform
{
  using linear_algebra_type = typename linear_algebra<scalar_type>    ;
  using vector3             = typename linear_algebra_type::vector3   ;
  using quaternion          = typename linear_algebra_type::quaternion;

  vector3    translation = vector3   ::Zero    ();
  quaternion rotation    = quaternion::Identity();
  vector3    scale       = vector3   ::Ones    ();
};
}