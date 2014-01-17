// $Id: well.hpp 883 2011-09-26 09:17:05Z perroe $

// Copyright (c)  2011, Norwegian Computing Center
// All rights reserved.
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
// �  Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
// �  Redistributions in binary form must reproduce the above copyright notice, this list of
//    conditions and the following disclaimer in the documentation and/or other materials
//    provided with the distribution.
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
// SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
// EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef NRLIB_WELL_HPP
#define NRLIB_WELL_HPP

#include <vector>
#include <sstream>
#include <map>

#include "nrlib/stormgrid/stormcontgrid.hpp"

namespace NRLib {
  class Well{
  public:
    /// Default constructor
    Well();

    /// Construct well with given name and no logs.
    Well(const std::string & name,
         double              rmissing = -999.0,
         int                 imissing = -999);

    /// Construct well from file
    Well(const std::string & file_name,
         bool              & read_ok,
         const std::string & facies_log = "");

    /// Constructor
    /// \param[in] cont_log Continuous logs
    /// \param[in] disc_log Discrete logs
    /// \param[in] well_name
    Well(const std::map<std::string, std::vector<double> > & cont_log,
         const std::map<std::string, std::vector<int> >    & disc_log,
         const std::string                                 & well_name);

    /// Destructor
    ~Well();

    /// Check existence of discrete log
    bool HasDiscLog(const std::string & name) const;
    /// Check existence of continuous log
    bool HasContLog(const std::string& name) const;

    /// Return continuous logs
    std::vector<double> & GetContLog(const std::string& name);
    /// Return continuous logs
    const std::vector<double> & GetContLog(const std::string& name) const;

    /// Return discrete logs
    std::vector<int> & GetDiscLog(const std::string& name);
    /// Return discrete logs
    const std::vector<int> & GetDiscLog(const std::string& name) const;

    /// Read a well from a file-name
    void ReadWell(const std::string              & file_name,
                  bool                           & read_ok,
                  const std::string              & facies_log = "");

    /// Add a continuous log
    /// Replaces the log if there is already a log with the given name.
    void AddContLog(const std::string& name, const std::vector<double>& log);
    /// Remove continuous log
    /// Does nothing if there is no log with the given name.
    void RemoveContLog(const std::string& name);
    /// Add discrete log
    /// Replaces the log if there is already a log with the given name.
    void AddDiscLog(const std::string& name, const std::vector<int>& log);
    /// Remove discrete log
    /// Does nothing if there is no log with the given name.
    void RemoveDiscLog(const std::string& name);
    ///
    void SetWellName(const std::string& wellname);
    ///
    const std::string& GetWellName() const { return well_name_; };
    /// Return true if x is missing
    bool IsMissing(double x) const;
    /// Return true if n is missing
    bool IsMissing(int n) const;
    /// Check if deviated
    bool IsDeviated() const { return is_deviated_; }
    /// Return cont. missing value
    double GetContMissing() const { return(well_rmissing_); }
    /// Return number of time data
    int GetNData(void)      const  { return n_data_  ;}
    /// Return disc. missing value
    int GetIntMissing() const { return(well_imissing_); }
    /// Set deviated
    void SetDeviated(bool b)  {is_deviated_ = b   ;}
    /// Set missing values
    void SetMissing(double value) {well_rmissing_ = value; well_imissing_ = static_cast<int>(value);}
    /// Return discrete value at position index in log with name logname
    /// Returns missing if there is no log with the given name, or index is out of range.
    int GetDiscValue(size_t index, const std::string& logname) const;
    /// Return continuous value at position index in log with name logname
    /// Returns missing if there is no log with the given name, or index is out of range.
    double GetContValue(size_t index, const std::string& logname) const;
    /// Set value at position index in log with name logname
    void SetDiscValue(int value, size_t index, const std::string& logname);
    /// Set value at position index in log with name logname
    void SetContValue(double value, size_t index, const std::string& logname);
    /// Return total number of logs
    size_t GetNlog() const;
    /// Return number of discrete logs
    size_t GetNContLog() const;
    /// Return length of log with name logname
    size_t GetContLogLength(const std::string& logname) const;
    /// Return all continuous logs
    const std::map<std::string,std::vector<double> > & GetContLog() const { return cont_log_; };
    /// Return all discrete logs
    const std::map<std::string,std::vector<int> > & GetDiscLog() const { return disc_log_; };
    /// Facies
    bool                                  HasFaciesLog()  const  { return has_facies_log_                      ;}
    /// Get number of facies
    int                                   GetNFacies()    const  { return static_cast<int>(facies_map_.size()) ;}
    /// Map integer log to facies name
    const std::map<int, std::string>  &   GetFaciesMap()  const  { return facies_map_                          ;}

    /// Set number of non-missing data
    void SetNumberOfNonMissingData(int n_data_nonmissing) {n_data_nonmissing_ = n_data_nonmissing ;}

    /// Set number of data
    void SetNumberOfData(int n_data)  {n_data_ = n_data ;}

    const unsigned int GetNumberOfNonMissingData()  const {return n_data_nonmissing_ ;}

    void SetUseForBackgroundTrend(int use_for_background_trend)         { use_for_background_trend_     = use_for_background_trend     ;}
    void SetUseForFiltering(int use_for_filtering)                      { use_for_filtering_            = use_for_filtering            ;}
    void SetUseForFaciesProbabilities(int use_for_facies_probabilities) { use_for_facies_probabilities_ = use_for_facies_probabilities ;}
    void SetUseForWaveletEstimation(int use_for_wavelet_estimation)     { use_for_wavelet_estimation_   = use_for_wavelet_estimation   ;}
    void SetRealVsLog(int real_vs_log)                                  { real_vs_log_                  = real_vs_log                  ;}

    int GetUseForBackgroundTrend(void)     const { return use_for_background_trend_     ;}
    int GetUseForFiltering(void)           const { return use_for_filtering_            ;}
    int GetUseForFaciesProbabilities(void) const { return use_for_facies_probabilities_ ;}
    int GetUseForWaveletEstimation(void)   const { return use_for_wavelet_estimation_   ;}
    int GetRealVsLog(void)                 const { return real_vs_log_                  ;}

    //bool getUseForBackgroundTrend(void)     const { return(use_for_background_trend_ > 0)    ;}

    int CheckStormgrid(StormContGrid & stormgrid) const;

  protected:
    // Number of time data including WELLMISSING values
    unsigned int              n_data_;

    // Number of data excluding WELLMISSING values
    unsigned int              n_data_nonmissing_;

  private:
    /// Continuous logs
    std::map<std::string,std::vector<double> > cont_log_;
    /// Discrete logs
    std::map<std::string,std::vector<int> >    disc_log_;
    /// Name of well
    std::string well_name_;
    /// Missing value for continous logs.
    double well_rmissing_;
    /// Missing value for discrete logs.
    int    well_imissing_;
    /// Parameter from ModelGeneral
    bool                        is_deviated_;
    /// Facies variables
    bool                        has_facies_log_;
    std::map<int, std::string>  facies_map_;

    int                         use_for_background_trend_;       //Uses the indicator enum from Modelsettings
    int                         use_for_filtering_;              //Uses the indicator enum from Modelsettings
    int                         use_for_wavelet_estimation_;     //Uses the indicator enum from Modelsettings
    int                         use_for_facies_probabilities_;   //Uses the indicator enum from Modelsettings
    int                         real_vs_log_;                    //Uses the indicator enum from Modelsettings

    // Number of data excluding WELLMISSING values
    //unsigned int              n_data_nonmissing_;

  };

}

#endif
