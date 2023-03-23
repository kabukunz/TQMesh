/*
* This file is part of the TQMesh library.  
* This code was written by Florian Setzwein in 2022, 
* and is covered under the MIT License
* Refer to the accompanying documentation for details
* on usage and license.
*/

#include <iostream>
#include <cassert>

#include <TQMeshConfig.h>

#include "run_examples.h"

#include "Vec2.h"
#include "Log.h"

#include "Vertex.h"
#include "Edge.h"
#include "Domain.h"
#include "Mesh.h"
#include "Smoother.h"

using namespace CppUtils;
using namespace TQMesh::TQAlgorithm;

/*********************************************************************
* This example covers the generation of a simple triangular mesh
*********************************************************************/
void run_example_11()
{
  /*------------------------------------------------------------------
  | First, we define the size function. This function describes
  | the size of the mesh elements with respect to their location 
  | in the domain. In this case, we use a constant size of 0.35
  ------------------------------------------------------------------*/
  UserSizeFunction f = [](const Vec2d& p) 
  { 
    return 0.5;
  };

  /*------------------------------------------------------------------
  | Next, we need to define the domain. It requires the size function
  | as argument.
  ------------------------------------------------------------------*/
  Domain domain { f };

  /*------------------------------------------------------------------
  | Now we define the exteriour boundary of the domain. The boundary 
  | itself is created from four connected edges, which in turn are 
  | defined by the four vertices v0, v1, v2 and v3.
  | Our final exterior boundary will look like this:
  |
  |                   v3                 v2
  |                     *---------------*
  |                     |               |
  |                     |               |
  |                     |               |
  |                     |               |
  |                     |               |
  |                     |               |
  |                     |               |
  |                     *---------------*
  |                    v0                v1
  |
  | Notice the orientation of the edges (v0,v1), (v1,v2), (v2,v3) 
  | and (v3,v0). 
  | Exterior boundary edges must always be defined in counter-
  | clockwise direction.
  ------------------------------------------------------------------*/
  Boundary&  b_ext = domain.add_exterior_boundary();

  Vertex& v0 = domain.add_vertex(  0.0,   0.0,   1.0,  1.0 );
  Vertex& v1 = domain.add_vertex(  1.0,   0.0,   1.0,  1.0 );
  Vertex& v2 = domain.add_vertex(  1.0,   1.0,   1.0,  1.0 );
  Vertex& v3 = domain.add_vertex(  0.0,   1.0,   1.0,  1.0 );

  b_ext.add_edge( v0, v1, 1 );
  b_ext.add_edge( v1, v2, 1 );
  b_ext.add_edge( v2, v3, 1 );
  b_ext.add_edge( v3, v0, 1 );
  
  /*------------------------------------------------------------------
  | In the following lines, the mesh will be initialized, as well 
  | as its advancing front structure (which is nescessary for the 
  | mesh generation)
  | After that, we simply triangulate the domain.
  ------------------------------------------------------------------*/
  Mesh mesh { domain };
  mesh.init_advancing_front();
  mesh.triangulate();

  /*------------------------------------------------------------------
  | In order to obtain a mesh that only consists of quad elements,
  | we will refine the mesh
  ------------------------------------------------------------------*/
  mesh.refine_to_quads();
  mesh.refine_to_quads();
  mesh.refine_to_quads();
  mesh.refine_to_quads();

  /*------------------------------------------------------------------
  | Here we use a smoother, in order to improve the mesh quality.
  | The smoothing is applied for four iterations. 
  ------------------------------------------------------------------*/
  Smoother smoother {};
  smoother.smooth(domain, mesh, 4);

  /*------------------------------------------------------------------
  | Finally, the mesh is exportet to a file in VTU format.
  ------------------------------------------------------------------*/
  std::string source_dir { TQMESH_SOURCE_DIR };
  std::string file_name 
  { source_dir + "/auxiliary/example_data/Example_11" };
  LOG(INFO) << "Writing mesh output to: " << file_name << ".txt";

  mesh.write_to_file( file_name, ExportType::txt );

} // run_example_11()
