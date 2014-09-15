// $Id: Geant4Hits.cpp 513 2013-04-05 14:31:53Z gaede $
//====================================================================
//  AIDA Detector description implementation for LCD
//--------------------------------------------------------------------
//
//  Author     : M.Frank
//
//====================================================================

// Framework include files
#include "DD4hep/Printout.h"
#include "DD4hep/InstanceCount.h"
#include "DDG4/Geant4Vertex.h"

using namespace DD4hep;
using namespace DD4hep::Simulation;

/// Default destructor
VertexExtension::~VertexExtension() {
}

/// Copy constructor
Geant4Vertex::Geant4Vertex(const Geant4Vertex& c)
  : ref(1), x(c.x), y(c.y), z(c.z), time(c.time), out(c.out), in(c.in)
{
  InstanceCount::increment(this);
}

/// Default constructor
Geant4Vertex::Geant4Vertex()
  : ref(1), x(0), y(0), z(0), time(0)
{
  InstanceCount::increment(this);
}

/// Default destructor
Geant4Vertex::~Geant4Vertex()  {
  InstanceCount::decrement(this);
}

/// Assignment operator
Geant4Vertex& Geant4Vertex::operator=(const Geant4Vertex& c)   {
  if ( this != &c )  {
    x = c.x;
    y = c.y;
    z = c.z;
    time = c.time;
    in = c.in;
    out = c.out;
  }
  return *this;
}

Geant4Vertex* Geant4Vertex::addRef()   {
  ++ref;
  return this;
}

void Geant4Vertex::release()  {
  if ( --ref <= 0 ) delete this;
}