
#pragma once

#include <third_party/box2d/box2d.h>

#include <vector>
using namespace std;

namespace phys {

struct Receptor {
  b2Color color;
  float distance = 0;

  Receptor() = default;

  explicit Receptor(const b2Color& color, float distance)
      : color(color), distance(distance) {}
};

class Camera {
 public:
  Camera(b2Body* body, float fov, float near, float far, int resolution);

  vector<Receptor> render() const;

  b2Body* body() const { return body_; }

  float fov() const { return fov_; }
  float near() const { return near_; }
  float far() const { return far_; }
  int resolution() const { return resolution_; }

 private:
  Receptor castRay(const b2Vec2& ray_start,
                   const b2Vec2& ray_end,
                   float min_fraction) const;

 private:
  b2Body* body_ = nullptr;

  // field of view (in degrees)
  const float fov_ = 0;

  const float near_ = 0;
  const float far_ = 0;

  const int resolution_ = 0;

  // the shadow attenuation factor
  // [0=completely blocking light .. 1=no shadows]
  float shadow_attenuation_ = 1.0f;

  bool render_specular_ = true;
  
  // technically this should be a property of the scene (world),
  // but modeled here for convenience and extra flexibility
  b2Color ambient_light_{ 0.2f, 0.2f, 0.2f };
};

}  // namespace phys