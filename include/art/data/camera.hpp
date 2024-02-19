#pragma once

#include <art/math/transform.hpp>
#include <art/math/projection.hpp>

namespace art
{
template <typename scalar_type>
struct camera
{
  art::transform <scalar_type> transform  = art::transform             <scalar_type>();
  art::projection<scalar_type> projection = art::perspective_projection<scalar_type>();
};
}