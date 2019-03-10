using System;
using System.Windows.Forms;

namespace DummyClient
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }

        private void button_login__Click(object sender, EventArgs e)
        {
            PK_C_REQ_ID_PW packet = new PK_C_REQ_ID_PW();
            packet.id_ = textbox_id_.Text;
            packet.password_ = textbox_pw_.Text;
            Program.programState_.sendPacket(packet);
        }

        private void button_quit__Click(object sender, EventArgs e)
        {
            this.Dispose();
            Application.Exit();
        }
    }
}
