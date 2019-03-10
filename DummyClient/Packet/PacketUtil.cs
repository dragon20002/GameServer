using System;
using System.IO;
using System.Text;

namespace DummyClient
{
    public static class PacketUtil
    {
        public static void encodeHeader(MemoryStream packet, long headerType)
        {
            PacketUtil.encode(packet, headerType);
        }

        public static int decodePacketLen(byte[] data, ref int offset)
        {
            return PacketUtil.decodeInt32(data, ref offset);
        }

        public static long decodePacketType(byte[] data, ref int offset)
        {
            return PacketUtil.decodeInt64(data, ref offset);
        }

        public static PacketInterface packetAnalyzer(byte[] packetByte, ref int offset, int packetLen)
        {
            long packetType = PacketUtil.decodePacketType(packetByte, ref offset);
            PacketInterface packet = PacketFactory.getPacket(packetType);
            if (packet == null) //데이터 없음
                return null;

            if (offset < packetLen)
                packet.decode(packetByte, ref offset);

            return packet;
        }


        //-- encode, decode ----------------------------------------------------------------//
        public static void encode(MemoryStream packet, byte value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(byte));
        }

        public static byte decodeByte(byte[] data, ref int offset)
        {
            byte val = data[offset];
            offset += sizeof(byte);
            return val;
        }

        public static void encode(MemoryStream packet, char value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(char));
        }

        public static char decodeChar(byte[] data, ref int offset)
        {
            char val = BitConverter.ToChar(data, offset);
            offset += sizeof(char);
            return val;
        }

        public static void encode(MemoryStream packet, short value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(short));
        }

        public static short decodeInt16(byte[] data, ref int offset)
        {
            short val = BitConverter.ToInt16(data, offset);
            offset += sizeof(short);
            return val;
        }

        public static void encode(MemoryStream packet, int value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(int));
        }

        public static int decodeInt32(byte[] data, ref int offset)
        {
            int val = BitConverter.ToInt32(data, offset);
            offset += sizeof(int);
            return val;
        }

        public static void encode(MemoryStream packet, uint value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(uint));
        }

        public static uint decodeUInt32(byte[] data, ref int offset)
        {
            uint val = BitConverter.ToUInt32(data, offset);
            offset += sizeof(uint);
            return val;
        }

        public static void encode(MemoryStream packet, long value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(long));
        }

        public static long decodeInt64(byte[] data, ref int offset)
        {
            long val = BitConverter.ToInt64(data, offset);
            offset += sizeof(long);
            return val;
        }

        public static void encode(MemoryStream packet, ulong value)
        {
            packet.Write(BitConverter.GetBytes(value), 0, sizeof(ulong));
        }

        public static ulong decodeUInt64(byte[] data, ref int offset)
        {
            ulong val = BitConverter.ToUInt64(data, offset);
            offset += sizeof(ulong);
            return val;
        }

        public static void encode(MemoryStream packet, string str)
        {
            PacketUtil.encode(packet, (int)str.Length);
            packet.Write(Encoding.UTF8.GetBytes(str), 0, str.Length);
        }

        public static string decodestring(byte[] data, ref int offset)
        {
            int strLen = PacketUtil.decodeInt32(data, ref offset);
            string str = System.Text.Encoding.ASCII.GetString(data, offset, strLen);
            offset += strLen;
            return str;
        }
        //-- -------------- ----------------------------------------------------------------//
    }
}
