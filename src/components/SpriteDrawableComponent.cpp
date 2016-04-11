#include "SpriteDrawableComponent.hpp"

SpriteDrawableComponent::SpriteDrawableComponent() {
    flat_shader = ShaderProgram::createFromFiles("shaders/flat.vs", "shaders/flat.fs");
}

void SpriteDrawableComponent::draw(Mesh& mesh, Transform2D& transform2D) {
    FlatDrawable flat_drawable(mesh, flat_shader);
    flat_drawable.draw(transform2D);
}
