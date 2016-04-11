#include "MeshFactory.hpp"

Mesh MeshFactory::createFlatMesh() {
    VertexSpecification flat_mesh_vertex_specification;

    flat_mesh_vertex_specification.addAttribute(VertexAttribute("position", 2, 0));
    flat_mesh_vertex_specification.addAttribute(VertexAttribute("texture_coordinates", 2, 2));

    vector<GLfloat> vertices = {
             -1.0f,  1.0f,  0.0f, 0.0f,
             -1.0f, -1.0f,  0.0f, 1.0f,
              1.0f,  1.0f,  1.0f, 0.0f,
              1.0f, -1.0f,  1.0f, 1.0f,

    };

    vector<GLuint> elements = {
            0, 1, 2,
            1, 3, 2,
    };

    MeshData mesh_data(vertices, elements);
    Mesh flat_mesh(mesh_data, flat_mesh_vertex_specification);
    return flat_mesh;
}
