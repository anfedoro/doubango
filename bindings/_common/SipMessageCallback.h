/*
* Copyright (C) 2010-2011 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou(at)doubango.org>
*
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/
#include "tsk_common.h"

class SipMessage;

#ifndef TINYWRAP_MESSAGE_CALLBACK_H
#define TINYWRAP_MESSAGE_CALLBACK_H

class SipMessageCallback {
public:
    SipMessageCallback();
    virtual ~SipMessageCallback();

    virtual char* onSipMessage(SipMessage* pMessage, char* data, int len) {
        // shoul be overloaded for Sip Message processing, otherwise do nothing
        return tsk_null;
    }


};

#endif /* TINYWRAP_MESSAGE_CALLBACK_H */