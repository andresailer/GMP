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
    if(mcIter->getGeneratorStatus() == 1) {
      std::cout << "MC " << mcIter->getPDG() << mcIter->getEnergy()  << std::endl;
    }
  }

  DataHandle<edm4hep::ReconstructedParticleCollection> recos_handle {"ReconstructedParticles", Gaudi::DataHandle::Reader, this};
  const auto* recos = recos_handle.get();
  for(auto mcIter = recos->begin(); mcIter != recos->end(); ++mcIter) {
    std::cout << "Reco energy " << mcIter->getEnergy()  << std::endl;
  }
  
  return StatusCode::SUCCESS;
}

StatusCode MyEmptyAlg::finalize() {
  return StatusCode::SUCCESS;
}
