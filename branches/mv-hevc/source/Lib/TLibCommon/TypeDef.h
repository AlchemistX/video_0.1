/* ====================================================================================================================

  The copyright in this software is being made available under the License included below.
  This software may be subject to other third party and   contributor rights, including patent rights, and no such
  rights are granted under this license.

  Copyright (c) 2010, SAMSUNG ELECTRONICS CO., LTD. and BRITISH BROADCASTING CORPORATION
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, are permitted only for
  the purpose of developing standards within the Joint Collaborative Team on Video Coding and for testing and
  promoting such standards. The following conditions are required to be met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
      the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
      the following disclaimer in the documentation and/or other materials provided with the distribution.
    * Neither the name of SAMSUNG ELECTRONICS CO., LTD. nor the name of the BRITISH BROADCASTING CORPORATION
      may be used to endorse or promote products derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 * ====================================================================================================================
*/

/** \file     TypeDef.h
    \brief    Define basic types, new types and enumerations
*/

#ifndef _TYPEDEF__
#define _TYPEDEF__

////////////////////////////
// HHI defines section start
////////////////////////////
#define HHI_NAL_UNIT_SYNTAX               1           ///< enable/disable NalUnit syntax 
#define HHI_ALLOW_CIP_SWITCH              1           ///< BB: allow to switch off CIP, via CIP : 0 in cfg file or -0 CIP in command line
#define HHI_DISABLE_INTER_NxN_SPLIT       0           ///< TN: disable redundant use of pu-mode NxN for CTBs larger 8x8 (inter only)
#define HHI_RMP_SWITCH                    0

// HHI tools
#define HHI_RQT                           1           ///< MWHK: residual quadtree
#define HHI_RQT_CHROMA_CBF_MOD            1           ///< HK: alternative syntax for coded block flag coding for chroma
#define HHI_RQT_INTRA                     1           ///< HS: residual quadtree for intra blocks
#define HHI_ALF                           0           ///< MS: separable adaptive loop filter 
#define HHI_AIS                           1           ///< BB: adaptive intra smoothing
#define HHI_INTERP_FILTER                 1           ///< HL: interpolation filter
#define HHI_TRANSFORM_CODING              1           ///< TN: modified transform coefficient coding with RDOQ
#define HHI_IMVP                          1           ///< SOPH: Interleaved Motion Vector Predictor 
#define HHI_MRG                           1           ///< SOPH: inter partition merging
#define HHI_MRG_PU                        0           ///< SOPH: inter partition merging on pu basis
#define HHI_AMVP_OFF                      0           ///< SOPH: Advanced Motion Vector Predictor deactivated [not in TMuC]
#define HHI_DEBLOCKING_FILTER             0           ///< MW: deblocking filter supporting residual quadtrees
#define HHI_RQT_ROOT                      1           ///< PHHK: signaling of residual quadtree root flag
#define HHI_RQT_FORCE_SPLIT_NxN           0           ///< MSHK: force split flags of residual quadtree for NxN PUs such that transform blocks are guaranteed to not span NxN PUs
#define HHI_RQT_FORCE_SPLIT_RECT          0           ///< MSHK: force split flags of residual quadtree for rectangular PUs such that transform blocks are guaranteed to not span rectangular PUs
#define HHI_RQT_FORCE_SPLIT_ASYM          0           ///< MSHK: force split flags of residual quadtree for asymmetric such that transform blocks are guaranteed to not span PUs asymmetric PUs
#define HHI_RQT_INTRA_SPEEDUP             1 // tests one best mode with full rqt
#define HHI_RQT_INTRA_SPEEDUP_MOD         0 // tests two best modes with full rqt
#define HHI_C319_SPS                      1           ///< BB: SPS from JCTVC-C319

#if HHI_RQT_INTRA_SPEEDUP_MOD && !HHI_RQT_INTRA_SPEEDUP
#error
#endif

#if ( HHI_RQT_INTRA && !HHI_RQT )
#error "HHI_RQT_INTRA can only be equal to 1 if HHI_RQT is equal to 1"
#endif

#if ( HHI_RQT_ROOT && !HHI_RQT )
#error "HHI_RQT_ROOT can only be equal to 1 if HHI_RQT is equal to 1"
#endif

