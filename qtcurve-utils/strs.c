/***************************************************************************
 *   Copyright (C) 2013~2013 by Yichao Yu                                  *
 *   yyc1992@gmail.com                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.              *
 ***************************************************************************/

#include "strs.h"

QTC_EXPORT char*
_qtcSPrintf(char *buff, size_t *size, bool allocated, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    char *res = _qtcSPrintfV(buff, size, allocated, fmt, ap);
    va_end(ap);
    return res;
}

QTC_EXPORT char*
_qtcSPrintfV(char *buff, size_t *_size, bool allocated,
             const char *fmt, va_list ap)
{
    if (!buff || !_size || !*_size) {
        char *res = NULL;
        vasprintf(&res, fmt, ap);
        return res;
    }
    va_list _ap;
    va_copy(_ap, ap);
    size_t size = *_size;
    size_t new_size = vsnprintf(buff, size, fmt, ap) + 1;
    if (new_size > size) {
        new_size = qtcAlignTo(new_size, 1024);
        if (allocated) {
            buff = realloc(buff, new_size);
        } else {
            buff = malloc(new_size);
        }
        *_size = new_size;
        new_size = vsnprintf(buff, new_size, fmt, _ap);
    }
    return buff;
}
