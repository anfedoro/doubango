#ifndef SIP_CHALLENGE_H
#define SIP_CHALLENGE_H

#include "tinyWRAP_config.h"
#include "tinysip.h"
#include "tinysip/authentication/tsip_challenge.h"
#include "Common.h"
#include <cstring>  // for memcpy

class SipStack;

class TINYWRAP_API SipChallenge {
public:
#if !defined(SWIG)
    SipChallenge(tsip_challenge_t* challenge);
#endif

    virtual ~SipChallenge() {};

    const SipStack* getStack() const;
    const char* getScheme() const;
    const char* getRealm() const;
    const char* getNonce() const;
    const char* getOpaque() const;
    const char* getAlgorithm() const;
    const char* getQop() const;
    const char* getUsername() const;
    const char* getHa1Hexstr() const;

    void setCK(char* ck);

    void setIK(char* ik);


    bool setHa1HexStr(const char* ha1_hexstr);

private:
    tsip_challenge_t* challenge_;
};

#endif // SIP_CHALLENGE_H