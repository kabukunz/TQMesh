/*
* This source file is part of the tqmesh library.  
* This code was written by Florian Setzwein in 2022, 
* and is covered under the MIT License
* Refer to the accompanying documentation for details
* on usage and license.
*/
#pragma once

#include <functional>
#include <cassert>
#include <float.h>
#include <limits.h>

#include "Helpers.h"

namespace TQMesh {
namespace TQAlgorithm {

/*********************************************************************
* CONSTANTS
*********************************************************************/
constexpr double TQ_SMALL  = 1.0E-13; //DBL_EPSILON;
constexpr double TQ_MAX    = DBL_MAX;
constexpr double TQ_MIN    = DBL_MIN;

constexpr double TQMeshMinimumElementSize = 0.001;
constexpr double TQMeshMinimumElementScaling = 0.001;

constexpr int TQMeshInteriorEdgeMarker = -1;
constexpr int TQMeshDefaultElementColor = 0;
constexpr int TQMeshDefaultMeshId = 0;

constexpr double TQMeshQuadLayerAngle = 1.57079633; // = 1/2 pi
constexpr double TQMeshQuadLayerRange = 0.75;

constexpr double TQMeshQuadRangeFactor = 0.50;
constexpr double TQMeshRangeFactor = 1.0;

constexpr double TQMeshWideSearchFactor = 10.0;

// This value is used to enlarge the search radius for edges
constexpr double TQMeshEdgeSearchFactor = 1.5;


/*********************************************************************
* 
*********************************************************************/
enum class ExportType { cout, txt, vtu };

} // namespace TQAlgorithm
} // namespace TQMesh 
