#ifndef SpriteDrawableComponent_h
#define SpriteDrawableComponent_h

#include "Mesh.hpp"
#include "Transform2D.hpp"
#include "FlatDrawable.hpp"
#include "ShaderProgram.hpp"
#include "Texture.hpp"

class SpriteDrawableComponent {
public:
    SpriteDrawableComponent();
    SpriteDrawableComponent(Texture texture);
    void draw(Mesh& mesh, Transform2D& transform_2D);
private:
    ShaderProgram flat_shader;
    Texture texture;

};

#endif
