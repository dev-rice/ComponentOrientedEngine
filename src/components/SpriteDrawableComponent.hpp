#ifndef SpriteDrawableComponent_h
#define SpriteDrawableComponent_h

#include "Mesh.hpp"
#include "Transform2D.hpp"
#include "FlatDrawable.hpp"
#include "ShaderProgram.hpp"

class SpriteDrawableComponent {
public:
    SpriteDrawableComponent();
    void draw(Mesh& mesh, Transform2D& transform2D);
private:
    ShaderProgram flat_shader;

};

#endif
