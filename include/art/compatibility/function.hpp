#pragma once

#ifdef __CUDACC__
#include <nvfunctional>
namespace art
{
template <typename type>
using function = nvstd::function<type>;
}
#else
#include <functional>
namespace art
{
template <typename type>
using function = std::function<type>;
}
#endif
