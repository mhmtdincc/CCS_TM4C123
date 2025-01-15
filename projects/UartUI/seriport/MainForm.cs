/*
 * Created by SharpDevelop.
 * User: din21
 * Date: 13.12.2024
 * Time: 12:12
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace seriportodev1
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
		{
		string gelenveri=string.Empty;
		public MainForm()
		{
			//
			// The InitializeComponent() call is required for Windows Forms designer support.
			//
			InitializeComponent();
			
			//
			// TODO: Add constructor code after the InitializeComponent() call.
			//
		}
		
		void ButtonaçClick(object sender, EventArgs e)
		{
	    if (!serialPort1.IsOpen){
			serialPort1.PortName=textcom.Text;
			serialPort1.BaudRate=Convert.ToInt32(textbaudrate.Text);
			serialPort1.DataBits=Convert.ToInt32(textdatabits.Text);
			serialPort1.Open();
			}
		}
		
		void ButtonkapatClick(object sender, EventArgs e)
		{
			if(serialPort1.IsOpen){
				serialPort1.Close();
			}
		}
		
		void ButtonmcyegönderClick(object sender, EventArgs e)
		{
		  serialPort1.Write("[" + textgönderilecekveri.Text + "]");
		}
		
		void SerialPort1DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
		{
			gelenveri=serialPort1.ReadLine();
			this.Invoke(new EventHandler(DisplayText));
		}
		
		private void DisplayText(object sender, EventArgs e){
			textgelenveri.Text=gelenveri;
			if(gelenveri[0]=='{'){
				
				textMCdengelen.Text=gelenveri.Substring(1,8);
				
			}
			else if (gelenveri[0]=='('){
				textADCverisi.Text=gelenveri.Substring(1,4);
			}
			else if (gelenveri[0]=='['){
				textgönderilecekveri.Text=gelenveri;
			}
		}
		
		void ButtonsaatgönderClick(object sender, EventArgs e)
		{
			serialPort1.Write("%"+textbaşlangıç.Text+"/");
		}
	}
}

