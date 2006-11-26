/*
 * Copyright (c) 2005-2006 Alon Bar-Lev <alon.barlev@gmail.com>
 * All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, or the OpenIB.org BSD license.
 *
 * GNU General Public License (GPL) Version 2
 * ===========================================
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2
 *  as published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program (see the file COPYING[.GPL2] included with this
 *  distribution); if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * OpenIB.org BSD license
 * =======================
 * Redistribution and use in source and binary forms, with or without modifi-
 * cation, are permitted provided that the following conditions are met:
 *
 *   o  Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   o  Redistributions in binary form must reproduce the above copyright no-
 *      tice, this list of conditions and the following disclaimer in the do-
 *      cumentation and/or other materials provided with the distribution.
 *
 *   o  The names of the contributors may not be used to endorse or promote
 *      products derived from this software without specific prior written
 *      permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LI-
 * ABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUEN-
 * TIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEV-
 * ER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABI-
 * LITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef ___PKCS11H_SESSION_H
#define ___PKCS11H_SESSION_H

#include "common.h"
#include "_pkcs11h-core.h"

CK_RV
_pkcs11h_session_getSlotList (
	IN const pkcs11h_provider_t provider,
	IN const CK_BBOOL token_present,
	OUT CK_SLOT_ID_PTR * const pSlotList,
	OUT CK_ULONG_PTR pulCount
);

CK_RV
_pkcs11h_session_getObjectAttributes (
	IN const pkcs11h_session_t session,
	IN const CK_OBJECT_HANDLE object,
	IN OUT const CK_ATTRIBUTE_PTR attrs,
	IN const unsigned count
);

CK_RV
_pkcs11h_session_freeObjectAttributes (
	IN OUT const CK_ATTRIBUTE_PTR attrs,
	IN const unsigned count
);

CK_RV
_pkcs11h_session_findObjects (
	IN const pkcs11h_session_t session,
	IN const CK_ATTRIBUTE * const filter,
	IN const CK_ULONG filter_attrs,
	OUT CK_OBJECT_HANDLE **const p_objects,
	OUT CK_ULONG *p_objects_found
);

CK_RV
_pkcs11h_session_getSessionByTokenId (
	IN const pkcs11h_token_id_t token_id,
	OUT pkcs11h_session_t * const p_session
);

CK_RV
_pkcs11h_session_release (
	IN const pkcs11h_session_t session
);

CK_RV
_pkcs11h_session_reset (
	IN const pkcs11h_session_t session,
	IN void * const user_data,
	IN const unsigned mask_prompt,
	OUT CK_SLOT_ID * const p_slot
);

CK_RV
_pkcs11h_session_getObjectById (
	IN const pkcs11h_session_t session,
	IN const CK_OBJECT_CLASS class,
	IN const CK_BYTE_PTR id,
	IN const size_t id_size,
	OUT CK_OBJECT_HANDLE * const p_handle
);

CK_RV
_pkcs11h_session_validate (
	IN const pkcs11h_session_t session
);

CK_RV
_pkcs11h_session_touch (
	IN const pkcs11h_session_t session
);

CK_RV
_pkcs11h_session_login (
	IN const pkcs11h_session_t session,
	IN const PKCS11H_BOOL public_only,
	IN const PKCS11H_BOOL readonly,
	IN void * const user_data,
	IN const unsigned mask_prompt
);

CK_RV
_pkcs11h_session_logout (
	IN const pkcs11h_session_t session
);

#endif

