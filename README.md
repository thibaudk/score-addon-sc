# SC

This attempt to run the supercollider audio server inside a score Device/Process Adapted from 
https://github.com/chriskiefer/OpenFrameworks-Supercollider-Host
Created by Chris on 10/09/2011.
Copyright 2011 Goldsmiths Creative Computing. All rights reserved.

Supercollider's CMakeLists.txt had to be modified to remove the need for boost's test_exec_monitor (comented out at ligne 275, 294, 295, 296)
A copy of the edited file is stored in the override folder

Libscsynth is curently built prior to the addon by hand inside score's build directory
``` <score_build_dir>/src/addons/score-addon-sc/3rdparty/supercollider ```
and configured with the folowing cmake command 
``` cmake -DCMAKE_PREFIX_PATH=<score_source_dir>/3rdparty/libossia/3rdparty/boost_1_78_0/ <score_source_dir>/src/addons/score-addon-sc/3rdparty/supercollider/ -GNinja -DSC_IDE=OFF -DSC_EL=OFF -DBUILD_TESTING=OFF -DAUDIOAPI=portaudio -DSC_QT=OFF -DSC_HIDAPI=OFF -DSC_ABLETON_LINK=OFF -DSCLANG_SERVER=OFF -DCMAKE_BUILD_TYPE=Debug -DLIBSCSYNTH=ON -DENABLE_TESTSUITE=OFF -DNO_LIBSNDFILE=ON ```

The SCProcess class embedes the portaudio callback function that links against libscsynth

Nothing else yet, just lincking, in the dirtyest way
