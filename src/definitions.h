#ifndef CRAVA_DEFINITIONS_H
#define CRAVA_DEFINITIONS_H

#include "nrlib/surface/surfaceio.hpp"
#include "nrlib/iotools/logkit.hpp"
#include "nrlib/stormgrid/stormcontgrid.hpp"
#include "nrlib/segy/segy.hpp"

typedef  NRLib2::RegularSurface<double>    Surface;
typedef  NRLib2::LogKit                    LogKit;
typedef  NRLib2::StormContGrid             StormContGrid;
typedef  NRLib2::SegY                      SegY;
typedef  NRLib2::SegyGeometry              SegyGeometry;
typedef  NRLib2::TraceHeaderFormat         TraceHeaderFormat;
typedef  NRLib2::TextualHeader             TextualHeader;
/**
   Class to hold definitions and constants used by CRAVA. (to replace global_def.h?)
*/    

//class Definitions 
//{
//public:
//
//  Example of use from Cohiba:
//  
//  inline static std::string LogFileDir(void)  { return "logfiles"; } /// Output directory for log files.
//  inline static double CholeskyEpsilon(void)                   { return 1e-32    ;} ///< Tolerance in Cholesky decomposition.
//  inline static double CholeskyOffDiagRepairFactor(void)       { return 0.999    ;} ///< Factor to multiply off-diagonal elements with.
//}

#endif
