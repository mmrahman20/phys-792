#include <iostream>
#include <TRandom3.h>
#include <TH1F.h>
#include <TCanvas.h>

using namespace std;

int main()
{
  TH1F hist("hist", ";Height [cm]", 10, 100, 200);
  TRandom3 gen(0);
  //cout<< gen.Gaus(0, 5.2) <<endl;

  for(int i=0; i<160; i++)
     hist.Fill(gen.Gaus(170, 20));

  TCanvas can;
  hist.Draw();
  can.Print("height.png");

  return 0;
}
