namespace DummyClient
{
    enum PacketType : long {
    /*1000*/    E_C_REQ_EXIT = 1000,
    /*1001*/    E_S_ANS_EXIT = 1001,
    /*1002*/    E_I_NOTIFY_TERMINAL = 1002,
    /*1003*/    E_C_REQ_HEARTBEAT = 1003,
    /*1004*/    E_S_ANS_HEARTBEAT = 1004,
    /*1005*/    E_C_REQ_ID_PW = 1005,
    /*1006*/    E_S_ANS_ID_PW = 1006,
    /*1007*/    E_I_DB_REQ_ID_PW = 1007,
    /*1008*/    E_I_DB_ANS_ID_PW = 1008,
    /*1009*/    E_C_REQ_CHATTING = 1009,
    /*1010*/    E_S_ANS_CHATTING = 1010,
    }
};
