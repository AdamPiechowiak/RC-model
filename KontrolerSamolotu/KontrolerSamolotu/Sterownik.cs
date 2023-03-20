using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Input;

namespace KontrolerSamolotu
{
    class Sterownik
    {
        private int moc;
        private int sterwysokosci;
        private int sterkierunku;
        private int lotki;
        private bool silnikON;
        public bool odczyt = true;

        public Keys keyZwiekszMoc;
        public Keys keyZmniejszMoc;
        public Keys keyWychylKierunekWLewo;
        public Keys keyWychylKierunekWPrawo;
        public Keys keyWychylWysokoscWDol;
        public Keys keyWychylWysokoscWGore;
        public Keys keyPrzechylWPrawo;
        public Keys keyPrzechylWLewo;
        public Keys keyWlaczSilnik;
        public Keys keyMocZero;
        public Keys keyMocSto;

        public int Moc { get => moc; set => moc = value; }
        public int Sterwysokosci { get => sterwysokosci; set => sterwysokosci = value; }
        public int Sterkierunku { get => sterkierunku; set => sterkierunku = value; }
        public int Lotki { get => lotki; set => lotki = value; }
        public bool SilnikON { get => silnikON; set => silnikON = value; }

        public Sterownik()
        {
            this.moc = 0;
            this.sterkierunku = 50;
            this.sterwysokosci = 50;
            this.lotki = 50;

            this.keyZwiekszMoc = Keys.Y;
            this.keyZmniejszMoc = Keys.H;
            this.keyWychylKierunekWLewo = Keys.Q;
            this.keyWychylKierunekWPrawo = Keys.E;
            this.keyWychylWysokoscWDol = Keys.S;
            this.keyWychylWysokoscWGore = Keys.W;
            this.keyPrzechylWLewo = Keys.D;
            this.keyPrzechylWPrawo = Keys.A;
            this.keyWlaczSilnik = Keys.L;
            this.keyMocSto = Keys.U;
            this.keyMocZero = Keys.J;
        }

        public void wlaczSilnik()
        {
            this.silnikON = true;
        }


        public void zwiekszMoc(int n)
        {
            this.moc += n;
            if (this.moc > 100)
            {
                this.moc = 100;
            }
        }

        public void zmniejszMoc(int n)
        {
            this.moc -= n;
            if (this.moc < 0)
            {
                this.moc = 0;
            }
        }

        public void ustawwMoc(int n)
        {
            this.moc = n;
            if (this.moc < 0)
            {
                this.moc = 0;
            }
            else if (this.moc > 100)
            {
                this.moc = 100;
            }
        }

        public void ustawwSterKierunku(int n)
        {
            this.sterkierunku = n;
            if (this.sterkierunku < 0)
            {
                this.sterkierunku = 0;
            }
            else if (this.sterkierunku > 100)
            {
                this.sterkierunku = 100;
            }
        }

        public void ustawwSterWysokosci(int n)
        {
            this.sterwysokosci = n;
            if (this.sterwysokosci < 0)
            {
                this.sterwysokosci = 0;
            }
            else if (this.sterwysokosci > 100)
            {
                this.sterwysokosci = 100;
            }
        }

        public void ustawwLotki(int n)
        {
            this.lotki = n;
            if (this.lotki < 0)
            {
                this.lotki = 0;
            }
            else if (this.lotki > 100)
            {
                this.lotki = 100;
            }
        }

    }
}
