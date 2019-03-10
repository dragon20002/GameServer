namespace DummyClient
{
    partial class LoginForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textbox_id_ = new System.Windows.Forms.TextBox();
            this.textbox_pw_ = new System.Windows.Forms.TextBox();
            this.idLabel_ = new System.Windows.Forms.Label();
            this.pwLabel_ = new System.Windows.Forms.Label();
            this.button_login_ = new System.Windows.Forms.Button();
            this.button_quit_ = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // textbox_id_
            // 
            this.textbox_id_.Location = new System.Drawing.Point(58, 36);
            this.textbox_id_.Name = "textbox_id_";
            this.textbox_id_.Size = new System.Drawing.Size(100, 21);
            this.textbox_id_.TabIndex = 0;
            // 
            // textbox_pw_
            // 
            this.textbox_pw_.Location = new System.Drawing.Point(58, 63);
            this.textbox_pw_.Name = "textbox_pw_";
            this.textbox_pw_.PasswordChar = '#';
            this.textbox_pw_.Size = new System.Drawing.Size(100, 21);
            this.textbox_pw_.TabIndex = 1;
            // 
            // idLabel_
            // 
            this.idLabel_.AutoSize = true;
            this.idLabel_.Location = new System.Drawing.Point(36, 39);
            this.idLabel_.Name = "idLabel_";
            this.idLabel_.Size = new System.Drawing.Size(16, 12);
            this.idLabel_.TabIndex = 2;
            this.idLabel_.Text = "ID";
            // 
            // pwLabel_
            // 
            this.pwLabel_.AutoSize = true;
            this.pwLabel_.Location = new System.Drawing.Point(29, 66);
            this.pwLabel_.Name = "pwLabel_";
            this.pwLabel_.Size = new System.Drawing.Size(23, 12);
            this.pwLabel_.TabIndex = 3;
            this.pwLabel_.Text = "PW";
            // 
            // button_login_
            // 
            this.button_login_.Location = new System.Drawing.Point(12, 112);
            this.button_login_.Name = "button_login_";
            this.button_login_.Size = new System.Drawing.Size(75, 23);
            this.button_login_.TabIndex = 4;
            this.button_login_.Text = "로그인";
            this.button_login_.UseVisualStyleBackColor = true;
            this.button_login_.Click += new System.EventHandler(this.button_login__Click);
            // 
            // button_quit_
            // 
            this.button_quit_.Location = new System.Drawing.Point(111, 112);
            this.button_quit_.Name = "button_quit_";
            this.button_quit_.Size = new System.Drawing.Size(75, 23);
            this.button_quit_.TabIndex = 5;
            this.button_quit_.Text = "종료";
            this.button_quit_.UseVisualStyleBackColor = true;
            this.button_quit_.Click += new System.EventHandler(this.button_quit__Click);
            // 
            // LoginForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(198, 157);
            this.Controls.Add(this.button_quit_);
            this.Controls.Add(this.button_login_);
            this.Controls.Add(this.pwLabel_);
            this.Controls.Add(this.idLabel_);
            this.Controls.Add(this.textbox_pw_);
            this.Controls.Add(this.textbox_id_);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "LoginForm";
            this.Text = "DummyLogin";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textbox_id_;
        private System.Windows.Forms.TextBox textbox_pw_;
        private System.Windows.Forms.Label idLabel_;
        private System.Windows.Forms.Label pwLabel_;
        private System.Windows.Forms.Button button_login_;
        private System.Windows.Forms.Button button_quit_;
    }
}