#if ( HHI_MRG_PU && !HHI_MRG )
#error "HHI_MRG_PU can only be equal to 1 if HHI_MRG is equal to 1"
#endif

#if ( HHI_RQT_FORCE_SPLIT_NxN || HHI_RQT_FORCE_SPLIT_RECT || HHI_RQT_FORCE_SPLIT_ASYM )
#define HHI_RQT_FORCE_SPLIT_ACC2_PU       1
#else
#define HHI_RQT_FORCE_SPLIT_ACC2_PU       0
#endif

#if ( HHI_RQT_FORCE_SPLIT_ACC2_PU &&  !HHI_RQT  )
#error "HHI_RQT_FORCE_SPLIT_ACC2_PU can only be equal to 1 if HHI_RQT is equal to 1"
#endif

#if HHI_AIS
// AIS
#define DEFAULT_IS                        0           ///< BB: set intra filtering always 0:off 1:on if AIS is disabled
#define AIS_TEST_BEST                     0           ///< BB: 0: compare every intra mode with filter on and off (encoder only)
                                                      ///<     1: compare best intra mode with filter on and off (encoder only)
#endif

#define HHI_INTERP_FILTER_KERNEL_FIX      1           ///< BB: interpolation filter fixed spline kernel

//////////////////////////
// HHI defines section end
//////////////////////////


////////////////////////////
// TEN defines section start
////////////////////////////
#define UNIFIED_DIRECTIONAL_INTRA         1           // Unified directional intra prediction as described in JCTVC-B100. ANG_INTRA needs to
                                                      // be set to 2 when this is enabled. Unified intra renders number of old intra prediction
                                                      // functions obsolete, but these functions have not disabled or removed from the code yet.

#if UNIFIED_DIRECTIONAL_INTRA
#define ANG_INTRA                         2           // Enable angular Intra coding (0: All ADI, 1: Ang for 8x8 PUs, 2: Ang for all PU sizes)
#else
#define ANG_INTRA                         1           // Enable angular Intra coding (0: All ADI, 1: Ang for 8x8 PUs, 2: Ang for all PU sizes)
#endif

#define PLANAR_INTRA                      0           // Enable planar Intra coding
#define TENTM_DEBLOCKING_FILTER           1           // Enable TENTM deblocking
#if HHI_INTERP_FILTER
#define TEN_DIRECTIONAL_INTERP            1           ///< AF: interpolation filter
#define TEN_DIRECTIONAL_INTERP_CHROMA     0           ///< DIF interpolation filter for chroma
#endif

#if (HHI_DEBLOCKING_FILTER && TENTM_DEBLOCKING_FILTER)
#error "Only one of TENTM_DEBLOCKING_FILTER and HHI_DEBLOCKING_FILTER can be defined"
#endif

#define LCEC_PHASE1                       1           // LCEC - integration phase 1
#define LCEC_PHASE2                       1           // LCEC - integration phase 2
#define LCEC_STAT                         0           // LCEC - support for LCEC bitusage statistics
//////////////////////////
// TEN defines section end
//////////////////////////


/////////////////////////////////
// QUALCOMM defines section start
/////////////////////////////////

#define LCEC_PHASE1_ADAPT_ENABLE          1           // Enable CU level VLC adaptation 
#define LCEC_CBP_YUV_ROOT                 1           // enable VLC phase-2 CBP root coding under RQT
#define QC_BLK_CBP                        1           // block level CBP coding, to be enabled only when LCEC_CBP_YUV_ROOT is enabled
#if LCEC_CBP_YUV_ROOT==0 && QC_BLK_CBP
#error
#endif

//#define QC_AMVRES    
#ifdef QC_AMVRES  
#define QC_AMVRES_LOW_COMPLEXTY
#endif
#define QC_CONFIG

#if HHI_INTERP_FILTER
//#define QC_SIFO
#define QC_SIFO_PRED
#if (defined QC_SIFO && TEN_DIRECTIONAL_INTERP==1)
#define USE_DIAGONAL_FILT                1
#endif
#endif

