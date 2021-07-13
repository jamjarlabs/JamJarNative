#include "render/material.hpp"

const JamJar::Color DEFAULT_COLOR(0.54, 0, 0.54, 1);

JamJar::Material::Material(Color color, const ShaderGroup &shaders, const Texture &texture)
    : color(color), shaders(shaders), texture(texture) {}

JamJar::Material::Material(Color color, const ShaderGroup &shaders)
    : color(color), shaders(shaders), texture(std::nullopt) {}

JamJar::Material::Material(Color color, const Texture &texture)
    : color(color), shaders(std::nullopt), texture(texture) {}

JamJar::Material::Material(Color color) : color(color), texture(std::nullopt) {}

JamJar::Material::Material() : Material(DEFAULT_COLOR) {}
