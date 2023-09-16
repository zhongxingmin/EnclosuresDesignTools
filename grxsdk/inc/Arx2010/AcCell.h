#pragma once

#include "dbTableStyle.h"

#define AcCellRange OdCellRange
#define AcCell GcCell

typedef struct GcCell
{
  int     mnRow;
  int     mnColumn;
} GcCell;

typedef OdArray<OdCellRange> OdCellRangeArray;