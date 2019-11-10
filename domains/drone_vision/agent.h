// Copyright 2019 The Darwin Neuroevolution Framework Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "drone.h"

#include <core/darwin.h>

#include <memory>
using namespace std;

namespace physics {

class Scene;

class Agent {
 public:
  Agent(const darwin::Genotype* genotype, Drone* drone);
  void simStep();

  static int inputs(const DroneConfig& config);
  static int outputs(const DroneConfig& config);

 private:
  Drone* drone_ = nullptr;
  unique_ptr<darwin::Brain> brain_;
};

}  // namespace physics
