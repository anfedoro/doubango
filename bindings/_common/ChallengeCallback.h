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

#include "tinysip/authentication/tsip_challenge.h"
#include "tinysip/authentication/tsip_milenage.h"
#include <vector>

#ifndef TINYWRAP_CHALLENGE_CALLBACK_H
#define TINYWRAP_CHALLENGE_CALLBACK_H

class SipChallenge;

class ChallengeCallback
{
public:
    ChallengeCallback();
    virtual ~ChallengeCallback();

    virtual const char* onChallengeCallback(SipChallenge* challenge, const char* password) 
    {
        TSK_DEBUG_INFO("*** Virtual onChallengeCallback called");
        return tsk_null;
    }

#if !defined(SWIG)
public:
    static int challenge_cb(tsip_challenge_t* challenge, const char* password, char** result);

#endif

private:


};

#endif /* TINYWRAP_CHALLENGE_CALLBACK_H */
