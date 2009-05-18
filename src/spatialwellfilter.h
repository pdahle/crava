#ifndef SPATIALWELLFILTER_H
#define SPATIALWELLFILTER_H

class Corr;
class FFTGrid;

class SpatialWellFilter
{
public:
  SpatialWellFilter(int nwells);
  ~SpatialWellFilter();
  
  void             setPriorSpatialCorr(FFTGrid *parSpatialCorr, WellData *well, int wellnr);
  void             doFiltering(Corr *corr, WellData **wells, int nWells, int relative);
  const float    * getAlphaFiltered(void) const {return alphaFiltered_;}
  const float    * getBetaFiltered(void) const {return betaFiltered_;}
  const float    * getRhoFiltered(void) const {return rhoFiltered_;}
  const int        getNdata(void) const {return nData_;}
  double        ** getSigmae(void) {return sigmae_;}
  
private:
  void             adjustDiagSigmae();
  void             calculateFilteredLogs(double **Aw, BlockedLogs *blockedlogs, int n, int lastn, int relative);
  double       *** priorSpatialCorr_;
  float          * alphaFiltered_;
  float          * betaFiltered_; 
  float          * rhoFiltered_;

  //float       ** alpha_;
  //float       ** beta_;
  //float       ** rho_; 
  double        ** sigmae_;
  int              nData_;   ///< sum no blocks in all wells
  int              nWells_;
  int            * n_;
};
#endif
