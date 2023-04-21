#! /bin/bash

./bin/run_examples $1
python3 scripts/plot_mesh.py /Users/max/Developer/Stage/Workspace/3D/TQMesh/auxiliary/example_data/Example_$1.txt
