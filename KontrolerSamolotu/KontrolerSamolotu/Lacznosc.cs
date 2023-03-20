using GMap.NET;
using GMap.NET.WindowsForms;
using GMap.NET.WindowsForms.Markers;
using SimpleHttp;
using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
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
    class Lacznosc
    {
        static public string dane = "";
        static public int licz = 0;

        static public void nasluchuj(Form1 f)
        {

            Route.Add("/connection", (req, res, props) => {
                Console.WriteLine("nawiazano polaczenie");
                res.AsText("ok");
            });


            Route.Add("/", (req, res, props) => {

                int i = 0;

                while(dane == "")
                {
                    Thread.Sleep(20);
                    i += 20;
                    if(i >= 2000)
                    {
                        break;
                    }
                }
                Console.WriteLine("dane :" + dane);
                String d = dane;
                dane = "";
                try
                {
                    res.AsText(d);
                }
                catch(Exception e)
                {
                    Console.WriteLine("wyjatek");
                    Console.WriteLine(e);
                }
                /*
                if (dane == "")
                {
                    res.AsText("");
                }
                else
                {
                    byte[] tekst = SzyfrujDane(dane);
                    res.AsText(Encoding.ASCII.GetString(tekst));
                }*/


            });

            Route.Add("/gpsfull", (req, res, props) => {

                String full = req.Headers["full"];

                Console.WriteLine("nasluchGPSfull");
                Console.WriteLine($"dane {licz} {full}");
                licz+=1;

                res.AsText("GPSfull");

            }, "POST");


            Route.Add("/gps", (req, res, props) => {

                if(req.Headers["ok"]=="true")
                {
                    String lat = req.Headers["lat"];
                    String lon = req.Headers["lon"];
                    String alt = req.Headers["alt"];

                    Console.WriteLine("nasluchGPS");
                    Console.WriteLine($"lat {lat} lon {lon} alt {alt}");

                    NumberFormatInfo provider = new NumberFormatInfo();
                    provider.NumberDecimalSeparator = ".";

                    double lt = Convert.ToDouble(lat, provider);
                    double lo = Convert.ToDouble(lon, provider);

                    PointLatLng point = new GMap.NET.PointLatLng(lt, lo);
                    GMapOverlay markers = new GMapOverlay("markers");
                    GMapMarker marker = new GMarkerGoogle(point, GMarkerGoogleType.red_small);
                    markers.Markers.Add(marker);

                    f.Invoke((MethodInvoker)delegate
                    {

                        //f.map.Position = point;
                        f.map.Overlays.Clear();
                        f.posXLabel.Text = "lat: " + lt;
                        f.posYLabel.Text = "lng: " + lo;
                        f.wysokoscLabel.Text = "wysokość: " + alt + "m";
                        f.map.Overlays.Add(markers);

                        f.map.Zoom -= 1;

                        f.map.Zoom +=1;

                    });
                }
                else
                {
                    Console.WriteLine("nasluchGPS");
                    Console.WriteLine("brak danych");
                }

                res.AsText("GPS");

            },"POST");

            Route.Add("/siec", (req, res, props) => {

                String ssid = req.Headers["ssid"];
                String rssi = req.Headers["rssi"];

                Console.WriteLine("siec");
                Console.WriteLine($"ssid {ssid} rssi {rssi}");

                res.AsText("siec");

            }, "POST");


            Route.Add("/rotacja", (req, res, props) => {

                String x = req.Headers["x"];
                String y = req.Headers["y"];
                String z = req.Headers["z"];

                Console.WriteLine("rotacja");
                Console.WriteLine($"x {x} y {y} z {z}");

                res.AsText("rotacja");

            }, "POST");

            Route.Add("/kierunek", (req, res, props) => {

                String kierunek = req.Headers["kierunek"];

                Console.WriteLine("kierunek");
                Console.WriteLine($"kierunek {kierunek}");

                res.AsText("kierunek");

            }, "POST");

            HttpServer.ListenAsync(
                4444,
                CancellationToken.None,
                Route.OnHttpRequestAsync
                ).Wait();
        }




        private static byte[] SzyfrujDane(string tekst)
        {
            Aes myAes = Aes.Create();

            byte[] bkey = { 43, 254, 249, 173, 103, 64, 133, 151, 177, 92, 35, 190, 170, 118, 110, 80, 134, 185, 232, 27, 105, 15, 207, 180, 225, 114, 37, 168, 205, 189, 226, 210 };
            byte[] biv = { 207, 101, 235, 121, 143, 208, 82, 189, 217, 132, 4, 233, 176, 218, 139, 6 };

            myAes.Key = bkey;
            myAes.IV = biv;

            /*
            Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Dgram, ProtocolType.Udp);

            IPAddress ipad = IPAddress.Parse("192.168.0.109");
            int port = 1234;

            IPEndPoint ep = new IPEndPoint(ipad, port);*/

            Random rnd = new Random();

            if (tekst.Length <= 480 && tekst.Length > 0)
            {

                int[] z = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
                int n = tekst.Length;
                int i = 0;
                while (n > 127)
                {
                    z[i] = 127;
                    n = n - 127;
                    i++;
                }
                z[3] = n;

                for (int j = 4; j < 14; j++)
                {
                    z[j] = rnd.Next(127);
                }

                for (int j = 13; j >= 0; j--)
                {
                    tekst = (char)z[j] + tekst;
                }

                byte[] encrypted = EncryptStringToBytes_Aes(tekst, myAes.Key, myAes.IV);

                return encrypted;
                //s.SendTo(encrypted, ep);

                //byte[] sendbuf = Encoding.ASCII.GetBytes(tekst);

                // Encrypt the string to an array of bytes.

                // Decrypt the bytes to a string.
                //string roundtrip = DecryptStringFromBytes_Aes(encrypted, myAes.Key, myAes.IV);
            }

            byte[] b = { 0 };
            return b;


        }

        private static byte[] EncryptStringToBytes_Aes(string plainText, byte[] Key, byte[] IV)
        {
            // Check arguments.
            if (plainText == null || plainText.Length <= 0)
                throw new ArgumentNullException("plainText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("IV");
            byte[] encrypted;

            // Create an Aes object
            // with the specified key and IV.
            using (Aes aesAlg = Aes.Create())
            {
                aesAlg.Key = Key;
                aesAlg.IV = IV;

                // Create an encryptor to perform the stream transform.
                ICryptoTransform encryptor = aesAlg.CreateEncryptor(aesAlg.Key, aesAlg.IV);

                // Create the streams used for encryption.
                using (MemoryStream msEncrypt = new MemoryStream())
                {
                    using (CryptoStream csEncrypt = new CryptoStream(msEncrypt, encryptor, CryptoStreamMode.Write))
                    {
                        using (StreamWriter swEncrypt = new StreamWriter(csEncrypt))
                        {
                            //Write all data to the stream.
                            swEncrypt.Write(plainText);
                        }
                        encrypted = msEncrypt.ToArray();
                    }
                }
            }

            // Return the encrypted bytes from the memory stream.
            return encrypted;
        }

        private static string DecryptStringFromBytes_Aes(byte[] cipherText, byte[] Key, byte[] IV)
        {
            // Check arguments.
            if (cipherText == null || cipherText.Length <= 0)
                throw new ArgumentNullException("cipherText");
            if (Key == null || Key.Length <= 0)
                throw new ArgumentNullException("Key");
            if (IV == null || IV.Length <= 0)
                throw new ArgumentNullException("IV");

            // Declare the string used to hold
            // the decrypted text.
            string plaintext = null;

            // Create an Aes object
            // with the specified key and IV.
            using (Aes aesAlg = Aes.Create())
            {
                aesAlg.Key = Key;
                aesAlg.IV = IV;

                // Create a decryptor to perform the stream transform.
                ICryptoTransform decryptor = aesAlg.CreateDecryptor(aesAlg.Key, aesAlg.IV);

                // Create the streams used for decryption.
                using (MemoryStream msDecrypt = new MemoryStream(cipherText))
                {
                    using (CryptoStream csDecrypt = new CryptoStream(msDecrypt, decryptor, CryptoStreamMode.Read))
                    {
                        using (StreamReader srDecrypt = new StreamReader(csDecrypt))
                        {

                            // Read the decrypted bytes from the decrypting stream
                            // and place them in a string.
                            plaintext = srDecrypt.ReadToEnd();
                        }
                    }
                }
            }

            return plaintext;
        }
    }
}



