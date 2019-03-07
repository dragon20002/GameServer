#pragma once
#include "stdafx.h"
#include "PacketHeader.h"
#include "PacketClass.h"

class PacketFactory : public Singleton<PacketFactory>
{
public:
    Packet* getPacket(Int64 packetType)
    {
        switch (packetType) {
            case E_C_REQ_EXIT:    return new PK_C_REQ_EXIT();
            case E_S_ANS_EXIT:    return new PK_S_ANS_EXIT();
            case E_I_NOTIFY_TERMINAL:    return new PK_I_NOTIFY_TERMINAL();
            case E_C_REQ_HEARTBEAT:    return new PK_C_REQ_HEARTBEAT();
            case E_S_ANS_HEARTBEAT:    return new PK_S_ANS_HEARTBEAT();
            case E_C_REQ_ID_PW:    return new PK_C_REQ_ID_PW();
            case E_S_ANS_ID_PW:    return new PK_S_ANS_ID_PW();
            case E_I_DB_REQ_ID_PW:    return new PK_I_DB_REQ_ID_PW();
            case E_I_DB_ANS_ID_PW:    return new PK_I_DB_ANS_ID_PW();
            case E_C_REQ_CHATTING:    return new PK_C_REQ_CHATTING();
            case E_S_ANS_CHATTING:    return new PK_S_ANS_CHATTING();
        }
        return nullptr;
    }
};
