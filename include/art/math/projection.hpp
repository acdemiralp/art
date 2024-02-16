#pragma once

#include <variant>

namespace art
{
template <typename scalar_type>
struct perspective_projection
{
  scalar_type vertical_field_of_view = static_cast<scalar_type>(2   ); // 2 radians = ~115 degrees. Similar to the human eye: ~130 degrees.
  scalar_type aspect_ratio           = static_cast<scalar_type>(1   );
  scalar_type focal_length           = static_cast<scalar_type>(1   );
  scalar_type near_clip              = static_cast<scalar_type>(0.01);
  scalar_type far_clip               = static_cast<scalar_type>(1000);
};

template <typename scalar_type>
struct orthographic_projection
{
  scalar_type height                 = static_cast<scalar_type>(1   );
  scalar_type aspect_ratio           = static_cast<scalar_type>(1   );
  scalar_type near_clip              = static_cast<scalar_type>(0.01);
  scalar_type far_clip               = static_cast<scalar_type>(1000);
};

// TODO: Other projection types.

template <typename scalar_type>
using projection = std::variant<
  perspective_projection <scalar_type>,
  orthographic_projection<scalar_type>>;
}