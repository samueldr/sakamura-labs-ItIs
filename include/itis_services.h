/**
 * 
 * 	ItIs - An ITRON Implementation for Research and Education
 * 
 * Copyright (C) 1989-1997 by Sakamura Laboratory, Univ. of Tokyo, JAPAN
 * Copyright (C) 1997-1998 by Embedded and Real-Time Systems Laboratory,
 * 				Toyohashi Univ. of Technology, JAPAN
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the universities nor the names of the laboratories
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE UNIVERSITIES OR THE LABORATORIES BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 *  @(#) $Id: itis_services.h,v 1.9 1998/01/30 09:53:59 hiro Exp $
 */

#ifndef _ITIS_SERVICES_
#define _ITIS_SERVICES_

/* 
 *  ItIsアプリケーション 標準インクルードファイル
 *
 *  ItIs のシステムコールを呼び出すアプリケーションは，すべてのこのファ
 *  イルをインクルードすべきである．
 *  システムコールをサブルーチンコールで呼び出す場合には，このファイル
 *  をインクルードする前に，LINK_KERNEL を定義 (#define) すること．
 */

#include <itron.h>
#include <itron_errno.h>
#include <itron_fncode.h>
#include <itis_debug.h>
#include <itis_stddefs.h>
#include <itis_isyscall.h>

/*
 *  システムコール呼出マクロ
 */
extern void	itis_perror(const char *file, int line,
				const char *expr, ER ercd);
extern void	itis_panic(const char *file, int line,
				const char *expr, ER ercd);

Inline ER
_itis_perror(const char *file, int line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		itis_perror(file, line, expr, ercd);
	}
	return(ercd);
}

Inline ER
_itis_panic(const char *file, int line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		itis_panic(file, line, expr, ercd);
	}
	return(ercd);
}

#define	syscall(s)	_itis_perror(__FILE__, __LINE__, #s, (s));
#define	_syscall(s)	_itis_panic(__FILE__, __LINE__, #s, (s));

#endif /* _ITIS_SERVICES_ */
