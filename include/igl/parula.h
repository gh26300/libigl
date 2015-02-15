// This file is part of libigl, a simple c++ geometry processing library.
// 
// Copyright (C) 2015 Alec Jacobson <alecjacobson@gmail.com>
// 
// This Source Code Form is subject to the terms of the Mozilla Public License 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef IGL_PARULA_H
#define IGL_PARULA_H
#include "igl_inline.h"
//#ifndef IGL_NO_EIGEN
#  include <Eigen/Dense>
//#endif
namespace igl
{
  // PARULA like MATLAB's parula
  //
  // Inputs:
  //   m  number of colors 
  // Outputs:
  //   J  m by list of RGB colors between 0 and 1
  //
  // Wrapper for directly computing [r,g,b] values for a given factor f between
  // 0 and 1
  //
  // Inputs:
  //   f  factor determining color value as if 0 was min and 1 was max
  // Outputs:
  //   r  red value
  //   g  green value
  //   b  blue value
  template <typename T>
  IGL_INLINE void parula(const T f, T * rgb);
  template <typename T>
  IGL_INLINE void parula(const T f, T & r, T & g, T & b);
  // Inputs:
  //   Z  #Z list of factors 
  //   normalize  whether to normalize Z to be tightly between [0,1]
  // Outputs:
  //   C  #C by 3 list of rgb colors
  template <typename DerivedZ, typename DerivedC>
  IGL_INLINE void parula(
    const Eigen::PlainObjectBase<DerivedZ> & Z,
    const bool normalize,
    Eigen::PlainObjectBase<DerivedC> & C);
  // Inputs:
  //   min_z  value at blue
  //   max_z  value at red
  template <typename DerivedZ, typename DerivedC>
  IGL_INLINE void parula(
    const Eigen::PlainObjectBase<DerivedZ> & Z,
    const double min_Z,
    const double max_Z,
    Eigen::PlainObjectBase<DerivedC> & C);
  const Eigen::Matrix<float,256,4> PARULA_COLOR_MAP = 
    (Eigen::Matrix<float,256,4>()<<
      0.2081,0.1663,0.5292,1,
      0.2091,0.1721,0.5411,1,
      0.2101,0.1779,0.553,1,
      0.2109,0.1837,0.565,1,
      0.2116,0.1895,0.5771,1,
      0.2121,0.1954,0.5892,1,
      0.2124,0.2013,0.6013,1,
      0.2125,0.2072,0.6135,1,
      0.2123,0.2132,0.6258,1,
      0.2118,0.2192,0.6381,1,
      0.2111,0.2253,0.6505,1,
      0.2099,0.2315,0.6629,1,
      0.2084,0.2377,0.6753,1,
      0.2063,0.244,0.6878,1,
      0.2038,0.2503,0.7003,1,
      0.2006,0.2568,0.7129,1,
      0.1968,0.2632,0.7255,1,
      0.1921,0.2698,0.7381,1,
      0.1867,0.2764,0.7507,1,
      0.1802,0.2832,0.7634,1,
      0.1728,0.2902,0.7762,1,
      0.1641,0.2975,0.789,1,
      0.1541,0.3052,0.8017,1,
      0.1427,0.3132,0.8145,1,
      0.1295,0.3217,0.8269,1,
      0.1147,0.3306,0.8387,1,
      0.0986,0.3397,0.8495,1,
      0.0816,0.3486,0.8588,1,
      0.0646,0.3572,0.8664,1,
      0.0482,0.3651,0.8722,1,
      0.0329,0.3724,0.8765,1,
      0.0213,0.3792,0.8796,1,
      0.0136,0.3853,0.8815,1,
      0.0086,0.3911,0.8827,1,
      0.006,0.3965,0.8833,1,
      0.0051,0.4017,0.8834,1,
      0.0054,0.4066,0.8831,1,
      0.0067,0.4113,0.8825,1,
      0.0089,0.4159,0.8816,1,
      0.0116,0.4203,0.8805,1,
      0.0148,0.4246,0.8793,1,
      0.0184,0.4288,0.8779,1,
      0.0223,0.4329,0.8763,1,
      0.0264,0.437,0.8747,1,
      0.0306,0.441,0.8729,1,
      0.0349,0.4449,0.8711,1,
      0.0394,0.4488,0.8692,1,
      0.0437,0.4526,0.8672,1,
      0.0477,0.4564,0.8652,1,
      0.0514,0.4602,0.8632,1,
      0.0549,0.464,0.8611,1,
      0.0582,0.4677,0.8589,1,
      0.0612,0.4714,0.8568,1,
      0.064,0.4751,0.8546,1,
      0.0666,0.4788,0.8525,1,
      0.0689,0.4825,0.8503,1,
      0.071,0.4862,0.8481,1,
      0.0729,0.4899,0.846,1,
      0.0746,0.4937,0.8439,1,
      0.0761,0.4974,0.8418,1,
      0.0773,0.5012,0.8398,1,
      0.0782,0.5051,0.8378,1,
      0.0789,0.5089,0.8359,1,
      0.0794,0.5129,0.8341,1,
      0.0795,0.5169,0.8324,1,
      0.0793,0.521,0.8308,1,
      0.0788,0.5251,0.8293,1,
      0.0778,0.5295,0.828,1,
      0.0764,0.5339,0.827,1,
      0.0746,0.5384,0.8261,1,
      0.0724,0.5431,0.8253,1,
      0.0698,0.5479,0.8247,1,
      0.0668,0.5527,0.8243,1,
      0.0636,0.5577,0.8239,1,
      0.06,0.5627,0.8237,1,
      0.0562,0.5677,0.8234,1,
      0.0523,0.5727,0.8231,1,
      0.0484,0.5777,0.8228,1,
      0.0445,0.5826,0.8223,1,
      0.0408,0.5874,0.8217,1,
      0.0372,0.5922,0.8209,1,
      0.0342,0.5968,0.8198,1,
      0.0317,0.6012,0.8186,1,
      0.0296,0.6055,0.8171,1,
      0.0279,0.6097,0.8154,1,
      0.0265,0.6137,0.8135,1,
      0.0255,0.6176,0.8114,1,
      0.0248,0.6214,0.8091,1,
      0.0243,0.625,0.8066,1,
      0.0239,0.6285,0.8039,1,
      0.0237,0.6319,0.801,1,
      0.0235,0.6352,0.798,1,
      0.0233,0.6384,0.7948,1,
      0.0231,0.6415,0.7916,1,
      0.023,0.6445,0.7881,1,
      0.0229,0.6474,0.7846,1,
      0.0227,0.6503,0.781,1,
      0.0227,0.6531,0.7773,1,
      0.0232,0.6558,0.7735,1,
      0.0238,0.6585,0.7696,1,
      0.0246,0.6611,0.7656,1,
      0.0263,0.6637,0.7615,1,
      0.0282,0.6663,0.7574,1,
      0.0306,0.6688,0.7532,1,
      0.0338,0.6712,0.749,1,
      0.0373,0.6737,0.7446,1,
      0.0418,0.6761,0.7402,1,
      0.0467,0.6784,0.7358,1,
      0.0516,0.6808,0.7313,1,
      0.0574,0.6831,0.7267,1,
      0.0629,0.6854,0.7221,1,
      0.0692,0.6877,0.7173,1,
      0.0755,0.6899,0.7126,1,
      0.082,0.6921,0.7078,1,
      0.0889,0.6943,0.7029,1,
      0.0956,0.6965,0.6979,1,
      0.1031,0.6986,0.6929,1,
      0.1104,0.7007,0.6878,1,
      0.118,0.7028,0.6827,1,
      0.1258,0.7049,0.6775,1,
      0.1335,0.7069,0.6723,1,
      0.1418,0.7089,0.6669,1,
      0.1499,0.7109,0.6616,1,
      0.1585,0.7129,0.6561,1,
      0.1671,0.7148,0.6507,1,
      0.1758,0.7168,0.6451,1,
      0.1849,0.7186,0.6395,1,
      0.1938,0.7205,0.6338,1,
      0.2033,0.7223,0.6281,1,
      0.2128,0.7241,0.6223,1,
      0.2224,0.7259,0.6165,1,
      0.2324,0.7275,0.6107,1,
      0.2423,0.7292,0.6048,1,
      0.2527,0.7308,0.5988,1,
      0.2631,0.7324,0.5929,1,
      0.2735,0.7339,0.5869,1,
      0.2845,0.7354,0.5809,1,
      0.2953,0.7368,0.5749,1,
      0.3064,0.7381,0.5689,1,
      0.3177,0.7394,0.563,1,
      0.3289,0.7406,0.557,1,
      0.3405,0.7417,0.5512,1,
      0.352,0.7428,0.5453,1,
      0.3635,0.7438,0.5396,1,
      0.3753,0.7446,0.5339,1,
      0.3869,0.7454,0.5283,1,
      0.3986,0.7461,0.5229,1,
      0.4103,0.7467,0.5175,1,
      0.4218,0.7473,0.5123,1,
      0.4334,0.7477,0.5072,1,
      0.4447,0.7482,0.5021,1,
      0.4561,0.7485,0.4972,1,
      0.4672,0.7487,0.4924,1,
      0.4783,0.7489,0.4877,1,
      0.4892,0.7491,0.4831,1,
      0.5,0.7491,0.4786,1,
      0.5106,0.7492,0.4741,1,
      0.5212,0.7492,0.4698,1,
      0.5315,0.7491,0.4655,1,
      0.5418,0.749,0.4613,1,
      0.5519,0.7489,0.4571,1,
      0.5619,0.7487,0.4531,1,
      0.5718,0.7485,0.449,1,
      0.5816,0.7482,0.4451,1,
      0.5913,0.7479,0.4412,1,
      0.6009,0.7476,0.4374,1,
      0.6103,0.7473,0.4335,1,
      0.6197,0.7469,0.4298,1,
      0.629,0.7465,0.4261,1,
      0.6382,0.746,0.4224,1,
      0.6473,0.7456,0.4188,1,
      0.6564,0.7451,0.4152,1,
      0.6653,0.7446,0.4116,1,
      0.6742,0.7441,0.4081,1,
      0.683,0.7435,0.4046,1,
      0.6918,0.743,0.4011,1,
      0.7004,0.7424,0.3976,1,
      0.7091,0.7418,0.3942,1,
      0.7176,0.7412,0.3908,1,
      0.7261,0.7405,0.3874,1,
      0.7346,0.7399,0.384,1,
      0.743,0.7392,0.3806,1,
      0.7513,0.7385,0.3773,1,
      0.7596,0.7378,0.3739,1,
      0.7679,0.7372,0.3706,1,
      0.7761,0.7364,0.3673,1,
      0.7843,0.7357,0.3639,1,
      0.7924,0.735,0.3606,1,
      0.8005,0.7343,0.3573,1,
      0.8085,0.7336,0.3539,1,
      0.8166,0.7329,0.3506,1,
      0.8246,0.7322,0.3472,1,
      0.8325,0.7315,0.3438,1,
      0.8405,0.7308,0.3404,1,
      0.8484,0.7301,0.337,1,
      0.8563,0.7294,0.3336,1,
      0.8642,0.7288,0.33,1,
      0.872,0.7282,0.3265,1,
      0.8798,0.7276,0.3229,1,
      0.8877,0.7271,0.3193,1,
      0.8954,0.7266,0.3156,1,
      0.9032,0.7262,0.3117,1,
      0.911,0.7259,0.3078,1,
      0.9187,0.7256,0.3038,1,
      0.9264,0.7256,0.2996,1,
      0.9341,0.7256,0.2953,1,
      0.9417,0.7259,0.2907,1,
      0.9493,0.7264,0.2859,1,
      0.9567,0.7273,0.2808,1,
      0.9639,0.7285,0.2754,1,
      0.9708,0.7303,0.2696,1,
      0.9773,0.7326,0.2634,1,
      0.9831,0.7355,0.257,1,
      0.9882,0.739,0.2504,1,
      0.9922,0.7431,0.2437,1,
      0.9952,0.7476,0.2373,1,
      0.9973,0.7524,0.231,1,
      0.9986,0.7573,0.2251,1,
      0.9991,0.7624,0.2195,1,
      0.999,0.7675,0.2141,1,
      0.9985,0.7726,0.209,1,
      0.9976,0.7778,0.2042,1,
      0.9964,0.7829,0.1995,1,
      0.995,0.788,0.1949,1,
      0.9933,0.7931,0.1905,1,
      0.9914,0.7981,0.1863,1,
      0.9894,0.8032,0.1821,1,
      0.9873,0.8083,0.178,1,
      0.9851,0.8133,0.174,1,
      0.9828,0.8184,0.17,1,
      0.9805,0.8235,0.1661,1,
      0.9782,0.8286,0.1622,1,
      0.9759,0.8337,0.1583,1,
      0.9736,0.8389,0.1544,1,
      0.9713,0.8441,0.1505,1,
      0.9692,0.8494,0.1465,1,
      0.9672,0.8548,0.1425,1,
      0.9654,0.8603,0.1385,1,
      0.9638,0.8659,0.1343,1,
      0.9623,0.8716,0.1301,1,
      0.9611,0.8774,0.1258,1,
      0.96,0.8834,0.1215,1,
      0.9593,0.8895,0.1171,1,
      0.9588,0.8958,0.1126,1,
      0.9586,0.9022,0.1082,1,
      0.9587,0.9088,0.1036,1,
      0.9591,0.9155,0.099,1,
      0.9599,0.9225,0.0944,1,
      0.961,0.9296,0.0897,1,
      0.9624,0.9368,0.085,1,
      0.9641,0.9443,0.0802,1,
      0.9662,0.9518,0.0753,1,
      0.9685,0.9595,0.0703,1,
      0.971,0.9673,0.0651,1,
      0.9736,0.9752,0.0597,1,
      0.9763,0.9831,0.0538,1).finished();
};

#ifndef IGL_STATIC_LIBRARY
#  include "parula.cpp"
#endif

#endif

