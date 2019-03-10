using System;

namespace DummyClient
{
    public static class PacketFactory
    {
        public static PacketInterface getPacket(Int64 packetType)
        {
            switch ((PacketType)packetType)
            {
                case PacketType.E_C_REQ_EXIT:    return new PK_C_REQ_EXIT();
                case PacketType.E_S_ANS_EXIT:    return new PK_S_ANS_EXIT();
                case PacketType.E_I_NOTIFY_TERMINAL:    return new PK_I_NOTIFY_TERMINAL();
                case PacketType.E_C_REQ_HEARTBEAT:    return new PK_C_REQ_HEARTBEAT();
                case PacketType.E_S_ANS_HEARTBEAT:    return new PK_S_ANS_HEARTBEAT();
                case PacketType.E_C_REQ_ID_PW:    return new PK_C_REQ_ID_PW();
                case PacketType.E_S_ANS_ID_PW:    return new PK_S_ANS_ID_PW();
                case PacketType.E_I_DB_REQ_ID_PW:    return new PK_I_DB_REQ_ID_PW();
                case PacketType.E_I_DB_ANS_ID_PW:    return new PK_I_DB_ANS_ID_PW();
                case PacketType.E_C_REQ_CHATTING:    return new PK_C_REQ_CHATTING();
                case PacketType.E_S_ANS_CHATTING:    return new PK_S_ANS_CHATTING();
            }
            return null;
        }
    }
}
