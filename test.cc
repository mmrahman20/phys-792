#include <iostream>

#include <TRandom3.h>
//#include <TRandom1.h>
#include <TRandom.h>
#include <TH1D.h>
#include <TF1.h>
#include <TCanvas.h>
#include <TStyle.h>
//#include <TMath.h>

//using namespace std;
//void gausRand(){
//  TRandom1 gen;
//  TRandom1 descrim;
//  TH1F *hist = new TH1F("hist", "Gaussian", 10, -1.0, 1.0);
//  
//  double toss;
//  double decide;
//  double probe;
//  
//  for(int i=0; i<10000; i++){
//  
//  toss = gen.Uniform(0, 2)-1;
//  probe = TMath::Gaus(toss, 0, 1, true);
//  decide = descrim.Uniform(0, 1);
//  if(decide<probe)
//    {hist->Fill(toss);}
//    
//  }
//  
//  hist->Draw();
//  hist->Fit("gaus");
//}
//  
void gaussRndm(){
	//create random number generator for gaussian distribution
	TRandom gausgen(0);

//  // style setting
//  gROOT->SetStyle("Plain");
//  gStyle->SetOptFit(111111);
//  gStyle->SetFrameBorderMode(0);
//  gStyle->SetFillColor(0);
//  gStyle->SetCanvasColor(0);
//  gStyle->SetFrameFillColor(0);
//  gStyle->SetCanvasBorderMode(0);
	//create histogram
	TH1D *hist = new TH1D("gdata", ";x;N", 40, 0.0, 100.0);

	//fill histogram with random numbers
	for(int i=0; i<100; i++)
		hist->Fill(gausgen.Gaus(45.0, 5.0));
  // define a fit function = gauss
  TF1 * f1 = new TF1("gauss", "[0] / sqrt(2.0 * TMath::Pi()) / [2] * exp(-(x-[1])*(x-[1])/2./[2]/[2])", 0, 100);

  //set parameter start values (mandatory). 
  f1->SetParNames("Constant","Mean","Sigma");
  f1->SetParameters(400.,hist->GetMean(),hist->GetRMS());
  f1->SetParLimits(0,  100.0, 700.0);
  f1->SetParLimits(1, 20.0,  70.0);
  f1->SetParLimits(2,  0.1,  10.0);
  f1->SetLineWidth(2);
  f1->SetLineColor(2); 

  // create new canvas to draw the histogram
	TCanvas *gcv = new TCanvas("gcv", "random", 5, 5, 800, 600);
  // perform fit
  hist->Fit("gauss");
	hist->Draw();
	gcv->SaveAs("gRandom.png");
}


int main()
{
//	int a = 2;
//	int b = 3;
//	int c = a*b;
//	std::cout << c << std::endl;
	
	TRandom3 generator(0);
	std::cout<< generator.Rndm() <<std::endl;

	TRandom gen(0);
	std::cout<< "Poisson Random Number:\t" << gen.PoissonD(10) <<std::endl;
	
	std::cout<< "Gaussian dist. Number:\t" << gen.Gaus(0,3) <<std::endl;
 
  gaussRndm();


	return 0;
}
