/*
Copyright (C) 2008 StrmnNrmn

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#pragma once

#include "Base/Types.h"

#ifndef UTILITY_ENDIAN_H_
#define UTILITY_ENDIAN_H_


// DAEDALUS_ENDIAN_MODE should be defined via //Platform as one of:
#define DAEDALUS_ENDIAN_LITTLE 1
#define DAEDALUS_ENDIAN_BIG 2

// The endianness should really be defined
#ifndef DAEDALUS_ENDIAN_MODE
#error DAEDALUS_ENDIAN_MODE was not specified in //Platform
#endif

#if (DAEDALUS_ENDIAN_MODE == DAEDALUS_ENDIAN_BIG)

	#define U8_TWIDDLE 0x0
	#define U16_TWIDDLE 0x0
	#define U16H_TWIDDLE 0x0
	#define BSWAP32(x) x
	#define BSWAP16(x) x

#elif (DAEDALUS_ENDIAN_MODE == DAEDALUS_ENDIAN_LITTLE)
	#define U8_TWIDDLE 0x3
	#define U16_TWIDDLE 0x2
	#define U16H_TWIDDLE 0x1

	#if defined( __GNUC__ ) && !defined(__clang__)

		#define BSWAP32(x) __builtin_bswap32(x)

		//__builtin_bswap16 is not defined on the PSP toolchain..
		#ifdef DAEDALUS_PSP
			#define BSWAP16(x) __builtin_allegrex_wsbh(x)
		#else
			#define BSWAP16(x) __builtin_bswap16(x)
		#endif

	#elif defined( _MSC_VER )

		#define BSWAP32(x) _byteswap_ulong(x)
		#define BSWAP16(x) _byteswap_ushort(x)

	#else
		//TODO: Clang?
		#define BSWAP32(x) ((x >> 24) | ((x >> 8) & 0xFF00) | ((x & 0xFF00) << 8) | (x << 24))
		#define BSWAP16(x) ((x>>8)|(x<<8))
	#endif

#else
	#error No DAEDALUS_ENDIAN_MODE specified
#endif


inline u32 SwapEndian( u32 x )
{
	return BSWAP32(x);
}

#endif // UTILITY_ENDIAN_H_
