
namespace KontrolerSamolotu
{
    partial class Form1
    {
        /// <summary>
        /// Wymagana zmienna projektanta.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Wyczyść wszystkie używane zasoby.
        /// </summary>
        /// <param name="disposing">prawda, jeżeli zarządzane zasoby powinny zostać zlikwidowane; Fałsz w przeciwnym wypadku.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Kod generowany przez Projektanta formularzy systemu Windows

        /// <summary>
        /// Metoda wymagana do obsługi projektanta — nie należy modyfikować
        /// jej zawartości w edytorze kodu.
        /// </summary>
        private void InitializeComponent()
        {
            this.btsetting = new System.Windows.Forms.Button();
            this.mocLabel = new System.Windows.Forms.Label();
            this.wysokoscLabel = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.czasLabel = new System.Windows.Forms.Label();
            this.sterWysLabel = new System.Windows.Forms.Label();
            this.sterKierLabel = new System.Windows.Forms.Label();
            this.lotkiLabel = new System.Windows.Forms.Label();
            this.silnikLabel = new System.Windows.Forms.Label();
            this.map = new GMap.NET.WindowsForms.GMapControl();
            this.posXLabel = new System.Windows.Forms.Label();
            this.posYLabel = new System.Windows.Forms.Label();
            this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
            this.label2 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // btsetting
            // 
            this.btsetting.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btsetting.AutoSize = true;
            this.btsetting.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.btsetting.Location = new System.Drawing.Point(777, 24);
            this.btsetting.Margin = new System.Windows.Forms.Padding(2);
            this.btsetting.Name = "btsetting";
            this.btsetting.Size = new System.Drawing.Size(171, 41);
            this.btsetting.TabIndex = 0;
            this.btsetting.Text = "sterowanie";
            this.btsetting.UseVisualStyleBackColor = true;
            this.btsetting.Click += new System.EventHandler(this.btsetting_Click);
            // 
            // mocLabel
            // 
            this.mocLabel.AutoSize = true;
            this.mocLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.mocLabel.Location = new System.Drawing.Point(22, 24);
            this.mocLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.mocLabel.Name = "mocLabel";
            this.mocLabel.Size = new System.Drawing.Size(62, 17);
            this.mocLabel.TabIndex = 1;
            this.mocLabel.Text = "moc: 0%";
            // 
            // wysokoscLabel
            // 
            this.wysokoscLabel.AutoSize = true;
            this.wysokoscLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.wysokoscLabel.Location = new System.Drawing.Point(22, 46);
            this.wysokoscLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.wysokoscLabel.Name = "wysokoscLabel";
            this.wysokoscLabel.Size = new System.Drawing.Size(95, 17);
            this.wysokoscLabel.TabIndex = 3;
            this.wysokoscLabel.Text = "wysokość: 0m";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label1.Location = new System.Drawing.Point(371, 214);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 17);
            this.label1.TabIndex = 4;
            // 
            // czasLabel
            // 
            this.czasLabel.AutoSize = true;
            this.czasLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.czasLabel.Location = new System.Drawing.Point(22, 71);
            this.czasLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.czasLabel.Name = "czasLabel";
            this.czasLabel.Size = new System.Drawing.Size(124, 17);
            this.czasLabel.TabIndex = 5;
            this.czasLabel.Text = "pozostały czas: 0s";
            // 
            // sterWysLabel
            // 
            this.sterWysLabel.AutoSize = true;
            this.sterWysLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.sterWysLabel.Location = new System.Drawing.Point(22, 95);
            this.sterWysLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.sterWysLabel.Name = "sterWysLabel";
            this.sterWysLabel.Size = new System.Drawing.Size(83, 17);
            this.sterWysLabel.TabIndex = 6;
            this.sterWysLabel.Text = "ster wys: 50";
            // 
            // sterKierLabel
            // 
            this.sterKierLabel.AutoSize = true;
            this.sterKierLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.sterKierLabel.Location = new System.Drawing.Point(24, 119);
            this.sterKierLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.sterKierLabel.Name = "sterKierLabel";
            this.sterKierLabel.Size = new System.Drawing.Size(83, 17);
            this.sterKierLabel.TabIndex = 7;
            this.sterKierLabel.Text = "ster kier: 50";
            // 
            // lotkiLabel
            // 
            this.lotkiLabel.AutoSize = true;
            this.lotkiLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.lotkiLabel.Location = new System.Drawing.Point(22, 142);
            this.lotkiLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.lotkiLabel.Name = "lotkiLabel";
            this.lotkiLabel.Size = new System.Drawing.Size(57, 17);
            this.lotkiLabel.TabIndex = 8;
            this.lotkiLabel.Text = "lotki: 50";
            // 
            // silnikLabel
            // 
            this.silnikLabel.AutoSize = true;
            this.silnikLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.silnikLabel.Location = new System.Drawing.Point(22, 166);
            this.silnikLabel.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.silnikLabel.Name = "silnikLabel";
            this.silnikLabel.Size = new System.Drawing.Size(74, 17);
            this.silnikLabel.TabIndex = 9;
            this.silnikLabel.Text = "silnik: OFF";
            // 
            // map
            // 
            this.map.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.map.Bearing = 0F;
            this.map.CanDragMap = true;
            this.map.EmptyTileColor = System.Drawing.Color.Navy;
            this.map.GrayScaleMode = false;
            this.map.HelperLineOption = GMap.NET.WindowsForms.HelperLineOptions.DontShow;
            this.map.LevelsKeepInMemory = 5;
            this.map.Location = new System.Drawing.Point(374, 95);
            this.map.MarkersEnabled = true;
            this.map.MaxZoom = 2;
            this.map.MinZoom = 2;
            this.map.MouseWheelZoomEnabled = true;
            this.map.MouseWheelZoomType = GMap.NET.MouseWheelZoomType.MousePositionWithoutCenter;
            this.map.Name = "map";
            this.map.NegativeMode = false;
            this.map.PolygonsEnabled = true;
            this.map.RetryLoadTile = 0;
            this.map.RoutesEnabled = true;
            this.map.ScaleMode = GMap.NET.WindowsForms.ScaleModes.Integer;
            this.map.SelectedAreaFillColor = System.Drawing.Color.FromArgb(((int)(((byte)(33)))), ((int)(((byte)(65)))), ((int)(((byte)(105)))), ((int)(((byte)(225)))));
            this.map.ShowTileGridLines = false;
            this.map.Size = new System.Drawing.Size(600, 435);
            this.map.TabIndex = 10;
            this.map.Zoom = 0D;
            // 
            // posXLabel
            // 
            this.posXLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.posXLabel.AutoSize = true;
            this.posXLabel.Location = new System.Drawing.Point(400, 71);
            this.posXLabel.Name = "posXLabel";
            this.posXLabel.Size = new System.Drawing.Size(21, 13);
            this.posXLabel.TabIndex = 11;
            this.posXLabel.Text = "lat:";
            // 
            // posYLabel
            // 
            this.posYLabel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.posYLabel.AutoSize = true;
            this.posYLabel.Location = new System.Drawing.Point(544, 71);
            this.posYLabel.Name = "posYLabel";
            this.posYLabel.Size = new System.Drawing.Size(24, 13);
            this.posYLabel.TabIndex = 12;
            this.posYLabel.Text = "lon:";
            // 
            // backgroundWorker1
            // 
            this.backgroundWorker1.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker1_DoWork);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(43, 260);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(267, 13);
            this.label2.TabIndex = 13;
            this.label2.Text = "25 silnik 26 ster w 27 ster k 32 lotka p 33 lotka l   884 g";
            this.label2.Click += new System.EventHandler(this.label2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(986, 542);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.posYLabel);
            this.Controls.Add(this.posXLabel);
            this.Controls.Add(this.map);
            this.Controls.Add(this.silnikLabel);
            this.Controls.Add(this.lotkiLabel);
            this.Controls.Add(this.sterKierLabel);
            this.Controls.Add(this.sterWysLabel);
            this.Controls.Add(this.czasLabel);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.wysokoscLabel);
            this.Controls.Add(this.mocLabel);
            this.Controls.Add(this.btsetting);
            this.KeyPreview = true;
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Form1";
            this.Text = "KontrolerSamolotu";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.Form1_KeyPress);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btsetting;
        public System.Windows.Forms.Label mocLabel;
        public System.Windows.Forms.Label wysokoscLabel;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label czasLabel;
        private System.Windows.Forms.Label sterWysLabel;
        private System.Windows.Forms.Label sterKierLabel;
        private System.Windows.Forms.Label lotkiLabel;
        private System.Windows.Forms.Label silnikLabel;
        public GMap.NET.WindowsForms.GMapControl map;
        public System.Windows.Forms.Label posXLabel;
        public System.Windows.Forms.Label posYLabel;
        private System.ComponentModel.BackgroundWorker backgroundWorker1;
        private System.Windows.Forms.Label label2;
    }
}

