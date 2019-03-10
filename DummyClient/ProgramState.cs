namespace DummyClient
{
    internal enum PROGRAM_STATE
    {
        LOGIN,
        CHATTING,
        MAX
    };

    class ProgramState
    {
        private PROGRAM_STATE state_;
        private FormState formState_ = null;

        public delegate void putMessageDele(string msg);
        public event putMessageDele putMessage_;
        
        private void changeState()
        {
            switch (state_)
            {
                case PROGRAM_STATE.LOGIN:
                    formState_ = new LoginFormState();
                    break;

                case PROGRAM_STATE.CHATTING:
                    formState_ = new ChattingFormState();
                    break;
            }
        }

        public void setState(PROGRAM_STATE state)
        {
            if (formState_ != null)
                formState_.close();

            state_ = state;
            this.changeState();
            formState_.open();
        }

        public void sendPacket(PacketInterface packet)
        {
            this.formState_.sendPacket(ref packet);
        }

        public void putMessage(string msg)
        {
            putMessage_(msg);
        }

        public void close()
        {
            this.formState_.close();
        }
    }
}
