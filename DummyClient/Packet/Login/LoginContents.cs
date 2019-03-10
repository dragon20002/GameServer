using System.Windows.Forms;

namespace DummyClient
{
    class LoginContents : ContentsProcess
    {
        public void recvReqIdPw(PacketInterface rowPacket)
        {
            PK_S_ANS_ID_PW packet = (PK_S_ANS_ID_PW)rowPacket;
            const int TRUE = 1;
            if (packet.result_ != TRUE)
            {
                MessageBox.Show("로그인 실패", "로그인", MessageBoxButtons.OK);
                return;
            }
            Program.programState_.setState(PROGRAM_STATE.CHATTING);
        }
    }
}