#define QC_ALF              1
#if QC_ALF
#define ENABLE_FORCECOEFF0  0
#define ALF_MEM_PATCH       1
#endif
#if (QC_ALF && HHI_ALF)
#error "Only one of QC_ALF and HHI_ALF can be defined"
#endif

#define DISABLE_ROT_LUMA_4x4_8x8           0
#define QC_MDDT                            0
#if QC_MDDT
#define ROT_CHECK                          0
#define absm(A) ((A)<(0) ? (-(A)):(A))
#define REG_DCT 65535
#define COMBINED_MAP
void InitScanOrderForSlice();
#define NUM_SCANS_16x16 9
#define NUM_SCANS_32x32 9
#define NUM_SCANS_64x64 9
void updateScanOrder(int first);
void normalizeScanStats();
#endif

/* Rounding control */
#define ROUNDING_CONTROL_BIPRED ///< From JCTVC-B074
#define ROUNDING_CONTROL_BIPRED_SPEEDUP_BITEXACT

#define TRANS_PRECISION_EXT     ///< From JCTVC-B074


#define BUGFIX48 1
#define BUGFIX50 1
#define BUGFIX50TMP 0 // for compatibility with previous versions without the crash
#define SCAN_LUT_FIX 1
#define ROUNDING_CONTROL_BIPRED_FIX

#ifdef QC_SIFO
#define SIFO_DIF_COMPATIBILITY			  1           // SIFO Extensions
#define FIX_TICKET67  1     // solves memory leak problem in SIFO
#endif
#define FIX_TICKET92  0     // faster SIFO encoder (encoder only change)

///////////////////////////////
// QUALCOMM defines section end
///////////////////////////////


///////////////////////////////////
// Panasonic defines section start
///////////////////////////////////

//#define EDGE_BASED_PREDICTION   // Enable edge based prediction for intra
#define BUGFIX51 1

///////////////////////////////////
// Panasonic defines section start
///////////////////////////////////

///////////////////////////////
// SAMSUNG defines section start
///////////////////////////////
#define SAMSUNG_REMOVE_AMP_FEN_PENALTY        1           ///< removal of FEN penality of AMP

#if HHI_RQT
#define HHI_RQT_DEPTH                         1           ///< controlling max quadtree depth
#if HHI_RQT_DEPTH
#define HHI_C319                              1           ///< BB: two separate depths for inter and intra from JCTVC-C319
#if HHI_C319
#define HHI_C319_INTER_FIX                    1           ///< BB: forced/inferred splits are counted as depth (exeption: inferred from intra_split)
#endif // HHI_C319
#endif // HHI_RQT_DEPTH
#define HHI_RQT_DISABLE_SUB                   0           ///< disabling subtree whose node size is smaller than partition size
#if     HHI_RQT_DEPTH && HHI_RQT_DISABLE_SUB
#error "Only one of HHI_RQT_DEPTH and HHI_RQT_DISABLE_SUB can be defined"
#endif
#endif

#if HHI_MRG
#define SAMSUNG_MRG_SKIP_DIRECT               1           ///< enabling of skip and direct when mrg is on
#endif

#define SAMSUNG_CHROMA_IF_EXT                 0           ///< DCT-based Interpolation filter for chroma signal

#if QC_MDDT
#define QC_MDDT_ROT_UNIFIED                   0           ///< better unification of MDDT and ROT
#endif

#if HHI_TRANSFORM_CODING
#define HHI_DISABLE_SCAN                      0           ///< disable adaptive scan
#endif

#define FAST_UDI_MAX_RDMODE_NUM               10          ///< maximum number of RD comparison in fast-UDI estimation loop 

#define SAMSUNG_FAST_UDI                      1           ///< improved mode decision for UDI (JCTVC-C207)
#if     SAMSUNG_FAST_UDI                           
#define SAMSUNG_FAST_UDI_MODESET              0           ///< 0: {9,9,4,4,5} (default) and 1: {9,9,9,9,5} for {4x4,8x8,16x16,32x32,64x64} 
#endif

#define BUGFIX_106                            1           // bug fix on mapping intra directions from 34 to 9

///////////////////////////////
// SAMSUNG defines section end
///////////////////////////////

