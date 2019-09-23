#!/bin/bash

HAO="/home/local/eda06/haoc"
HAO_WORKSPACE="$HAO/workspace"
ANAROUTE_DIR="$HAO/projects/anaroute"
BENCH_DIR="../bench"


./anaroute --tech_lef $HAO_WORKSPACE/packages/tech/tsmc40_vhv.lef \
           --tech_file a \
           --design_type a \
           --design_file $BENCH_DIR/magical/OTA_FF_2s_v3_nodummy/OTA_FF_2s_v3_nodummy.gr \
           --placement_layout a \
           --iopin a \
           --symnet a \
           --out a
