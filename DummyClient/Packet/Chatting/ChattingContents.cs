namespace DummyClient
{
    class ChattingContents : ContentsProcess
    {
        public void recvChatting(PacketInterface rowPacket)
        {
            PK_S_ANS_CHATTING packet = (PK_S_ANS_CHATTING)rowPacket;
            Program.programState_.putMessage(packet.id_ + packet.text_);
        }
    }
}
