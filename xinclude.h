/*
 *  LibXDiff by Davide Libenzi ( File Differential Library )
 *  Copyright (C) 2003  Davide Libenzi
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, see
 *  <http://www.gnu.org/licenses/>.
 *
 *  Davide Libenzi <davidel@xmailserver.org>
 *
 */

#if !defined(XINCLUDE_H)
#define XINCLUDE_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifdef _WIN32
#else
#include <unistd.h>
#endif

#include "xmacros.h"
#include "xdiff.h"
#include "xtypes.h"
#include "xutils.h"
#include "xprepare.h"
#include "xdiffi.h"
#include "xemit.h"

#define giterr_set_oom() 0

/**
 * Check a pointer allocation result, returning -1 if it failed.
 */
#define GITERR_CHECK_ALLOC(ptr) if (ptr == NULL) { return -1; }

/** Check for additive overflow, setting an error if would occur. */
#define GIT_ADD_SIZET_OVERFLOW(out, one, two) \
        (git__add_sizet_overflow(out, one, two) ? (giterr_set_oom(), 1) : 0)

/** Check for additive overflow, setting an error if would occur. */
#define GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize) \
        (git__multiply_sizet_overflow(out, nelem, elsize) ? (giterr_set_oom(), 1) : 0)

/** Check for additive overflow, failing if it would occur. */
#define GITERR_CHECK_ALLOC_ADD(out, one, two) \
        if (GIT_ADD_SIZET_OVERFLOW(out, one, two)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD3(out, one, two, three) \
        if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), three)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD4(out, one, two, three, four) \
        if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), four)) { return -1; }

#define GITERR_CHECK_ALLOC_ADD5(out, one, two, three, four, five) \
        if (GIT_ADD_SIZET_OVERFLOW(out, one, two) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), three) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), four) || \
                GIT_ADD_SIZET_OVERFLOW(out, *(out), five)) { return -1; }

/** Check for multiplicative overflow, failing if it would occur. */
#define GITERR_CHECK_ALLOC_MULTIPLY(out, nelem, elsize) \
        if (GIT_MULTIPLY_SIZET_OVERFLOW(out, nelem, elsize)) { return -1; }

#endif /* #if !defined(XINCLUDE_H) */
