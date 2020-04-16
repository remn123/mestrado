#pragma once

#include <memory>
#include <string>
#include <vector>

#include <Property.h>

class Edge
{
public:
  std::shared_ptr<Property> physical;
  std::vector<long> nodes;
  
  long left;
  long right;
  long id;
  long ghost;
  int type;
  int group;
  int boundary;
public:
  Edge(const std::vector<long>&, const long&, const long&, const long&);
  ~Edge();

  void print_nodes(void);

private:

};

// Face CLASS
class Face
{
public:

  std::shared_ptr<std::vector<long>> nodes = std::make_shared<std::vector<long>>();
  long id;
  
public:
  Face(std::vector<std::string>);
  ~Face();

  void print_nodes(void);

private:

};