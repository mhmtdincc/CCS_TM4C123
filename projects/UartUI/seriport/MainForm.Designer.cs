/*
 * Created by SharpDevelop.
 * User: din21
 * Date: 13.12.2024
 * Time: 12:12
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace seriportodev1
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.labelcoomno = new System.Windows.Forms.Label();
			this.textcom = new System.Windows.Forms.TextBox();
			this.buttonaç = new System.Windows.Forms.Button();
			this.labelbaudrate = new System.Windows.Forms.Label();
			this.textbaudrate = new System.Windows.Forms.TextBox();
			this.buttonkapat = new System.Windows.Forms.Button();
			this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
			this.labeldatabits = new System.Windows.Forms.Label();
			this.textdatabits = new System.Windows.Forms.TextBox();
			this.labelgönderilecekveri = new System.Windows.Forms.Label();
			this.textgönderilecekveri = new System.Windows.Forms.TextBox();
			this.buttonmcyegönder = new System.Windows.Forms.Button();
			this.labelgelenveri = new System.Windows.Forms.Label();
			this.textgelenveri = new System.Windows.Forms.TextBox();
			this.labelbaşlangıç = new System.Windows.Forms.Label();
			this.textbaşlangıç = new System.Windows.Forms.TextBox();
			this.buttonsaatgönder = new System.Windows.Forms.Button();
			this.labeladcverisi = new System.Windows.Forms.Label();
			this.textADCverisi = new System.Windows.Forms.TextBox();
			this.labellcd = new System.Windows.Forms.Label();
			this.textMCdengelen = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// labelcoomno
			// 
			this.labelcoomno.Location = new System.Drawing.Point(28, 42);
			this.labelcoomno.Name = "labelcoomno";
			this.labelcoomno.Size = new System.Drawing.Size(100, 32);
			this.labelcoomno.TabIndex = 0;
			this.labelcoomno.Text = "com no";
			// 
			// textcom
			// 
			this.textcom.Location = new System.Drawing.Point(259, 42);
			this.textcom.Name = "textcom";
			this.textcom.Size = new System.Drawing.Size(100, 22);
			this.textcom.TabIndex = 1;
			this.textcom.Text = "COM3";
			// 
			// buttonaç
			// 
			this.buttonaç.Location = new System.Drawing.Point(440, 42);
			this.buttonaç.Name = "buttonaç";
			this.buttonaç.Size = new System.Drawing.Size(75, 23);
			this.buttonaç.TabIndex = 2;
			this.buttonaç.Text = "aç";
			this.buttonaç.UseVisualStyleBackColor = true;
			this.buttonaç.Click += new System.EventHandler(this.ButtonaçClick);
			// 
			// labelbaudrate
			// 
			this.labelbaudrate.Location = new System.Drawing.Point(28, 112);
			this.labelbaudrate.Name = "labelbaudrate";
			this.labelbaudrate.Size = new System.Drawing.Size(100, 23);
			this.labelbaudrate.TabIndex = 3;
			this.labelbaudrate.Text = "baudrate";
			// 
			// textbaudrate
			// 
			this.textbaudrate.Location = new System.Drawing.Point(259, 112);
			this.textbaudrate.Name = "textbaudrate";
			this.textbaudrate.Size = new System.Drawing.Size(100, 22);
			this.textbaudrate.TabIndex = 4;
			this.textbaudrate.Text = "115200";
			// 
			// buttonkapat
			// 
			this.buttonkapat.Location = new System.Drawing.Point(440, 112);
			this.buttonkapat.Name = "buttonkapat";
			this.buttonkapat.Size = new System.Drawing.Size(75, 23);
			this.buttonkapat.TabIndex = 5;
			this.buttonkapat.Text = "kapat";
			this.buttonkapat.UseVisualStyleBackColor = true;
			this.buttonkapat.Click += new System.EventHandler(this.ButtonkapatClick);
			// 
			// serialPort1
			// 
			this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.SerialPort1DataReceived);
			// 
			// labeldatabits
			// 
			this.labeldatabits.Location = new System.Drawing.Point(28, 180);
			this.labeldatabits.Name = "labeldatabits";
			this.labeldatabits.Size = new System.Drawing.Size(100, 23);
			this.labeldatabits.TabIndex = 6;
			this.labeldatabits.Text = "databits";
			// 
			// textdatabits
			// 
			this.textdatabits.Location = new System.Drawing.Point(259, 181);
			this.textdatabits.Name = "textdatabits";
			this.textdatabits.Size = new System.Drawing.Size(100, 22);
			this.textdatabits.TabIndex = 7;
			this.textdatabits.Text = "8";
			// 
			// labelgönderilecekveri
			// 
			this.labelgönderilecekveri.Location = new System.Drawing.Point(28, 286);
			this.labelgönderilecekveri.Name = "labelgönderilecekveri";
			this.labelgönderilecekveri.Size = new System.Drawing.Size(118, 44);
			this.labelgönderilecekveri.TabIndex = 8;
			this.labelgönderilecekveri.Text = "gönderilecek veri";
			// 
			// textgönderilecekveri
			// 
			this.textgönderilecekveri.Location = new System.Drawing.Point(201, 260);
			this.textgönderilecekveri.Multiline = true;
			this.textgönderilecekveri.Name = "textgönderilecekveri";
			this.textgönderilecekveri.Size = new System.Drawing.Size(185, 78);
			this.textgönderilecekveri.TabIndex = 9;
			this.textgönderilecekveri.Text = "lcd nin 1. satırında gözükecek";
			// 
			// buttonmcyegönder
			// 
			this.buttonmcyegönder.Location = new System.Drawing.Point(440, 266);
			this.buttonmcyegönder.Name = "buttonmcyegönder";
			this.buttonmcyegönder.Size = new System.Drawing.Size(75, 72);
			this.buttonmcyegönder.TabIndex = 10;
			this.buttonmcyegönder.Text = "MC ye gönder";
			this.buttonmcyegönder.UseVisualStyleBackColor = true;
			this.buttonmcyegönder.Click += new System.EventHandler(this.ButtonmcyegönderClick);
			// 
			// labelgelenveri
			// 
			this.labelgelenveri.Location = new System.Drawing.Point(28, 434);
			this.labelgelenveri.Name = "labelgelenveri";
			this.labelgelenveri.Size = new System.Drawing.Size(100, 23);
			this.labelgelenveri.TabIndex = 11;
			this.labelgelenveri.Text = "gelen veri";
			// 
			// textgelenveri
			// 
			this.textgelenveri.Location = new System.Drawing.Point(201, 431);
			this.textgelenveri.Multiline = true;
			this.textgelenveri.Name = "textgelenveri";
			this.textgelenveri.Size = new System.Drawing.Size(228, 43);
			this.textgelenveri.TabIndex = 12;
			// 
			// labelbaşlangıç
			// 
			this.labelbaşlangıç.Location = new System.Drawing.Point(28, 528);
			this.labelbaşlangıç.Name = "labelbaşlangıç";
			this.labelbaşlangıç.Size = new System.Drawing.Size(100, 23);
			this.labelbaşlangıç.TabIndex = 13;
			this.labelbaşlangıç.Text = "başlangıç";
			// 
			// textbaşlangıç
			// 
			this.textbaşlangıç.Location = new System.Drawing.Point(201, 528);
			this.textbaşlangıç.Name = "textbaşlangıç";
			this.textbaşlangıç.Size = new System.Drawing.Size(175, 22);
			this.textbaşlangıç.TabIndex = 14;
			this.textbaşlangıç.Text = "12:34:56";
			// 
			// buttonsaatgönder
			// 
			this.buttonsaatgönder.Location = new System.Drawing.Point(457, 506);
			this.buttonsaatgönder.Name = "buttonsaatgönder";
			this.buttonsaatgönder.Size = new System.Drawing.Size(75, 62);
			this.buttonsaatgönder.TabIndex = 15;
			this.buttonsaatgönder.Text = "saat gönder";
			this.buttonsaatgönder.UseVisualStyleBackColor = true;
			this.buttonsaatgönder.Click += new System.EventHandler(this.ButtonsaatgönderClick);
			// 
			// labeladcverisi
			// 
			this.labeladcverisi.Location = new System.Drawing.Point(28, 619);
			this.labeladcverisi.Name = "labeladcverisi";
			this.labeladcverisi.Size = new System.Drawing.Size(100, 23);
			this.labeladcverisi.TabIndex = 16;
			this.labeladcverisi.Text = "ADC verisi";
			// 
			// textADCverisi
			// 
			this.textADCverisi.Location = new System.Drawing.Point(201, 619);
			this.textADCverisi.Name = "textADCverisi";
			this.textADCverisi.Size = new System.Drawing.Size(158, 22);
			this.textADCverisi.TabIndex = 17;
			// 
			// labellcd
			// 
			this.labellcd.Location = new System.Drawing.Point(29, 700);
			this.labellcd.Name = "labellcd";
			this.labellcd.Size = new System.Drawing.Size(100, 23);
			this.labellcd.TabIndex = 18;
			this.labellcd.Text = "lcd";
			// 
			// textMCdengelen
			// 
			this.textMCdengelen.Location = new System.Drawing.Point(201, 701);
			this.textMCdengelen.Name = "textMCdengelen";
			this.textMCdengelen.Size = new System.Drawing.Size(175, 22);
			this.textMCdengelen.TabIndex = 19;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(573, 790);
			this.Controls.Add(this.textMCdengelen);
			this.Controls.Add(this.labellcd);
			this.Controls.Add(this.textADCverisi);
			this.Controls.Add(this.labeladcverisi);
			this.Controls.Add(this.buttonsaatgönder);
			this.Controls.Add(this.textbaşlangıç);
			this.Controls.Add(this.labelbaşlangıç);
			this.Controls.Add(this.textgelenveri);
			this.Controls.Add(this.labelgelenveri);
			this.Controls.Add(this.buttonmcyegönder);
			this.Controls.Add(this.textgönderilecekveri);
			this.Controls.Add(this.labelgönderilecekveri);
			this.Controls.Add(this.textdatabits);
			this.Controls.Add(this.labeldatabits);
			this.Controls.Add(this.buttonkapat);
			this.Controls.Add(this.textbaudrate);
			this.Controls.Add(this.labelbaudrate);
			this.Controls.Add(this.buttonaç);
			this.Controls.Add(this.textcom);
			this.Controls.Add(this.labelcoomno);
			this.Name = "MainForm";
			this.Text = "seriportodev1";
			this.ResumeLayout(false);
			this.PerformLayout();
		}
		private System.Windows.Forms.TextBox textMCdengelen;
		private System.Windows.Forms.Label labellcd;
		private System.Windows.Forms.TextBox textADCverisi;
		private System.Windows.Forms.Label labeladcverisi;
		private System.Windows.Forms.Button buttonsaatgönder;
		private System.Windows.Forms.TextBox textbaşlangıç;
		private System.Windows.Forms.Label labelbaşlangıç;
		private System.Windows.Forms.TextBox textgelenveri;
		private System.Windows.Forms.Label labelgelenveri;
		private System.Windows.Forms.Button buttonmcyegönder;
		private System.Windows.Forms.TextBox textgönderilecekveri;
		private System.Windows.Forms.Label labelgönderilecekveri;
		private System.Windows.Forms.TextBox textdatabits;
		private System.Windows.Forms.Label labeldatabits;
		private System.IO.Ports.SerialPort serialPort1;
		private System.Windows.Forms.Button buttonkapat;
		private System.Windows.Forms.TextBox textbaudrate;
		private System.Windows.Forms.Label labelbaudrate;
		private System.Windows.Forms.Button buttonaç;
		private System.Windows.Forms.TextBox textcom;
		private System.Windows.Forms.Label labelcoomno;
	}
}
