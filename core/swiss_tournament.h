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

#include <core/darwin.h>
#include <core/properties.h>
#include <core/tournament.h>

namespace tournament {

//! SwissTournament configuration
struct SwissTournamentConfig : public core::PropertySet {
  PROPERTY(rounds, int, 20, "Number of tournament rounds");
  PROPERTY(rematches, bool, true, "Play both-side rematches?");
};

//! [Swiss-style tournament](https://en.wikipedia.org/wiki/Swiss-system_tournament)
class SwissTournament : public Tournament {
  class PairingLog;
  
 public:
  explicit SwissTournament(const core::PropertySet& config);

  void evaluatePopulation(darwin::Population* population, GameRules* game_rules) override;

 private:
  SwissTournamentConfig config_;
};

}  // namespace tournament
