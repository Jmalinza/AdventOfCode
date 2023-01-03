#pragma once

#include "utility.h"

#include <map>
#include <string>
#include <sstream>

using namespace aoc::utility;

namespace aoc::twenty22
{
    class RockScissorPaper
    {
        using Action = std::string;
        using Round = std::pair<Action , Action>;
        public:
            static int score_round(Action opponent, Action player)
            {
                if(opponent.empty() && player.empty()) return 0;

                auto round_score = _round_score_map.at({map_action(opponent), map_action(player)});
                auto action_score = _action_score_map.at(map_action(player));

                return round_score + action_score;
            }

            static std::string cheat(Action opponent, std::string needed_result)
            {
                if(needed_result == "Y") return opponent;

                auto possible_actions = _result_action_map.at(needed_result);

                return possible_actions[opponent];
            }
        private:
            static Action map_action(Action action)
            {
                auto result = _action_map1.find(action);
                if(result == _action_map1.end())
                    result = _action_map2.find(action);

                return result->second;
            }

            static inline const std::map<Action , Action> _action_map1{
                    {"A", "rock"}, {"B", "paper"}, {"C", "scissors"}};

            static inline const std::map<Action , Action> _action_map2{
                    {"X", "rock"}, {"Y", "paper"}, {"Z", "scissors"}};

            static inline const std::map<Action , int> _action_score_map{{"rock", 1}, {"paper", 2}, {"scissors", 3}};

            static inline const std::map<Round , int> _round_score_map{
                    {{"rock"    , "rock"}    , 3},
                    {{"paper"   , "paper"}   , 3},
                    {{"scissors", "scissors"}, 3},
                    {{"scissors", "paper"}   , 0},
                    {{"rock"    , "scissors"}, 0},
                    {{"paper"   , "rock"}    , 0},
                    {{"rock"    , "paper"}   , 6},
                    {{"paper"   , "scissors"}, 6},
                    {{"scissors", "rock"}    , 6}
            };

            static inline const std::map<std::string, std::map<Action, Action>> _result_action_map{
                    {"Z",
                            {{"A", "B"},
                             {"B", "C"},
                             {"C", "A"}}
                    },
                    {"X",
                            {{"A", "C"},
                             {"B", "A"},
                             {"C", "B"}}
                    }
            };
    };

    int find_score_from_strategy_guide(std::string path){
        std::vector<std::string> file(readAllLinesFrom(path));
        int score = 0;
        for(const auto& line: file)
        {
            std::stringstream round(line);
            std::string opponent;
            std::string player;
            round >> opponent;
            round >> player;
            score += RockScissorPaper::score_round(opponent, player);
        }

        return score;
    }

    int find_score_from_fixing_guide(std::string path){
        std::vector<std::string> file(readAllLinesFrom(path));
        int score = 0;
        for(const auto& line: file)
        {
            std::stringstream round(line);
            std::string opponent;
            std::string needed_result;
            round >> opponent;
            round >> needed_result;
            score += RockScissorPaper::score_round(opponent, RockScissorPaper::cheat(opponent, needed_result));
        }

        return score;
    }
}
