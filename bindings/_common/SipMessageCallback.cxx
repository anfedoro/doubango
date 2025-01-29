#include "SipMessageCallback.h"
#include "SipMessage.h"
#include "tinysip/transports/tsip_transport.h"
#include "tsk_buffer.h"

static int sip_message_xxx_callback(tsip_message_t* msg, void** data, tsk_size_t* size)
{
 
    SipMessageCallback* callback = static_cast<SipMessageCallback*>(tsip_get_message_callback_data());
    if(callback) {
        

        if (msg) {
            SipMessage* sip_msg = new SipMessage(msg);
   
            char* out_data = callback->onSipMessage(sip_msg, *(char**)data, (int)*size);
            if(out_data) {
                tsk_size_t old_size = *size;
                *size = strlen(out_data);
                char* new_data = (char*)tsk_malloc(*size);
                if(new_data) {
                    memcpy(new_data, out_data, *size);
                    void* old_data = *data;
                    *data = new_data;
                    TSK_FREE(old_data);
                }
                else {
                    *size = old_size;
                    TSK_DEBUG_ERROR("Failed to allocate memory for the new data\n");
                }
            }
        
            delete sip_msg;

        }
        else {
            callback->onSipMessage(tsk_null, *(char**)data, (int)*size);
        }
        
    } 

}


SipMessageCallback::SipMessageCallback(){
    tsip_set_message_callback_data(this);
    tsip_set_message_callback(sip_message_xxx_callback);
}

SipMessageCallback::~SipMessageCallback(){
    tsip_set_message_callback(tsk_null);
    tsip_set_message_callback_data(tsk_null);
}
