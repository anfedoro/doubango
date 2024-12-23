#include "SipMessageCallback.h"
#include "SipMessage.h"
#include "tinysip/transports/tsip_transport.h"
#include "tsk_buffer.h"

static int sip_message_xxx_callback(tsip_message_t* msg, tsk_buffer_t** buffer)
{
 
    SipMessageCallback* callback = static_cast<SipMessageCallback*>(tsip_get_message_callback_data());
    if(callback) {
        SipMessage *sip_msg = new SipMessage(msg);
        char* data = callback->onSipMessage(sip_msg,(char*)(*buffer)->data, (*buffer)->size);
        if(data) {
            tsk_buffer_t* new_buffer = tsk_buffer_create(data, tsk_strlen(data));
           
            if(new_buffer) {
                tsk_buffer_t* old_buffer = *buffer;
                *buffer = new_buffer;
                TSK_OBJECT_SAFE_FREE(old_buffer);
            }
        }
        
        delete sip_msg;
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
