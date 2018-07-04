/**
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following
 *   disclaimer in the documentation and/or other materials provided
 *   with the distribution.
 * * Neither the name of The Linux Foundation nor the names of its
 *   contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 *   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 *   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 *   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 *   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 *   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 *   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 *   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef SOURCES_LOG_H
#define SOURCES_LOG_H

#include<syslog.h>

#define RLOGE(fmt, args...) \
    do_syslog_new(LOG_ERR, "[DJ:E][%s:%d] " fmt, __func__, __LINE__, ## args)
#define RLOGI(fmt, args...) \
    do_syslog_new(LOG_ERR, "[DJ:I][%s:%d] " fmt, __func__, __LINE__, ## args)
#define RLOGW(fmt, args...) \
    do_syslog_new(LOG_ERR, "[DJ:W][%s:%d] " fmt, __func__, __LINE__, ## args)
#define RLOGD(fmt, args...) \
    do_syslog_new(LOG_ERR, "[DJ:D][%s:%d] " fmt, __func__, __LINE__, ## args)
#define RLOGW_IF(...) do {do_syslog_new(LOG_ERR, "RLOGW_IF: %s %s", __func__, __VA_ARGS__ );} while(0)
#define RLOGI_IF(...) do {do_syslog_new(LOG_ERR, "RLOGI_IF: %s %s", __func__, __VA_ARGS__ );} while(0)
#define RLOGV_IF(...) do {do_syslog_new(LOG_ERR, "RLOGV_IF: %s %s", __func__, __VA_ARGS__ );} while(0)
#define ALOGE(...) do {do_syslog_new(LOG_ERR, "ALOGE: %s %s", __func__, __VA_ARGS__ );} while(0)
#define RLOGV(...) do {do_syslog_new(LOG_ERR, "RLOGV: %s %s", __func__, __VA_ARGS__ );} while(0)

static inline void do_syslog_new(int level, const char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    vsyslog(level, fmt, args);
    va_end(args);
}

#endif //SOURCES_LOG_H
