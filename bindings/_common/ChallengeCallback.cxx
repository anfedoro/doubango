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
#include "ChallengeCallback.h"
#include "SipChallenge.h"
#include "SipStack.h"
#include "Common.h"


/* Callback function for challenge calculation, which call ChallengeCallback object virtual function and can be overloaded
    By default it returns -1 and causes doubango internal authentication cnallenge result calculation
*/
static int challenge_xxx_cb(tsip_challenge_t* challenge, const char* password, char** result)
{
    int ret = -1;
    if(!challenge) return -1;
    
    
    ChallengeCallback* callback = static_cast<ChallengeCallback*>(tsip_get_challenge_data());
    if(callback) {
          
        SipChallenge* ch = new SipChallenge(challenge);
        AKA_RES_T aka_res_hex;
        const char* aka_res = callback->onChallengeCallback(ch, password);
        if(aka_res) {
            tsk_str_to_hex(aka_res, AKA_RES_SIZE *2, aka_res_hex);
            *result = (char*)tsk_calloc(1, AKA_RES_SIZE + 1);
            memcpy(*result, aka_res_hex, AKA_RES_SIZE);
            ret = 0;
        }
        delete ch;
    
    return ret;
    }
    
}

ChallengeCallback::ChallengeCallback()
{
    tsip_set_challenge_data(this);
    tsip_set_challenge_callback(ChallengeCallback::challenge_cb);
}

ChallengeCallback::~ChallengeCallback()
{
    tsip_set_challenge_data(tsk_null);
    tsip_set_challenge_callback(tsk_null);
}

int ChallengeCallback::challenge_cb(tsip_challenge_t* challenge, const char* password, char** result)
{
    TSK_DEBUG_INFO("ChallengeCallback cb function called");
    return challenge_xxx_cb(challenge, password, result);
}