///////////////////////////////
// DOCOMO defines section start
///////////////////////////////
//#define DCM_PBIC //Partition-Based Illumination Compensation
#define DCM_RDCOST_TEMP_FIX //Enables temporary bug fixes to RD cost computation (does not affect TMuC0.7 performance under current encoder settings, but is needed for proper RD cost computation when DCM_PBIC is enabled)

///////////////////////////////
// DOCOMO defines section end
///////////////////////////////

////////////////////////////////
// TOSHIBA defines section start
////////////////////////////////
#define TSB_ALF_HEADER                 1           // Send ALF ON/OFF flag in slice header
#if (TSB_ALF_HEADER && HHI_ALF)
#error "Only one of TSB_ALF_HEADER and HHI_ALF can be defined"
#endif
////////////////////////////////
// TOSHIBA defines section end
////////////////////////////////

////////////////////////////////
// TI defines section start
////////////////////////////////
#define TI_SIGN_BIN0_PCP  1 // Enable sign and bin0 plane coding
////////////////////////////////
// TI defines section end
////////////////////////////////

#define BUGFIX85TMP 1 // Ignore cost of CBF (affects RQT off setting)
#define BUGFIX102 1 // Do not code terminating bit when using LCEC


////////////////////////////////
// MICROSOFT&USTC defines section start
////////////////////////////////
#define MS_NO_BACK_PRED_IN_B0           1           // disable backward prediction when list1 == list0, and disable list1 search, JCTVC-C278
#define MS_LAST_CBF                     1           // last cbf handling, JCTVC-C277
////////////////////////////////
// MICROSOFT&USTC defines section end
////////////////////////////////

// ====================================================================================================================
// Basic type redefinition
// ====================================================================================================================

typedef       void                Void;
typedef       bool                Bool;

typedef       char                Char;
typedef       unsigned char       UChar;
typedef       short               Short;
typedef       unsigned short      UShort;
typedef       int                 Int;
typedef       unsigned int        UInt;
typedef       long                Long;
typedef       unsigned long       ULong;
typedef       double              Double;

// ====================================================================================================================
// 64-bit integer type
// ====================================================================================================================

#ifdef _MSC_VER
typedef       __int64             Int64;

#if _MSC_VER <= 1200 // MS VC6
typedef       __int64             UInt64;   // MS VC6 does not support unsigned __int64 to double conversion
#else
typedef       unsigned __int64    UInt64;
#endif

#else

typedef       long long           Int64;
typedef       unsigned long long  UInt64;

#endif

// ====================================================================================================================
// Type definition
// ====================================================================================================================

typedef       UChar           Pxl;        ///< 8-bit pixel type
typedef       Short           Pel;        ///< 16-bit pixel type
typedef       Int             TCoeff;     ///< transform coefficient

/// parameters for adaptive loop filter
typedef struct _AlfFilter
{
  Int   iFilterLength         ; // != number of Coeffs !!! number of tabs
  Int   iFilterSymmetry       ;
  Int   iNumOfCoeffs          ;
  Int   iOverlap              ;
  Bool  bIsHorizontal         ;
  Bool  bIsVertical           ;
  Int*  aiQuantFilterCoeffs   ;
  Int*  aiTapCoeffMapping     ;
  Int*  aiCoeffWeights        ;
  Bool  bIsValid              ;
  Int   iHorizontalOverlap    ;
  Int   iVerticalOverlap      ;
} AlfFilter;


/// parameters for adaptive loop filter
class TComPicSym;

struct _AlfParam
{
  Int alf_flag;                           ///< indicates use of ALF
  Int cu_control_flag;                    ///< coding unit based control flag
  Int chroma_idc;                         ///< indicates use of ALF for chroma
  Int tap;                                ///< number of filter taps
  Int num_coeff;                          ///< number of filter coefficients
  Int *coeff;                             ///< filter coefficient array
  Int tap_chroma;                         ///< number of filter taps (chroma)
  Int num_coeff_chroma;                   ///< number of filter coefficients (chroma)
  Int *coeff_chroma;                      ///< filter coefficient array (chroma)
#if QC_ALF
  //CodeAux related
  Int realfiltNo;
  Int filtNo;
  Int filterPattern[16];
  Int startSecondFilter;
  Int noFilters;
  Int varIndTab[16];

