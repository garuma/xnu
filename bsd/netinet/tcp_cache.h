/*
 * Copyright (c) 2015 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

/* TCP-cache to store and retrieve TCP-related information */

#ifndef _NETINET_TCP_CACHE_H
#define _NETINET_TCP_CACHE_H

#include <netinet/tcp_var.h>
#include <netinet/in.h>

extern void tcp_cache_set_cookie(struct tcpcb *tp, u_char *cookie, u_int8_t len);
extern int tcp_cache_get_cookie(struct tcpcb *tp, u_char *cookie, u_int8_t *len);
extern unsigned int tcp_cache_get_cookie_len(struct tcpcb *tp);

extern void tcp_heuristic_tfo_inc_loss(struct tcpcb *tp);
extern void tcp_heuristic_tfo_snd_good(struct tcpcb *tp);
extern void tcp_heuristic_tfo_rcv_good(struct tcpcb *tp);
extern void tcp_heuristic_tfo_middlebox(struct tcpcb *tp);
extern void tcp_heuristic_tfo_reset_loss(struct tcpcb *tp);
extern void tcp_heuristic_tfo_success(struct tcpcb *tp);
extern boolean_t tcp_heuristic_do_tfo(struct tcpcb *tp);

extern void tcp_cache_init(void);

#endif /* _NETINET_TCP_CACHE_H */

