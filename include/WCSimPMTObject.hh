#ifndef WCSimWCPMTObject_h
#define WCSimWCPMTObject_h 1

#include "WCSimDetectorConstruction.hh"
#include "globals.hh"
#include "Randomize.hh"
#include <map>
#include <vector>
#include <TGraph.h>

class WCSimPMTObject
{

public:
  virtual G4String GetPMTName()=0;
  virtual G4double GetExposeHeight()=0;
  virtual G4double GetRadius()=0;
  virtual G4double* Getqpe()=0;
  virtual G4double* GetQE()=0;
  virtual G4double* GetQEWavelength()=0;
  virtual G4double  GetmaxQE()=0;
  virtual G4double  GetCollectionEfficiency(double);
  virtual double    HitTimeSmearing(double)=0;
  virtual G4double GetPMTGlassThickness()=0;
  virtual G4double GetDarkRate()=0;
  virtual G4double GetDarkRateConversionFactor()=0;
  virtual G4int    GetNbOfQEDefined()=0;
protected:
  virtual G4double* GetCollectionEfficiencyArray();
  virtual G4double* GetCollectionEfficiencyAngle();
  G4double Interpolate_func(G4double, G4int, G4double*, G4double*);
};

class PMT20inch : public WCSimPMTObject
{

public:
  
  PMT20inch();
  ~PMT20inch();
 
public:
  G4String GetPMTName() ;
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
};

class PMT8inch : public WCSimPMTObject
{

public:
  
  PMT8inch();
  ~PMT8inch();
 
public:
  G4String GetPMTName(); 
  G4double GetExposeHeight(); 
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
};

 class PMT10inch : public WCSimPMTObject
{

public: 
  PMT10inch();
  ~PMT10inch();
 
public:
  G4String GetPMTName(); 
  G4double GetExposeHeight(); 
  G4double GetRadius(); 
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
 };

 class PMT10inchHQE : public WCSimPMTObject
{

public: 
  PMT10inchHQE();
  ~PMT10inchHQE();
 
public:
  G4String GetPMTName(); 
  G4double GetExposeHeight(); 
  G4double GetRadius(); 
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
 };

 class PMT12inchHQE : public WCSimPMTObject
{

public: 
  PMT12inchHQE();
  ~PMT12inchHQE();
 
public:
  G4String GetPMTName(); 
  G4double GetExposeHeight(); 
  G4double GetRadius(); 
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
 };

class HPD20inchHQE : public WCSimPMTObject
{

public:
  
  HPD20inchHQE();
  ~HPD20inchHQE();
 
public:
  G4String GetPMTName() ;
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
protected:
  G4double* GetCollectionEfficiencyArray();
};

class HPD12inchHQE : public WCSimPMTObject
{

public:
  
  HPD12inchHQE();
  ~HPD12inchHQE();
 
public:
  G4String GetPMTName() ;
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
protected:
  G4double* GetCollectionEfficiencyArray();
};

class BoxandLine20inchHQE : public WCSimPMTObject
{

public:
  
  BoxandLine20inchHQE();
  ~BoxandLine20inchHQE();
 
public:
  G4String GetPMTName() ;
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
protected:
  G4double* GetCollectionEfficiencyArray();
};

class BoxandLine12inchHQE : public WCSimPMTObject
{

public:
  
  BoxandLine12inchHQE();
  ~BoxandLine12inchHQE();
 
public:
  G4String GetPMTName() ;
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
protected:
  G4double* GetCollectionEfficiencyArray();
};

class PMT5inch : public WCSimPMTObject
{

 public:

  PMT5inch();
  ~PMT5inch();

 public:
  G4String GetPMTName();
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
};

class PMT3inch : public WCSimPMTObject
{

 public:

  PMT3inch();
  ~PMT3inch();

 public:
  G4String GetPMTName();
  G4double GetExposeHeight();
  G4double GetRadius();
  G4double* Getqpe();
  G4double* GetQE();
  G4double* GetQEWavelength();
  G4double  GetmaxQE();
  double    HitTimeSmearing(double);
  G4double GetPMTGlassThickness();
  G4double GetDarkRate();
  G4double GetDarkRateConversionFactor();
  G4int    GetNbOfQEDefined();
};

class WCSimBasicPMTObject
{

 public:
  WCSimBasicPMTObject();
  WCSimBasicPMTObject(std::map<G4double,G4double>);
  WCSimBasicPMTObject(std::vector<G4double>,std::vector<G4double>,G4double);
  ~WCSimBasicPMTObject();

 private:
  std::vector<G4double> QE;
  std::vector<G4double> wavelength;
  std::map<G4double,G4double> mapQE;
  G4double  maxQE;
  TGraph   *gQE = nullptr;

 public:
  std::vector<G4double> GetQE(){ return QE;};
  void SetQE(std::vector<G4double> qe){ QE=qe;};

  std::vector<G4double> GetWavelength(){ return wavelength;};
  void SetWavelength(std::vector<G4double> qe){ wavelength=qe;};

  std::map<G4double,G4double> GetMapQE(){ return mapQE;};
  void SetMapQE(std::map<G4double,G4double> qe){ mapQE=qe;};

  G4double GetmaxQE(){ return maxQE;};
  void SetmaxQE(G4double qe){ maxQE=qe;};

  TGraph* GetgQE(){ return gQE;};
  void SetgQE(TGraph *g){ gQE=g;};

  void DefineQEHist(std::map<G4double,G4double>);
};

#endif