  //Coeff send related
  Int filters_per_group_diff; //this can be updated using codedVarBins
  Int filters_per_group;
  Int codedVarBins[16]; 
  Int forceCoeff0;
  Int predMethod;
  Int **coeffmulti;
  Int minKStart;
  Int maxScanVal;
  Int kMinTab[42];
#endif
#if TSB_ALF_HEADER
  UInt num_alf_cu_flag;
  UInt num_cus_in_frame;
  UInt alf_max_depth;
  UInt *alf_cu_flag;
#endif
};

struct _AlfParamHHI
{
  Int alf_flag;                           ///< indicates use of ALF
  Int cu_control_flag;                    ///< coding unit based control flag
  Int chroma_idc;

  AlfFilter*  acHorizontalAlfFilter ;
  AlfFilter*  acVerticalAlfFilter ;
  Bool        bSeparateQt;
  TComPicSym* pcQuadTree;
  Int         aiPlaneFilterMapping[3] ;
};

/// parameters for deblocking filter
typedef struct _LFCUParam
{
  Bool bInternalEdge;                     ///< indicates internal edge
  Bool bLeftEdge;                         ///< indicates left edge
  Bool bTopEdge;                          ///< indicates top edge
#if !HHI_DEBLOCKING_FILTER && !TENTM_DEBLOCKING_FILTER
  Bool bLumaEdgeFilter[2][4];             ///< array of luma edge decisions
  Int  iBsEdgeSum[2][4];                  ///< array of Bs edge sum values
#endif
} LFCUParam;

/// parapeters for TENTM coefficient VLC
typedef struct _LastCoeffStruct
{
    int level;
    int last_pos;
} LastCoeffStruct;

// ====================================================================================================================
// Enumeration
// ====================================================================================================================

/// supported slice type
enum SliceType
{
  I_SLICE,
  P_SLICE,
  B_SLICE
};

/// supported partition shape
enum PartSize
{
  SIZE_2Nx2N,           ///< symmetric motion partition,  2Nx2N
  SIZE_2NxN,            ///< symmetric motion partition,  2Nx N
  SIZE_Nx2N,            ///< symmetric motion partition,   Nx2N
  SIZE_NxN,             ///< symmetric motion partition,   Nx N

  SIZE_2NxnU,           ///< asymmetric motion partition, 2Nx( N/2) + 2Nx(3N/2)
  SIZE_2NxnD,           ///< asymmetric motion partition, 2Nx(3N/2) + 2Nx( N/2)
  SIZE_nLx2N,           ///< asymmetric motion partition, ( N/2)x2N + (3N/2)x2N
  SIZE_nRx2N,           ///< asymmetric motion partition, (3N/2)x2N + ( N/2)x2N

  SIZE_NONE = 15
};

/// supported prediction type
enum PredMode
{
  MODE_SKIP,            ///< SKIP mode
  MODE_INTER,           ///< inter-prediction mode
  MODE_INTRA,           ///< intra-prediction mode
  MODE_NONE = 15
};

#if PLANAR_INTRA
enum PlanarType
{
  PLANAR_FLAG   = 0,
  PLANAR_DELTAY = 1,
  PLANAR_DELTAU = 2,
  PLANAR_DELTAV = 3,
};
#endif

/// texture component type
enum TextType
{
  TEXT_LUMA,            ///< luma
  TEXT_CHROMA,          ///< chroma (U+V)
  TEXT_CHROMA_U,        ///< chroma U
  TEXT_CHROMA_V,        ///< chroma V
#if LCEC_PHASE2
  TEXT_ALL,             ///< Y+U+V
#endif
  TEXT_NONE = 15
};

/// reference list index
enum RefPicList
{
  REF_PIC_LIST_0 = 0,   ///< reference list 0
  REF_PIC_LIST_1 = 1,   ///< reference list 1
  REF_PIC_LIST_X = 100  ///< special mark
};

/// distortion function index
enum DFunc
{
  DF_DEFAULT  = 0,
  DF_SSE      = 1,      ///< general size SSE
  DF_SSE4     = 2,      ///<   4xM SSE
  DF_SSE8     = 3,      ///<   8xM SSE
  DF_SSE16    = 4,      ///<  16xM SSE
  DF_SSE32    = 5,      ///<  32xM SSE
  DF_SSE64    = 6,      ///<  64xM SSE
  DF_SSE16N   = 7,      ///< 16NxM SSE

