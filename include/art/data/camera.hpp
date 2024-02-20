#pragma once

#include <cstddef>
#include <functional>

#include <art/math/transform.hpp>
#include <art/math/projection.hpp>

namespace art
{
#ifdef __CUDACC__
#define ART_HOST        __host__
#define ART_DEVICE               __device__
#define ART_HOST_DEVICE __host__ __device__

#include <nvfunctional>
template <typename type>
using function = nvstd::function<type>;
#else
#define ART_HOST
#define ART_DEVICE
#define ART_HOST_DEVICE

#include <functional>
template <typename type>
using function = std::function<type>;
#endif

template <typename container_type>
struct resizable_container_interface
{
  void begin ()
  {

  }
  void end   ()
  {

  }
  void resize(const std::size_t size)
  {
    
  }
};

template <typename scalar_type>
struct default_ray
{
  using linear_algebra = art::linear_algebra<scalar_type>;
  using vector3        = typename linear_algebra::vector3;

  vector3 origin   ;
  vector3 direction;
};

template<typename transform_type, typename projection_type>
struct missing_ray_generation_implementation : std::false_type {};

template <typename scalar_type, typename ray_type = default_ray<scalar_type>, typename container_type = std::vector<default_ray<scalar_type>>>
ART_HOST_DEVICE inline std::int32_t default_ray_generation_function(const art::transform<scalar_type>& transform, const art::projection<scalar_type>& projection)
{
  static_assert(missing_ray_generation_implementation<transform_type, projection_type>::value, "Missing default ray generation function implementation for transform-projection pair.")
  return {};
}

template <typename scalar_type, typename ray_type = default_ray<scalar_type>, typename container_type = std::vector<default_ray<scalar_type>>>
ART_HOST_DEVICE inline container_type default_ray_generation_function(const art::transform<scalar_type>& transform, const art::perspective_projection <scalar_type>& projection)
{
  // TODO.
}
template <typename scalar_type, typename ray_type = default_ray<scalar_type>, typename container_type = std::vector<default_ray<scalar_type>>>
ART_HOST_DEVICE inline container_type default_ray_generation_function(const art::transform<scalar_type>& transform, const art::orthographic_projection<scalar_type>& projection)
{
  // TODO.
}

template <typename scalar_type, typename ray_type = default_ray<scalar_type>, typename container_type = std::vector<default_ray<scalar_type>>>
struct camera
{
  art::transform <scalar_type>                                                                               transform               = art::transform                 <scalar_type>();
  art::projection<scalar_type>                                                                               projection              = art::perspective_projection    <scalar_type>();
  art::function  <container_type(const art::transform <scalar_type>&, const art::projection <scalar_type>&)> ray_generation_function = default_ray_generation_function<scalar_type>; // TODO: Ray order.
};
}