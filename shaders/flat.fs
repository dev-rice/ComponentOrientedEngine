#version 410 core

in vec2 TextureCoordinates;

out vec4 outColor;

uniform sampler2D sprite_texture;

void main() {
    vec4 sprite_texel = texture(sprite_texture, TextureCoordinates);
    outColor = sprite_texel;

}
