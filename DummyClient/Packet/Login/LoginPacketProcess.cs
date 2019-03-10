using System.Windows.Forms;

namespace DummyClient
{
    class LoginPacketProcess : PacketProcess
    {
        LoginContents contents_ = null;

        public LoginPacketProcess()
        {
            contents_ = new LoginContents();
        }

        public override void run(PacketInterface packet)
        {
            PacketType type = (PacketType)packet.type();
            switch (type)
            {
                case PacketType.E_S_ANS_ID_PW:
                    contents_.recvReqIdPw(packet);
                    return;
            }
            if (!base.defaultRun(packet))
            {
#if DEBUG
                MessageBox.Show("잘못된 패킷이 수신되었습니다. : " + type.ToString(), "error", MessageBoxButtons.OK);
                Application.Exit();
            }
#endif
        }
    }
}
