#include "SpriteDrawableComponent.hpp"

SpriteDrawableComponent::SpriteDrawableComponent() {

}

SpriteDrawableComponent::SpriteDrawableComponent(Texture texture) : texture(texture) {

    flat_shader = ShaderProgram::createFromFiles("shaders/flat.vs", "shaders/flat.fs");
}

void SpriteDrawableComponent::draw(Mesh& mesh, Transform2D& transform2D) {
    mesh.linkToShader(flat_shader);

    mesh.prepareToBeDrawn();
    flat_shader.use();

    glUniform1i(flat_shader.getUniformLocation("sprite_texture"), 0);

    glActiveTexture(GL_TEXTURE0);
    texture.bind(GL_TEXTURE_2D);

    glm::mat3 transformation = transform2D.getTransformationMatrix();
    GLint transformation_location = flat_shader.getUniformLocation("transformation");
    glUniformMatrix3fv(transformation_location, 1, GL_FALSE, glm::value_ptr(transformation));

    mesh.draw();

}
