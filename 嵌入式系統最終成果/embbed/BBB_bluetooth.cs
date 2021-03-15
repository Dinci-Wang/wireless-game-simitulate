using System;
using System.IO.Ports;
/// <summary>
/// Summary description for Class1
/// </summary>
public class BBB_bluetooth
{
   // private string Portnumber;
   // private Int32 Boundrate;
   // private int delay;
    private SerialPort Linkport;
    public bool status=false;
	public BBB_bluetooth(string Portnumber,Int32 Boundrate)
	{
        Linkport = new SerialPort(Portnumber, Boundrate);
        Linkport.DataBits = 8;
        Linkport.Parity = Parity.None;
        Linkport.StopBits = StopBits.One;
	}
    public void Connect()
    {
        status = true;
        Linkport.Open();
    }
    public void Disconnect()
    {
        status = false;
        Linkport.Close();
    }
    public int Readchar()
    {
        int read = Linkport.ReadChar();
        return read;
    }
}