  DF_SAD      = 8,      ///< general size SAD
  DF_SAD4     = 9,      ///<   4xM SAD
  DF_SAD8     = 10,     ///<   8xM SAD
  DF_SAD16    = 11,     ///<  16xM SAD
  DF_SAD32    = 12,     ///<  32xM SAD
  DF_SAD64    = 13,     ///<  64xM SAD
  DF_SAD16N   = 14,     ///< 16NxM SAD

  DF_SADS     = 15,     ///< general size SAD with step
  DF_SADS4    = 16,     ///<   4xM SAD with step
  DF_SADS8    = 17,     ///<   8xM SAD with step
  DF_SADS16   = 18,     ///<  16xM SAD with step
  DF_SADS32   = 19,     ///<  32xM SAD with step
  DF_SADS64   = 20,     ///<  64xM SAD with step
  DF_SADS16N  = 21,     ///< 16NxM SAD with step

  DF_HADS     = 22,     ///< general size Hadamard with step
  DF_HADS4    = 23,     ///<   4xM HAD with step
  DF_HADS8    = 24,     ///<   8xM HAD with step
  DF_HADS16   = 25,     ///<  16xM HAD with step
  DF_HADS32   = 26,     ///<  32xM HAD with step
  DF_HADS64   = 27,     ///<  64xM HAD with step
  DF_HADS16N  = 28,     ///< 16NxM HAD with step

  DF_SSE_FRAME = 33     ///< Frame-based SSE
};

/// index for reference type
enum  ERBIndex
{
  ERB_NONE    = 0,      ///< normal case
  ERB_LTR     = 1       ///< long-term reference
};

/// index for SBAC based RD optimization
enum CI_IDX
{
  CI_CURR_BEST = 0,     ///< best mode index
  CI_NEXT_BEST,         ///< next best index
  CI_TEMP_BEST,         ///< temporal index
  CI_CHROMA_INTRA,      ///< chroma intra index
#if HHI_RQT
  CI_QT_TRAFO_TEST,
  CI_QT_TRAFO_ROOT,
#endif
  CI_NUM,               ///< total number
};

/// motion vector predictor direction used in AMVP
enum MVP_DIR
{
  MD_LEFT = 0,          ///< MVP of left block
  MD_ABOVE,             ///< MVP of above block
  MD_ABOVE_RIGHT,       ///< MVP of above right block
  MD_BELOW_LEFT,        ///< MVP of below left block
  MD_ABOVE_LEFT         ///< MVP of above left block
};

/// motion vector prediction mode used in AMVP
enum AMVP_MODE
{
  AM_NONE = 0,          ///< no AMVP mode
  AM_EXPL,              ///< explicit signalling of motion vector index
};

/// effect mode used in GRF
enum EFF_MODE
{
  EFF_WP_SO = 0,        ///< weighted prediction (scale+offset)
  EFF_WP_O,             ///< weighted prediction (offset)
  EFF_NONE
};

/// interpolation filter type
#if HHI_INTERP_FILTER
enum InterpFilterType
{
  IPF_SAMSUNG_DIF_DEFAULT = 0,          ///< Samsung DCT-based filter
  IPF_HHI_4TAP_MOMS,                    ///< HHI 4-tap MOMS filter
  IPF_HHI_6TAP_MOMS,                    ///< HHI 6-tap MOMS filter
# if TEN_DIRECTIONAL_INTERP
  IPF_TEN_DIF                           ///< TEN directional filter
# else
  IPF_TEN_DIF_PLACEHOLDER               ///< Place holder to keep ordering if IPF_TEN_DIF not compiled-in
# endif
# ifdef QC_SIFO
  ,IPF_QC_SIFO                          ///< Qualcomm Switched Interpolation Filters with Offsets
# else
  ,IPF_QC_SIFO_PLACEHOLDER              ///< Place holder to keep ordering if IPF_QC_SIFO not compiled-in
# endif
  ,IPF_LAST
};
#endif

#endif
