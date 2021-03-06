/* Copyright (c) 2016, Linaro Limited
 * All rights reserved.
 *
 * SPDX-License-Identifier:     BSD-3-Clause
 */

#ifndef ODP_PLAT_CPU_ARCH_H_
#define ODP_PLAT_CPU_ARCH_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @ingroup odp_compiler_optim
 *  @{
 */

#if defined __OCTEON__
#define ODP_CACHE_LINE_SIZE 128
#endif

/**
 * @}
 */

static inline void odp_cpu_pause(void)
{
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
	__asm__ __volatile__ ("nop");
}

#ifdef __cplusplus
}
#endif

#endif
