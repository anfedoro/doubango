#include "SipChallenge.h"


SipChallenge::SipChallenge(tsip_challenge_t* challenge){
    challenge_ = challenge;

    TSK_DEBUG_INFO("SipChallenge created");
    // Print SIP Challenge Content
    TSK_DEBUG_INFO("SIP Challenge data content:");
    TSK_DEBUG_INFO("\tScheme: %s", this->getScheme());
    TSK_DEBUG_INFO("\tRealm: %s", this->getRealm());
    TSK_DEBUG_INFO("\tNonce: %s", this->getNonce());
    TSK_DEBUG_INFO("\tOpaque: %s", this->getOpaque());
    TSK_DEBUG_INFO("\tAlgorithm: %s", this->getAlgorithm());
    TSK_DEBUG_INFO("\tQop: %s", this->getQop());
    TSK_DEBUG_INFO("\tUsername: %s", this->getUsername());
    TSK_DEBUG_INFO("\tHa1Hexstr: %s", this->getHa1Hexstr());
    
}

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


// Setter for CK
void SipChallenge::setCK(char* ck) {
    if (challenge_) {
        tsk_str_to_hex(ck, AKA_CK_SIZE *2, challenge_->ck);
    }
}



// Setter for IK
void SipChallenge::setIK(char * ik) {
    if (challenge_) {
        tsk_str_to_hex(ik, AKA_IK_SIZE *2, challenge_->ik);
    }
}


// Setter for Ha1Hexstr
bool SipChallenge::setHa1HexStr(const char* ha1_hexstr) {
    if (challenge_) {
        tsk_strupdate(&challenge_->ha1_hexstr, ha1_hexstr);
        return true;
    }
    return false;
}