#ifndef MeshFactory_h
#define MeshFactory_h

#include "VertexSpecification.hpp"
#include "MeshData.hpp"
#include "Mesh.hpp"

class MeshFactory {
public:

    MeshFactory();

    Mesh createFlatMesh();

private:

    VertexSpecification flat_mesh_vertex_specification;
};

#endif
