#include <art/math/linear_algebra.hpp>

namespace art
{
template <typename _vector_type>
struct basic_ray
{
  using vector_type = _vector_type;

  vector_type origin    {};
  vector_type direction {};
};

template <typename scalar_type>
using basic_ray2  = basic_ray<typename linear_algebra<scalar_type>::vector2>;
template <typename scalar_type>
using basic_ray3  = basic_ray<typename linear_algebra<scalar_type>::vector3>;
template <typename scalar_type>
using basic_ray4  = basic_ray<typename linear_algebra<scalar_type>::vector4>;

template <typename scalar_type>
using default_ray = basic_ray3<scalar_type>;
}
