#include "common.h"

#include "PRinternal/dbgproto.h"
#include "PR/os_internal.h"
#include "PR/sptask.h"
#include "PRinternal/rmonint.h"

#include "PRinternal/macros.h"

int __rmonSetFault(KKHeader* req) {
    KKFaultRequest* request = (KKFaultRequest*)req;
    KKObjectEvent reply;

    reply.header.code = request->header.code;
    reply.header.error = TV_ERROR_NO_ERROR;
    reply.object = request->tid;

    __rmonSendReply(&reply.header, sizeof(reply), KK_TYPE_REPLY);
    return TV_ERROR_NO_ERROR;
}

INCLUDE_ASM("asm/nonmatchings/rmon/rmonmisc", __rmonInit);

void __rmonPanic()
{
    for(;;)
    {
    }
}

int __rmonSetComm(KKHeader* req) {
    KKObjectEvent reply;

    reply.header.code = req->code;
    reply.object = 0;
    reply.header.error = TV_ERROR_NO_ERROR;
    
    __rmonSendReply(&reply.header, sizeof(reply), KK_TYPE_REPLY);
    return TV_ERROR_NO_ERROR;
}
