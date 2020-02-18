//============================================================================
// Name        : exponDecay.cc
// Author      : Md Muktadir Rahman
// Version     : v0.1
// Copyright   : Free to use
// Description : Exponenetial decay data and Fit with exponenetial function 
//                in C++ using ROOT libraries
// 
// Refference  : https://www.mpp.mpg.de/~neslihan/ss12/intro_root.html
//============================================================================


#include <iostream>
// ROOT libraries
#include <TRandom3.h>
#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>

using namespace std;

// function to generate and fit exponential decay.
void expRndm(){

	// random number generator 
	TRandom3 expGen(0);

	// costruct a histogram
  int nBin = 25;
  int xmin = 0.1;
  int xmax = 100;
	TH1D *hist = new TH1D("exp_hist", ";Height [cm];", nBin, xmin, xmax);

	//fill the histogram with exponential decay data with Parameter Tau.
  Double_t expTau = 15.0; 
	for(int i=0; i<170; i++)
		hist->Fill(expGen.Exp(expTau));
   
  // define a exponential fit function with parameter Tau. 
  TF1 * eff1 = new TF1("expon", "[0] * exp(-x/[1])", 0.1, 100);
  // set and limit parametrs for fit function
  eff1->SetParNames("Const", "Tau");
  eff1->SetParameters(35.0, 20.0);
  eff1->SetParLimits(0,  10.0, 50.0);
  eff1->SetParLimits(1,  10.0, 20.0);
  eff1->SetLineWidth(2);
  eff1->SetLineColor(2); 

  // create new canvas 
  int ecv_width = 1024;
  int ecv_height = 768;
	TCanvas *expCv = new TCanvas("expCv", "random", 5, 5, ecv_width, ecv_height );
 
  hist->Fit("expon", "Q");
	hist->Draw();
 
  // save the canvas into a png file
	expCv->SaveAs("exp.png");
}

// main function.
int main()
{
  cout << "Generating exponential decay data and fitting using exponential function...\n" << endl;
  expRndm();

	return 0;
}
