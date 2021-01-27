#ifndef ROUTE_PLANNER_H
#define ROUTE_PLANNER_H

#include "route_model.h"
#include <iostream>
#include <string>
#include <vector>

class RoutePlanner {
public:
  RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x,
               float end_y);
  float GetDistance() const { return distance; }
  void AStarSearch();
  static bool Compare(RouteModel::Node *node1, RouteModel::Node *node2) {
    return (node1->h_value + node1->g_value > node2->h_value + node2->g_value);
  }

  void AddNeighbors(RouteModel::Node *current_node);
  float CalculateHValue(RouteModel::Node const *node);
  std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
  RouteModel::Node *NextNode();

private:
  std::vector<RouteModel::Node *> open_list;
  RouteModel::Node *start_node;
  RouteModel::Node *end_node;

  float distance = 0.0f;
  RouteModel &m_Model;
};

#endif