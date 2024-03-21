#pragma once

#ifdef __CUDACC__
#define ART_HOST        __host__
#define ART_DEVICE               __device__
#define ART_HOST_DEVICE __host__ __device__
#else
#define ART_HOST
#define ART_DEVICE
#define ART_HOST_DEVICE
#endif
