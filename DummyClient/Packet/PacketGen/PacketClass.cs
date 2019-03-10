using System;
using System.IO;

namespace DummyClient
{
    public class PK_C_REQ_EXIT : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_C_REQ_EXIT; }
        Int64 type() { return (Int64) PacketType.E_C_REQ_EXIT; }
        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
        }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_S_ANS_EXIT : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_S_ANS_EXIT; }
        Int64 type() { return (Int64) PacketType.E_S_ANS_EXIT; }
        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
        }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_I_NOTIFY_TERMINAL : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_I_NOTIFY_TERMINAL; }
        Int64 type() { return (Int64) PacketType.E_I_NOTIFY_TERMINAL; }
        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
        }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_C_REQ_HEARTBEAT : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_C_REQ_HEARTBEAT; }
        Int64 type() { return (Int64) PacketType.E_C_REQ_HEARTBEAT; }
        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
        }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_S_ANS_HEARTBEAT : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_S_ANS_HEARTBEAT; }
        Int64 type() { return (Int64) PacketType.E_S_ANS_HEARTBEAT; }
        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
        }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_C_REQ_ID_PW : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_C_REQ_ID_PW; }
        Int64 type() { return (Int64) PacketType.E_C_REQ_ID_PW; }
        public string         id_;
        public string         password_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, id_);
            PacketUtil.encode(packet_, password_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            id_ = PacketUtil.decodestring(packet, ref offset);
            password_ = PacketUtil.decodestring(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_S_ANS_ID_PW : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_S_ANS_ID_PW; }
        Int64 type() { return (Int64) PacketType.E_S_ANS_ID_PW; }
        public Byte         result_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, result_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            result_ = PacketUtil.decodeByte(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_I_DB_REQ_ID_PW : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_I_DB_REQ_ID_PW; }
        Int64 type() { return (Int64) PacketType.E_I_DB_REQ_ID_PW; }
        public UInt64         clientId_;
        public string         id_;
        public string         password_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, clientId_);
            PacketUtil.encode(packet_, id_);
            PacketUtil.encode(packet_, password_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            clientId_ = PacketUtil.decodeUInt64(packet, ref offset);
            id_ = PacketUtil.decodestring(packet, ref offset);
            password_ = PacketUtil.decodestring(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_I_DB_ANS_ID_PW : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_I_DB_ANS_ID_PW; }
        Int64 type() { return (Int64) PacketType.E_I_DB_ANS_ID_PW; }
        public UInt64         clientId_;
        public string         id_;
        public Byte         result_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, clientId_);
            PacketUtil.encode(packet_, id_);
            PacketUtil.encode(packet_, result_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            clientId_ = PacketUtil.decodeUInt64(packet, ref offset);
            id_ = PacketUtil.decodestring(packet, ref offset);
            result_ = PacketUtil.decodeByte(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_C_REQ_CHATTING : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_C_REQ_CHATTING; }
        Int64 type() { return (Int64) PacketType.E_C_REQ_CHATTING; }
        public string         text_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, text_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            text_ = PacketUtil.decodestring(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
    public class PK_S_ANS_CHATTING : PacketData, PacketInterface
    {
        Int64 PacketInterface.type() { return (Int64) PacketType.E_S_ANS_CHATTING; }
        Int64 type() { return (Int64) PacketType.E_S_ANS_CHATTING; }
        public string         id_;
        public string         text_;

        void PacketInterface.encode()
        {
            PacketUtil.encodeHeader(packet_, this.type());
            PacketUtil.encode(packet_, id_);
            PacketUtil.encode(packet_, text_);
    }
        void PacketInterface.decode(byte[] packet, ref int offset)
        {
            id_ = PacketUtil.decodestring(packet, ref offset);
            text_ = PacketUtil.decodestring(packet, ref offset);
        }
        MemoryStream PacketInterface.getStream()
        {
            return packet_;
        }
    }
}
