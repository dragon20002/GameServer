using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DummyClient
{
    internal abstract class FormState
    {
        protected Form form_;
        protected Network network_;

        public abstract void open();

        protected void setForm()
        {
            form_.TopLevel = false;
            form_.Dock = System.Windows.Forms.DockStyle.Fill;
            Program.mainForm_.Invoke(new MethodInvoker(delegate ()
            {
                form_.Parent = Program.mainForm_.mainPanel_;
                form_.Show();
            }));
        }

        public void close()
        {
            Program.mainForm_.removePanelForm(ref form_);
            if (network_ != null)
                network_.disconnect();

            Thread.Sleep(1);
            form_.Hide();
        }

        // HACK : 처음 접속하는 로그인 서버 ip, port
        private string loginIp_ = "127.0.0.1";
        private int loginPort_ = 9000;

        public bool connectToLoginServer()
        {
            return connectToLoginServer(loginIp_, loginPort_);
        }

        public bool connectToLoginServer(string ip, int port)
        {
            if (network_ == null)
                network_ = new Network();

            return network_.connect(ip, port);
        }

        public void sendPacket(ref PacketInterface packet)
        {
            network_.sendPacket(packet);
        }
    }

    internal class LoginFormState : FormState
    {
        public override void open()
        {
            form_ = new LoginForm();
            setForm();
            if (!base.connectToLoginServer())
            {
                var result = MessageBox.Show("로그인 서버 연결에 실패. 다시 연결 시도할까요?", "error", MessageBoxButtons.RetryCancel);
                if (result != DialogResult.Retry)
                {
                    form_.Close();
                    Application.Exit();
                }
            }
            network_.setPacketProcess(new LoginPacketProcess());
        }
    }

    internal class ChattingFormState : FormState
    {
        public override void open()
        {
            form_ = new ChattingForm();
            setForm();
            if (!base.connectToLoginServer())
            {
                MessageBox.Show("채팅 서버 연결에 실패했습니다.", "error", MessageBoxButtons.OK);
                Program.programState_.setState(PROGRAM_STATE.LOGIN);
            }
            network_.setPacketProcess(new ChattingPacketProcess());
        }
    }
}
