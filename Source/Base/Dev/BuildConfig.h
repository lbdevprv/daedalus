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

#ifndef CONFIG_DEV_BUILDCONFIG_H_
#define CONFIG_DEV_BUILDCONFIG_H_


#define	DAEDALUS_DEBUG_CONSOLE				// Enable debug console
#define	DAEDALUS_DEBUG_DISPLAYLIST			// Enable the display list debugger
#undef	DAEDALUS_DEBUG_DYNAREC				// Enable to enable various debugging options for the dynarec
#undef	DAEDALUS_DEBUG_MEMORY
#undef	DAEDALUS_DEBUG_PIF					// Enable to enable various debugging options for PIF (Peripheral interface)
#undef	DAEDALUS_ENABLE_SYNCHRONISATION		// Enable for sync testing
#define	DAEDALUS_ENABLE_ASSERTS				// Enable asserts
#undef	DAEDALUS_ENABLE_PROFILING			// Enable the built-in profiler
#undef	DAEDALUS_PROFILE_EXECUTION			// Enable to keep track of various execution stats
#define	DAEDALUS_BATCH_TEST_ENABLED			// Enable the batch test
#undef	ALLOW_TRACES_WHICH_EXCEPT
#define	DAEDALUS_LOG						// Enable various logging
#undef	DAEDALUS_DIALOGS					// Enable this to ask confimation dialogs in the GUI
#undef	DAEDALUS_SILENT						// Define to quiet Debug Messages
#undef  DAEDALUS_ACCURATE_TMEM				// Full tmem emulation(Very accurate, but slighty slower) When this defined, is irrelevant having DAEDALUS_FAST_TMEM defined or not
#undef  DAEDALUS_BREAKPOINTS_ENABLED		// Whether breakpoint support is enabled.

#endif // BASE_DEV_BUILDCONFIG_H_