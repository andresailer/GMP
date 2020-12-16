#pragma once 

#include <k4FWCore/DataHandle.h>

#include <edm4hep/MCParticle.h>
#include <edm4hep/MCParticleCollection.h>
#include <edm4hep/ReconstructedParticleCollection.h>


#include "GaudiAlg/GaudiAlgorithm.h"
#include "Gaudi/Property.h"


class MyEmptyAlg : public GaudiAlgorithm {
public:
  explicit MyEmptyAlg(const std::string&, ISvcLocator*);
  virtual ~MyEmptyAlg();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize() final;
  /**  Execute.
   *   @return status code
   */
  virtual StatusCode execute() final;
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize() final;

private:
  // member variable 
  int m_member = 0; 

};
