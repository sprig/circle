//
// util.h
//
// Circle - A C++ bare metal environment for Raspberry Pi
// Copyright (C) 2014-2019  R. Stange <rsta2@o2online.de>
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#ifndef _circle_util_h
#define _circle_util_h

#include <circle/macros.h>
#include <circle/types.h>

#ifdef __cplusplus
extern "C" {
#endif

void *memset (void *pBuffer, int nValue, size_t nLength) FROM_STDLIB;

void *memcpy (void *pDest, const void *pSrc, size_t nLength) FROM_STDLIB;
#define memcpyblk memcpy

void *memmove (void *pDest, const void *pSrc, size_t nLength) FROM_STDLIB;

int memcmp (const void *pBuffer1, const void *pBuffer2, size_t nLength) FROM_STDLIB;

size_t strlen (const char *pString) FROM_STDLIB;

int strcmp (const char *pString1, const char *pString2) FROM_STDLIB;
int strcasecmp (const char *pString1, const char *pString2) FROM_STDLIB;
int strncmp (const char *pString1, const char *pString2, size_t nMaxLen) FROM_STDLIB;

char *strcpy (char *pDest, const char *pSrc) FROM_STDLIB;

char *strncpy (char *pDest, const char *pSrc, size_t nMaxLen) FROM_STDLIB;

char *strcat (char *pDest, const char *pSrc) FROM_STDLIB;

char *strchr (const char *pString, int chChar) FROM_STDLIB;
char *strstr (const char *pString, const char *pNeedle) FROM_STDLIB;

char *strtok_r (char *pString, const char *pDelim, char **ppSavePtr) FROM_STDLIB;

unsigned long strtoul (const char *pString, char **ppEndPtr, int nBase) FROM_STDLIB;

int char2int (char chValue);			// with sign extension

#ifdef __GNUC__

#define bswap16		__builtin_bswap16
#define bswap32		__builtin_bswap32

#else

u16 bswap16 (u16 usValue);
u32 bswap32 (u32 ulValue);

#endif

#define le2be16		bswap16
#define le2be32		bswap32

#define be2le16		bswap16
#define be2le32		bswap32

#ifdef __cplusplus
}
#endif

#endif
