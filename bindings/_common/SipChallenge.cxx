#include "SipChallenge.h"
#include <cstring>  // for memcpy

SipChallenge::SipChallenge(tsip_challenge_t* challenge) : challenge_(challenge) {}

const SipStack* SipChallenge::getStack() const {
    return static_cast<const SipStack*>(challenge_->stack);
}

const char* SipChallenge::getScheme() const {
    return challenge_->scheme;
}

const char* SipChallenge::getRealm() const {
    return challenge_->realm;
}

const char* SipChallenge::getNonce() const {
    return challenge_->nonce;
}

const char* SipChallenge::getOpaque() const {
    return challenge_->opaque;
}

const char* SipChallenge::getAlgorithm() const {
    return challenge_->algorithm;
}

const char* SipChallenge::getQop() const {
    return challenge_->qop;
}

const char* SipChallenge::getUsername() const {
    return challenge_->username;
}

const char* SipChallenge::getHa1Hexstr() const {
    return challenge_->ha1_hexstr;
}

// Getter for CK
void SipChallenge::getCK(AKA_CK_T& ck_out) const {
    if (challenge_) {
        std::memcpy(ck_out, challenge_->ck, AKA_CK_SIZE + 1);
    }
}

// Setter for CK
void SipChallenge::setCK(const AKA_CK_T& ck) {
    if (challenge_) {
        std::memcpy(challenge_->ck, ck, AKA_CK_SIZE + 1);
    }
}

// Getter for IK
void SipChallenge::getIK(AKA_IK_T& ik_out) const {
    if (challenge_) {
        std::memcpy(ik_out, challenge_->ik, AKA_IK_SIZE + 1);
    }
}

// Setter for IK
void SipChallenge::setIK(const AKA_IK_T& ik) {
    if (challenge_) {
        std::memcpy(challenge_->ik, ik, AKA_IK_SIZE + 1);
    }
}

// // Getter for Cnonce
// void SipChallenge::getCnonce(tsk_md5string_t& cnonce_out) const {
//     if (challenge_) {
//         std::memcpy(cnonce_out, challenge_->cnonce, TSK_MD5_STRING_SIZE + 1);
//     }
// }

// // Setter for Cnonce
// void SipChallenge::setCnonce(const tsk_md5string_t& cnonce) {
//     if (challenge_) {
//         std::memcpy(challenge_->cnonce, cnonce, TSK_MD5_STRING_SIZE + 1);
//     }
// }

// Setter for Ha1Hexstr
bool SipChallenge::setHa1HexStr(const char* ha1_hexstr) {
    if (challenge_) {
        tsk_strupdate(&challenge_->ha1_hexstr, ha1_hexstr);
        return true;
    }
    return false;
}