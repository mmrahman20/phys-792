//============================================================================
// Name        : rndm.cc
// Author      : Md Muktadir Rahman
// Version     : v0.1
// Copyright   : Free to use
// Description : Random number generator and Fit in C++ using ROOT libraries
// 
// Refference  : https://www.mpp.mpg.de/~neslihan/ss12/intro_root.html
//============================================================================


#include <iostream>
// ROOT libraries
#include "TRandom3.h"
#include "TRandom.h"
#include "TH1D.h"
#include "TF1.h"
#include "TCanvas.h"

using namespace std;

// function to generate and fit gaussian distribution.
void gaussRndm(){

	// gaussian random number generator 
	TRandom gaussGen(0);

	// costruct a histogram
  int nBin = 50;
  int xmin = 0.0;
  int xmax = 100;
	TH1D *hist = new TH1D("gdata", ";x;# of entries", nBin, xmin, xmax);

	//fill the histogram with 100 random numbers obeying Gaussian dist. with mean = 45, sd = 5
  Double_t gmean = 45.0;
  Double_t gsd = 5; 
	for(int i=0; i<100; i++)
		hist->Fill(gaussGen.Gaus(gmean, gsd));
   
  // define a Gaussian fit function with parameters 
  TF1 * gff1 = new TF1("gauss", "[0] / sqrt(2.0 * TMath::Pi()) / [2] * exp(-(x-[1])*(x-[1])/2./[2]/[2])", 0, 100);

  // set and limit parametrs for fit function
  gff1->SetParNames("Constant","Mean","Sigma");
  gff1->SetParameters(400,hist->GetMean(),hist->GetRMS());
//  gff1->SetParLimits(0,  100.0, 700.0);
//  gff1->SetParLimits(1, 20.0,  70.0);
//  gff1->SetParLimits(2,  0.1,  10.0);
  gff1->SetLineWidth(2);
  gff1->SetLineColor(2); 

  // create new canvas 
  int gcv_width = 1024;
  int gcv_height = 768;
	TCanvas *gcv = new TCanvas("gcv", "random", 5, 5, gcv_width, gcv_height );
 
  // Double_t norm = 1;
  // hist->Scale(norm/hist->Integral());
  // perform Gaussian fit and draw
  hist->Fit("gauss", "Q");
	hist->Draw();
 
  // save the canvas into a png file
	gcv->SaveAs("gRandom.png");
}


int main()
{
	
  // Default random number constructor
	TRandom gen(0);
 
  // Print 10 random numbers that obey Poisson's distribution
  cout<< "\nGenerating a list of 10 Poisson Random Numbers:\n\n";
  cout<< "Poissons (mean=15)\tGaussian(mean=7, sd=3)\n" <<endl;
  for(int i=0; i<10; i++){
    cout<< "\t" << gen.PoissonD(15) << "\t\t\t" << gen.Gaus(7, 3) << endl;
  }
  cout<< endl; 
  
//	cout<< "\nGenerating a list of 10 Gaussian Random Numbers:\n[";
//  for(int i=0; i<10; i++){
//    cout<< gen.Gaus(0, 3) << ", ";
//  }
//  cout << "\b\b]\n" << endl;
  
  cout << "Generating random numbers and fitting using gaussian distribution ...\n" << endl;
 
  gaussRndm();


	return 0;
}
