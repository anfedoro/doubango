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


    // Use methods for working with CK and IK arrays
    void getCK(AKA_CK_T& ck_out) const;
    void setCK(const AKA_CK_T& ck);

    void getIK(AKA_IK_T& ik_out) const;
    void setIK(const AKA_IK_T& ik);

    // void getCnonce(tsk_md5string_t& cnonce_out) const;
    // void setCnonce(const tsk_md5string_t& cnonce);

    bool setHa1HexStr(const char* ha1_hexstr);

private:
    tsip_challenge_t* challenge_;
};

#endif // SIP_CHALLENGE_H