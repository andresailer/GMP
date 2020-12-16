#include "EmptyAlg.h"

#include <iostream>



DECLARE_COMPONENT(MyEmptyAlg)

MyEmptyAlg::MyEmptyAlg(const std::string& aName, ISvcLocator* aSvcLoc) : GaudiAlgorithm(aName, aSvcLoc) {
  //  declareProperty("Particle", mcps_handle, "");
}

MyEmptyAlg::~MyEmptyAlg() {}

StatusCode MyEmptyAlg::initialize() {
  return StatusCode::SUCCESS;
}

StatusCode MyEmptyAlg::execute() {


  std::cout << "Define"  << std::endl;
  std::cout << "get"  << std::endl;
  DataHandle<edm4hep::MCParticleCollection> mcps_handle {"Particle", Gaudi::DataHandle::Reader, this};
  const edm4hep::MCParticleCollection* mcps = mcps_handle.get();
  std::cout << "got"  << std::endl;
  std::cout << mcps  << std::endl;
  
  for(auto mcIter = mcps->begin(); mcIter != mcps->end(); ++mcIter) {
    std::cout << mcIter->getPDG()  << std::endl;
  }
  
  return StatusCode::SUCCESS;
}

StatusCode MyEmptyAlg::finalize() {
  return StatusCode::SUCCESS;
}
