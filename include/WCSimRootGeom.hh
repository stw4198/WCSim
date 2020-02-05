#ifndef WCSim_RootGeom
#define WCSim_RootGeom

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootGeom                                                      
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"

class TDirectory;

//////////////////////////////////////////////////////////////////////////

class WCSimRootPMT : public TObject {

private:
  Int_t fTubeNo;
  Int_t fCylLoc;  // endcap1, wall, endcap2
  Float_t fOrientation[3];
  Float_t fPosition[3];

public:
  WCSimRootPMT();
  WCSimRootPMT(Int_t tubeNo, Int_t cylLoc, Float_t orientation[3], Float_t position[3]);
  virtual ~WCSimRootPMT();
  bool CompareAllVariables(const WCSimRootPMT * c) const;

  void  SetTubeNo(Int_t i) {fTubeNo=i;}
  void  SetCylLoc(Int_t i) {fCylLoc=i;}
  void  SetOrientation(Int_t i, Float_t f) {fOrientation[i]= ( (i<3) ? f : 0);}
  void  SetPosition(Int_t i, Float_t f) {fPosition[i]= ( (i<3) ? f : 0);}

  Int_t GetTubeNo() const {return fTubeNo;}
  Int_t GetCylLoc() const {return fCylLoc;}
  Float_t GetOrientation(Int_t i=0) const {return (i<3) ? fOrientation[i] : 0;}
  Float_t GetPosition(Int_t i=0) const {return (i<3) ? fPosition[i] : 0;}
  
  // mPMT function for compatibility with Benjamin's fitter
  Int_t GetmPMTNo() const {return 0;}
  Int_t GetmPMT_PMTNo() const {return 0;}

  ClassDef(WCSimRootPMT,1)  //WCSimPMT structure
};


//////////////////////////////////////////////////////////////////////////

class WCSimRootGeom : public TObject {

private:

	static const Int_t     maxNumPMT = 40000;
  Float_t                fWCCylRadius;  // Radius of WC tank
  Float_t                fWCCylLength;  // Length of WC tank
  
  Int_t                  fgeo_type;  // mailbox or cylinder?

  Float_t                fWCPMTRadius; // Radius of PMT
  Int_t                  fWCNumPMT;   // Number of PMTs
  Float_t                fODWCPMTRadius; // Radius of OD PMT
  Int_t                  fODWCNumPMT; // Number of OD PMTs
  Float_t                fWCOffset[3]; // Offset of barrel center in global coords
  Int_t                  fOrientation; //Orientation o detector, 0 is 2km horizontal, 1 is Upright

  // Could make a TClonesArray of PMTs but let's keep it simple
  //   since the arrays just won't be that large
  //WCSimRootPMT          fPMTArray[maxNumPMT];  // Array of PMTs
  TClonesArray           *fPMTArray;

public:

  WCSimRootGeom();
  virtual ~WCSimRootGeom();
  bool CompareAllVariables(const WCSimRootGeom * c) const;

  // Sets and gets

  void  SetWCCylRadius(Float_t f) {fWCCylRadius=f;}
  void  SetWCCylLength(Float_t f) {fWCCylLength=f;}

  void SetGeo_Type(Int_t f){fgeo_type = f;}

  void  SetWCNumPMT(Int_t i) {fWCNumPMT= i;}
  void  SetODWCNumPMT(Int_t i) {fODWCNumPMT= i;}
  void  SetWCPMTRadius(Float_t f) {fWCPMTRadius = f;}
  void  SetODWCPMTRadius(Float_t f) {fODWCPMTRadius = f;}
  void  SetWCOffset(Float_t x, Float_t y, Float_t z) 
           {fWCOffset[0]=x; fWCOffset[1]=y; fWCOffset[2] = z;}
  void  SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], bool expand=true);
  void  SetOrientation(Int_t o) {fOrientation = o;}

  Float_t GetWCCylRadius() const {return fWCCylRadius;}
  Float_t GetWCCylLength() const {return fWCCylLength;}

  Int_t GetGeo_Type() const {return fgeo_type;}
  

  //Int_t GetWCNumPMT() const {return fWCNumPMT;}
  Int_t GetWCNumPMT(bool hybridsecondtype=false) const {// Add bool for compatibility with Benjamin's Fitter
  	if ( hybridsecondtype )
  		return fWCNumPMT;
  	else 
  		return fWCNumPMT;
  }
  
  Int_t GetODWCNumPMT() const {return fODWCNumPMT;}
  Float_t GetWCPMTRadius() const {return fWCPMTRadius;}
  Float_t GetODWCPMTRadius() const {return fODWCPMTRadius;}
  Float_t GetWCOffset(Int_t i) const {return (i<3) ? fWCOffset[i] : 0.;}
  Int_t GetOrientation() const { return fOrientation; }
  //WCSimRootPMT GetPMT(Int_t i){return *(new WCSimRootPMT());}
  //WCSimRootPMT GetPMT(Int_t i){return *(WCSimRootPMT*)(*fPMTArray)[i];}
  WCSimRootPMT GetPMT(Int_t i,bool hybridsecondtype=false) { // Add bool for compatibility with Benjamin's Fitter
  	if ( hybridsecondtype )
  		return *(WCSimRootPMT*)(*fPMTArray)[i];
  	else 
  		return *(WCSimRootPMT*)(*fPMTArray)[i];
  }
  const WCSimRootPMT * GetPMTPtr(Int_t i) const {return (WCSimRootPMT*)(fPMTArray->At(i));}

  ClassDef(WCSimRootGeom,1)  //WCSimRootEvent structure
};


#endif
