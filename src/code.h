/************************************************************************
*
*  LibTMail
*  Copyright (C) 2010  Thor Qin
*
* This library is free software; you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public
* License as published by the Free Software Foundation; either
* version 2 of the License, or (at your option) any later version.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
* 
* You should have received a copy of the GNU Lesser General Public
* License along with this library; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* Author: Thor Qin
* Bug Report: thor.qin@gmail.com
*
**************************************************************************/

#ifndef _CODE_H_
#define _CODE_H_

#include "config.h"
#include <string>

namespace tmail
{

size_t get_wchar_utf8_length(wchar_t ch);
inline size_t get_utf8_base64_length(size_t len)
{
	return (len / 3 + (len % 3 > 0 ? 1 : 0)) * 4 + 12;
}

bool is_ascii_printable_string(const std::wstring& src);
bool is_ascii_printable_string(const std::string& src);

// `content` must already encoded with `charset`.
const std::string encode_base64(const char* content, size_t len,
		const std::string& charset, bool column_limited = false);
inline const std::string encode_base64(const std::wstring& src, bool column_limited = false);

// `content` must already encoded with `charset`.
const std::string encode_qprint(const char* content, size_t len,
		const std::string& charset, bool column_limited = false);
inline const std::string encode_qprint(const std::wstring& src, bool column_limited = false);


const std::wstring decode_base64(const char* content, size_t len, const std::string& charset);
const std::wstring decode_qprint(const char* content, size_t len, const std::string& charset);
const std::wstring decode_header_field(const std::string& src);


// If mailbox has any non-ascii characters then use utf8-base64 encode the mailbox, except `@` character.
const std::string encode_mailbox_base64(const std::wstring& src);






inline const std::string encode_base64(const std::wstring& src, bool column_limited)
{
	std::string tmp;
	tlib::wstring_to_utf8(src, tmp);
	return encode_base64(tmp.c_str(), tmp.length(), "UTF-8", column_limited);
}

inline const std::string encode_qprint(const std::wstring& src, bool column_limited)
{
	std::string tmp;
	tlib::wstring_to_utf8(src, tmp);
	return encode_qprint(tmp.c_str(), tmp.length(), "UTF-8", column_limited);
}

} // End of namespace


#endif
