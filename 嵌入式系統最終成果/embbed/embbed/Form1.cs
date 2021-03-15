using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace embbed
{
    public partial class Form1 : Form
    {
        public Random ram = new Random();
        private BBB_bluetooth bluetooth;
        Label[] bullet = new Label[500];
        bool read = false;
        int score_p1=0, score_p2=0;
        bool full = false;
        int tail = 0;
        int head = 0;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
           
            string[] Usingport = SerialPort.GetPortNames();
            comboBox1.DataSource = Usingport;
        }

      

        private void e(object sender, KeyPressEventArgs e)
        {
            if (full == false)
            {
                if (e.KeyChar == 32)
                {
                    bullet[tail] = new Label();
                    bullet[tail].AutoSize = false;
                    bullet[tail].Font = new Font("|", 15, FontStyle.Bold);
                    bullet[tail].ForeColor = Color.DarkRed;
                    bullet[tail].Name = "bullet_" + tail;
                    bullet[tail].Text = "|";
                    bullet[tail].Location = bee.Location;
                    bullet[tail].Left += 11;
                   
                    Controls.Add(bullet[tail]);

                    if ((tail + 1) % 50 == head)
                    {
                        full = true;
                    }
                    else
                    {
                        tail = (tail + 1) % 50;
                    }
                }
            }

            if (e.KeyChar == 97)
            {
                if (bee.Left >= 240)
                {
                    bee.Left -= 10;
                    
                }

            }
            if (e.KeyChar == 100)
            {
                if (bee.Left <= 1500)
                {
                   bee.Left += 10;
                    
                }
            }

            if (e.KeyChar == 119)
            {
                if (bee.Top >= 30)
                {
                    bee.Top -= 10;

                }

            }
            if (e.KeyChar == 115)
            {
                if (bee.Top <= 500)
                {
                    bee.Top += 10;

                }
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
           
            label1.Text = "head: " + head.ToString();
            label2.Text = "tail: " + tail.ToString();
            int temp = head;
            int monsterL = monster.Left+14,monsterT=monster.Top;
            while (true)
            {
                if (temp == tail) { break; }
                bullet[temp].Top -= 25;
                
                if ((monsterL - bullet[temp].Left) <20&& (monsterL - bullet[temp].Left)>-20&&
                    (bullet[temp].Top-monsterT) < 20 && ( monsterT-bullet[temp].Top) > -15)
                {
                    if (bullet[temp].AutoSize == false)
                    {
                        score_p1 += 1;
                        P1_score.Text = score_p1.ToString();
                    }
                    else
                    {
                        score_p2 += 1;
                        P2_score.Text = score_p2.ToString();
                    }
                    monster.Left = ram.Next(250, 1500);
                    monster.Top = ram.Next(5,450);
                 
                }
                if (bullet[temp].Top <= 20)
                {
                    bullet[temp].Dispose();
                    bullet[temp] = null;
                    head = (head + 1) % 500;
                    full = false;
                    
                }
                temp = (temp + 1) % 500;
            }
        }

      
        

        private void button1_Click_1(object sender, EventArgs e)
        {
          
            string choseport;
            choseport = comboBox1.SelectedItem.ToString();
            bluetooth = new BBB_bluetooth(choseport, 38400);
            bluetooth.Connect();
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
          //  label3.Text = bluetooth.Readchar().ToString();
            bluetooth.Disconnect();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (score_p1 == 5)
            {
               gameset.Text= "Player1 win Player2 suck ass";
            }

            else if (score_p2 == 5)
            {
                gameset.Text = "Player2 win Player1 suck ass";
            }
            if (bluetooth.status == true)
            {
                int ch=0;
                if (read == true)
                {
                    ch = bluetooth.Readchar();
                    if (ch == 100) { read = false; }
                    else
                    {
                        ch -= 48;
                        Bee_action(ch, false);
                    }
                }
                if (read == true)
                {
                    ch = bluetooth.Readchar();
                    if (ch == 100) { read = false; }
                    else
                    {
                        ch -= 48;
                        Bee_action(ch, false);
                    }
                }
                if (read == true)
                {
                    ch = bluetooth.Readchar();
                    if (ch == 100) { read = false; }
                    else
                    {
                        ch -= 48;
                        Bee_action(ch, true);
                    }
                }
                if (read == true)
                {
                    ch = bluetooth.Readchar();
                    if (ch == 100) { read = false; }
                    else
                    {
                        ch -= 48;
                        Bee_action(ch, true);
                    }
                }

                
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            timer2.Enabled = true;
            read = true;
        }
        private void Bee_action(int movent,bool selectbee)
        {
            if (movent == 0) { return; }
            int detx=0, dety=0;
            if (movent == 1) { detx = 0;dety =14; }
            else if (movent == 2) { detx = 10; dety = 10; }
            else if (movent == 3) { detx = 14; dety = 0; }
            else if (movent == 4) { detx = 10; dety = -10; }
            else if (movent == 5) { detx = 0; dety = -14; }
            else if (movent == 6) { detx = -10; dety = -10; }
            else if (movent == 7) { detx = -14; dety = 0; }
            else if (movent == 8) { detx = -10; dety = 10; }
            else if (movent == 9)
            {
                if (full == false)
                {
                        
                        bullet[tail] = new Label();
                        bullet[tail].AutoSize = selectbee;
                        bullet[tail].Font = new Font("|", 15, FontStyle.Bold);
                        bullet[tail].Name = "bullet_" + tail;
                        bullet[tail].Text = "|";
                    if (selectbee == false)
                    {
                        bullet[tail].ForeColor = Color.DarkRed;
                        bullet[tail].Location = bee2.Location;
                    }
                    else
                    {
                        bullet[tail].ForeColor = Color.Lime;
                        bullet[tail].Location = bee.Location;
                    }
                        bullet[tail].Left += 11;
                     
                        Controls.Add(bullet[tail]);

                        if ((tail + 1) % 500 == head)
                        {
                            full = true;
                        }
                        else
                        {
                            tail = (tail + 1) % 500;
                        }
                    
                }
            }
            if (selectbee == true)
            {
                bee.Left += detx;
                bee.Top += dety;
            }
           else if (selectbee == false)
            {
                bee2.Left += detx;
                bee2.Top += dety;
            }
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }
    }
}
