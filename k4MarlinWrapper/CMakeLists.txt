#   Copyright 2019 CERN
#
#  Author: Andre Sailer <andre.philippe.sailer@cern.ch>
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#   Unless required by applicable law or agreed to in writing, software
#   distributed under the License is distributed on an "AS IS" BASIS,
#   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#   See the License for the specific language governing permissions and
#   limitations under the License.
#
#   In applying this licence, CERN does not waive the privileges and immunities
#   granted to it by virtue of its status as an Intergovernmental Organization
#   or submit itself to any jurisdiction. 
#

gaudi_install(PYTHON)
gaudi_install(SCRIPTS)

gaudi_add_module(k4MarlinWrapper
  SOURCES
    src/components/LcioEventAlgo.cpp
    src/components/MarlinProcessorWrapper.cpp
    src/components/EmptyAlg.cpp
  LINK
    GaudiAlgLib
    GaudiKernel
    ROOT::Core
    k4FWCore::k4FWCore
    EDM4HEP::edm4hep
    ${LCIO_LIBRARIES}
    ${Marlin_LIBRARIES}
)

target_include_directories(k4MarlinWrapper PUBLIC
  k4MarlinWrapper/
  ${Marlin_INCLUDE_DIRS}
  ${LCIO_INCLUDE_DIRS}
)
