#ifndef STANDARD_2D_PRIMITIVE_PRIMITIVE_SYSTEM_HPP
#define STANDARD_2D_PRIMITIVE_PRIMITIVE_SYSTEM_HPP

#include "component/component.hpp"
#include "entity/entity.hpp"
#include "message/message_bus.hpp"
#include "system/evaluator.hpp"
#include "system/map_system.hpp"
#include <string>

namespace JamJar::Standard::_2D {
class PrimitiveSystem : public MapSystem {
  public:
    explicit PrimitiveSystem(MessageBus *messageBus);
    void OnMessage(Message *message) override;
    const static std::string DEFAULT_PRIMITIVE_VERTEX_SHADER_NAME;
    const static std::string DEFAULT_PRIMITIVE_FRAGMENT_SHADER_NAME;

  private:
    void preRender(float alpha);
    static bool evaluator(Entity *entity, const std::vector<JamJar::Component *> &components);
#ifdef __EMSCRIPTEN__
    void loadWebgl2Shaders();
#endif
};
}; // namespace JamJar::Standard::_2D

#endif
