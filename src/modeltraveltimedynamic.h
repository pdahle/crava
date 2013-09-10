/***************************************************************************
*      Copyright (C) 2008 by Norwegian Computing Center and Statoil        *
***************************************************************************/

#ifndef MODELTRAVELTIMEDYNAMIC_H
#define MODELTRAVELTIMEDYNAMIC_H

#include "src/definitions.h"

class InputFiles;
class ModelSettings;
class RMSTrace;

class ModelTravelTimeDynamic
{
public:
  ModelTravelTimeDynamic(const ModelSettings           * modelSettings,
                         const InputFiles              * inputFiles,
                         const int                     & vintage);

  ~ModelTravelTimeDynamic();


  bool                          getFailed()                const { return failed_                 ;}
  std::vector<bool>             getFailedDetails()         const { return failed_details_         ;}

  const std::vector<RMSTrace *> getRMSTraces()             const { return rms_traces_             ;}
  const int                     getNLayersAbove()          const { return n_layers_above_         ;}
  const int                     getNLayersBelow()          const { return n_layers_below_         ;}
  const double                  getVarVpAbove()            const { return var_vp_above_           ;}
  const double                  getVarVpBelow()            const { return var_vp_below_           ;}
  const double                  getRangeAbove()            const { return range_above_            ;}
  const double                  getRangeBelow()            const { return range_below_            ;}


private:

  void                          processHorizons(std::vector<Surface>   & horizons,
                                                const InputFiles       * inputFiles,
                                                std::string            & errTxt,
                                                bool                   & failed);

  void                          processRMSData(const ModelSettings      * modelSettings,
                                               const InputFiles         * inputFiles,
                                               std::string              & errTxt,
                                               bool                     & failed);

  void                          readRMSData(const std::string & fileName,
                                            std::string       & errTxt);


  std::vector<Surface>      horizons_;              ///< Horizons used for horizon inversion
  std::vector<RMSTrace *>   rms_traces_;

  int                       n_layers_above_;        ///< Number of layers to be used in the RMS inversion above the reservoir
  int                       n_layers_below_;        ///< Number of layers to be used in the RMS inversion below the reservoir

  double                    var_vp_above_;          ///< Var(Vp) above the reservoir // �nsker egentlig Var(Vp^2)
  double                    var_vp_below_;          ///< Var(Vp) below the reservoir // �nsker egentlig Var(Vp^2)

  double                    range_above_;           ///< Range of the temporal corralation function used above the reservoir
  double                    range_below_;           ///< Range of the temporal corralation function used below the reservoir

  bool                      failed_;                ///< Indicates whether errors occured during construction.
  std::vector<bool>         failed_details_;        ///< Detailed failed information.

  int                       thisTimeLapse_;         ///< Time lapse of the current travel time data set

};

#endif
