using GMap.NET.MapProviders;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace KontrolerSamolotu
{
    public partial class Form1 : Form
    {
        private Sterownik s = new Sterownik();
        private Dictionary<int, bool> klawiatura = new Dictionary<int, bool>();

        public Form1()
        {
            InitializeComponent();
            klawiatura.Add((int)s.keyWychylWysokoscWGore, false);
            klawiatura.Add((int)s.keyWychylWysokoscWDol, false);
            klawiatura.Add((int)s.keyWychylKierunekWPrawo, false);
            klawiatura.Add((int)s.keyWychylKierunekWLewo, false);
            klawiatura.Add((int)s.keyPrzechylWLewo, false);
            klawiatura.Add((int)s.keyPrzechylWPrawo, false);
            klawiatura.Add((int)s.keyZmniejszMoc, false);
            klawiatura.Add((int)s.keyZwiekszMoc, false);
            klawiatura.Add((int)s.keyWlaczSilnik, false);
            klawiatura.Add((int)s.keyMocZero, false);
            klawiatura.Add((int)s.keyMocSto, false);

            map.MapProvider = GMapProviders.OpenStreetMap;
            map.DragButton = MouseButtons.Left;
            map.ShowCenter = false;
            map.Position = new GMap.NET.PointLatLng(52, 19);
            map.MinZoom = 1;
            map.MaxZoom = 100;
            map.Zoom = 5;

            backgroundWorker1.RunWorkerAsync();

        }

        private void btsetting_Click(object sender, EventArgs e)
        {
            

            aktualizujWyswietloneDane();
            Dictionary<int, bool>.KeyCollection keyColl = klawiatura.Keys;

            // The elements of the KeyCollection are strongly typed
            // with the type that was specified for dictionary keys.
            Console.WriteLine();

            foreach (int s in keyColl)
            {
                Console.WriteLine("Key = "+ s.ToString()+" value = "+klawiatura[s].ToString());
            }
        }


        private void aktualizujWyswietloneDane()
        {
            mocLabel.Text = "moc: "+s.Moc.ToString()+"%";
            sterWysLabel.Text = "ster wys: " + s.Sterwysokosci.ToString();
            sterKierLabel.Text = "ster kier: " + s.Sterkierunku.ToString();
            lotkiLabel.Text = "lotki: " + s.Lotki.ToString();
            if(s.SilnikON)
            {
                silnikLabel.Text = "silnik: ON";
            }
            if (!s.SilnikON)
            {
                silnikLabel.Text = "silnik: OFF";
            }
        }


        private string przygotujDane()
        {
            /*
            Dictionary<string, int> points = new Dictionary<string, int>
            {
                { "m", s.Moc },
                { "sk", s.Sterkierunku },
                { "sw", s.Sterwysokosci },
                { "l", s.Lotki }
            };*/
            string json2 = "{\"m\":" + s.Moc + ",\"sk\":" + s.Sterkierunku + ",\"sw\":" + s.Sterwysokosci + ",\"l\":" + s.Lotki;
            if (s.SilnikON)
            {
                json2 += ",\"s\":\"Y\"";
            }
            else
            {
                json2 += ",\"s\":\"N\"";
            }
                
                json2+="}";
            //string json = JsonConvert.SerializeObject(points, Formatting.Indented);
            //Console.WriteLine(json2);

            return json2;
        }


        private void odczytKlawiatury()
        {
            if (klawiatura[(int)s.keyMocZero] && !klawiatura[(int)s.keyMocSto])
            {
                s.ustawwMoc(0);
            }
            else if (!klawiatura[(int)s.keyMocZero] && klawiatura[(int)s.keyMocSto])
            {
                s.ustawwMoc(100);
            }


            if (klawiatura[(int)s.keyZmniejszMoc] && !klawiatura[(int)s.keyZwiekszMoc])
            {
                s.zmniejszMoc(1);
            }
            else if (!klawiatura[(int)s.keyZmniejszMoc] && klawiatura[(int)s.keyZwiekszMoc])
            {
                s.zwiekszMoc(1);
            }

            if (klawiatura[(int)s.keyPrzechylWLewo] && !klawiatura[(int)s.keyPrzechylWPrawo])
            {
                s.ustawwLotki(0);
            }
            else if (!klawiatura[(int)s.keyPrzechylWLewo] && klawiatura[(int)s.keyPrzechylWPrawo])
            {
                s.ustawwLotki(100);
            }
            else
            {
                s.ustawwLotki(50);
            }

            if (klawiatura[(int)s.keyWychylWysokoscWGore] && !klawiatura[(int)s.keyWychylWysokoscWDol])
            {
                s.ustawwSterWysokosci(100);
            }
            else if (!klawiatura[(int)s.keyWychylWysokoscWGore] && klawiatura[(int)s.keyWychylWysokoscWDol])
            {
                s.ustawwSterWysokosci(0);
            }
            else
            {
                s.ustawwSterWysokosci(50);
            }

            if (klawiatura[(int)s.keyWychylKierunekWPrawo] && !klawiatura[(int)s.keyWychylKierunekWLewo])
            {
                s.ustawwSterKierunku(100);
            }
            else if (!klawiatura[(int)s.keyWychylKierunekWPrawo] && klawiatura[(int)s.keyWychylKierunekWLewo])
            {
                s.ustawwSterKierunku(0);
            }
            else
            {
                s.ustawwSterKierunku(50);
            }

            if(klawiatura[(int)s.keyWlaczSilnik])
            {
                s.wlaczSilnik();
            }

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {

            if (klawiatura.ContainsKey(e.KeyValue))
            {
                klawiatura[e.KeyValue] = true;
            }

           
            odczytKlawiatury();
            aktualizujWyswietloneDane();
            Lacznosc.dane = przygotujDane();
            Console.WriteLine("dodano dane");
            //Console.WriteLine(przygotujDane());
            //Console.WriteLine(przygotujDane().Length);
            //Console.WriteLine(e.KeyValue);


        }

        private void Form1_KeyPress(object sender, KeyPressEventArgs e)
        {
            //Console.WriteLine(e.KeyChar);
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if (klawiatura.ContainsKey(e.KeyValue))
            {
                klawiatura[e.KeyValue] = false;
            }


            odczytKlawiatury();
            aktualizujWyswietloneDane();
            Lacznosc.dane = przygotujDane();
            //Lacznosc.wyslijDane(przygotujDane());
        }


        public static void setPosition()
        {

        }

        private void backgroundWorker1_DoWork(object sender, DoWorkEventArgs e)
        {


            Lacznosc.nasluchuj(this);

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }
    }
}
