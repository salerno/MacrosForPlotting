using namespace RooFit;

make_plots_CombineWorkspace()
{

 gSystem->AddIncludePath("-I$ROOFITSYS/include/");
 gSystem->Load("libRooFit");
 gSystem->Load("libHiggsAnalysisCombinedLimit.so");

 TFile* f = new TFile("hzz4l_2e2muS_8TeV.input.root","OPEN");
 RooWorkspace* w = f->Get("w");
 RooAbsPdf* Zjets = w->pdf("bkg_qqzz");
 //RooHistFunc* Zjets = w->function("ggZZinterf_TemplatePdf_3_8");
 //RooFormulaVar* Zjets = w->function("interfNorm_ggZZrate_3_8");
 RooRealVar* m = w->var("CMS_zz4l_mass");
 RooRealVar* kd = w->var("CMS_zz4l_widthKD");

 TH2F* hh_pdf = Zjets->createHistogram("CMS_zz4l_mass,CMS_zz4l_widthKD",69,30);
 hh_pdf->GetXaxis()->SetLimits(220,1000);
 hh_pdf->SetTitle("qqZZ 2e2mu;m_{4l};D_{gg10}");
 //TH3D* hh_pdf = Zjets->createHistogram("CMS_zz4l_GGsm,CMS_zz4l_mass,CMS_zz4l_widthKD",20,69,30);
 
 TH1D * hh_pdf_X = hh_pdf->ProjectionX();
 TCanvas* c1 = new TCanvas("qqZZ","qqZZ",800,800);
 hh_pdf_X->Draw();
 //hh_pdf->Draw("COLZ");

}
