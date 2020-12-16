
from Gaudi.Configuration import *

from Configurables import LcioEvent, EventDataSvc, k4DataSvc, MyEmptyAlg
algList = []

theFile= 'edminput.root'
evtsvc = k4DataSvc('EventDataSvc')
evtsvc.input = '$k4MarlinWrapper_tests_DIR/inputFiles/' + theFile

from Configurables import PodioInput
inp = PodioInput("InputReader")
inp.collections = ["Particle"]
inp.OutputLevel = DEBUG
algList.append(inp)

# read = LcioEvent()
# read.OutputLevel = DEBUG
# read.Files = ["$k4MarlinWrapper_tests_DIR/inputFiles/muons.slcio"]
# algList.append(read)


tester = MyEmptyAlg()
algList.append(tester)

from Configurables import ApplicationMgr
ApplicationMgr( TopAlg = algList,
                EvtSel = 'NONE',
                EvtMax   = 10,
                ExtSvc = [evtsvc],
                OutputLevel=DEBUG
)
